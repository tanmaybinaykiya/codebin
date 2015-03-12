<?php
    header("Content-type: application/vnd.ms-excel");
    header("Content-disposition: attachment; filename=Users_".date("d-m-y").".csv");
    header("Pragma: no-cache");
    header("Expires: 0");
    // print out the cvs file column heads
    echo "ID,Email,Name,Mobile,College\n";
    // get that data!
    foreach ($users as $user) {
        echo '"Q11' . $user['User']['id_no'] . '","' . $user['User']['email'] .'","'. $user['User']['name'] . '","' . $user['User']['mobile'] . '","' . $user['User']['college'] . '"' . "\n";
    }
?>