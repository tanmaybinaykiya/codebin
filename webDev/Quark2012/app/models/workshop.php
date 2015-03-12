<?php
class Workshop extends AppModel {

	var $name = 'Workshop';
	var $validate = array(
		'name' => array('notempty'),
		'price' => array('numeric'),
		'route' => array('notempty')
	);
    var $hasMany = array(
        'WorkshopsUser' => array(
			'className' => 'WorkshopsUser',
			'dependent' => true
		)
	);
    
	function fetchByRoute($route) {
		return $this->find('first', array('conditions' => array('Workshop.route' => $route)));
	}
}
?>