o<?php session_start(); ?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=iso-8859-1" />
<link REL="SHORTCUT ICON" HREF="css/favicon.ico">
<title>BITS, Pilani - K. K. Birla Goa Campus : SWD</title>
</head>

<body>
<?php 
$usernm=$_POST["user_id"];
$pwd=$_POST["pwd"];

$str=fopen("http://10.1.1.82:800/auth.php?u=$usernm&p=$pwd","r");

$line=trim(fgets($str));


if($line=="true")
{
			$con=mysql_connect("localhost","ODBC","");
			
				if (!$con)
			  		{
  							die('Could not connect: ' . mysql_error());
  					}

			mysql_select_db("student", $con);
			$str = sprintf("SELECT * FROM student_info WHERE loginID='%s' ",$usernm);
			$result = mysql_query($str);
			$row = mysql_fetch_array($result);
			$hos=$row['hostel'];
			$id=$row['studentID'];
			$usernm=strtolower($usernm);
			$result = mysql_query("SELECT * FROM warden WHERE email='$usernm' ");
			$result2 = mysql_query("SELECT * FROM staff WHERE username='$usernm' ");
			$result3 = mysql_query("select * from med where email='$usernm' ");
			$result1 = mysql_query("SELECT * FROM super WHERE email='$usernm' ");
			
			
			if( ($p=strstr($usernm,"h200")) || ($p=strstr($usernm,"f200")) || ($p=strstr($usernm,"f201")) || ($p=strstr($usernm,"h201")) )
				{
					$_SESSION['username']=$usernm;										
					/*$str1 = sprintf("SELECT * FROM student_details WHERE id='%s' ",$id); //unCOMMENT TO allow THE ADDR_DETAIL PAGE
					$str1_result = mysql_query($str1);
					if($str1_row = mysql_fetch_array($str1_result))
					{
					$sessionid = session_id();
					header("Location: student_pagetemp1?PHPSESSID=$sessionid");
					}
					else
					{
						$sessionid = session_id();
						header("Location: chng_addr?PHPSESSID=$sessionid");
					}*/																	// TILL HERE
					$sessionid = session_id();
					header("Location: student_pagetemp1?PHPSESSID=$sessionid");
				}
				
			else if(($row = mysql_fetch_array($result2)) )
				{
					
					$_SESSION['username']=$usernm;		
					$sessionid = session_id();			
					header("Location: swd?PHPSESSID=$sessionid");
				}
				
				else if(($row = mysql_fetch_array($result3)) )
				{
					
					$_SESSION['username']=$usernm;		
					$sessionid = session_id();			
					header("Location: searchform3?PHPSESSID=$sessionid");
				}
			
			else if(($row = mysql_fetch_array($result)) || $usernm=='bjcbabu' || $usernm=='keraman' || ($row = mysql_fetch_array($result1)))
			{
					
					$_SESSION['username']=$usernm;
					$sessionid = session_id();
					header("Location: warden?PHPSESSID=$sessionid");
			}
			else
			{
			  $_SESSION['username']=$usernm;
			  $sessionid = session_id();
			  header("Location: Home_const?PHPSESSID=$sessionid");
			}
}			

else
{
	include("Home_loginerror.html");
}
?>
 <?php mysql_close($con); ?>  
</body>
</html>
