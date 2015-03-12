<?php
include('connection.php')
?>

<html>
<head>
<title>Registration for a BITSAA Account</title>
        <link href="css/register.css" rel="stylesheet" type="text/css" media="screen" />
                    <!-- favicon -->
                    <link rel="icon" href="favicon.ico" type="image/x-icon" />
                    <link rel="shortcut icon" href="favicon.ico" type="image/x-icon" />
</head>
<body>

<a href="index.php"><img src="img/brandsaa.png" style="position:absolute; top:0px; right:0px; z-index:1"/>
<img src="img/bits.png" style="position:absolute; top:0px; left:0px; z-index:1"/></a>
<div style="left:550px; top: 70px; font-size:25px; position:absolute;">Create an Account</div>
<div id="updateerror"><?php
session_start();
    if($_SESSION['rerror']!="0")
    {    
    echo $_SESSION['rerror'];
    $_SESSION['rerror']="0";
    }
?></div>
<div id="mainreg">
<form name="registration" method="POST" action="register_submit.php" enctype="multipart/form-data">
<div id="firstreg">
<table><tr><td>
First Name: </td> <td> </td> <td> <input type="text" name="first" /> </td> </tr> <tr> <td>
Last Name: </td> <td> </td> <td> <input type="text" name="last" /></td> </tr> <tr> <td>
Photo (Size 200 KB or less): </td> <td> </td> <td> <input type="file" name="file" id="file" size="20"/> </td> </tr> <tr> <td>
Email: </td> <td> </td> <td> <input type="text" name="email" /></td> </tr> <tr> <td>
Phone: </td> <td style="color:#555" align=right> +91-</td> <td> <input type="text" name="phone" /></td> </tr> <tr> <td>
Password: </td> <td> </td> <td> <input type="password" name="password" /></td> </tr> <tr> <td>
Confirm Password: </td> <td> </td> <td> <input type="password" name="confirm_password" /></td> </tr> </table>  </div> <div id="secondreg">
<table><tr> <td width=165>
<!--ID Number: </td> <td> </td> <td> <input type="text" name="id" /></td> </tr> <tr> <td> -->
Year of joining: </td> <td> </td> <td> <input type="text" name="yoj" maxlength="4" size="4" /></td> </tr> <tr> <td>
First Branch: </td> <td> </td> <td> <select name="branch">
<option value="Chemical">Chemical</option>
<option value="Civil">Civil</option>
<option value="Mechanical">Mechanical</option>
<option value="Electrical and Electronics">Electrical and Electronics</option>
<option value="Electronics and Instrumentation">Electronics and Instrumentation</option>
<option value="Electronics and Communications">Electronics and Communications</option>
<option value="Computer Science">Computer Science</option>
<option value="Information Systems">Information Systems</option>
<option value="M Sc. Biology">M Sc. Biology</option>
<option value="M Sc. Chemistry">M Sc. Chemistry</option>
<option value="M Sc. Economics">M Sc. Economics</option>
</select></td> </tr> <tr> <td>
Campus: </td> <td> </td> <td> <select name="campus">
<option value="Pilani" selected="selected">Pilani</option>
<option value="Goa">Goa</option>
<option value="Dubai">Dubai</option>
<option value="Hyderabad">Hyderabad</option>
</select></td> </tr> <tr> <td>

</td> </tr> </table> </div>

<div id="thirdreg">
<table><tr> <td>
DC Nick: </td> <td> </td> <td> <input type="text" name="dcnick" /></td> </tr> <tr> <td>
Nickname: </td> <td> </td> <td> <input type="text" name="aka" /></td> </tr> <tr> <td>
Facebook: </td> <td style="color:#555" align=right>  http://www.facebook.com/</td> <td><input type="text" name="hfb" /></td> </tr> <tr> <td>
Twitter: </td> <td style="color:#555" align=right>  @</td> <td><input type="text" name="htwit" /></td> </tr> <tr> <td>
Linked-In: </td> <td style="color:#555" align=right>  http://www.linkedin.com/profile/view?id=</td> <td><input type="text" name="hlink" /></td> </tr> <tr> <td>
Google Plus: </td> <td style="color:#555" align=right>  https://plus.google.com/u/0/</td> <td><input type="text" name="hgpl" /></td> </tr> <tr> <td>
Blog : </td> <td style="color:#555" align=right>  http://www.</td> <td><input type="text" name="hblog" /></td> </tr> <tr> <td> </table>
</div> <div id="fourthreg">
<input type="submit" value="Register" /> </div>
</form>
</div>
<?
include('footer.php')
?>
</body>
</html>
