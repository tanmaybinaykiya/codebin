<?php
@session_start();
if ($_SESSION['loggedin'] != TRUE)
	header("Location: index.php");
$table = $_SESSION['table'];
$usernm = $_SESSION['usernm'];
if ($table == 'faculty')
{
	$type = 1;
}
if ($table == 'faculty_incharge')
{
	$type = 2;
}
if ($table == 'groupleader')
{
	$type = 3;
}
include_once 'connect.php';
$query = "SELECT * FROM $table WHERE loginID='$usernm'";
$result = mysql_query($query);
if ($result == 0)
 {
	 $_SESSION['loggedin'] = FALSE;
	 session_destroy();
 echo("</br><b><center><font color='red'>Incorect Login Type</center></font></b>");
include("index.php");	
die();
    }
$count=1;
if(mysql_num_rows($result)) 
{
	if($type ==1){
		while($data=mysql_fetch_array($result,MYSQL_ASSOC)) //$line=mysql_fetch_array($paymajor,MYSQL_ASSOC)
		{ 	
			$name=$data['NAME'];
			$psrn=$data['PSRN'];
			$_SESSION['psrn'] = $psrn;
			$department=$data['DEPARTMENT'];
			$location['faculty'][] =$data['LOCATION'];
			$computer['faculty'][]=$data['COMPUTER'];
			if($type==1)
			{
				$ip_o['faculty'][]=$data['IP_O'];
				$ip_r['faculty'][]=$data['IP_R'];
			}
			$cpe['faculty'][]=$data['CPE'];
			$ups['faculty'][] =$data['UPS'];
			$headphone['faculty'][]=$data['HEADPHONE'];
			$webcam['faculty'][]=$data['WEBCAM'];
			$mobile['faculty'][]=$data['MOBILE'];
			$laptop['faculty'][]=$data['LAPTOP'];
			$printer['faculty'][]=$data['PRINTER'];
			$others['faculty'][]=$data['OTHERS'];
			$flag['faculty'][]=$data['FLAG'];
		}
	}
	else{
		while($data=mysql_fetch_array($result,MYSQL_ASSOC)){
			$name=$data['NAME'];
			$psrn=$data['PSRN'];
			$_SESSION['psrn'] = $psrn;
			$department=$data['DEPARTMENT'];
			$location['others'][]=$data['LOCATION'];
			$computer['others'][]=$data['COMPUTER'];
			$ip_phone['others'][]=$data['IP_PHONE'];
			$cpe['others'][]=$data['CPE'];
			$ups['others'][] =$data['UPS'];
			$headphone['others'][]=$data['HEADPHONE'];
			$webcam['others'][]=$data['WEBCAM'];
			$laptop['others'][]=$data['LAPTOP'];
			$printer['others'][]=$data['PRINTER'];
			$others['others'][]=$data['OTHERS'];
			$flag['others'][]=$data['FLAG'];
		}
	}
	
$main =<<< EOF
<table id="details">
<th colspan="2"> <center>BITS - PILANI, K.K. Birla GOA CAMPUS</center></th>
<tr><td><center><strong>LOCATION</strong></center></td>
EOF;
echo $main;
	
		}

  $pagemaincontent = ob_get_contents();
  ob_end_clean();
  $pagetitle = "Inventory System";
  //Apply the template
  include("master.php");
?>
</body>
</html>