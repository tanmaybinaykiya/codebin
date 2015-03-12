<?php
?>
<html>
<head>
<title>BITSAA Division, BITS Pilani</title>
<meta keywords="bitsaa alumni website bits bitspilani pilani goa hyderabad dubai batch batchof"/>
<!-- css stylesheets-->
        <link href="css/stylesheet_login.css" rel="stylesheet" type="text/css" media="screen" />
                    <!-- favicon -->
                    <link rel="icon" href="favicon.ico" type="image/x-icon" />
                    <link rel="shortcut icon" href="favicon.ico" type="image/x-icon" />
</head>
<body>
<!--<div id="tophalf">-->
<div id="bitsaainfo">
<h3 style="position:absolute;top:-40px;left:200px;">BITS Alumni Division</h3>
Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veni am, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.
</div>
<!--</div>-->

<a href="index.php"><img src="img/brandsaa.png" style="position:absolute; top:0px; right:0px; z-index:1"/>
<img src="img/bits.png" style="position:absolute; top:0px; left:0px; z-index:1"/></a>
<div id="loginform">
<h3 style="position:absolute;top:-30px;left:120px;">Log In</h3>
<form name="login" method="post" action="loginresolve.php">
<table>
<tr>
<td width=40%>Email : </td><td> <input type="text" name="email" /></td> </tr> <tr> <td>
Password : </td><td> <input type="password" name="password" /></td> </tr> <tr> <td> </td> <td>
<div id="splash">
<?php
session_start();
if (isset($_SESSION['wrong']))
echo "Username and Password do not match.";
?>
</div></td> </tr> <tr> <td> </td> <td>
<input type="submit" value="Log In" /></td> </tr>
</table>
</form> <div style="position:relative; top:8px; color:#444;">
<a href="register.php">New User </a> <a href="forgotpassword.php" style="position:relative; left:50px;">Forgot Password</a> 
</div>
</div>
<?
include('footer.php')
?>
</body>
</html>
