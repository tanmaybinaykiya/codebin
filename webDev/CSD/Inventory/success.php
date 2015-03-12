<?php
session_start();
$host = 'localhost';
$user='root';
$password='';
$connection = mysql_connect($host, $user, $password) or die("error connecting");
mysql_select_db('inv_mgt_system') or die("cannot select database");
$flag = $_POST["flag"];
$table = $_SESSION['table'];
?>
<?php
if(isset($_POST["submit1"]))
{
	$psrn = $_SESSION['psrn'];
	if (isset($_POST['flag']))
		{			
			$query = "UPDATE $table SET flag = 1 WHERE psrn = '$psrn'";;
			mysql_query($query) or die ("Error in inserting faculty");
		}
}
?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=iso-8859-1" />
<link REL="SHORTCUT ICON" HREF="css/favicon.ico">
<title>BITS, Pilani - K. K. Birla Goa Campus </title>
</head>
<body>
<h1 style="color:#000099"><center>Data entered successfully.</center></h1>

</head>
<?php
  //Assign all Page Specific variables
  $pagemaincontent = ob_get_contents();
  ob_end_clean();
  $pagetitle = "Inventory System";
  //Apply the template
  include("master.php");
?>
</html>