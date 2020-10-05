<?php
include('config.php'); //add mysql connection iformation in conn.php

$affectedrow = 0;
$xml_file_name = "test.xml";

if(file_exists($xml_file_name)){
    $xml_file = simplexml_load_file($xml_file_name) or die ("Error: kan object niet aanmaken (is het xml bestand aanwezig op de server?) ");

    $date_from      = $xml_file->items->date[0]->from;
    $date_until      = $xml_file->items->date[0]->until;
    $food_parts1     = $xml_file->items->food_parts[0]->part1;
    $food_parts2   = $xml_file->items->food_parts[0]->part2;
    $food_parts3     = $xml_file->items->food_parts[0]->part3;
    $food_parts4     = $xml_file->items->food_parts[0]->part4;
    $aler_parts1      = $xml_file->items->aler_part[0]->part1;
    $aler_parts2      = $xml_file->items->aler_part[0]->part2;
    $aler_parts3      = $xml_file->items->aler_part[0]->part3;
    $aler_parts4      = $xml_file->items->alergeen[0]->deel4;


//opalen van data niet in de subtree

    foreach ($xml_file->children() as $row){
        $daymenu_date = $row->daymenu_date;
        $daymenu_logo = $row->daymenu_logo;
        $comments = $row->comments;

        $sql = "INSERT INTO menu(datum_van,datum_tot,dagmenu_datum,dagmenu_logo,onderdeel_cmp1,onderdeel_cmp2,onderdeel_cmp3,alergeen_cmp1,alergeen_cmp2,alergeen_cmp3,opmerkingen) 
            VALUES ('" . $date_from . "','" . $date_until . "','" . $daymenu_date . "','" . $daymenu_logo . "','" . $food_parts1 . "','" . $food_parts2 . "','" . $food_parts3 . "','" . $food_parts4 . "','" . $aler_parts1 . "','" . $aler_parts2 . "','" . $aler_parts3 . "','". $aler_parts4."','".$comments."')";

        $result = mysqli_query($conn, $sql);
        if(! empty($result)){
            $affectedrow ++;
        }else{
            $error_message = mysqli_error($conn) . "\n";
        }
    }
    ?>
<?php
    if($affectedrow > 0){
        $message = $affectedrow . " rows added\n";
        $currdate = date("d-m-y");
        $file = $xml_file_name;
        $filename = $currdate."_".$file;
        if(rename($file,"_PROCESSED/$filename")){
            echo "file hase been moved to the _PROCESSED folder";
        }else{
            echo "file is not moved to the _PROCESSED folder!!";
        }
    }else{
        echo "\n";
        $message = "no rows inserted in mysql";
    }
    echo $message;
}else{
    echo "File does not exisits ($xml_file_name)";
}
