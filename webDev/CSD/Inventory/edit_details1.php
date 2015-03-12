<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=iso-8859-1" />
<link REL="SHORTCUT ICON" HREF="css/favicon.ico">
<title>BITS, Pilani - K. K. Birla Goa Campus </title>
</head>
<body>
<div style="margin-left:40px;margin-top:10px;">	<a href="admin.php">Back</a></div>
<?php
error_reporting(0);
session_start();
$selector = "none";
if ($_SESSION['loggedin'] != TRUE && $_SESSION['isadmin'] != TRUE)
	header("Location: index.php");
$type = $_SESSION['type'];
$psrn = $_POST['psrn'];
$location=$_POST['loc'];

$t = $_SESSION["count"];
$i=1;
while($i<=$t){
	if($_POST['id'.$i] != "") $selector = $_POST['id'.$i];
	$i++;
}

//echo "<b>$selector</b>";

include_once 'connect.php';

if ($type == 1)
{
	$table = 'faculty';
}
else if ($type == 2)
{
	$table = 'faculty_incharge';
}
else if ($type == 3)
{
	$table = 'groupleader';
}
if($selector == "none"){
$query = "SELECT * FROM $table WHERE psrn = '$psrn' AND LOCATION = '$location' ORDER BY id ASC";
$result = mysql_query($query) or die("Query failed!");
}
if($selector!="none"){
	$query = "SELECT * FROM $table WHERE psrn = '$psrn' AND LOCATION = '$location' AND id='$selector' ORDER BY id ASC";
	$result = mysql_query($query) or die("Query failed!");
}
while($data=mysql_fetch_array($result))
	{
		$name=$data['NAME'];
		$psrn=$data['PSRN'];
		$loginid=$data['LOGINID'];
		$department=$data['DEPARTMENT'];
		$computer=$data['COMPUTER'];
		if($type==1)
		{
			$ip_o=$data['IP_O'];
			$ip_r=$data['IP_R'];
		}
		if($type==2 || $type==3)
		{
			$ip_phone=$data['IP_PHONE'];
			$id = $data['id'];
		}
		$cpe=$data['CPE'];
		$ups =$data['UPS'];
		$headphone=$data['HEADPHONE'];
		$webcam=$data['WEBCAM'];
		if($type==1)
		{
			$mobile=$data['MOBILE'];
		}
		$laptop=$data['LAPTOP'];
		$printer=$data['PRINTER'];
		$others=$data['OTHERS'];
		$flag=$data['FLAG'];
	}
?>
<h3 align="center">For PSRN: <?php echo $psrn; ?></h3>
<form action="update_details.php" method="post">
<table align="center">
<tr>
<td>Name<td>
<td><input type="text" name="name" value="<?php echo $name; ?>" /></td>
</tr>
<tr>
<td><input type="hidden" name="psrn" value="<?php echo $psrn; ?>" /></td>
</tr>
<tr>
<td><input type="hidden" name="id" value="<?php echo $id; ?>" /></td>
</tr>
<tr>
<td><input type="hidden" name="loginid" value="<?php echo $loginid; ?>" /></td>
</tr>
<tr>
<td>Department<td>
<td><input type="text" name="department" value="<?php echo $department; ?>" /></td>
</tr>
<tr>
<td>Location<td>
<td><input type="text" name="location" value="<?php echo $location; ?>" />
 </td>
</tr>
<tr>
<td>Computer<td>
<td><input type="text" name="computer" value="<?php echo $computer; ?>" /></td>
</tr>
<?php
if($type==1)
{
?>
	<tr>
	<td>IP O<td>
	<td><input type="text" name="ip_o" value="<?php echo $ip_o; ?>" /></td>
	</tr>
	<tr>
	<td>IP R<td>
	<td><input type="text" name="ip_r" value="<?php echo $ip_r; ?>" /></td>
	</tr>
<?php
}
?>
<?php
if($type==2 || $type==3)
{
?>
	<tr>
	<td>IP PHONE<td>
	<td><input type="text" name="ip_o" value="<?php echo $ip_phone; ?>" /></td>
	</tr>
<?php
}
?>
<tr>
<td>CPE<td>
<td><input type="text" name="cpe" value="<?php echo $cpe; ?>" /></td>
</tr>
<tr>
<td>UPS<td>
<td><input type="text" name="ups" value="<?php echo $ups; ?>" /></td>
</tr>
<tr>
<td>Headphone<td>
<td><input type="text" name="headphone" value="<?php echo $headphone; ?>" /></td>
</tr>
<tr>
<td>Webcam<td>
<td><input type="text" name="webcam" value="<?php echo $webcam; ?>" /></td>
</tr>
<?php
if($type==1)
{
?>
<tr>
<td>Mobile<td>
<td><input type="text" name="mobile" value="<?php echo $mobile; ?>" /></td>
</tr>
<?php
}
?>
<tr>
<td>Laptop<td>
<td><input type="text" name="laptop" value="<?php echo $laptop; ?>" /></td>
</tr>
<tr>
<td>Printer<td>
<td><input type="text" name="printer" value="<?php echo $printer; ?>" /></td>
</tr>
<tr>
<td>Others<td>
<td><input type="text" name="others" value="<?php echo $others; ?>" /></td>
</tr>
<tr>
<td>Flag<td>
<td>
<?php
if ($flag == 'Y')
	echo '<input type="checkbox" name="flag" checked="checked" value="Y" />';
else
	echo '<input type="checkbox" name="flag" />';
?>
</td>
</tr>
</table>
<br>
<div align="center">
<input type="submit" value="Update Details" />
</div>
</form>
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