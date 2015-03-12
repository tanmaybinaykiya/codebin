<?php
class Event extends AppModel {

	var $name = 'Event';

	//The Associations below have been created with all possible keys, those that are not needed can be removed
	var $belongsTo = array(
		'Category' => array(
			'className' => 'Category',
			'foreignKey' => 'category_id',
			'conditions' => '',
			'fields' => 'Category.name',
			'order' => ''
		)
	);
        var $hasMany = array(
            'Team' => array(
        	'className' => 'Team',
                'foreignKey' => 'event_id',
        	'dependent' => false
            )
        );

	function fetchByRoute($route) {
		return $this->find('first', array('conditions' => array('Event.route' => $route)));
	}

}
?>