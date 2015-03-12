<?php
@session_start();
if ($_SESSION['loggedin'] != TRUE)
	header("Location: index.php");
$table = $_SESSION['table'];
//ho "WELCOME $name";
$usernm = $_SESSION['usernm'];
//echo "WELCOME <strong>$usernm</strong>";
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
// or die("Query failed!");
if ($result == 0)
 {
	 $_SESSION['loggedin'] = FALSE;
	 session_destroy();
 echo("</br><b><center><font color='red'>Incorect Login Type..</center></font></b>");
include("index.php");	
die();
    }
$count=1;
if(mysql_num_rows($result)) 
{
	$total_rows = mysql_num_rows($result);
	$result_check = $result;
	$arr_check = array(
		'COMPUTER'	=> 0,
		'IP_PHONE'	=> 0,
		'CPE'		=> 0,
		'UPS'		=> 0,
		'HEADPHONE'	=> 0,
		'WEBCAM'	=> 0,
		'LAPTOP'	=> 0,
		'PRINTER'	=> 0,
		'OTHERS'	=> 0
	);
	while($data_check = mysql_fetch_array($result_check))
	{
		if ($data_check['COMPUTER'] == NULL)
			$arr_check['COMPUTER']++;
		if ($data_check['IP_PHONE'] == NULL)
			$arr_check['IP_PHONE']++;
		if ($data_check['CPE'] == NULL)
			$arr_check['CPE']++;
		if ($data_check['UPS'] == NULL)
			$arr_check['UPS']++;
		if ($data_check['HEADPHONE'] == NULL)
			$arr_check['HEADPHONE']++;
		if ($data_check['WEBCAM'] == NULL)
			$arr_check['WEBCAM']++;
		if ($data_check['LAPTOP'] == NULL)
			$arr_check['LAPTOP']++;
		if ($data_check['PRINTER'] == NULL)
			$arr_check['PRINTER']++;
		if ($data_check['OTHERS'] == NULL)
			$arr_check['OTHERS']++;
	}
	$result = mysql_query($query);
	$flag=1;
	while($data = mysql_fetch_array($result,MYSQL_ASSOC)) //$line=mysql_fetch_array($paymajor,MYSQL_ASSOC)
	{ 	
		$name=$data['NAME'];
		$psrn=$data['PSRN'];
		$_SESSION['psrn'] = $psrn;
		$department=$data['DEPARTMENT'];
		$location=$data['LOCATION'];
		if($count==1)
		{
			//echo "Welcome: <b>$name<b><br/>";
		}
		$computer=$data['COMPUTER'];
		if($type==1)
		{
			$ip_o=$data['IP_O'];
			$ip_r=$data['IP_R'];
		}
		if($type==2  || $type==3)
		{
			$ip_phone=$data['IP_PHONE'];
		}
		$cpe=$data['CPE'];
		$ups =$data['UPS'];
		$headphone=$data['HEADPHONE'];
		$webcam=$data['WEBCAM'];
		if($type==1)
		{
			$mobile=$data['MOBILE'];
		}
		$laptop=$data['LAPTOP'];
		$printer=$data['PRINTER'];
		$others=$data['OTHERS'];
		$flag*=$data['FLAG'];
		//echo $flag;
?>
<?php
if($type==1 && $count==1)
{
?>
<table id="details">
<th colspan="2"> <center>BITS - PILANI, K.K. Birla GOA CAMPUS</center></th>
<tr><td><center><strong>LOCATION</strong></center></td>
		<?php
			echo '<td><center>'.$location.'</td></tr></center>';
		if($computer!="")
		{
		?>
		<tr><td><center><strong>COMPUTER</strong></center></td>
		<?php
			echo '<td><center>'.$computer.'</td></tr></center>';
		}
		if($ip_o!="")
		{
		?>
		<tr><td><center><strong>IP(Office)</strong></center></td>
		<?php
			echo '<td><center>'.$ip_o.'</td></tr></center>';
		}
		if($ip_r!="")
		{
		?>
		<tr><td><center><strong>IP(Residence)</strong></center></td>
		<?php
			echo '<td><center>'.$ip_r.'</td></tr></center>';
		}
		if($cpe!="")
		{
		?>
		<tr><td><center><strong>CPE</strong></center></td>
		<?php
			echo '<td><center>'.$cpe.'</td></tr></center>';
		}
		if($ups!="")
		{
		?>
		<tr><td><center><strong>UPS</strong></center></td>
		<?php
			echo '<td><center>'.$ups.'</td></tr></center>';
		}
		if($headphone!="")
		{
		?>
		<tr><td><center><strong>HEADPHONE</strong></center></td>
		<?php
			echo '<td><center>'.$headphone.'</td></tr></center>';
		}
		if($webcam!="")
		{
		?>
		<tr><td><center><strong>WEBCAM</strong></center></td>
		<?php
			echo '<td><center>'.$webcam.'</td></tr></center>';
		}
		if($mobile!="")
		{
		?>
		<tr><td><center><strong>MOBILE</strong></center></td>
		<?php
			echo '<td><center>'.$mobile.'</td></tr></center>';
		}
		if($laptop!="")
		{
		?>
		<tr><td><center><strong>LAPTOP</strong></center></td>
		<?php
			echo '<td><center>'.$laptop.'</td></tr></center>';
		}
		if($printer!="")
		{
		?>
		<tr><td><center><strong>PRINTER</strong></center></td>
		<?php
			echo '<td><center>'.$printer.'</td></tr></center>';
		}
		if($others!="")
		{
		?>
		<tr><td><center><strong>OTHERS</strong></center></td>
		<?php
			echo '<td><center>'.$others.'</td></tr></center>';
		}
		?>
	</table>
<?php




}
else
{ 
//echo "count=$count";
?>
<?php
if($count==1)
{
?>	
<table id="details">
	<!--<tr bgcolor="#CCCCCC"><td colspan="13"><h2><center>BITS - PILANI, K.K. Birla GOA CAMPUS</center></h2></td></tr>-->
	<th colspan="10"> <center>BITS - PILANI, K.K. Birla GOA CAMPUS</center></th>
		<tr>
			<!--
			<td><center>PSRN</center></td>
			<td><center>NAME</center></td>
			<td>DEPARTMENT</center></td>
			-->
			<td><center>LOCATION</center></td>
			<?php if($arr_check['COMPUTER'] != $total_rows) :?>
			<td><center>COMPUTER</center></td>
			<?php endif; if($arr_check['IP_PHONE'] != $total_rows) :?>
			<td NOWRAP><center>IP PHONE</center></td>
			<?php endif; if($arr_check['CPE'] != $total_rows) :?>
			<td><center>CPE</center></td>
			<?php endif; if($arr_check['UPS'] != $total_rows) :?>
			<td><center>UPS</center></td>
			<?php endif; if($arr_check['HEADPHONE'] != $total_rows) :?>
			<td><center>HEADPHONE</center></td>
			<?php endif; if($arr_check['WEBCAM'] != $total_rows) :?>
			<td><center>WEBCAM</center></td>
			<?php endif; if($arr_check['LAPTOP'] != $total_rows) :?>
			<td><center>LAPTOP</center></td>
			<?php endif; if($arr_check['PRINTER'] != $total_rows) :?>
			<td><center>PRINTER</center></td>
			<?php endif; if($arr_check['OTHERS'] != $total_rows) :?>
			<td><center>OTHERS</center></td>
			<?php endif; ?>
		</tr>
		<?php
}
		?>
		<tr>
		<?php
		//echo '<td NOWRAP><center>'.$psrn.'</td></center>';
		//echo '<td NOWRAP><center>'.$name.'</td></center>';
		//echo '<td NOWRAP><center>'.$department.'</td></center>';
		?>
		<td NOWRAP><center><?php echo $location; ?></td></center>
		<?php if($arr_check['COMPUTER'] != $total_rows) :?>
		<td NOWRAP><center><?php echo $computer; ?></td></center>
		<?php endif; if($arr_check['IP_PHONE'] != $total_rows) :?>
		<td NOWRAP><center><?php echo $ip_phone; ?></td></center>
		<?php endif; if($arr_check['CPE'] != $total_rows) :?>
		<td NOWRAP><center><?php echo $cpe; ?></td></center>
		<?php endif; if($arr_check['UPS'] != $total_rows) :?>
		<td NOWRAP><center><?php echo $ups; ?></td></center>
		<?php endif; if($arr_check['HEADPHONE'] != $total_rows) :?>
		<td NOWRAP><center><?php echo $headphone; ?></td></center>
		<?php endif; if($arr_check['WEBCAM'] != $total_rows) :?>
		<td NOWRAP><center><?php echo $webcam; ?></td></center>
		<?php endif; if($arr_check['LAPTOP'] != $total_rows) :?>
		<td NOWRAP><center><?php echo $laptop; ?></td></center>
		<?php endif; if($arr_check['PRINTER'] != $total_rows) :?>
		<td NOWRAP><center><?php echo $printer; ?></td></center>
		<?php endif; if($arr_check['OTHERS'] != $total_rows) :?>
		<td NOWRAP><center><?php echo $others; ?></td></center>
		<?php endif; ?>
		</tr>
		<?php
	}
$count++;	
	}
?>
</table>
<?php
}
else
{
	$_SESSION['loggedin'] = FALSE;
	 session_destroy();
	echo("</br><b><center><font color='red'>Incorect Login Type1</center></font></b>");
	include("index.php");	
	die();
	//die ("<center><font color='red'>PSRN not found</font></center>");
}
/*		
}			
else
{
	include("Home_loginerror.html");
}
*/
?>
<?php


if ($flag != 1 )
{
	?>
	<br>
	<form id="form2" name="form2" method="post" action="success.php">
	<center>
	<table width="500" border="2" align="center" cellpadding="2" style="border: solid 2px black;">
	<tr><td><center><input type="checkbox" name="flag" value="Flag_Checked" checked/></center></td><td><center>Yes, I have these Assets.</center></td>
	<td><center><input type="submit" style="width:70" name="submit1" value="Submit" ></center></td></tr>
	</table>
	</center>
	</form>
	<?php
}
?>
<?php
  //Assign all Page Specific variables
  $pagemaincontent = ob_get_contents();
  ob_end_clean();
  $pagetitle = "Inventory System";
  //Apply the template
  include("master.php");
?>
</body>
</html>