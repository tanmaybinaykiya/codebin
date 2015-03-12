<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
	<head>
		<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
		<title>Welcome to the Room Booking Service</title>
			<link href="styles/indexstyle.css" rel="stylesheet" type="text/css" />
			<link href="styles/styles.css" rel="stylesheet" type="text/css" />
			<script type="text/javascript">

			</script>
	</head>
	<body>
	    <div class="body">
	        <div class="wrapper">
	        	<?php
					include("header.php");
				?>
	        	<div class="content">
	        		<div class="ApproveTable" style="clear:both; float:left;">
						<?php
							include("connection.php");
							mysql_select_db("room_book", $con)or die("cannot select DB");
							
							$sql=mysql_query("SELECT * FROM roomstatus");	
							$num_rows = mysql_num_rows($sql);
							

							if($num_rows){
								echo '<form action="approved.php" method="POST">
										<table id="AppTable" cellspacing="0px" >
									<thead>
										<tr>
											<th>Room</th><th>Student Id</th><th>Date</th><th>Start Time</th><th>End Time</th><th style="  width:330px;">Comment</th><th style="  min-width:45px;">Approve</th>
										</tr>	
									</thead>
								<tbody>';
							}

							while($row = mysql_fetch_array($sql))
							{

								//************************************* IN  TIME  
								$timeI=$row['startT'];
								$time1=$timeI%10;
								$time21=($timeI-$time1)/10;
								
								if($time1){
									$time1=$time1*30;
								}
								else{
									$time1="00";
								}					
								$timeI= $time21.".".$time1;
								//************************************* IN  TIME 

								//************************************* OUT  TIME 
								$timeO=$row['endT'];
								$time2=$timeO%10;
								$time22=($timeO-$time2)/10;
								
								if($time2){
									$time2=$time2*30;
								}
								else{
									$time2="00";
								}					
								$timeO= $time22.".".$time2;
								//************************************* out  TIME 

								//************************************* NULL COMMENT

								if(!$row['comment'])
								{
									$comm="--";
								}
								else {
									$comm=$row['comment'];
								}
								//************************************* NULL COMMENT

								echo "	<tr>
											 <td>".$row['room'].
											"</td><td>".$row['studID'].
											"</td><td>".$row['date'].
											"</td><td>".$timeI.
											"</td><td>".$timeO.
											"</td><td>".$comm.
											// "</td><td><input type=\"checkbox\" id=\"a".$row['id']."\" name=\"app\" value=".$row['id'].
											// "></td><td><input type=\"checkbox\" id=\"d".$row['id']."\" name=\"disapp\" value=".$row['id'].
											"</td><td>  <select name=\"a".$row['id']."\">
															<option value=\"0\">Disapprove</option>
															<option value=\"1\">Approve</option>
														</select>".
											"</td></tr>
											
									";
								
							}
							if($num_rows){
								echo "</tbody></table><div class=\"buttons\" style=\"clear:both;  margin:20px 430px 0 430px ;\">
											<button  type=\"submit\" >Submit</button>
											</div>
											</form>";
							}
							mysql_close($con);
						?>
							
					</div>
	        	</div>
	            <?php
				include("footer.php");
				?>
	        </div>
	    </div>
	</body>
</html>