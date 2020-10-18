<?php
$num = array(10, 1, 3, 4, 9, 7, 2, 5, 8);

var_dump($num);

for($i=0;$i<count($num)-1;$i++) {
  for($j=$i+1;$j$num[$j]) {
      $temp = $num[$i];
      $num[$i] = $num[$j];
      $num[$j] = $temp;
    }
  }
}

var_dump($num);