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
        	<div class="content">
			<?php
				session_start();
				if($_SESSION['username'] != "username")
				{
					header("location:login.php");
				}
				//session_destroy();
			?>
				Login Successful !
				
        	</div>
            <?php
			include("footer.php");
			?>
		
        </div>
	
    </div>
</body>
</html>
