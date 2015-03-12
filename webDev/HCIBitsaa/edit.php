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
$em=$_SESSION['email'];
$first = checkinput($_POST['first']);
$last = checkinput($_POST['last']);
$dcnick = checkinput($_POST['dcnick']);
$aka = checkinput($_POST['aka']);
$email = checkinput($_POST['email']);
$idno = checkinput($_POST['id']);
$yoj = checkinput($_POST['yoj']);
$phone = checkinput($_POST['phone']);
$branch = checkinput($_POST['branch']);
$campus = checkinput($_POST['campus']);
$htwit = checkinput($_POST['htwit']);
$hblog = checkinput($_POST['hblog']);
$hgpl = checkinput($_POST['hgpl']);
$hfb = checkinput($_POST['hfb']);
$hlink = checkinput($_POST['hlink']);

if (!checkblank($yoj)) {
 $sql = "UPDATE users SET yoj='".$yoj."' WHERE email='".$em."'";
    if($yoj>1950 && $yoj<2050)
    {    
    $res=mysql_query($sql);
    echo $sql;
    echo $res;
    }
    else
    $_SESSION['error']="Invalid year";
    header( 'Location: profile.php' ) ;
}
if (!checkblank($last)) {
 $sql = "UPDATE users SET last='".$last."' WHERE email='".$em."'";
    $res=mysql_query($sql);
    echo $sql;
    echo $res;
    header( 'Location: profile.php' ) ;
}
if (!checkblank($first)) {
 $sql = "UPDATE users SET first='".$first."' WHERE email='".$em."'";
    $res=mysql_query($sql);
    echo $sql;
    echo $res;
    header( 'Location: profile.php' ) ;
}
if (!checkblank($dcnick)) {
 $sql = "UPDATE users SET dcnick='".$dcnick."' WHERE email='".$em."'";
    $res=mysql_query($sql);
    echo $sql;
    echo $res;
    header( 'Location: profile.php' ) ;
}
if (!checkblank($aka)) {
 $sql = "UPDATE users SET aka='".$aka."' WHERE email='".$em."'";
    $res=mysql_query($sql);
    echo $sql;
    echo $res;
    header( 'Location: profile.php' ) ;
}
if (!checkblank($email)) {
 $sql = "UPDATE users SET email='".$email."' WHERE email='".$em."'";
    $res=mysql_query($sql);
    echo $sql;
    echo $res;
    header( 'Location: profile.php' ) ;
}
if (!checkblank($phone)) {
 $sql = "UPDATE users SET phone='".$phone."' WHERE email='".$em."'";
    if($phone>10000000 && $phone<999999999)
    {    
    $res=mysql_query($sql);
    echo $sql;
    echo $res;
    }
    else
    $_SESSION['error']="Not a valid phone number";
    header( 'Location: profile.php' ) ;
}
if (!checkblank($branch)) {
 $sql = "UPDATE users SET branch='".$branch."' WHERE email='".$em."'";
    $res=mysql_query($sql);
    echo $sql;
    echo $res;
    header( 'Location: profile.php' ) ;
}
if (!checkblank($campus)) {
 $sql = "UPDATE users SET campus='".$campus."' WHERE email='".$em."'";
    $res=mysql_query($sql);
    echo $sql;
    echo $res;
    header( 'Location: profile.php' ) ;
}
if (!checkblank($hfb)) {
 $sql = "UPDATE users SET hfb='".$hfb."' WHERE email='".$em."'";
    $res=mysql_query($sql);
    echo $sql;
    echo $res;
    header( 'Location: profile.php' ) ;
}
if (!checkblank($htwit)) {
 $sql = "UPDATE users SET htwit='".$htwit."' WHERE email='".$em."'";
    $res=mysql_query($sql);
    echo $sql;
    echo $res;
    header( 'Location: profile.php' ) ;
}
if (!checkblank($hgpl)) {
 $sql = "UPDATE users SET hgpl='".$hgpl."' WHERE email='".$em."'";
    $res=mysql_query($sql);
    echo $sql;
    echo $res;
    header( 'Location: profile.php' ) ;
}
if (!checkblank($hblog)) {
 $sql = "UPDATE users SET hblog='".$hblog."' WHERE email='".$em."'";
    $res=mysql_query($sql);
    echo $sql;
    echo $res;
    header( 'Location: profile.php' ) ;
}
if (!checkblank($hlink)) {
 $sql = "UPDATE users SET hlink='".$hlink."' WHERE email='".$em."'";
    $res=mysql_query($sql);
    echo $sql;
    echo $res;
    header( 'Location: profile.php' ) ;
}

if (($_FILES["file"]["type"] == "image/jpeg") && ($_FILES["file"]["size"] < 200000))
 {
    $sql = "SELECT * from `users` where email='" . $em . "'";
    $res=mysql_query($sql);
    echo $sql;
    echo $res;
    $row = mysql_fetch_array($res);
    $path=$row['impath'];

    echo "Upload: " . $_FILES["file"]["name"] . "<br />";
    echo "Type: " . $_FILES["file"]["type"] . "<br />";
    echo "Size: " . ($_FILES["file"]["size"] / 1024) . " Kb<br />";
    echo "Temp file: " . $_FILES["file"]["tmp_name"] . "<br />";
    echo "p file: " . $_FILES["file"]["error"] . "<br />";
    echo $path;
      if(is_dir("img/users") && is_writable("img/users"))
        {
            if(move_uploaded_file($_FILES["file"]["tmp_name"], $path)){
            echo "Stored in: ".$path;
            }
        }
        else
        $_SESSION['error']="There was an error in uploading the file";


    header( 'Location: profile.php' ) ;
}
if (($_FILES["file"]["size"] > 200000))
{
        $_SESSION['error']="The file is too large";


    header( 'Location: profile.php' ) ;
}
header( 'Location: profile.php' ) ;
?>

    
</p>
</body>
</html>
