<!--INSERT INTO `roomstatus`( `room`, `studID`, `startT`, `endT`, `date`, `status`, `comment`) VALUES ('A603','f2009494g','17:00:00','19:00:00','15-12-2012',1,'DCM INDUCTIONS')-->
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>

<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<title>Welcome to the Room Booking Service</title>
<link href="styles/styles.css" rel="stylesheet" type="text/css" />
<link href="styles/innerstyle.css" rel="stylesheet" type="text/css" />
<link href="styles/viewstyles.css" rel="stylesheet" type="text/css" />
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
			target:"inputField",
			dateFormat:"%d-%M-%Y"
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
			?>
        	<div class="content">
            	<div id="info">
            <form action="chart.php" method="post" >
            <div style="float:left; margin-top:5px;">Choose Date : </div> <input type="text" style="float:left; margin-left:10px;"   id="inputField" />
                
                
            	<div class="buttons" style="float:left; margin-left:10px;">
    				<button  type="submit" name="Submit">Submit</button>
        		</div>
            
               <!-- <input type="submit" value="Submit" style="background:#09F; border:1px solid #fff; color:#fff; width:100px; height:30px; font-weight:bold;" /> -->
               </form> 
            </div>
    			<div class="main_window">
				<div id="awing">
                	<p>A WING  </p>
					<div class="lower">
                    	<div class="lt">
                            	<div id="503" style="background-color:#D94737; border-color:#C03525;" class="lowroom">A 503</div>
                            	<div id="502" class="lowroom">A 502</div>
                            	<div id="501" class="lowroom">A 501</div>
                        </div>
                        <div class="mid">
                        		<div id="504" class="midlowroom">A 504 </div>
                            	<div id="505" class="midlowroom">A 505</div>
                        </div>
                        <div class="rt">
                        	<div id="506" class="lowroom">A 506</div>
                            	<div id="507" class="lowroom">A 507</div>
                            	<div id="508" class="lowroom">A 508</div>
                        </div>
                    </div>
                                 	
					<div class="upper">
                    	<div class="back">
                        	<div id="601" class="backroom"> A 601</div>
                        	
                        </div>
                        <div class="front">
                        	<div id="605" class="frontroom">A 605</div>
                        	<div id="604" class="frontroom">A 604</div>
                        	<div id="603" class="frontroom">A 603</div>
                            <div id="602" class="frontroom">A 602</div>
                        </div>
                   	</div>                	
                </div>
                <div id="cwing">
                	 <p>C WING  </p>
					<div class="lower">
                    	<div class="lt">
                            	<div id="303"style="background-color:#D94737; border-color:#C03525;" class="lowroom">C 303</div>
                            	<div id="302" class="lowroom">C 302</div>
                            	<div id="301" class="lowroom">C 301</div>
                        </div>
                        <div class="mid">
                        		<div id="304" style="background-color:#D94737; border-color:#C03525;" class="midlowroom">C 304</div>
                            	<div id="305" class="midlowroom">C 305</div>
                            	
                        </div>
                        <div class="rt">
                        	<div id="306" class="lowroom">C 306</div>
                            	<div id="307" class="lowroom">C 307</div>
                            	<div id="308" style="background-color:#D94737; border-color:#C03525;" class="lowroom">C 308</div>
                        </div>
                    </div>                	
					<div class="upper">
                    	<div class="back">
                        	<div id="C401" class="backroom"> C 401</div>
                        </div>
                        <div class="front">
                        	<div id="405" style="background-color:#D94737; border-color:#C03525;" class="frontroom">C 405</div>
                        	<div id="404" class="frontroom">C 404</div>
                        	<div id="403" style="background-color:#D94737; border-color:#C03525;" class="frontroom">C 403</div>
                            <div id="402" class="frontroom">C 402</div>
                        </div>
                   	</div>                	
                </div>
            </div>    
            </div>
        	<?php
			include("footer.php");
			?>

        </div>
    </div>
</body>
</html>