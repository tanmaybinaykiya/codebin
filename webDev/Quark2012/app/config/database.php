<?php
class DATABASE_CONFIG {

	var $default = array(
		
	);

	// Localhost
	var $test = array(
		'driver' => 'mysql',
		'persistent' => false,
		'host' => 'localhost',
		'login' => 'root',
		'password' => '',
		'database' => 'quark2011',
		'prefix' => '',
	);

	// Live Server
	var $live = array(
		'driver' => 'mysql',
		'persistent' => false,
		'host' => 'bits.fatcow.com',
		'login' => 'quark2012',
		'password' => '',
		'database' => 'quark2012',
		'prefix' => '',
	);

	function __construct() {
		$this->default = $this->test;
	}
}
?>