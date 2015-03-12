<?php
$host="bits.fatcowmysql.com";
$user_name="waves";
$pass_word="waves2011";
$webroot="http://www.bits-waves.org";
/*$host = "localhost";
$user_name = "root";
$pass_word = "12345";*/
$db = "waves";
mysql_connect($host, $user_name, $pass_word);
mysql_select_db($db);
?>
