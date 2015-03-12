<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=iso-8859-1" />
<link REL="SHORTCUT ICON" HREF="css/favicon.ico">
<title>BITS, Pilani - K. K. Birla Goa Campus </title>
</head>
<body>
<div style="margin-left:40px;margin-top:10px;">	<a href="admin.php">Back</a></div>
<?php
error_reporting(0);
session_start();
if ($_SESSION['loggedin'] != TRUE && $_SESSION['isadmin'] != TRUE)
	header("Location: index.php");
$type = $_SESSION['type'];
$psrn = $_GET['psrn'];
include_once 'connect.php';
if ($type == 1)
{
	$table = 'faculty';
}
else if ($type == 2)
{
	$table = 'faculty_incharge';
}
else if ($type == 3)
{
	$table = 'groupleader';
}
?>
<form method="POST" action="edit_details1.php">
<br><br>
<center>
Please select your location: 
<input type="hidden" value="<?php echo $psrn;?>" name="psrn" />
        <select location="location" name="loc">
        <option></option>
      <?php
        $result1 = mysql_query("SELECT * FROM $table WHERE psrn = '$psrn' ORDER BY LOCATION ASC") or die(mysql_error());
		$i=1; 
		$num = mysql_num_rows($result1);
		$_SESSION["num"] = $num;
         while ($row = mysql_fetch_array($result1)) 
		 {
			   echo '<option value="' . $row['LOCATION'] . '" name="loc">' . $row['LOCATION']. '</option>'; 
			   $_SESSION[$i] = $row['id'];
			   $_SESSION['location'.$i] = "$row[LOCATION]";
			   
			   $i++;
        }
		
    	
    ?>
       
    </select><br /><br />
<?php 

	function checkSimilar(){
		$num = $_SESSION["num"];
		$g = 1;
			for($b=1;$b<=$num;$b++){
				for($c=1;$c<=$num;$c++){
					if($c!=$b){
					if($_SESSION['location'.$b] == $_SESSION['location'.$c]){
					$_SESSION["replica"] = "true";
					$_SESSION["duplicate"] = $_SESSION['location'.$b];
					$java[$g] = $_SESSION['location'.$b];
					$g++;
					
					}}
				}
			}
				global $finalDup;
				global $count;
				$unique = array_unique($java);
				$count = count($unique);
				$gipsy = 1;
				//echo "<br />";echo $count;echo "<br />";
				for($ab=1;$ab<$g;$ab++){
					if(@$unique[$ab]!=""){
						$finalDup[$gipsy] = $unique[$ab];
						$gipsy++;
					}
				}
				//echo "<br />";
			//	print_r($finalDup);echo "<br />";
				//print_r($unique);
	}
	checkSimilar();
	$_SESSION["count"] = $count;
	echo "<br />";
	//print_r($finalDup);	echo "<br />";
	if($count>=1){
		echo "The Faculty has got more than one record for the following rooms";echo "<br /><br />";
		
		for($t=1;$t<=$count;$t++){
			echo $finalDup[$t]; echo "  &nbsp;&nbsp;&nbsp;";
			echo '<select name="id'.$t.'"><option></option>';
			$query = "SELECT * FROM $table WHERE LOCATION='$finalDup[$t]' AND PSRN='$psrn'";
			$query2 = mysql_query($query);
			while($result = mysql_fetch_array($query2)){
			$id = $result['id'];
		 	echo '<option value="' . $id. '" name="id'.$t.'">' .  $id. '</option>';
			}
			 echo "</select><br /><br />";
		}
	}
	
?>
    <input type="submit" value="submit" >
</center>
</form>
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