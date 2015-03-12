<html>
<head>
</head>
<body>

<?php

	if ($_POST["mit"])
	{
		switch ($_POST["mit"])
		{
			case 1:
				 header( 'Location: book.php' ) ;
				break;
			case 2:
				 header( 'Location: status.php' ) ;
				break;
			default:
				 header( 'Location: chart.php' ) ;
		}
	}
?>
</body>
</html>