<?php
/*
usage assign $XSPFurl to your icecast url eg:
$XSPFurl = 'http://localhost:8000/stream01.xspf'
CallIcecast($XSPFurl);

and then you need to echo out what you want to see
eg: echo $stream['info']['title']; //this will return the track name.
*/
function CallIcecast($XSPFurl){
$xml = simplexml_load_file($XSPFurl);

$stream['info']['title']= (string) $xml->trackList->track->title;
$stream['info']['loaction'] = (string) $xml->trackList->loaction;
$stream['info']['server_description'] = (string) $xml->trackList->track->annotation;

preg_match_all('/^(.*):(.*)/m', (string) $xml->trackList->track->annotation,$matches);
     if(isset($matches[1]) && isset($matches[2]) && isset($matches[3])){
         $t = array_combine($matches[1], $matches[2], $matches[3]);
         foreach($t as $key => $val){
             $fkey = str_replace(" ", "_",$key);
             $stream['info'][strtolower($fkey)] = trim($val);
             }
         }
     returun $stream;

}
?>