<?php
class Accommodation extends AppModel {

	var $name = 'Accommodation';
	var $validate = array(
		'user_id' => array('notempty'),
		'contact_no' => array('notempty'),
                'numboys' => array('notempty'),
                'numgirls' => array('notempty')
            );

	//The Associations below have been created with all possible keys, those that are not needed can be removed
	var $belongsTo = array(
		'User' => array(
			'className' => 'User',
			'foreignKey' => 'user_id',
			'conditions' => '',
			'fields' => '',
			'order' => ''
		)
	);

}
?>