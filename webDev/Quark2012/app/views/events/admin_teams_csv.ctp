<?php
    header("Content-type: application/vnd.ms-excel");
    header("Content-disposition: attachment; filename=teams_".date("d-m-y").".csv");
    header("Pragma: no-cache");
    header("Expires: 0");
    // print out the cvs file column heads
    echo "team_id_number,name,quark_id_number,email,college,mobile,encrypted_password\n";
    // get that data!
    foreach ($teams as $team) {
        $teamId = $team['id_no'];
        foreach($team['Membership'] as $Membership) {
            if (!isset($userRole) || ($userRole == 'tl' && $Membership['user_role'] == 'creator')) {
                echo '"' . $teamId . '","' . $Membership['User']['name'] . '","Q11' . $Membership['User']['id_no'] . '","' . $Membership['User']['email'] . '","' . $Membership['User']['college'] . '","' . $Membership['User']['mobile'] . '","' . $Membership['User']['password'] . '"' . "\n";
            }
        }
    }
?>