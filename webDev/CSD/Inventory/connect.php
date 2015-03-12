<?php 
$host = 'localhost';
$user='localhost';
$password='iamtanmay';
$connection = mysql_connect($host, $user, $password) or die("error connecting");
mysql_select_db('inv_mgt') or die("cannot select database");

?>