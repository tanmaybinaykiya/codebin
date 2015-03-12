<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>

<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />

<title>Welcome to the Room Booking Service</title>
<link href="styles/indexstyle.css" rel="stylesheet" type="text/css" />
<link href="styles/styles.css" rel="stylesheet" type="text/css" />
</head>

<body>
    <div class="body">
        <div class="wrapper">
        	<?php
				include("header.php");
			?>
        	<div class="content" style>
				<form action="login.php" method="post">
					<label for="username">Username </label><input  type="text" class="rightcol" id="username"  name="username" /> 
					<input type='hidden' name='submitted' id='submitted' value='1'/>
					<label for="password">Password </label><input  type="password" class="rightcol" id="password"  name="password" /> 
					<div class="buttons" style="clear:both; margin:20px 0 0 178px;"> 
						<button  type="submit" >Submit</button> 
					</div>
					<?php
				ob_start();
				include("connection.php");
				if(isset($_POST['submitted']))
				{
					mysql_select_db("room_book", $con)or die("cannot select DB");
					$username=$_POST['username']; 
					$password=$_POST['password'];

					// To protect MySQL injection (more detail about MySQL injection)
					$username = stripslashes($username);
					$password = stripslashes($password);
					$username = mysql_real_escape_string($username);
					$password = mysql_real_escape_string($password);

					$sql="SELECT * FROM members WHERE username='$username' and password='$password'";
					$result=mysql_query($sql);
					

					// Mysql_num_row is counting table row
					$count=mysql_num_rows($result);
					// If result matched $myusername and $mypassword, table row must be 1 row

					if($count==1)
					{
						// Register $myusername, $mypassword and redirect to file "login_success.php"
						session_register("username");
						session_register("password"); 
						$_SESSION['username'] = "username";
						header("location:login_result.php");
					}
					else
					{
						echo '<p style="clear:both; float:left;  font-size:10px; color:#ed1c24;">Invalid Username or Password</p>';
					}
				}
				ob_end_flush();
			?>
				</form>
				
        	</div>
            <?php
			include("footer.php");
			?>
		
        </div>
	
    </div>
</body>
</html>
