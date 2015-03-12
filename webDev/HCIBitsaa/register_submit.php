<html>
<head>
<title>Registration Complete!</title>
</head>
<body><p>
<?php

include('common.php');
include('connection.php');
include("checkEmail.php");
session_start();

function generatekey() {
    $result = 1;
    while ($result > 0) {
        $string = str_shuffle('dfghjklzxcvbnm');
        $sql = "SELECT id from temp_users where verify_key='" . $string . "'";
        $query = mysql_query($sql);
        $result = mysql_num_rows($query);
    }
    return $string;
}

$first = checkinput($_POST['first']);
$last = checkinput($_POST['last']);
$dcnick = checkinput($_POST['dcnick']);
$aka = checkinput($_POST['aka']);
$email = checkinput($_POST['email']);
$phone = checkinput($_POST['phone']);
$idno = checkinput($_POST['id']);
$yoj = checkinput($_POST['yoj']);
//$mobile = checkinput($_POST['mobile']);
$mobile=9552435405;
$branch = checkinput($_POST['branch']);
$campus = checkinput($_POST['campus']);
$htwit = checkinput($_POST['htwit']);
$hblog = checkinput($_POST['hblog']);
$hgpl = checkinput($_POST['hgpl']);
$hfb = checkinput($_POST['hfb']);
$hlink = checkinput($_POST['hlink']);
$password = md5($_POST['password']);
$confirm_password = md5($_POST['confirm_password']);
//$keycode = generatekey();
$imkey=generatekey();
if (checkblank($first) || checkblank($last) ||checkblank($yoj) ||($password == "d41d8cd98f00b204e9800998ecf8427e") || ($confirm_password == "d41d8cd98f00b204e9800998ecf8427e")) {
    echo "All fields are required.";
    $_SESSION['rerror']="All fields are required.";
    header( 'Location: register.php' ) ;
    exit();

}

if ($password != $confirm_password) {
    echo "The password fields don't match.";
    $_SESSION['rerror']="The password fields don't match.";
    header( 'Location: register.php' ) ;
    exit();    
}


if (checkEmail($email) == 0) {
    echo "You'll need to use a valid e-mail address.";
    $_SESSION['rerror']="You'll need to use a valid e-mail address.";
    header( 'Location: register.php' ) ;
    exit();
}

if (!isValidEmail($email)) {
    echo "You'll need to use a valid e-mail address.";
    $_SESSION['rerror']="You'll need to use a valid e-mail address.";
    header( 'Location: register.php' ) ;
    exit();
}
if (!is_numeric($phone)) {
    echo "Your mobile number seems to be invalid.";
    $_SESSION['rerror']="Your phone number seems to be invalid.";
    header( 'Location: register.php' ) ;
    exit();
}
if ($mobile < 6000000000 || $mobile > 9999999999) {
    echo "Your mobile number seems to be invalid.";
    exit();
}

if (($_FILES["file"]["type"] == "image/jpeg") && ($_FILES["file"]["size"] < 200000))
  {
  if ($_FILES["file"]["error"] > 0)
    {
    echo "Return Code: " . $_FILES["file"]["error"] . "<br />";
    }
  else
    {
    echo "Upload: " . $_FILES["file"]["name"] . "<br />";
    echo "Type: " . $_FILES["file"]["type"] . "<br />";
    echo "Size: " . ($_FILES["file"]["size"] / 1024) . " Kb<br />";
    echo "Temp file: " . $_FILES["file"]["tmp_name"] . "<br />";
    echo "p file: " . $_FILES["file"]["error"] . "<br />";

      $path="img/users/" . $imkey .".jpg";
      if(is_dir("img/users") && is_writable("img/users"))
        {
      if(move_uploaded_file($_FILES["file"]["tmp_name"], $path)){
      echo "Stored in: ".$path;
            }
        }
    }
  }
else
  {
  echo "Invalid file";
  }
/*
//send mail using php mailer
require('phpmailer/class.phpmailer.php');
$mail = new PHPMailer();

$mail->Mailer = "smtp";
$mail->IsSMTP(); // send via SMTP

$mail->Host = "ssl://smtp.gmail.com";
$mail->Port = 465;                    // set the SMTP port


$mail->SMTPAuth = true; // turn on SMTP authentication
$mail->SMTPDebug = 0;                     // enables SMTP debug information (for testing)

$mail->Username = "               "; // SMTP username
$mail->Password = "     "; // SMTP password
//$webmaster_email = "bhaavan@bitsaa.org"; //Reply to this email ID
//$mail->From = $webmaster_email;
$mail->SetFrom('', '');
$mail->FromName = "";
$mail->AddAddress($email, $name);
//$mail->AddReplyTo($webmaster_email,"");

$mail->WordWrap = 50; // set word wrap

$mail->IsHTML(true); // send as HTML
$mail->Subject = "BITSAA Registration";

$mail->Body = "Hi " . $name . ",<br/>
				We've almost completed your registration!<br/>
				Click on the link below to confirm your registration.<br/>
				<a href=\"" . $webroot . "/confirm.php?id=" . $keycode . "\">Confirm Registration</a><br />
				
				--<br/>
				<br/>
				BITSAA"; //HTML Body

$mail->AltBody = "Hi,
				<br/>
				We've almost completed your registration!
				Click on the link below to confirm your registration.
				\"" . $webroot . "/confirm.php?id=" . $keycode . "'<br />
				<br/>
				--<br/>
				Thanks,				
				BITSAA"; //Text Body

if (!$mail->Send()) {
    echo "There was an error dispatching the confirmation e-mail."; //. $mail->ErrorInfo;
    $sent = false;
} else {
    echo "We've dispatched a verification key to your mailbox.";
    $sent = true;
}
*/
//if ($sent) {
//    $sql = "INSERT INTO temp_users (first,last,dcnick,aka,email,idno,yoj,password,branch,campus,verify_key) VALUES ('$first','$last','$dcnick','$aka','$email','$idno','$yoj','$password','$branch','$campus','$keycode')";
    $sql = "INSERT INTO users (first,last,dcnick,aka,email,idno,yoj,password,branch,campus,phone,impath,hfb,htwit,hblog,hlink,hgpl) VALUES ('$first','$last','$dcnick','$aka','$email','$idno','$yoj','$password','$branch','$campus','$phone','$path','$hfb','$htwit','$hblog','$hlink','$hgpl')";
    $res=mysql_query($sql);
    echo $sql;
    echo $res;
    header( 'Location: index.php' ) ;
//}
?></p>
</body>
</html>
