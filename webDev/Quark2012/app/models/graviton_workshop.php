<?php
class GravitonWorkshop extends AppModel {

	var $name = 'GravitonWorkshop';
	var $validate = array(
		'name' => array('notempty')
	);

	//The Associations below have been created with all possible keys, those that are not needed can be removed
	var $hasMany = array(
		'GravitonCentre' => array(
			'className' => 'GravitonCentre',
			'foreignKey' => 'graviton_workshop_id',
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