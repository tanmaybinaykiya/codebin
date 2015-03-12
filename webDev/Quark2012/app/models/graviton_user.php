<?php
class GravitonUser extends AppModel {

	var $name = 'GravitonUser';
	var $validate = array(
		'name' => array('notempty'),
		'email' => array(
			'rule' => 'email',
			'message' => 'Please enter a valid e-mail address',
			'allowEmpty' => false,
			'required' => true
		),
		'mobile' => array(
			'rule' => array('custom','/^9[0-9]*$/'),
			'message' => 'Please enter a valid mobile number',
			'allowEmpty' => false,
			'required' => true
		),
		'college' => array('notempty'),
		'college_year' => array(
			'rule' => array('inlist', array('1st', '2nd', '3rd', '4th', '5th')),
			'message' => 'Invalid value',
			'allowEmpty' => false,
			'required' => true
		),
		'city' => array('notempty'),
		'state' => array('notempty')
	);

	//The Associations below have been created with all possible keys, those that are not needed can be removed
	var $belongsTo = array(
		'GravitonTeam' => array(
			'className' => 'GravitonTeam',
			'foreignKey' => 'graviton_team_id',
			'conditions' => '',
			'fields' => '',
			'order' => ''
		)
	);

}
?>