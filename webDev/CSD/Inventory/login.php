<?php 
@session_start();
@$usernm=$_POST["myusername"];
@$pwd=$_POST["mypassword"];
if (@$usernm == NULL){
	header("Location: index.php");
}
	include_once 'connect.php';
	
	$query = "SELECT * FROM accounts WHERE loginid='$usernm' AND password='$pwd'";
	$result = mysql_query($query) or die("Query failed!");
	
	
	while($row=mysql_fetch_array($result))
	{
	$sa=$row['usertype'];
	}
	if($sa == "Super Admin")
{
	$_SESSION['isadmin'] = TRUE;
	$_SESSION['loggedin'] = TRUE;
		header("Location: admin.php");
}
else
{
//$str=fopen("http://10.1.1.82:800/auth.php?u=$usernm&p=$pwd","r");

$line=trim(fgets($str));

//$i=1;
if($line=="true")
//if($i==1)
{

	//$pwd = md5($pwd);

		$_SESSION['isadmin'] = FALSE;	
		$_SESSION['table'] = $_POST["type1"];
		$_SESSION['usernm'] = $usernm;
		$_SESSION['loggedin'] = TRUE;
		header("Location: /Inventory/home.php");
}			
else
{  
?> 
<html><center> 
<?php echo("</br><b><font color='red'>Incorect Username or Password</font></b>");
include("index.php");	
} 
}
?> 
</center></html>