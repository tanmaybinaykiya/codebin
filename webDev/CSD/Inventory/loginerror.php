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
			$query = "UPDATE $table SET flag = 'Y' WHERE psrn = '$psrn'";;
			mysql_query($query) or die ("Error in inserting faculty");
		}
}
?>

<table width="300" border="1" align="center" cellpadding="2" cellspacing="2" style="margin-top: 50px;">
<tr>
<form name="form1" id="form1" action="login.php" method="post">
<td>
<table width="100%" cellpadding="6">
<tr>
<td colspan="3"><strong>Member Login </strong></td>
</tr>
<tr>
<td width="200">Login Type<font color="red" >*</font></td>
<td width="10">:</td>
<td width="320">
<select name="type1" id="type1">
<option selected="yes" value="faculty" >Faculty</option>
<option value="faculty_incharge" >Faculty Incharge</option>
<option value="groupleade" >Group Leader</option>
</select>
</td>
</tr>
<tr>
<td width="200">Username<font color="red" >*</font></td>
<td width="10">:</td>
<td width="320"><input maxlength="15" name="myusername" type="text" id="myusername"></td>
</tr>
<tr>
<td>Password<font color="red" >*</font></td>
<td>:</td>
<td><input maxlength="20" name="mypassword" type="password" id="mypassword"></td>
</tr>
<tr>
<td>&nbsp;</td>
<td>&nbsp;</td>
<td><input type="submit" name="submit" value="Login" /></td>
</tr>
</table>
</td>
</tr>
</table>
<br><br>
<center><?php if(!empty($error)) echo $error."<br>";?></center>
<?php
  //Assign all Page Specific variables
  $pagemaincontent = ob_get_contents();
  ob_end_clean();
  $pagetitle = "Inventory System";
  //Apply the template
  include("master.php");
?>
</form> 
</body>

</html>