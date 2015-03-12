<?php
$host="localhost";
$username="root";
$password="";
$con = mysql_connect($host,$username,$password);

if (!$con)
  {
  die('Could not connect: ' . mysql_error());
  }
  
?>