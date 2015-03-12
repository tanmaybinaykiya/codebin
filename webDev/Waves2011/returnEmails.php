<?php

// echos all emails

include("connection.php");

$query = "SELECT email FROM `temp_users`";

$result = mysql_query($query);

$emailList = "";

while ($line = mysql_fetch_array($result, MYSQL_ASSOC)) {
    $emailList .= $line['email'] . ";";
}

echo "";
?>