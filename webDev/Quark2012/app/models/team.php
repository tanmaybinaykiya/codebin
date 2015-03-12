<?php
class Team extends AppModel {
	var $belongsTo = 'Event';
	var $hasMany = array(
		'Membership' => array(
			'className' => 'Membership',
			'foreignKey' => 'team_id',
			'dependent' => true
		),
		'Invite' => array(
			'className' => 'Invite',
			'foreignKey' => 'team_id',
			'dependent' => true
		)
	);

	function fetchCreatorId($id = null) {
		if ($id != null) {
			return $this->Membership->field('user_id', array('Membership.user_role' => 'creator', 'Membership.team_id' => $id));
		}
		return null;
	}

	function memberCount($id = null) {
		if ($id != null) {
			return $this->Membership->find('count', array('conditions' => array('Membership.team_id' => $id)));
		}
		return 0; // Team does not exist
	}
}