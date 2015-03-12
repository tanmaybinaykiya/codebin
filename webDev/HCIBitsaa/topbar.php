<html>
<head>
<title>
<?php
echo $row['first'];
?>'s Profile, BITS Alumni Division
</title>
<!-- css stylesheets-->
        <link href="css/profile.css" rel="stylesheet" type="text/css" media="screen" />
        <link href="css/jquery.lightbox-0.5.css" rel="stylesheet" type="text/css" media="screen" />
                    <!-- favicon -->
                    <link rel="icon" href="favicon.ico" type="image/x-icon" />
                    <link rel="shortcut icon" href="favicon.ico" type="image/x-icon" />
		<script type="text/javascript" src="js/jquery.js"></script>
		<script type="text/javascript" src="js/jquery.lightbox-0.5.js"></script>
		<script type="text/javascript" src="js/script.js"></script>
</head>
<body>
<div class="searchd"></div>
<!--<img src="img/search.png" style="position:absolute;top:-68px;right:110px;" id="searchu"/> -->
<img src="img/search.png" style="position:absolute;top:-86px;right:187px;" id="searchu"/>
<img src="img/search.png" style="position:absolute;top:-57px;right:187px;" id="searchi"/>
<div id="search">
<form name="search" method="post" action="search.php">
<input type="text" name="search"  id="searchbar" size="22"/>
<input type="submit" value="Search" />
</form>
</div>
<img src="img/bits1.png" style="position:absolute;top:0px;left:0px;"/>
<!--<img src="img/brandsaa.png" style="position:absolute;top:0px;left:300px;"/> -->
<img src="img/links.png" style="position:absolute;top:-54px;right:-61px;"/>
<a href="profile.php"> <img src="img/home.png" style="position:absolute;top:0px;right:170px;"/> </a>
<a href="settings.php"> <img src="img/setting.png" style="position:absolute;top:0px;right:90px;"/> </a>
<a href="logout.php"><img src="img/logout.png" style="position:absolute;top:4px;right:10px;"/> </a>
