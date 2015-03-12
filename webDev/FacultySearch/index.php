<html>
<head>
	<title>WELCOME to ICOP</title>
	<link rel="stylesheet" href="styles/styles2.css" type="text/css"/>
	
	<link rel="stylesheet" href="styles/navStyles.css" type="text/css"/>
	<link rel="stylesheet" href="styles/autocomplete.css" type="text/css"/>
  	
  	<link rel="stylesheet" href="styles/font-awesome.css">
  	<link rel="stylesheet" href="styles/font-awesome-ie7.css">

	<script src="scripts/jquery.js" type="text/javascript"></script>
	<script src="scripts/dimensions.js" type="text/javascript"></script>
	<script src="scripts/autocomplete.js" type="text/javascript"></script>

<script type="text/javascript">
	$(function(){
		    setAutoComplete("search", "results", "autocomplete.php?part=");
	});

</script>
<style type="text/css">
#quick{
	display: none;
}
</style>
</head>
<body>
	<?php include 'navBar.php'; ?>
	<div class="wrapper">

		<input id="search" name="search" placeholder="Search here for Faculty or Chamber" type="text" />
		<div id="results" style="width:200px;"></div>	
	</div>	
		<div id="info">
			<div class="myBox" style="margin-left:0px; 	">
				<p ><i class="icon-search" style="font-size:125px; "></i></p>
				<p  class="myText"> Search for the faculty</p>
			</div>
			<div class="myBox">
				<p ><i class="icon-map-marker" style="font-size:125px; "></i></p>
				<p class="myText" > Find the Faculty's Chamber</p>
			</div>
			<div class="myBox">
				<p ><i class="icon-arrow-right" style="font-size:125px; "></i></p>
				<p class="myText" > Go to the faculty</p>
			</div>
		</div>	

	
</body>
</html>