<?php
include('common.php');
include('connection.php');
include('topbar.php');
session_start();
if(!isset($_SESSION['logged']))
{
header( 'Location: index.php' ) ;
}
else if($_SESSION['logged']!=1)
{
header( 'Location: index.php' ) ;
}
$search=$_POST['search'];
?>
<head>
<title>
Search Results
</title>
<!-- css stylesheets-->
        <link href="css/search.css" rel="stylesheet" type="text/css" media="screen" />
                    <!-- favicon -->
                    <link rel="icon" href="favicon.ico" type="image/x-icon" />
                    <link rel="shortcut icon" href="favicon.ico" type="image/x-icon" />
</head>
<body>
<div id="searchm" style="position:absolute;top:150px;left:210px;color:#FFF;">
<form name="search" method="post" action="search.php">
<input type="text" name="search" size="50"/>
<input type="submit" value="Search" /> </div>
</form>
<?php
$c=0;
$sqlf = "SELECT * from `users` where first LIKE '%" . $search . "%'";
$queryf = mysql_query($sqlf);
$c += mysql_num_rows ($queryf);
$sqll = "SELECT * from `users` where last LIKE '%" . $search . "%'";
$queryl = mysql_query($sqll);
$c += mysql_num_rows ($queryl);
$sqld = "SELECT * from `users` where dcnick LIKE '%" . $search . "%'";
$queryd = mysql_query($sqld);
$c += mysql_num_rows ($queryd);
$sqla = "SELECT * from `users` where aka LIKE '%" . $search . "%'";
$querya = mysql_query($sqla);
$c += mysql_num_rows ($querya);
echo "<div id='searchb'>";
    if($c>0)
    {
    echo "<div id='headr'>Name Results</div>";
    }

    while($row = mysql_fetch_array($queryf))
    {
    echo "<div id='searchr'>";
    echo "<a href=profilev?user=".$row['id']."><b>".$row['first']." ".$row['last']."</b></a><br/>";
    echo $row['yoj'].", ".$row['campus']."<br/><br/>";
    echo "</div>";
    }
    while($row = mysql_fetch_array($queryl))
    {
    echo "<div id='searchr'>";
    echo "<a href=profilev?user=".$row['id']."><b>".$row['first']." ".$row['last']."</b></a><br/>";
    echo $row['yoj'].", ".$row['campus']."<br/><br/>";
    echo "</div>";
    }
    while($row = mysql_fetch_array($queryd))
    {
    echo "<div id='searchr'>";
    echo "<a href=profilev?user=".$row['id']."><b>".$row['first']." ".$row['last']."</b></a><br/>";
    echo $row['yoj'].", ".$row['campus']."<br/><br/>";
    echo "</div>";
    }    
    while($row = mysql_fetch_array($querya))
    {
    echo "<div id='searchr'>";
    echo "<a href=profilev?user=".$row['id']."><b>".$row['first']." ".$row['last']."</b></a><br/>";
    echo $row['yoj'].", ".$row['campus']."<br/><br/>";
    echo "</div>";
    }

?>
<br/>
<?php
$c=0;
$sqlf = "SELECT * from `users` where id LIKE '%" . $search . "%'";
$queryf = mysql_query($sqlf);
$c += mysql_num_rows ($queryf);
$sqll = "SELECT * from `users` where yoj LIKE '%" . $search . "%'";
$queryl = mysql_query($sqll);
$c += mysql_num_rows ($queryl);
$sqld = "SELECT * from `users` where campus LIKE '%" . $search . "%'";
$queryd = mysql_query($sqld);
$c += mysql_num_rows ($queryd);
$sqla = "SELECT * from `users` where branch LIKE '%" . $search . "%'";
$querya = mysql_query($sqla);
$c += mysql_num_rows ($querya);
    if($c>0)
    {
    echo "<div id='headr'>Other Results</div>";
    }

    while($row = mysql_fetch_array($queryf))
    {
    echo "<div id='searchr'>";
    echo "<a href=profilev?user=".$row['id']."><b>".$row['first']." ".$row['last']."</b></a><br/>";
    echo $row['yoj'].", ".$row['campus']."<br/><br/>";
    echo "</div>";
    }
    while($row = mysql_fetch_array($queryl))
    {
    echo "<div id='searchr'>";
    echo "<a href=profilev?user=".$row['id']."><b>".$row['first']." ".$row['last']."</b></a><br/>";
    echo $row['yoj'].", ".$row['campus']."<br/><br/>";
    echo "</div>";
    }
    while($row = mysql_fetch_array($queryd))
    {
    echo "<div id='searchr'>";
    echo "<a href=#><b>".$row['first']." ".$row['last']."</b></a><br/>";
    echo $row['yoj'].", ".$row['campus']."<br/><br/>";
    echo "</div>";
    }    
    while($row = mysql_fetch_array($querya))
    {
    echo "<div id='searchr'>";
    echo "<a href=profilev?user=".$row['id']."><b>".$row['first']." ".$row['last']."</b></a><br/>";
    echo $row['yoj'].", ".$row['campus']."<br/><br/>";
    echo "</div>";
    }
echo "</div>";
?>
</body>
</html>
