<html>
<head>
<title>
<?php 
@session_start();
echo $pagetitle; 
?>
</title>
<link rel="stylesheet" href="style.css" type="text/css" />
<script type="text/javascript" src="jquery-1.5.js"></script>
<script type="text/javascript">
$(function(){
	var height = $(window).height();
	var req = 0.68 * height;
	var mainH = $("#main").height();
	//alert(mainH);
	//alert(req);
	if(mainH<req){
		//$("#main").height(req);
	}
});

</script>
</head>
<body>
<div id="header">
	<img src="images/bits.gif" alt="BITS Logo" height="100px" width="110px" />
	<h1>CC - Inventory Management System</h1>
</div>
<div id="topbar">
<ul>
<li><a href="contactus.php">Contact Us</a></li>
<?php if(!isset($_SESSION['loggedin'])): ?>
	<li><a href="index.php">Login</a></li>
<?php endif; ?>
<?php if(isset($_SESSION['loggedin'])): ?>
	<li><a href="logout.php">Logout</a></li>
<?php endif; ?>
</ul>
</div>
<?php 
if ($_SESSION['loggedin'] == TRUE && $_SESSION['isadmin'] != TRUE){
$user = <<<EOL
<div id="userDetails">
<b>Welcome</b> : $name &nbsp;&nbsp;&nbsp;&nbsp; <b>Department :</b> $department &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; <b>PSRN :</b> $psrn
</div><br />
EOL;
echo $user;
}
?>
<div id="main">
<?php
echo $pagemaincontent; 
?>
</div>
<div id="footer">
	&copy; Copyright 2010 CSD, BITS, Pilani K. K. Birla Goa Campus
</div>