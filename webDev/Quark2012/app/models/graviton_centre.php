<?php
class GravitonCentre extends AppModel {

	var $name = 'GravitonCentre';

	//The Associations below have been created with all possible keys, those that are not needed can be removed
	var $belongsTo = array(
		'GravitonWorkshop'
	);
	var $hasMany = array(
		'GravitonTeam' => array(
			'className' => 'GravitonTeam',
			'foreignKey' => 'graviton_centre_id',
			'dependent' => false,
			'conditions' => '',
			'fields' => '',
			'order' => '',
			'limit' => '',
			'offset' => '',
			'exclusive' => '',
			'finderQuery' => '',
			'counterQuery' => ''
		)
	);

}
?>