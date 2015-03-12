<?php
class Category extends AppModel {

	var $name = 'Category';

	//The Associations below have been created with all possible keys, those that are not needed can be removed
	var $hasMany = array(
		'Event' => array(
			'className' => 'Event',
			'foreignKey' => 'category_id',
			'dependent' => false,
			'conditions' => '',
			'fields' => array('Event.name', 'Event.route'),
			'order' => 'Event.name ASC',
			'limit' => '',
			'offset' => '',
			'exclusive' => '',
			'finderQuery' => '',
			'counterQuery' => ''
		)
	);

        function fetchById($id = null) {
            if ($id != null) {
		return $this->find('first', array('conditions' => array('Category.id' => $id)));
            }
            return null;
	}

	function fetchByRoute($route) {
		$this->bindModel(array('hasMany' => array('Event' => array('fields' => ''))));
		return $this->find('first', array(
			'conditions' => array('Category.route' => $route),
			'recursive' => 1
		));
	}

	function fetchMenu() {
		return $this->find('all', array(
			'fields' => array('Category.name', 'Category.route'),
			'recursive' => 1
		));
	}

}
?>