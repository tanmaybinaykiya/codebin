<?php
class UsersController extends AppController {

    var $name = 'Users';
    var $helpers = array('Html', 'Form', 'Javascript', 'Parser');
    var $uses = array('User', 'Event', 'Team', 'Membership', 'Invite', 'Accommodation', 'Workshop', 'WorkshopsUser','College');
    var $components = array('Auth', 'Email','Upload');

    function beforeFilter() {
        parent::beforeFilter();
        $this->Auth->allow(array('register', 'verify', 'admin_login','resetpwd','resetpwdmail'));
    }

    function index() {
        $this->Event->unbindModel(array('hasMany' => array('Team'), 'belongsTo' => array('Category')));
        $this->User->unbindModel(array('hasMany' => array('Membership')));
        $membershipArray = $this->Membership->fetchTeams($this->Auth->user('id'));
        $teamInvites = $this->Invite->fetchByEmail($this->Auth->user('email'));
        $accommodation = $this->Accommodation->find('first', array('conditions' => array('user_id' => $this->Auth->user('id'))));
        $user = $this->User->find('first', array('conditions' => array('id' => $this->Auth->user('id'))));
        $workshopRegistrations = $this->WorkshopsUser->find('all', array('conditions' => array('user_id' => $this->Auth->user('id')),'recursive' => 0 ));
        $uploadedfiles = listFilesInDir('../../app/webroot/proofs','A'.$this->Auth->user('id_no'));
       
        $this->set(compact('user','membershipArray', 'teamInvites', 'accommodation', 'workshopRegistrations','uploadedfiles'));

        if (!empty($this->data)) {
            if ($this->Invite->create($this->data) && $this->Invite->validates()) {
                // Check if User is the creator of the Team
                if (!$this->Membership->hasAny(array('Membership.team_id' => $this->data['Invite']['team_id'], 'Membership.user_id' => $this->Auth->user('id'), 'Membership.user_role' => 'creator'))) {
                    $this->Session->setFlash('You are not the creator of this Team.');
                }
                // Check if User has already been invited to team
                else if ($this->Invite->hasAny(array('Invite.team_id' => $this->data['Invite']['team_id'], 'Invite.email' => $this->data['Invite']['email']))) {
                    $this->Session->setFlash('You have already invited this user to your team.');
                }
                // Check if User has signed up for Event
                else {
                    $myTeam = $this->Team->findById($this->data['Invite']['team_id']);
                    $event = $this->Event->findById($myTeam['Team']['event_id']);
                    // Check if Team Limit has been reached
                    if ($this->Team->memberCount($this->data['Invite']['team_id']) >= $event['Event']['max_participants']) {
                        $this->Session->setFlash('Your team is already full. You cannot invite more members.');
                        return;
                    }
                    $user = $this->User->find('first', array('conditions' => array('User.email' => $this->data['Invite']['email'])));
                    if ($user != null) {
                        $this->User->id = $user['User']['id'];
                        if ($this->User->hasRegisteredFor($event['Event']['id'])) {
                            $this->Session->setFlash('This user is already part of a team for this Event.');
                            return;
                        }
                    }
                    // Notify User by Email

                    // Set layout variables
                    $invite_greeting = 'Greetings!'; // First line of email body
                    $inviter_name = $this->Auth->user('name');
                    $invitee_user_role = 'Team Member';
                    $event_name = $event['Event']['name'];

                    $this->Email->from = 'Quark 2012 <info@bits-quark.org>';
                    $this->Email->subject = $inviter_name . ' has invited you for ' . $event_name;
                    if ($user != null) {
                        $invite_greeting = 'Dear ' . $user['User']['name'] . ',';
                        $this->Email->to = $user['User']['name'] . ' <' . $user['User']['email'] . '>';
                        $this->Email->template = 'invite';
                    } else {
                        $this->Email->to = $this->data['Invite']['email'];
                        $this->Email->template = 'invite_new';
                    }
                    $this->Email->sendAs = 'both';
                    $this->set('invite_greeting', $invite_greeting);
                    $this->set('inviter_name', $inviter_name);
                    $this->set('invitee_user_role', $invitee_user_role);
                    $this->set('event_name', $event_name);
                    if ($this->Email->send()) {
                        // Save Invite
                        $this->Invite->save();
                        $this->Session->setFlash('You have successfully invited this user to your team.');
                        // Erase data
                        unset($this->data['Invite']);
                    } else {
                        $this->Session->setFlash('There was an error emailing this user.');
                    }
                }
            } else {
                $this->Session->setFlash('An error occurred. Could not invite user.');
            }
        }
    }

    function login() {
        if ($this->Auth->user()) {
            $verify_key = $this->Auth->user('verify_key');
            if (!empty($verify_key)) {
                $this->Session->setFlash('You have not yet verified your account. Please check your email and click on the verification link to proceed.');
                $this->logout();
            } else {
                $this->redirect(array('controller' => 'users', 'action' => 'index'));
            }
        }
    }

    function logout() {
        $this->Session->del('Auth.User');
        $this->redirect(array('controller' => 'pages', 'action' => 'display', 'home'));
    }

    function accommodation() {
        $accommodation = $this->Accommodation->find('first', array('conditions' => array('user_id' => $this->Auth->user('id'))));
        $uploadedfiles = listFilesInDir('../../app/webroot/proofs','A'.$this->Auth->user('id_no'));
        $flash='';
        
        if (!empty($this->data)) {
            if (!empty($accommodation)) 
            {
                $this->data['Accommodation']['id'] = $accommodation['Accommodation']['id'];
            }
            $this->data['Accommodation']['user_id'] = $this->Auth->user('id');
            $temp = 'Q11'.$this->Auth->user('id_no');
            if(!isset($this->data['Accommodation']['quark_ids']))
            {
                $this->data['Accommodation']['quark_ids'] = array();
            }
            array_push($this->data['Accommodation']['quark_ids'],$temp);
            $this->data['Accommodation']['quark_ids'] = json_encode($this->data['Accommodation']['quark_ids']);
            
           // debug($this->data['Accommodation']['travelproof'][0]['error']);
            
            if(count($uploadedfiles)>=1 &&  $this->data['Accommodation']['travelproof'][0]['error'] != 4)
            {
                $flash.=' You are allowed to upload only 1 zip, rar or 7z file. ';
            	
		        
            }
            //upload here
           else if(count($uploadedfiles)<1 )
           {
               if ($this->Accommodation->create($this->data) && $this->Accommodation->validates()) {

		        foreach ($this->data['Accommodation']['travelproof'] as $proof)
			    {
			        
		            $filename=$proof['name'];
		            $ext=trim(substr($filename,strrpos($filename,".")+1,strlen($filename)));
		            if($proof['size']>0)
		            {
			            $destination = realpath('../../app/webroot/proofs') . '/A'.$this->Auth->user('id_no').'_';
			            $file=$proof;
			            if($ext=='zip'||$ext=='rar'||$ext=='7z'||$ext=='zipx')
			            {
			                $result=$this->Upload->upload($file,$destination);
			                if($result==false)
			                {
			                    $errors=$this->Upload->errors;
			                    if(is_array($errors))
			                    {
			                        $errors=implode("<br/>", $errors);
			                    }
			                    $this->Session->setFlash($errors);
			                    return;
			                }
			                
			
			            }
			            else
			            {
			            	$this->Session->setFlash(' Fill the form properly and upload travel proof only in rar or zip formats. ');

                                        return;
			            }
		        	}
			        else
			        {

                                    $this->Session->setFlash(' You did not upload a File. Please, try again. ');

			            return;
			        }
			    }
               }
               else
               {
                    $this->Session->setFlash(' There was an error in submitting your form. ');
               }
            }
		    //save data
	       
	        if ($this->Accommodation->save($this->data))
	        {
                    $flash .= 'Your accommodation information has been recorded. ';
                    $this->Session->setFlash($flash);
	            //$this->redirect(array('controller' => 'users', 'action' => 'index'));
	        } 
	        else 
	        {
                    $flash .= ' There was an error in submitting your form. ';
                    $this->Session->setFlash($flash);
	            
	        }

                
                
        }
 
        $accommodation = $this->Accommodation->find('first', array('conditions' => array('user_id' => $this->Auth->user('id'))));
        $uploadedfiles = listFilesInDir('../../app/webroot/proofs','A'.$this->Auth->user('id_no'));
        $this->set(compact('accommodation','uploadedfiles'));
    }

    function workshop() {
        $workshopArray = $this->Workshop->find('list');

        if (!empty($this->data)) {
            $selectedworkshop = $this->Workshop->find('first', array('conditions' => array('id' => $this->data['Workshop']['workshop_id'])));
            if($selectedworkshop['Workshop']['team_event'] == 'Yes')
            {
                $this->redirect(array('controller' => 'users', 'action' => 'team_workshop',$this->data['Workshop']['workshop_id']));
            }
            else
            {

                $array['user_id'] = $this->Auth->user('id');
                $array['workshop_id'] = $this->data['Workshop']['workshop_id'];

                if($this->WorkshopsUser->hasAny(array('user_id'=>$array['user_id'] ,'workshop_id'=>$array['workshop_id'])))
                {
                    $this->Session->setFlash('You have already registered for this workshop!');
                    $this->redirect(array('controller' => 'users', 'action' => 'index'));
                }
                else
                {
                    if ($this->WorkshopsUser->save($array)){
                        $this->Session->setFlash('Thanks for registering for the workshop, "' . $workshopArray[$this->data['Workshop']['workshop_id']] . '". Please check your e-mail for payment details.');
                        $this->Email->from = 'Quark 2012 <info@bits-quark.org>';
                        $this->Email->to = $this->Auth->user('name') . ' <' . $this->Auth->user('email') . '>';
                        $this->Email->subject = 'Workshop Registration Details for Quark 2012';
                        $this->Email->template = 'workshop';
                        $this->Email->sendAs = 'both';

                        $workshop = $this->Workshop->find('first', array('conditions' => array('id' => $array['workshop_id'])));
                        $wsPrice = $workshop['Workshop']['price'];
                        $wsName = $workshop['Workshop']['name'];
                        $userName = $this->Auth->user('name');
                        $userId = "Q11" . $this->Auth->user('id_no');

                        $favour = "Director, BITS, Pilani - K. K. Birla Goa Campus";
                        $payable = "State Bank Of India, ZUARINAGAR Branch. [Branch Code: 01976]";

                        $this->set(compact('wsPrice', 'wsName', 'userName', 'userId', 'favour', 'payable'));
                        if ($this->Email->send()) {
                            $this->redirect(array('controller' => 'users', 'action' => 'index'));
                        } else {
                            $this->Session->setFlash('The mail server doesn\'t seem to be responding.');
                        }
                    }
                    else {
                        $this->Session->setFlash('There was an error in submitting your form.');
                    }
                }
                $this->set(compact('workshop'));
            }
        }
        $this->set(compact('workshopArray'));
    }

    function team_workshop($id)
    {
        $flash = "";
        $team_id = "";
        $workshop = $this->Workshop->find('first', array('conditions' => array('id' => $id)));
        $this->set('id',$id);
        if($workshop!=null)
        {
            $this->set('member_no',$workshop['Workshop']['no_of_members']);
            if(!empty($this->data))
            {
                foreach($this->data['Workshop']['quark_id'] as $quark_id)
                {   $quark_id = substr($quark_id,3);
                    
                    
                    $user = $this->User->find('first', array('conditions' => array('id_no' => $quark_id)));
                    if($user == null)
                    {
                        $this->Session->setFlash('Wrong quark id/ids.');
                        return;
                    }
                }
                foreach($this->data['Workshop']['quark_id'] as $quark_id)
                {
                   
                    $quark_id = substr($quark_id,3);
                    $user = $this->User->find('first', array('conditions' => array('id_no' => $quark_id)));
                    $array['team_id'] = 'W'.$this->Auth->user('id_no');
                    $array['workshop_id'] = $id;
                    $array['user_id'] = $user['User']['id'];
                    if($this->WorkshopsUser->hasAny(array('user_id'=>$array['user_id'] ,'workshop_id'=>$array['workshop_id'])))
                    {
                        $this->Session->setFlash(" Quark id "."Q11".$quark_id." already registered. ");
                        return;
                    }
                    else
                    {
                        $this->WorkshopsUser->create();
                        if ($this->WorkshopsUser->save($array))
                        {
                           
                        }
                        else
                        {
                            $flash .= " Error in submitting form for quark id "."Q11".$quark_id." <br/>";

                        }
                    }
                    $team_id = $array['team_id'];
                    
                }
                 $this->Email->from = 'Quark 2012 <info@bits-quark.org>';
                $this->Email->to = $this->Auth->user('name') . ' <' . $this->Auth->user('email') . '>';
                $this->Email->subject = 'Workshop Registration Details for Quark 2012';
                $this->Email->template = 'team_workshop';
                $this->Email->sendAs = 'both';

                $workshop = $this->Workshop->find('first', array('conditions' => array('id' => $array['workshop_id'])));
                $wsPrice = $workshop['Workshop']['price'];
                $wsName = $workshop['Workshop']['name'];
                $userName = $this->Auth->user('name');
                $userId = "Q11" . $this->Auth->user('id_no');
                $teamId = 'W' . $this->Auth->user('id_no');

                $favour = "Director, BITS, Pilani - K. K. Birla Goa Campus";
                $payable = "State Bank Of India, ZUARINAGAR Branch. [Branch Code: 01976]";

                $this->set(compact('wsPrice', 'wsName', 'userName', 'userId', 'favour', 'payable', 'teamId'));
                if ($this->Email->send())
                {

                }
                else
                {
                    $flash .= 'The mail server doesn\'t seem to be responding.<br/>';
                }
                if($flash == "") $flash = "Team successfully registered.<br/> Your team id is ".'W'.$this->Auth->user('id_no')."<br/>A mail has been sent to your email address. Please check it out for more info.";
                $this->Session->setFlash($flash);

            }
        }
        else
        {
            $this->Session->setFlash("Invalid workshop");
            $this->redirect(array('controller' => 'users', 'action' => 'workshop'));
        }
    }
    function register() {
    	
    	$this->set('colleges',$this->College->find('list',array('fields' => array('College.college','College.college'), 'order' => array('College.college'))));
    	
    	
        if (!empty($this->data)) {
        	if($this->data['User']['secretword'] == $this->data['User']['secretword2'])
        	{
	            if ($this->User->create($this->data) && $this->User->validates()) {
	
	                $this->data['User']['password'] = Security::hash($this->data['User']['secretword'], null, true);
	                $this->data['User']['verify_key'] = $this->__getRandId(32);
	                unset($this->data['User']['secretword']);
	
	                $this->Email->from = 'Quark 2012 <no-reply@bits-quark.org>';//keem from email id
	                $this->Email->to = $this->data['User']['name'] . ' <' . $this->data['User']['email'] . '>';
	                $this->Email->subject = 'Verification Email for Quark 2012';
	                $this->Email->template = 'welcome';
	                $this->Email->sendAs = 'both';
	                $this->set('name', $this->data['User']['name']);
	                $this->set('verify_link', 'http://www.bits-quark.org/portal/users/verify/' . $this->data['User']['verify_key']);
	               
	
	                /* Set delivery method */
	                
	                
	
	                if ($this->Email->send()) {
	                    $this->set('mail_sent', true);
	                } else {
	                    
	                    $this->Session->setFlash('The mail server doesn\'t seem to be responding.');
	                    unset($this->data['User']['verify_key']); // Make sure the user is able to register atleast
	                }
	                
	                if ($this->User->save($this->data)) {
	                    unset($this->data['User']);
	                    $this->set('success', true);
	                } else {
	                    $this->Session->setFlash('An error occured.');
	                }
	
	            } else {
	                $this->Session->setFlash('There seems to be an error with your submission.');
	                unset($this->data['User']['secretword']);
	            }
        	}
        	else
        	{
        		 $this->Session->setFlash('Passwords do not match.');
	             unset($this->data['User']['secretword']);
        	}
        }
    }

    function verify($key = null) {
        $user = $this->User->find('first', array('conditions' => array('User.verify_key' => $key)));
        if ($user != null) {
            // Verification Successful
            $this->User->id = $user['User']['id'];
            $this->User->saveField('verify_key', '');
            $this->Session->setFlash('You have successfully verified your account. You may now log in.');
        }
        $this->redirect(array('controller' => 'users', 'action' => 'login'));
    }

    function resetpwd($key = null) {
        
        $user = $this->User->find('first', array('conditions' => array('User.reset_password_key' => $key)));
        if ($user != null) {
            $this->set('key', $key);
            // Verification Successful
            if(!empty($this->data))
            {
                if($this->data['User']['secretword'] == $this->data['User']['secretword2'])
        	{
                    $this->data['User']['password'] = Security::hash($this->data['User']['secretword'], null, true);
                    $this->User->id = $user['User']['id'];
                    $this->User->saveField('reset_password_key', '');
                    $this->User->saveField('password', $this->data['User']['password'] );
                    $this->Session->setFlash('You have successfully reset your password. You should now log in.');
                    $this->redirect(array('controller' => 'users', 'action' => 'login'));
                }
                else
        	{
                     $this->Session->setFlash('Passwords do not match.');
	             unset($this->data['User']['secretword']);
        	}
            }
        }
        else
        {
            $this->Session->setFlash('Invalid key');
            $this->set('key',false);
            $this->redirect(array('controller' => 'users', 'action' => 'resetpwdmail'));
        }
        //$this->redirect(array('controller' => 'users', 'action' => 'login'));
    }
    function resetpwdmail()
    {
        $this->set('displayform', true);
        if(!empty($this->data))
        {
                $user = $this->User->find('first', array('conditions' => array('User.email' => $this->data['User']['email'])));
                $this->data['User']['reset_password_key'] = $this->__getRandId(32);
                $this->Email->from = 'Quark 2012 <no-reply@bits-quark.org>';//keem from email id
                $this->Email->to =  ' <' . $this->data['User']['email'] . '>';
                $this->Email->subject = 'Reset Password Email for Quark 2012';
                $this->Email->template = 'resetpwd';
                $this->Email->sendAs = 'both';

                $this->set('reset_password_link', 'http://www.bits-quark.org/portal/users/resetpwd/' . $this->data['User']['reset_password_key']);

                if ($this->Email->send()) {
                    $this->set('displayform', false);
                    $this->Session->setFlash('A mail has been sent to this email address. Please check your mail and follow the link to reset your password');
                    $this->User->id = $user['User']['id'];
                    $this->User->saveField('reset_password_key', $this->data['User']['reset_password_key']);
                } else {

                    $this->Session->setFlash('The mail server doesn\'t seem to be responding.');
                    unset($this->data['User']['reset_password_key']);
                }
               

        }
    }

    function edit_user_info()
    {
        
        $this->set('colleges',$this->College->find('list',array('fields' => array('College.college','College.college'), 'order' => array('College.college'))));
        if (!empty($this->data))
        {
        	if($this->data['User']['secretword'] == $this->data['User']['secretword2'])
        	{
                    $this->data['User']['password'] = Security::hash($this->data['User']['secretword'], null, true);
                    $this->User->id =  $this->Auth->user('id');
                    $this->User->saveField('name', $this->data['User']['name']);
                    $this->User->saveField('password', $this->data['User']['password'] );
                    $this->User->saveField('gender', $this->data['User']['gender']);
                    $this->User->saveField('college', $this->data['User']['college']);
                    $this->User->saveField('othercollege', $this->data['User']['othercollege']);
                    $this->User->saveField('address', $this->data['User']['address']);
                    $this->User->saveField('state', $this->data['User']['state']);
                    $this->User->saveField('year', $this->data['User']['year']);
                    $this->User->saveField('mobile', $this->data['User']['mobile']);
                    $this->Session->setFlash('Your Info has been updated');
                    $this->redirect(array('controller' => 'users', 'action' => 'index'));
                }
                else
                {
                    $this->Session->setFlash('Password do not match');
                }
        }
    }

    function join($teamId = null) {
        // Team Parameter is empty
        if ($teamId == null) {
            $this->__errorOccurred('No such team exists.');
        }
        // Find Team, Check if Team Exists
        $team = $this->Team->findById($teamId);
        if ($team == null) {
            $this->__errorOccurred('No such team exists. It was probably disbanded.');
        }
        // Check if User was Invited by Team
        $this->User->id = $this->Auth->user('id');
        if (!$this->User->hasInvite($teamId)) {
            $this->__errorOccurred('You haven\'t been invited by this team. Please contact the Team Owner first.');
        }
        // Check if Team is Full
        $event = $this->Event->find('first', array('conditions' => array('Event.id' => $team['Team']['event_id'])));
        if ($this->Team->memberCount($team['Team']['id']) >= $event['Event']['max_participants']) {
            $this->__errorOccurred('Sorry, but this team is already full!');
        }
        // Check if User has registered for Event already
        if ($this->User->hasRegisteredFor($event['Event']['id'])) {
            $this->__errorOccurred('Sorry, but you have already joined a team for this Event.');
        }
        $invite = $this->Invite->find('first', array('conditions' => array('Invite.team_id' => $teamId, 'Invite.email' => $this->Auth->user('email'))));
        // Delete Invitation
        $this->Invite->deleteAll(array('Invite.team_id' => $teamId, 'Invite.email' => $this->Auth->user('email')));
        // Make User Join Team
        $data = array(
            'Membership' => array(
                'team_id' => $teamId,
                'user_id' => $this->Auth->user('id'),
                'user_role' => 'member'
            )
        );
        $this->Membership->save($data);
        $this->__processCompleted('You have successfully joined this team!');
    }

    function participate($eventId = null) {
        $event = $this->Event->findById($eventId);

        // Check if event exists
        if ($event == null) {
            $this->redirect('/');
        }
        // Pass onto view
        $this->set('event', $event);

        // Check if user has already registered for event
        $this->User->id = $this->Auth->user('id');
        if ($this->User->hasRegisteredFor($event['Event']['id'])) {
            $this->__errorOccurred('You\'ve already registered for the event, ' . $event['Event']['name'] . '.');
        }

        // Register the user for the event: Create Team
        $data = array(
            'Team' => array(
                'event_id' => $event['Event']['id']
            ),
            'Membership' => array(
                'user_id' => $this->Auth->user('id'),
                'user_role' => 'creator'
            )
        );
        // Save Team
        if (!$this->Team->save($data)) {
            $this->__errorOccurred('Failed to create team.');
        }
        // Set Team ID
        $data['Membership']['team_id'] = $this->Team->id;
        // Save Membership Join
        if (!$this->Team->Membership->save($data)) {
            $this->__errorOccurred('Failed to add user to team.');
        }
        $this->__processCompleted('You have been successfully registered.');
    }

    function disband($teamId = null) {
        // Check if it is a valid team
        $team = $this->Team->findById($teamId);
        if ($team == null) {
            $this->__errorOccurred();
        }
        // Check if it was called by the Team Creator
        if ($this->Team->fetchCreatorId($teamId) != $this->Auth->user('id')) {
            $this->__errorOccurred('You are not the creator of this team.');
        }
        // Disband team
        $this->Team->delete($teamId);
        $this->__processCompleted('You have successfully disbanded the team.');
    }

    function quit($teamId = null) {
        // Check if it is a valid team
        $team = $this->Team->findById($teamId);
        if ($team == null) {
            $this->__errorOccurred();
        }
        // Check if it was called by the Team Creator
        /*if ($this->Team->hasMember($this->Auth->user('id'))) {
            $this->__errorOccurred('You are not a part of this team.');
        }*/
        // Check the number of people in the team
        // If count = 1, delete the team
        if ($this->Team->memberCount($teamId) == 1) {
            $this->Team->delete($teamId);
        }
        // Quit from team
        $this->Membership->deleteAll(array('Membership.user_id' => $this->Auth->user('id'), 'Membership.team_id' => $teamId));
        $this->__processCompleted('You have successfully left the team.');
    }

    function admin_index() {
        $this->User->recursive = 0;
        $this->set('users', $this->paginate());
    }

    function admin_view($id = null) {
        if (!$id) {
            $this->Session->setFlash(__('Invalid User.', true));
            $this->redirect(array('action'=>'index'));
        }    
        $this->set('user', $this->User->read(null, $id));
        
    }

    function admin_add() {
        if (!empty($this->data)) {
            $this->User->create();
            if ($this->User->save($this->data)) {
                $this->Session->setFlash(__('The User has been saved', true));
                $this->redirect(array('action'=>'index'));
            } else {
                $this->Session->setFlash(__('The User could not be saved. Please, try again.', true));
            }
        }
    }

    function admin_edit($id = null) {
        if (!$id && empty($this->data)) {
            $this->Session->setFlash(__('Invalid User', true));
            $this->redirect(array('action'=>'index'));
        }
        if (!empty($this->data)) {
            if ($this->User->save($this->data)) {
                $this->Session->setFlash(__('The User has been saved', true));
                $this->redirect(array('action'=>'index'));
            } else {
                $this->Session->setFlash(__('The User could not be saved. Please, try again.', true));
            }
        }
        if (empty($this->data)) {
            $this->data = $this->User->read(null, $id);
        }
    }

    function admin_delete($id = null) {
        if (!$id) {
            $this->Session->setFlash(__('Invalid id for User', true));
            $this->redirect(array('action'=>'index'));
        }
        if ($this->User->del($id)) {
            $this->Session->setFlash(__('User deleted', true));
            $this->redirect(array('action'=>'index'));
        }
    }

    function admin_login() {
        // Initialization: If there are 0 users, add a new user
        $total = $this->User->find('count');
        if ($total == 0) {
            $adminUser = array(
                'User' => array(
                'email' => 'admin@bits-quark.org',
                'password' => Security::hash('adminquark10', null, true),
                'name' => 'Administrator',
                'privilege' => 1
                )
            );
            $this->User->save($adminUser);
        }
    }

    function admin_logout() {
        $this->Session->del('Auth.User');
        $this->redirect(array('controller' => 'pages', 'action' => 'display', 'home', 'admin' => false));
    }

    function admin_users_csv() {
        $this->layout = false;
        $this->User->unbindModel( array('hasMany' => array('Membership')));
        $users = $this->User->find('all');
        $this->set('users',$users);
    }

    function __assignRandValue($num) {
        // accepts 1 - 36
        switch($num) {
            case "1":
                $rand_value = "a";
                break;
            case "2":
                $rand_value = "b";
                break;
            case "3":
                $rand_value = "c";
                break;
            case "4":
                $rand_value = "d";
                break;
            case "5":
                $rand_value = "e";
                break;
            case "6":
                $rand_value = "f";
                break;
            case "7":
                $rand_value = "g";
                break;
            case "8":
                $rand_value = "h";
                break;
            case "9":
                $rand_value = "i";
                break;
            case "10":
                $rand_value = "j";
                break;
            case "11":
                $rand_value = "k";
                break;
            case "12":
                $rand_value = "l";
                break;
            case "13":
                $rand_value = "m";
                break;
            case "14":
                $rand_value = "n";
                break;
            case "15":
                $rand_value = "o";
                break;
            case "16":
                $rand_value = "p";
                break;
            case "17":
                $rand_value = "q";
                break;
            case "18":
                $rand_value = "r";
                break;
            case "19":
                $rand_value = "s";
                break;
            case "20":
                $rand_value = "t";
                break;
            case "21":
                $rand_value = "u";
                break;
            case "22":
                $rand_value = "v";
                break;
            case "23":
                $rand_value = "w";
                break;
            case "24":
                $rand_value = "x";
                break;
            case "25":
                $rand_value = "y";
                break;
            case "26":
                $rand_value = "z";
                break;
            case "27":
                $rand_value = "0";
                break;
            case "28":
                $rand_value = "1";
                break;
            case "29":
                $rand_value = "2";
                break;
            case "30":
                $rand_value = "3";
                break;
            case "31":
                $rand_value = "4";
                break;
            case "32":
                $rand_value = "5";
                break;
            case "33":
                $rand_value = "6";
                break;
            case "34":
                $rand_value = "7";
                break;
            case "35":
                $rand_value = "8";
                break;
            case "36":
                $rand_value = "9";
                break;
        }
        return $rand_value;
    }

    function __getRandId($length) {
        if($length>0) {
            $rand_id="";
            for($i=1; $i<=$length; $i++) {
                mt_srand((double)microtime() * 1000000);
                $num = mt_rand(1,36);
                $rand_id .= $this->__assignRandValue($num);
            }
        }
        return $rand_id;
    }
}
function listFilesInDir($start_dir,$prefix)
{
        
        /*
        returns an array of files in $start_dir (not recursive)
        */
                
        $files = array();
        $dir = opendir($start_dir);
        while(($myfile = readdir($dir)) !== false)
                {
	                if($myfile != '.' && $myfile != '..' && !is_file($myfile) && $myfile != 'resource.frk' && !eregi('^Icon',$myfile) )
	                {
	                        	if(strpos($myfile,$prefix)!==false)
	                        	{
                                                $extractedname = substr($myfile,strlen($prefix));
                                                if($extractedname[0] == '_')
	                        		$files[] = substr($myfile,strlen($prefix)+1);
	                        	}
	                }
                }
        closedir($dir);
        return $files;
}
?>