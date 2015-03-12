<?php
include('common.php');
include('connection.php');
session_start();
if(!isset($_SESSION['logged']))
{
header( 'Location: index.php' ) ;
}
else if($_SESSION['logged']!=1)
{
header( 'Location: index.php' ) ;
}
$id=$_GET['user'];
$sql = "SELECT * from `users` where id='" . $id . "'";
$query = mysql_query($sql);
$row = mysql_fetch_array($query);
include('profilecontent.php');
?>
</body>
</html>
