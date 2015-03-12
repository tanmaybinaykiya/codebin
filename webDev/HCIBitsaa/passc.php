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
$password = md5($_POST['pass1']);
$confirm_password = md5($_POST['pass2']);
if (($password == "d41d8cd98f00b204e9800998ecf8427e") || ($confirm_password == "d41d8cd98f00b204e9800998ecf8427e")) {
    echo "All fields are required.";
    $_SESSION['error']="All fields are required.";
    header( 'Location: settings.php' ) ;
    exit();

}

if ($password != $confirm_password) {
    echo "The password fields don't match.";
    $_SESSION['error']="The password fields don't match.";
    header( 'Location: settings.php' ) ;
    exit();    
}

    $sql = "INSERT INTO users (first,last,dcnick,aka,email,idno,yoj,password,branch,campus,phone,impath,hfb,htwit,hblog,hlink,hgpl) VALUES ('$first','$last','$dcnick','$aka','$email','$idno','$yoj','$password','$branch','$campus','$phone','$path','$hfb','$htwit','$hblog','$hlink','$hgpl')";
    $res=mysql_query($sql);
    echo $sql;
    echo $res;
    $_SESSION['error']="Password updated successfully";
    header( 'Location: profile.php' ) ;
//}
?></p>
</body>
</html>

