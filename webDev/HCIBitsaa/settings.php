<?php
include('common.php');
include('connection.php');
include('topbar.php');
session_start();
if(!isset($_SESSION['logged']))
{
header( 'Location: index.php' ) ;
}
else if($_SESSION['logged']!=1)
{
header( 'Location: index.php' ) ;
}
$search=$_POST['search'];
?>
<div id="updateerror"><?php
    if($_SESSION['error']!="0")
    {    
    echo $_SESSION['error'];
    $_SESSION['error']="0";
    }
?></div>
<div id="centerc">
<div style="font-size:18px;position:relative;left:125px;">Change Password </div><br/>
<form name="passs" action="passc.php" method="post">
<table> <tr> <td>Password </td> <td>
<input type="password" name="pass1" /> </td></tr> <tr><td>
Confirm Password </td> <td><input type="password" name="pass2" /> </td></tr> </table> <br/>
<div style="font-size:18px;position:relative;left:125px;"><input type="submit" value="Change" /> </div><br/> <br/>
</div>
</form>
</body>
</html>
