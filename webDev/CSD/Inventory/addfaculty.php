<html>
<head>
<title>Add Faculty </title>
<?php  
error_reporting(0);
session_start(); ?>
</head>
<body>
<div style="margin-left:40px;margin-top:10px;">	<a href="admin.php">Back</a></div>
<br />
<form action="add_fac.php" method="post">
<table align="center">
<tr>
<td>Name<td>
<td><input type="text" name="name" value="" /></td>
</tr>
<tr>
<td>PSRN<td>
<td><input type="text" name="psrn" value="" /></td>
</tr>
<tr>
<td>LOGIN ID<td>
<td><input type="text" name="loginid" value="" /></td>
</tr>
<tr>
<td>CATEGORY<td>
<td><input type="text" name="category" value="" /></td>
</tr>
<tr>
<td>Department<td>
<td><input type="text" name="department" value="" /></td>
</tr>
<tr>
<td>Location<td>
<td><input type="text" name="location" value="" />
 </td>
</tr>
<tr>
<td>Computer<td>
<td><input type="text" name="computer" value="" /></td>
</tr>
	<tr>
	<td>IP O<td>
	<td><input type="text" name="ip_o" value="" /></td>
	</tr>
	<tr>
	<td>IP R<td>
	<td><input type="text" name="ip_r" value="" /></td>
	</tr>
<tr>
<td>CPE<td>
<td><input type="text" name="cpe" value="" /></td>
</tr>
<tr>
<td>UPS<td>
<td><input type="text" name="ups" value="" /></td>
</tr>
<tr>
<td>Headphone<td>
<td><input type="text" name="headphone" value="" /></td>
</tr>
<tr>
<td>Webcam<td>
<td><input type="text" name="webcam" value="" /></td>
</tr>
<tr>
<td>Mobile<td>
<td><input type="text" name="mobile" value="" /></td>
</tr>

<tr>
<td>Laptop<td>
<td><input type="text" name="laptop" value="" /></td>
</tr>
<tr>
<td>Printer<td>
<td><input type="text" name="printer" value="" /></td>
</tr>
<tr>
<td>Others<td>
<td><input type="text" name="others" value="" /></td>
</tr>
<tr>
<td>Flag<td>
<td>
<input type="checkbox" name="flag" value="Y" />
</td>
</tr>
</table>
<div align="center">
<input type="submit" value="Add Details" />
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