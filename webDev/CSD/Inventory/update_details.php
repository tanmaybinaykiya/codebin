<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=iso-8859-1" />
<link REL="SHORTCUT ICON" HREF="css/favicon.ico">
<title>BITS, Pilani - K. K. Birla Goa Campus </title>
</head>
<body>
<div style="margin-left:40px;margin-top:10px;">	<a href="admin.php">Back</a></div>
<br /><br />
<div style="margin-left:15px;">
<?php
include_once 'connect.php';
error_reporting(0);
session_start();
if ($_SESSION['loggedin'] != TRUE && $_SESSION['isadmin'] != TRUE)
	header("Location: index.php");
$type = $_SESSION['type'];
echo $type;
/*Retrieving Values*/
$id = mysql_real_escape_string($_POST['id']);
$name = mysql_real_escape_string($_POST['name']);
$psrn = mysql_real_escape_string($_POST['psrn']);
$loginid = mysql_real_escape_string($_POST['loginid']);
echo "my psrn is : $loginid";
$department = mysql_real_escape_string($_POST['department']);

$location = mysql_real_escape_string($_POST['location']);
$computer = mysql_real_escape_string($_POST['computer']);
if($type==1)
{
	$ip_o=mysql_real_escape_string($data['IP_O']);
	$ip_r=mysql_real_escape_string($data['IP_R']);
}
if($type==2  || $type==3)
{
	$ip_phone=mysql_real_escape_string($data['ip_phone']);
	$id = mysql_real_escape_string($_POST['id']);
}
$cpe = mysql_real_escape_string($_POST['cpe']);
$ups = mysql_real_escape_string($_POST['ups']);
$headphone = mysql_real_escape_string($_POST['headphone']);
$webcam = mysql_real_escape_string($_POST['webcam']);
if($type==1)
{
	$mobile=mysql_real_escape_string($data['MOBILE']);
}
$laptop = mysql_real_escape_string($_POST['laptop']);
$printer = mysql_real_escape_string($_POST['printer']);
$others = mysql_real_escape_string($_POST['others']);

if (isset($_POST['flag']))
	$flag = 'Y';
else
	$flag = 'N';


mysql_select_db('inv_mgt_system') or die("cannot select database");
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
if($type == 1)
{
$query = "UPDATE $table SET
			NAME = '$name',
			DEPARTMENT = '$department',
			LOCATION = '$location',
			COMPUTER = '$computer',
			IP_O = '$ip_o',
			IP_R = '$ip_r',
			CPE = '$cpe',
			UPS = '$ups',
			HEADPHONE = '$headphone',
			WEBCAM = '$webcam',
			MOBILE = '$mobile',
			LAPTOP = '$laptop',
			PRINTER = '$printer',
			OTHERS = '$others',
			FLAG = '$flag'
			WHERE psrn = '$psrn'";
$result = mysql_query($query) or die("Query failed type1");
	echo 'Faculty Data Updated';
	/**
$to = "$loginid@bits-goa.ac.in";
 $subject = "Hi!";
 $body = "Hi,\n\nHow are you?";
 $headers = "From: omp@bits-goa.ac.in" . "\r\n" .
"CC: f2009629@bits-goa.ac.in";
*/
	
	$your_email = "omp@bits.goa.ac.in";
	$response="This is the body of the mail";
//require_once('include/phpmailer/class.phpmailer.php');
require_once('include/phpmailer/class.phpmailer.php');
$mail = new PHPMailer(true);
$mail->IsSMTP();
try {
	$mail->Host       = "ssl://10.10.10.113";
	$mail->SMTPAuth   = true;
	$mail->Port       = 465;
	$mail->Username   = "test";
	$mail->Password   = "passpass";
	$mail->Body = $response;
	
	
$mail->From="ccoffice@bits-goa.ac.in";
$mail->FromName="CC Office";
$mail->Sender="ccoffice@bits-goa.ac.in";
//$mail->AddReplyTo("replies@example.com", "Replies for my site");
echo $loginid."@bits-goa.ac.in";
$mail->AddAddress($loginid."@bits-goa.ac.in");
$mail->Subject = "Inventory Details";

$mail->IsHTML(true);
$mail->Body = "<p>Dear Sir <br> Your Invetory has been changed. Please verify that.</p><p>Cc Office</p>";
$mail->AltBody="This is text only alternative body.";
	
	
//$mail->AddAddress($your_email,"admin");
 //$mail->AddReplyTo('omp'.'@bits-goa.ac.in', 'Om Prakash');
//$mail->AddAddress($loginid."@bits-goa.ac.in",$name);
 } catch (phpmailerException $e) {
                    $error = $e->errorMessage();
                } catch (Exception $e) {
                    $error = $e->getMessage();
                }                
 if ($mail->Send()) 
 {
	 
   echo("<p>E-Mail successfully sent!</p>");
  } 
 else 
 {
   echo("<p>Message delivery failed...</p>");
  }
} 
else
{
$query = "UPDATE $table SET
			NAME = '$name',
			DEPARTMENT = '$department',
			LOCATION = '$location',
			COMPUTER = '$computer',
			IP_PHONE  = '$ip_phone',
			CPE = '$cpe',
			UPS = '$ups',
			HEADPHONE = '$headphone',
			WEBCAM = '$webcam',
			LAPTOP = '$laptop',
			PRINTER = '$printer',
			OTHERS = '$others',
			FLAG = '$flag'
			WHERE PSRN = '$psrn' AND id='$id'";
$result = mysql_query($query) or die("Query failed type2".mysql_error());
	if($result) echo 'FI Details Updated';
	$your_email = "omp@bits.goa.ac.in";
	$response="This is the body of the mail";
//require_once('include/phpmailer/class.phpmailer.php');
require_once('include/phpmailer/class.phpmailer.php');
$mail = new PHPMailer(true);
$mail->IsSMTP();
try {
	$mail->Host       = "ssl://10.10.10.113";
	$mail->SMTPAuth   = true;
	$mail->Port       = 465;
	$mail->Username   = "test";
	$mail->Password   = "passpass";
	$mail->Body = $response;
	
	
$mail->From="ccoffice@bits-goa.ac.in";
$mail->FromName="CC Office";
$mail->Sender="ccoffice@bits-goa.ac.in";
//$mail->AddReplyTo("replies@example.com", "Replies for my site");
echo $loginid."@bits-goa.ac.in";
$mail->AddAddress($loginid."@bits-goa.ac.in");
$mail->Subject = "Inventory Details";

$mail->IsHTML(true);
$mail->Body = "<p>Dear Sir <br> Your Invetory has been changed. Please verify that.</p><p>Cc Office</p>";
$mail->AltBody="This is text only alternative body.";
	
	
//$mail->AddAddress($your_email,"admin");
 //$mail->AddReplyTo('omp'.'@bits-goa.ac.in', 'Om Prakash');
//$mail->AddAddress($loginid."@bits-goa.ac.in",$name);
 } catch (phpmailerException $e) {
                    $error = $e->errorMessage();
                } catch (Exception $e) {
                    $error = $e->getMessage();
                }                
 if ($mail->Send()) 
 {
	 
   echo("<p>E-Mail successfully sent!</p>");
  } 
 else 
 {
   echo("<p>Message delivery failed...</p>");
  }
	
	if(!$result) echo "Failed <br /> $psrn<br />$table";

}
?>
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