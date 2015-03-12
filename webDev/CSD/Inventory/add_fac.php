<html>
<head>
<title> Add Faculty </title>
<?php error_reporting(0);
session_start();
?>
</head>
<body>
<div style="margin-left:40px;margin-top:10px;">	<a href="admin.php">Back</a></div>
<?php
$name = mysql_real_escape_string($_POST['name']);
$psrn = mysql_real_escape_string($_POST['psrn']);
$loginid = mysql_real_escape_string($_POST['loginid']);
$category = mysql_real_escape_string($_POST['category']);
$department = mysql_real_escape_string($_POST['department']);
$location = mysql_real_escape_string($_POST['location']);
$computer = mysql_real_escape_string($_POST['computer']);
$ip_o = mysql_real_escape_string($_POST['ip_o']);
$ip_r = mysql_real_escape_string($_POST['ip_r']);
$cpe = mysql_real_escape_string($_POST['cpe']);
$ups = mysql_real_escape_string($_POST['ups']);
$headphone = mysql_real_escape_string($_POST['headphone']);
$webcam = mysql_real_escape_string($_POST['webcam']);
$mobile = mysql_real_escape_string($_POST['mobile']);
$laptop = mysql_real_escape_string($_POST['laptop']);
$printer = mysql_real_escape_string($_POST['printer']);
$others = mysql_real_escape_string($_POST['others']);
$flag = mysql_real_escape_string($_POST['flag']);

include_once 'connect.php';
$query = "INSERT INTO faculty(PSRN,LOGINID,NAME,DEPARTMENT,CATEGORY,LOCATION,COMPUTER,IP_O,IP_R,CPE,UPS,HEADPHONE,WEBCAM,MOBILE,LAPTOP,PRINTER,OTHERS,FLAG) VALUES ('$psrn','$loginid','$name','$department','$category','$location','$computer','$ip_o','$ip_r','$cpe','$ups','$headphone','$webcam','$mobile','$laptop','$printer','$others','$flag')";

$success = mysql_query($query) or die("<b>QUERY FAILED!! </b><br />".mysql_error());

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
$mail->FromName="Computer Center";
$mail->Sender="ccoffice@bits-goa.ac.in";
//$mail->AddReplyTo("replies@example.com", "Replies for my site");
echo $loginid."@bits-goa.ac.in";
$mail->AddAddress($loginid."@bits-goa.ac.in");
$mail->Subject = "Test 1";

$mail->IsHTML(true);
$mail->Body = "<h1>Test 1 of PHPMailer html</h1><p>This is a test</p>";
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
	$success1 = "true";
   echo("<p>E-Mail successfully sent!</p>");
  } 
 else 
 {
	$success1 = "false";
   echo("<p>Message delivery failed...</p>");
  }


if($success && $success1 =="true"){
echo "Faculty Details Successfully Added";
}

$pagemaincontent = ob_get_contents();
  ob_end_clean();
  //Apply the template
  include("master.php");

?>
	


</body>
</head>