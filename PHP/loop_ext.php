<?php
/*ths wil loop trough your directory you have defined in $files and you will be able to call ite
 *  i have used xml in addition to our xml_parser function 
 * */
$files = glob("_WATCH/*xml");
if(is_array($files)){
    foreach ($files as $filename){
        $xml_file = file_get_contents($filename, FILE_TEXT);
        //proceed program logic

        echo $filename;
    }
}