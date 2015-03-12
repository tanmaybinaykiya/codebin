<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>

<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />

<title>Welcome to the Room Booking Service</title>
<link href="styles\indexstyle.css" rel="stylesheet" type="text/css" />
<link href="styles\styles.css" rel="stylesheet" type="text/css" />
</head>

<body>
    
        <div class="wrapper">
        	<?php include("header.php"); ?>
        	<div class="content">
				<form name="booking" method="POST" style="width:400px;" action="booking_submit.php">
                      
                    <p style="font-size:20px;">Book A Room</p>
                    
                        <label for="psrn">PSRN Number :</label>
                        <input class="right" type="text" name="psrn" id="psrn"/>
                    
                    
                        <label for="startd">Date : </label>
                        <input type="text" name="startd" id="startd"  class="right"/>
                    
                    
                        <label for="startt">Start Time :</label>
                        <select name="startt" id="startt" class="right">
                            <option value="08:00:00">0800</option>
                            <option value="09:00:00">0900</option>
                            <option value="10:00:00">1000</option>
                            <option value="11:00:00">1100</option>
                            <option value="12:00:00">1200</option>
                            <option value="13:00:00">1300</option>
                            <option value="14:00:00">1400</option>
                            <option value="15:00:00">1500</option>
                            <option value="16:00:00">1600</option>
                            <option value="17:00:00">1700</option>
                            <option value="18:00:00">1800</option>
                            <option value="19:00:00">1900</option>
                            <option value="20:00:00">2000</option>
                            <option value="21:00:00">2100</option>
                            <option value="22:00:00">2200</option>
                            <option value="23:00:00">2300</option>
                        </select>
                    
                        <label for="endt">End Time : </label>
                        <select name="endt" id="endt" class="right">
                            <option value="08:00:00">0800</option>
                            <option value="09:00:00">0900</option>
                            <option value="10:00:00">1000</option>
                            <option value="11:00:00">1100</option>
                            <option value="12:00:00">1200</option>
                            <option value="13:00:00">1300</option>
                            <option value="14:00:00">1400</option>
                            <option value="15:00:00">1500</option>
                            <option value="16:00:00">1600</option>
                            <option value="17:00:00">1700</option>
                            <option value="18:00:00">1800</option>
                            <option value="19:00:00">1900</option>
                            <option value="20:00:00">2000</option>
                            <option value="21:00:00">2100</option>
                            <option value="22:00:00">2200</option>
                            <option value="23:00:00">2300</option>
                        </select>
                    
                    
                        <label for="room">Room : </label>
                        <select name="room" id="room" class="right">
                            <option value="A101">A101</option>
                            <option value="A102">A102</option>
                            <option value="A103">A103</option>
                            <option value="A104">A104</option>
                            <option value="A105">A105</option>
                            <option value="A106">A106</option>
                            <option value="A107">A107</option>
                        </select>
                    
                        <label for="type">Utility : </label>
                        <select name="type" id="type" class="right">
                            <option value="VideoConf">VideoConf</option>
                            <option value="Skype">Skype</option>
                            <option value="TeleConf">TeleConf</option>
                            <option value="Other">Other</option>
                        </select>
                    
                        <label for="comments">Comments : </label>
                        <input type="text" name="comments" id="comments" class="right"/>
                    
                        <input type="submit" style="clear:both; float:right; margin:10px 160px 0 0" value="Book" id="submit"/>
                    
                                      
				</form>
        	</div>
            <?php include("footer.php"); ?>
		</div>
	
    
</body>
</html>
