<?php //session_start();
$usernm=$_POST["myusername"];
$pwd=$_POST["mypassword"];
//if ($usernm == NULL)
//	header("Location: http://localhost/Inventory/");

	$host = 'localhost';
	$user='root';
	$password='';
	$connection = mysql_connect($host, $user, $password) or die("error connecting");
	mysql_select_db('inv_mgt_system') or die("cannot select database");
	//$pwd = md5($pwd);
	//$pwd = md5($pwd);
	$query = "SELECT * FROM accounts WHERE loginid='$usernm' AND password='$pwd'";
	$result = mysql_query($query) or die("Query failed!");
	
	if(mysql_num_rows($result)>0)
	{
		echo ("ac");
	}
		else {
			echo("er");
		}
			
?> 
<html><center> 
<?php
echo("</br><b><font color='red'>Incorect Username or Password</font></b>");
include("index1.php");	
?> 
</center></html>