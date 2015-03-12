<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<title>Welcome to the Room Booking Service</title>
<link href="styles/indexstyle.css" rel="stylesheet" type="text/css" />
<link href="styles/styles.css" rel="stylesheet" type="text/css" />
<!-- 
	Copyright 2009 Itamar Arjuan
	jsDatePick is distributed under the terms of the GNU General Public License.
	
-->
<link rel="stylesheet" type="text/css" media="all" href="javascript/jsDatePick_ltr.min.css" />
<script type="text/javascript" src="javascript/jsDatePick.min.1.3.js"></script>

<script type="text/javascript">

	window.onload = function(){
		new JsDatePick({
			useMode:2, 
			target:"date", 
			dateFormat:"%Y-%m-%d"
			
			/*selectedDate:{				This is an example of what the full configuration offers.
				day:5,						For full documentation about these settings please see the full version of the code.
				month:9,
				year:2006
			},
			yearsRange:[1978,2020],
			limitToToday:false,
			cellColorScheme:"beige",
			dateFormat:"%m-%d-%Y",
			imgPath:"img/",
			weekStartDay:1*/
		});
	};
</script>


</head>
<body>

    <div class="body">
        <div class="wrapper">
        	<?php
			include("header.php");
			$valid=true;
			?>
        	<div class="content">
				<div class="bookingform">
					<form  action="book.php" method="post">
					
					<input type='hidden' name='submitted' id='submitted' value='1'/>
					<!--<label for="studid"> ID </label> 
					<input  class="rightcol" type="text" name="studid" /> 
						
					-->
					<p><strong>BOOK A ROOM </strong></p>
					<label for="room"> Class* </label>
					<select class="rightcol"  name="room" id="room">
						<option value=00>  -  </option>
							<option value=C-301>C-301</option>
							<option value=C-302>C-302</option>
							<option value=C-303>C-303</option>
							<option value=C-304>C-304</option>
							<option value=C-305>C-305</option>
							<option value=C-306>C-306</option>
							<option value=C-307>C-307</option>
							<option value=C-308>C-308</option>
						<option value=00>  -  </option>
							<option value=C-401>C-401</option>
							<option value=C-402>C-402</option>
							<option value=C-403>C-403</option>
							<option value=C-404>C-404</option>
							<option value=C-405>C-405</option>
						<option value=00>  -</option>
							<option value=A-501>A-501</option>
							<option value=A-502>A-502</option>
							<option value=A-503>A-503</option>
							<option value=A-504>A-504</option>
							<option value=A-505>A-505</option>
							<option value=A-506>A-506</option>
							<option value=A-507>A-507</option>
							<option value=A-508>A-508</option>
						<option value=00>  -</option>
							<option value=A-601>A-601</option>
							<option value=A-602>A-602</option>
							<option value=A-603>A-603</option>
							<option value=A-604>A-604</option>
							<option value=A-605>A-605</option>
					</select>
					<span class="error">
					<?php
						if(isset($_POST['submitted']))
						{
							if($_POST["room"]==00)
							{
								echo('Enter a valid room');
								$valid=false;	
							}
						}
					?></span>		
					<label for="date">Date*</label>
					<input type="text"  class="rightcol"  id="date" name="date" /> 
					
						<?php
							
							
							if(isset($_POST['submitted']))
							{
								if($_POST["date"]==null)
								{
									echo('<div id="dateError"> Enter a valid date</div>');
									$valid=false;
								}
								else
								{	
									$date=$_POST["date"];
									$givenyear=(int)substr($date,0,4);
									$givendate=(int)substr($date,8);
									$givenmonth=(int)substr($date,5,2);
									
									$currdate=(int)date('d');
									$currmonth=(int)date('m');
									$curryear=(int)date('Y');
									
									
									if($curryear!=$givenyear)
									{ 
										echo('<div id="dateError"> Invalid year</div>');
										$valid=false;
									}
									else if ($currmonth >$givenmonth)
									{ 
										echo('<div id="dateError"> Given date has already occured.  </div>');
										$valid=false;
									}
									else if($currdate>$givendate)
									{ 
										echo('<div id="dateError"> Given date has already occured.</div>');
										$valid=false;
									}
									else {$valid=true;}
								}
							}
						?>
					
					<label for="startt"> From*  </label>
					<select class="rightcol"  name="startt">
						<option value=50>05 : 00</option>
						<option value=51>05 : 30</option>
						<option value=60>06 : 00</option>
						<option value=61>06 : 30</option>
						<option value=70>07 : 00</option>
						<option value=71>07 : 30</option>
						<option value=80>08 : 00</option>
						<option value=81>08 : 30</option>
					</select>
					<label for="endt">To* </label>
					<select class="rightcol"  name="endt">
						<option value=51>05 : 30</option>
						<option value=60>06 : 00</option>
						<option value=61>06 : 30</option>
						<option value=70>07 : 00</option>
						<option value=71>07 : 30</option>
						<option value=80>08 : 00</option>
						<option value=81>08 : 30</option>
						<option value=90>09 : 00</option>
					</select>
					<span class="error">
					<?php
						if(isset($_POST['submitted']))
						{
							$startt=$_POST["startt"];
							$endt=$_POST["endt"];
							if ($startt >= $endt)
							{
								echo('Start time exceeds End time.');
								$valid=false;
							}								
						}
					?></span>
					<label for="comment">Comments </label><input  type="text" class="rightcol" id="comment"  name="comment" /> 
					<div class="buttons" style="clear:both; float:left; margin:20px 0 0 180px; "><button type="submit">Submit</button></div>
					<?php
						include ("connection.php");
						if(isset($_POST['submitted'])&& ($valid))
						{
							mysql_select_db("room_book", $con)or die("cannot select DB");
							$room=$_POST["room"];
							$studid="f2009494g"/*$_POST["studid"]*/;
							$startt=$_POST["startt"];
							$endt=$_POST["endt"];
							$date2=$_POST["date"];
							//$status=$_post["status"];
							$comment=$_POST["comment"];
							$sql="INSERT INTO `roomstatus`( `room`, `studID`, `startT`, `endT`, `date`, `comment`) VALUES (\"$room\",\"$studid\",\"$startt\",\"$endt\",\"$date2\",\"$comment\")";
							
							
							if (!mysql_query($sql,$con))
							{
								die(' Error: ' . mysql_error());
							}
							else
							{
								header( 'Location: success.php' ) ;
							}
						}
						
					?>    
					</form>
				<span style="font-size:10px; clear:both; float:left; color:red; margin-top:30px;">Fields marked with * are mandatory.</span>	
				</div>
				
        	</div>
        	<?php
			include("footer.php");
			?>

        </div>
    </div>
</body>
</html>
					