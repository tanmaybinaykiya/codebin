<?php
include('connection.php');
$psrn=$_POST['psrn'];
$startt=$_POST['startt'];
$endt=$_POST['endt'];
$startd=$_POST['startd'];
//$endd=$_POST['startd'];
$type=$_POST['type'];
$room=$_POST['room'];
$comment=$_POST['comments'];
$sql="SELECT * FROM bookings WHERE room='".$room."'";
$query=mysql_query($sql);
$counter=0;
while($row = mysql_fetch_array($query))
  {
    if($row['startd']==$startd)
    {
        if(($row['startt']>$startt && $row['startt']>$endt) || ($row['endt']<$startt && $row['endt']<$endt))
        {

        }
        else
        {

        echo $counter++;
        }
    }
  
  }
if($counter==0)
{
$sql="INSERT INTO bookings (psrn,startd,startt,endt,comment,room,type) VALUES (".$psrn.",'".$startd."','".$startt."','".$endt."','".$comment."','".$room."','".$type."')";
echo $sql;
mysql_query($sql);
}
else
{
echo "Katta";
}
echo "yoyoyoyo";
?>

