<?php
class GravitonFeedback extends AppModel {

	var $name = 'GravitonFeedback';
	var $validate = array(
		'name' => array('notempty'),
		'email' => array('email'),
		'phone' => array('numeric'),
		'college' => array('notempty'),
		'no_of_kits' => array('numeric')
	);

	//The Associations below have been created with all possible keys, those that are not needed can be removed
	var $belongsTo = array(
		'GravitonCentre' => array(
			'className' => 'GravitonCentre',
			'foreignKey' => 'graviton_centre_id',
			'conditions' => '',
			'fields' => '',
			'order' => ''
		)
	);

}
?>