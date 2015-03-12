<?php
    header("Content-type: application/vnd.ms-excel");
    header("Content-disposition: attachment; filename=accommodations_".date("d-m-y").".csv");
    header("Pragma: no-cache");
    header("Expires: 0");
    // print out the cvs file column heads
    echo "Team ID,Team Leader email, Team Leader Name,Quark IDS,Number of boys,Number of girls,Time in,Time out,Contact number,Alternate contact number,Uploaded files,Approval,Events,Workshops\n";
    // get that data!
    
    
    foreach ($accommodations as $accommodation) {
         $uploadedfiles = listFilesInDir('../../app/webroot/proofs','A'.$accommodation['User']['id_no']);
        $quark_ids = json_decode($accommodation['Accommodation']['quark_ids']);
        echo '"A' . $accommodation['User']['id_no'] . '","'.$accommodation['User']['email']. '","'.$accommodation['User']['name']. '","';
        foreach($quark_ids as $quark_id)
        {
            echo $quark_id.";";
        }
        echo '","' . $accommodation['Accommodation']['numboys'] . '","' . $accommodation['Accommodation']['numgirls'] . '","' . $accommodation['Accommodation']['time_in'] . '","' . $accommodation['Accommodation']['time_out'] . '","' . $accommodation['Accommodation']['contact_no'] . '","' . $accommodation['Accommodation']['alternate_contact_no'] . '","';
        foreach($uploadedfiles as $file)
        {
            echo $file.";";
        }
        echo '","'.$accommodation['Accommodation']['approval'].'","';
        $events = json_decode($accommodation['Accommodation']['events']);
        $workshops = json_decode($accommodation['Accommodation']['workshops']);
        foreach($events as $event)
        {
            echo $event.";";
        }
        echo '","';
        foreach($workshops as $workshop)
        {
            echo $workshop.";";
        }
        echo '"' . "\n";
    }
    
    function listFilesInDir($start_dir,$prefix)
    {

            /*
            returns an array of files in $start_dir (not recursive)
            */

            $files = array();
            $dir = opendir($start_dir);
            while(($myfile = readdir($dir)) !== false)
                    {
                            if($myfile != '.' && $myfile != '..' && !is_file($myfile) && $myfile != 'resource.frk' && !eregi('^Icon',$myfile) )
                            {
                                            if(strpos($myfile,$prefix)!==false)
                                            {
                                                    $extractedname = substr($myfile,strlen($prefix));
                                                    if($extractedname[0] == '_')
                                                    $files[] = $myfile;
                                            }
                            }
                    }
            closedir($dir);
            return $files;
    }
?>