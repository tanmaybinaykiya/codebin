<?php
class College extends AppModel {

	var $name = 'College';
	var $validate = array(
		'college' => array('notempty')
	);
}
?>