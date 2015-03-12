<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<title>Welcome to the Room Booking Service</title>
<link href="styles\indexstyle.css" rel="stylesheet" type="text/css" />
<link href="styles\styles.css" rel="stylesheet" type="text/css" />
<!-- 
	Copyright 2009 Itamar Arjuan
	jsDatePick is distributed under the terms of the GNU General Public License.
	
-->
<link rel="stylesheet" type="text/css" media="all" href="javascript\jsDatePick_ltr.min.css" />
<script type="text/javascript" src="javascript\jsDatePick.min.1.3.js"></script>

<script type="text/javascript">

	window.onload = function(){
		new JsDatePick({
			useMode:2,
			target:"date",
			dateFormat:"%Y-%d-%m"
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

<!--
<script type='text/javascript'>


function validate()
{	
	var validj=false;
	
	if(notEmpty(document.getElementById('date'),'Please Enter a Date'))
	{
		if(dateValid(document.getElementById('date')))
		{
			if(timeValid(document.getElementById('startt')),document.getElementById('endt'))
			{
				validj=true;
			}
		}
	}
	if validj	{
		< ?php 
			$valid=true;
		?>
	}
	else{
		< ?php 
			$valid=false;
		?>
	}
}
function dateValid(date)
{
/*	if()
	{
		return true;
	}
	else return false;*/
	alert (date);
	return true;
}
function timeValid(startt,endt)
{
/*	if()
	{
		return true;
	}
	else return false;*/
	alert (startt);
	return true;
}

function notEmpty(elem, helperMsg){
	alert("function");
	if(elem.value.length == 0){
		alert(helperMsg);
		elem.focus();
		return false;
	}
	return true;
}
</script>
-->


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
							<option value=01>C 301</option>
							<option value=02>C 302</option>
							<option value=03>C 303</option>
							<option value=04>C 304</option>
							<option value=05>C 305</option>
							<option value=06>C 306</option>
							<option value=07>C 307</option>
							<option value=08>C 308</option>
						<option value=00>  -  </option>
							<option value=11>C 401</option>
							<option value=12>C 402</option>
							<option value=13>C 403</option>
							<option value=14>C 404</option>
							<option value=15>C 405</option>
						<option value=00>  -</option>
							<option value=21>A 501</option>
							<option value=22>A 502</option>
							<option value=23>A 503</option>
							<option value=24>A 504</option>
							<option value=25>A 505</option>
							<option value=26>A 506</option>
							<option value=27>A 507</option>
							<option value=28>A 508</option>
						<option value=00>  -</option>
							<option value=31>A 601</option>
							<option value=32>A 602</option>
							<option value=33>A 603</option>
							<option value=34>A 604</option>
							<option value=35>A 605</option>
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
					<input type="text" class="rightcol"  id="date" name="date" /> 
					
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
									$currdate= strtotime('now');
									if(strtotime($date) < strtotime($currdate))
									{ 
										echo('<div id="dateError"> Enter a valid date</div>');
										$valid=false;
									}
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
							mysql_select_db("room_book", $con);
							$room=$_POST["room"];
							$studid="f2009494g"/*$_POST["studid"]*/;
							$startt=$_POST["startt"];
							$endt=$_POST["endt"];
							$date=$_POST["date"];
							//$status=$_post["status"];
							$comment=$_POST["comment"];
							$sql="INSERT INTO `roomstatus`( `room`, `studID`, `startT`, `endT`, `date`, `status`, `comment`) VALUES ($room,\"$studid\",\"$startt\",\"$endt\",\"$date\",1,\"$comment\")";
							if (!mysql_query($sql,$con))
							{
								die(' Error: ' . mysql_error());
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
					