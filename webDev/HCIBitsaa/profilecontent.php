<?php
include('topbar.php');
echo "<div id='firstc' class='h3' style='position:absolute;top:45px;left:330px;'>".$row['first']."</div>";
echo " ";
echo "<div id='lastc' class='h3' style='position:absolute;top:45px;left:530px;'>".$row['last']."</div>";
?>
<?php
echo "<div id='yojc' class='h4' style='position:absolute;top:45px;left:1050px;'>| ".$row['yoj']."  </div>";
echo "<div id='campusc' class='h4' style='position:absolute;top:45px;right:300px;'>".$row['campus']."</div>";
?>

<?php
$hql = "SELECT * from `hubs` where campus='" . $row['campus'] . "'";
$hquery = mysql_query($hql);
$hrow = mysql_fetch_array($hquery);
echo "<a href=".$hrow['hubaddr'].">";
echo "<img src='img/dcpp.png' style='left:450px;' id='dcpp' title='".$hrow['hub']."'/> </a>";
$hrow = mysql_fetch_array($hquery);
echo "<a href=".$hrow['hubaddr'].">";
echo "<img src='img/dcpp.png' style='left:490px;' id='dcpp' title='".$hrow['hub']."'/> </a>";
?>
<?php
echo "<div id='dcnickc' class='h5' style='position:absolute;top:90px;left:330px;'>".$row['dcnick']."</div>";
?>


<?php
echo "<div id='akac' class='h5' style='position:absolute;top:90px;left:533px;'>".$row['aka']."</div>";
?>

<?php
echo "<div id='branchc' class='h6' style='text-align:right;position:absolute;top:90px;right:235px;'>".$row['branch']."</div>";
?>

<?php
echo "<div id='emailc' class='h7' style='position:absolute;top:260px;left:350px;width:250px;'> <img src='img/email.png' style='position:absolute;top:22px;left:7px;'/>".$row['email']."</div>";
?>

<?php
echo "<div id='phonec' class='h7' style='position:absolute;top:260px;left:886px;'><img src='img/call.png' style='position:absolute;top:16px;left:7px;'/>".$row['phone']."</div>";
?>

<div id="batchsnaps">
Batch Snaps
<ul> <li>
<a title="Batchsnap" href="img/batch/EEE.jpg"><img src="img/batch/EEE.jpg" style="position:absolute;right:10px;top:30px;" width="150px" id="batchs"/></a> </li> </ul>
</div>
<?php
echo "<img src='".$row['impath']."' style='position:absolute;left:40px;top:100px;' width=220px; id='imfilec'/>";
?>
<?php
echo "<a target='_blank' href= 'https://twitter.com/#!/".$row['htwit']."'>";
?>
<div class="blueb" id="twitter">
<img src="img/twitter.png" class="tileico"/>
<p><?
echo "@".$row['htwit'];
?>
</p>
</div>
</a>
<?php
echo "<a target='_blank' href= 'http://www.linkedin.com/profile/view?id=".$row['hlink']."'>";
?>
<div class="blueb" id="linkedin">
<img src="img/linkedin.png" class="tileico"/>
<p><?
echo "Resume";
?>
</p>
</div>
</a>
<?php
echo "<a target='_blank' href= 'http://www.facebook.com/".$row['hfb']."'>";
?>
<div class="blueb" id="facebook">
<img src="img/fb.png" class="tileico"/>
<p><?
echo "/".$row['first'];
?>
</p>
</div>
</a>
<?php
echo "<a target='_blank' href= 'https://plus.google.com/u/0/".$row['hgpl']."/posts'>";
?>
<div class="blueb" id="plus">
<img src="img/gplus.png" class="tileico"/>
<p><?
echo "+".$row['first'];
?>
</p>
</div>
</a>
<?php
echo "<a target='_blank' href= 'http://www.".$row['hblog']."'>";
?>
<div class="blueb" id="blog">
<img src="img/blog.png" class="tileico"/>
<p><?
echo "Blog";
?>
</p>
</div>
</a><!--
<a href="google">
<div class="blueb" id="linkedin">
<img src="img/linkedin.png" class="tileico"/>
</div>
</a>
<a href="google">
<div class="blueb" id="facebook">
<img src="img/fb.png" class="tileico"/>
</div>
</a>
<a href="google">
<div class="blueb" id="plus">
<img src="img/gplus.png" class="tileico"/>
</div>
</a>
<a href="google">
<div class="blueb" id="blog">
<img src="img/blog.png" class="tileico"/>
</div>
</a>-->
