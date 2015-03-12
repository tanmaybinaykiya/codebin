<?php
class Page extends AppModel {

	var $name = 'Page';
	var $validate = array(
		'name' => array('notempty'),
		'route' => array('notempty')
	);

	function fetchByRoute($route = 'home') {
		return $this->find('first', array('conditions' => array('Page.route' => $route)));
	}

}
?>