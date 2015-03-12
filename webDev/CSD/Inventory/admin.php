<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=iso-8859-1" />
<link REL="SHORTCUT ICON" HREF="css/favicon.ico">
<title>BITS, Pilani - K. K. Birla Goa Campus </title>
</head>
<body>
<?php
session_start();
if ($_SESSION['loggedin'] != TRUE && $_SESSION['isadmin'] != TRUE)
	header("Location: /Inventory/");
?>
<br>
<div>
<p align="center">
<ul>
<li> <a href="addfaculty.php"> Add Faculty </a></li><br />
<li><a href="search.php?type=1">Edit Faculty</a></li><br>
<li><a href="search.php?type=2">Edit Faculty In Charge</a></li><br>
<li><a href="search.php?type=3">Edit HOD</a></li>
</ul>
</p>
</div>
<?php
  //Assign all Page Specific variables
  $pagemaincontent = ob_get_contents();
  ob_end_clean();
  $pagetitle = "Inventory System";
  //Apply the template
  include("master.php");
?>
</body>
</html>