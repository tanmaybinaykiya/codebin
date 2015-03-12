<?php
class AccommodationsController extends AppController {

	var $name = 'Accommodations';
	var $helpers = array('Html', 'Form', 'Parser');
        var $uses = array( 'Accommodation', 'User', 'Event', 'Team', 'Membership', 'Workshop', 'WorkshopsUser');
        
        function admin_export_csv() {
            $this->layout = false;
            $this->Accommodation->recursive = 1;
            $accommodations = $this->Accommodation->find('all');
            $i = 0;

            foreach($accommodations as $accommodation)
            {

                $events = array();
                $workshopsarr = array();
                $quark_ids = json_decode($accommodation['Accommodation']['quark_ids']);

                foreach($quark_ids as $quark_id)
                {
                    array_push($events,$quark_id);
                    array_push($workshopsarr,$quark_id);
                    $user = $this->User->find('first',array('conditions' => array('User.id_no' => substr($quark_id,3))));

                    $members = $this->Membership->find('all',array('conditions' => array('Membership.user_id' => $user['User']['id'])));
                    foreach($members as $member)
                    {
                        $team = $this->Team->find('first',array('conditions' => array('Team.id'=>$member['Membership']['team_id'])));

                        $event = $this->Event->find('first',array('conditions' => array('Event.id'=>$team['Team']['event_id'])));

                        array_push($events,$event['Event']['name']);
                    }
                    $workshops = $this->WorkshopsUser->find('all', array('conditions' => array('WorkshopsUser.user_id' => $user['User']['id'])));
                    foreach($workshops as $workshop)
                    {
                        $theworkshop = $this->Workshop->find('first', array('conditions' => array('Workshop.id' => $workshop['WorkshopsUser']['workshop_id'])));
                        array_push($workshopsarr, $theworkshop['Workshop']['name']);
                    }
                }
                $eventcoded = json_encode($events);
                $workshopscoded = json_encode($workshopsarr);
                $accommodations[$i]['Accommodation']['events'] = $eventcoded;
                $accommodations[$i]['Accommodation']['workshops'] = $workshopscoded;

                $i++;
            }
           
            
            $this->set(compact('accommodations'));
        }

	function admin_index() {
		$this->Accommodation->recursive = 1;
             
		$this->set('accommodations', $this->paginate());
              
	}

	function admin_view($id = null) {
                $this->Accommodation->recursive = 1;
		if (!$id) {
			$this->Session->setFlash(__('Invalid Accommodation.', true));
			$this->redirect(array('action'=>'index'));
		}
		$this->set('accommodation', $this->Accommodation->read(null, $id));
               
	}

	function admin_add() {
		if (!empty($this->data)) {
			$this->Accommodation->create();
			if ($this->Accommodation->save($this->data)) {
				$this->Session->setFlash(__('The Accommodation has been saved', true));
				$this->redirect(array('action'=>'index'));
			} else {
				$this->Session->setFlash(__('The Accommodation could not be saved. Please, try again.', true));
			}
		}
		$users = $this->Accommodation->User->find('list');
		$this->set(compact('users'));
	}

	function admin_edit($id = null) {
		if (!$id && empty($this->data)) {
			$this->Session->setFlash(__('Invalid Accommodation', true));
			$this->redirect(array('action'=>'index'));
		}
		if (!empty($this->data)) {
			if ($this->Accommodation->save($this->data)) {
				$this->Session->setFlash(__('The Accommodation has been saved', true));
				$this->redirect(array('action'=>'index'));
			} else {
				$this->Session->setFlash(__('The Accommodation could not be saved. Please, try again.', true));
			}
		}
		if (empty($this->data)) {
			$this->data = $this->Accommodation->read(null, $id);
		}
		$users = $this->Accommodation->User->find('list');
		$this->set(compact('users'));
	}

	function admin_delete($id = null) {
		if (!$id) {
			$this->Session->setFlash(__('Invalid id for Accommodation', true));
			$this->redirect(array('action'=>'index'));
		}
		if ($this->Accommodation->del($id)) {
			$this->Session->setFlash(__('Accommodation deleted', true));
			$this->redirect(array('action'=>'index'));
		}
	}
        

}

?>