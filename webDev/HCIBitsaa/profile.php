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
$email=$_SESSION['email'];
$sql = "SELECT * from `users` where email='" . $email . "'";
$query = mysql_query($sql);
$row = mysql_fetch_array($query);
include('profilecontent.php');
?>
<div id="updateerror"><?php
    if($_SESSION['error']!="0")
    {    
    echo $_SESSION['error'];
    $_SESSION['error']="0";
    }
?></div>
<img src="img/edit.png" style="position:absolute;top:66px;left:310px;" id="firsta"/>
<img src="img/edit.png" style="position:absolute;top:66px;left:1120px;" id="yoja"/>
<img src="img/edit.png" style="position:absolute;top:66px;left:512px;" id="lasta"/>
<img src="img/edit.png" style="position:absolute;top:100px;left:310px;" id="dcnicka"/>
<img src="img/edit.png" style="position:absolute;top:100px;left:513px;" id="akaa"/>
<!--<img src="img/edit.png" style="position:absolute;top:300px;left:420px;" id="emaila"/> -->
<img src="img/edit.png" style="position:absolute;top:277px;left:1120px;" id="phonea"/>
<img src="img/edit.png" style="position:absolute;top:100px;left:1120px;" id="brancha"/>
<img src="img/edit.png" style="position:absolute;top:42px;left:1039px;" id="campusa"/>
<img src="img/edit.png" style="position:absolute;top:100px;left:210px;" id="imfilea"/>
<form name="edit" method="post" action="edit.php" enctype="multipart/form-data" id="edit">
<input type="text" name="yoj" id="yojb" class="edit" style="position:absolute;top:70px;left:1075px;"/>
<input type="text" name="last" id="lastb" class="edit" style="position:absolute;top:70px;left:542px;"/>
<input type="text" name="first" id="firstb" class="edit" style="position:absolute;top:70px;left:343px;"/>
<input type="text" name="dcnick" id="dcnickb" class="edit" style="position:absolute;top:114px;left:343px;"/>
<input type="text" name="aka" id="akab" class="edit" style="position:absolute;top:114px;left:542px;"/>
<input type="text" name="email" id="emailb" class="edit" style="position:absolute;top:70px;left:343px;"/>
<input type="text" name="phone" id="phoneb" class="edit" style="position:absolute;top:265px;left:870px;"/>
<select type="text" name="branch" id="branchb" class="edit" style="position:absolute;top:114px;left:903px"/>
<option value="">-Select Your Branch-</option>
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
</select>
<select name="campus" id="campusb" class="edit" style="position:absolute;top:69px;left:986px;">
<option value="" selected="selected"> </option>
<option value="Pilani">Pilani</option>
<option value="Goa">Goa</option>
<option value="Dubai">Dubai</option>
<option value="Hyderabad">Hyderabad</option>
</select>
<input type="file" name="file" id="imfileb" class="edit" style="position:absolute;top:100px;left:210px;"/> 
<!--<input type="submit" value="Change" />-->
</form>
</body>
</html>
