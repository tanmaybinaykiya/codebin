<html>
<head>
<title>Logging -in </title>
</head>
<body>

<?php
include('common.php');
include('connection.php');
$email = checkinput($_POST['email']);
$password= md5($_POST['password']);
$sql = "SELECT email,password from `users` where email='" . $email . "' and password='".$password."'";
//$sql = "SELECT * from users";
echo $sql;
$query = mysql_query($sql);
$row = mysql_fetch_array($query);
session_start();
    if($row['email']==$email && $row['password']==$password)
    {
    $_SESSION['logged']=1;    
    $_SESSION['email']=$email;
    $_SESSION['id']=$row['id'];
    header( 'Location: profile.php' ) ;
    }
    else
    {
    $_SESSION['wrong']=1;
    header( 'Location: index.php' ) ;
    }
    ?>
</body>
</html>
