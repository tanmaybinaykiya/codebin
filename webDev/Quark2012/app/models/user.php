<?php
class User extends AppModel {

	var $name = 'User';
        var $hasMany = array(
		'Membership' => array(
			'className' => 'Membership',
			'dependent' => true
		)
	);
	var $validate = array(
		'email' => array(
			'notEmpty' => array(
				'rule' => 'notEmpty',
				'message' => 'Please enter an e-mail address.',
				'required' => true
			),
			'email' => array(
				'rule' => 'email',
				'message' => 'Please enter a valid e-mail address.'
			),
			'isUnique' => array(
				'rule' => 'isUnique',
				'message' => 'This e-mail address has already been registered.'
			)
		),
		'secretword' => array(
			'rule' => array('minLength', 6),
			'message' => 'Password must be atleast 6 characters long.'
		),
		'name' => array(
			'notEmpty' => array(
				'rule' => 'notEmpty',
				'message' => 'Please enter your name.'
			)
		),
		'mobile' => array(
			'notEmpty' => array(
				'rule' => 'notEmpty',
				'message' => 'Please enter your mobile number.'
			),
			'numeric' => array(
				'rule' => 'numeric',
				'message' => 'Please enter only digits.'
			)
		)
	);
	
	function hasRegisteredFor($eventId = null) {
            if ($eventId != null) {
                    // Find list of teams user has registered for
                    $teamIds = $this->Membership->find('list', array(
                            'fields' => 'team_id',
                            'conditions' => array(
                                    'Membership.user_id' => $this->id
                            )
                    ));
                    // Returns true if user belongs to a team that registered for this event
                    return $this->Membership->Team->hasAny(array(
                            'Team.id' => $teamIds,
                            'Team.event_id' => $eventId
                    ));
            }
            return false;
        }

        function hasInvite($teamId = null) {
            if ($teamId != null) {
                    // TODO: Shorten this association?
                    return $this->Membership->Team->Invite->hasAny(array(
                            'team_id' => $teamId,
                            'email' => $this->field('email')
                    ));
            }
            return false;
        }
}
?>