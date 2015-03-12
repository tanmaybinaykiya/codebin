<html>
	<head>
		<title><?php echo'Lorem Ipsum '?> Profile Page</title>
		<link rel="stylesheet" href="styles/styles.css" />
		<link rel="stylesheet" href="styles/profileStyles.css" />
		<link rel="stylesheet" href="styles/navStyles.css" />
		<link rel="stylesheet" href="styles/autocomplete.css" type="text/css"/>
		
		<script src="scripts/jquery.js" type="text/javascript"></script>
		<script src="scripts/dimensions.js" type="text/javascript"></script>
		<script src="scripts/autocomplete.js" type="text/javascript"></script>
			
		<script type="text/javascript">
		    $(function(){
		        setAutoComplete("quickInput", "quickResults", "autocomplete.php?part=");
		    });
		</script>	
	</head>
	<body>
		<?php include 'navBar.php'; ?>
		<div class="wrapper" style="margin-left:300px;">
			
			<div id="page">
				<img id="ProfilePic" src="img/professors/<?php echo'name'+'.jpg'; ?>" width="150px" height="180px"/>
				<p id="name"><?php echo'Lorem Ipsum' ?>	</p>

				<div id="info">
					<p class="left">Chamber No</p><p class="right"> <?php echo'<a href="view.php">X XOX </a>'; ?></p>	
					<p class="left">Department</p><p class="right"> <?php echo'Department'; ?></p>	
					<p class="left">Subjects Taught</p><p class="right">
						<?php echo'Lorem Ipsum
							  </br>Lorem Ipsum
							  </br>Lorem Ipsum
							  </br>Lorem Ipsum '; ?>
					</p>	
					<p class="left">Qualification</p><p class="right"> 
						<?php echo'X XOX 
					</br>X XOX
					</br>X XOX
					'; ?>
					</p>	
					<p class="left">Page</p><p class="right"> <?php echo'<a href="#">www.blahblah.com</a>'; ?></p>	
				</div>	
			</div>	
		</div>	
	</body>	
</html>