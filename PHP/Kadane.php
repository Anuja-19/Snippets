<?php
/**
 * Implementation of Kadane's algorithm in PHP
 * Execute this file whith: php -f Kadane.php
 * 
 * Kadane's algorithm - Maximum Sum Subarray:
 *      Given an array of integers, find the maximun possible sum you can get from one of its contiguous subarrays.
 *      The subarray from which this sum comes must contain at least one element.
 * Example:
 *      For $inputArray = [-2, 2, 5, -11, 6], the output should be kadane($array) = 7.
 * 
 * @author juanmagutierrez
 */

/**
 * Implementation of Kadane's algorithm using brute force
 * @param array $array of integers
 * @return int
 */
function brute_force_kadane(array $array) : int {
    $max_sum = $array[0];
    
    for ($i=0; $i < count($array); $i++) {
        $current_sum = $array[$i];
        
        for ($j=$i+1; $j < count($array); $j++) {
            
            $current_sum = maximum($array[$j], $current_sum + $array[$j]);
            
            $max_sum = maximum($max_sum, $current_sum);
            
            echo "(max_sum: $max_sum) current_sum: ".$current_sum." \n";  
        }
    }
    
    return $max_sum;
}

/**
 * Implementation of Kadane's algorithm traversing given array just once
 * @param array $array
 * @return int
 */
function improved_kadane(array $array) : int {
    $max_sum = $array[0];
    $current_sum = $array[0];
    
    for ($i=0; $i < count($array); $i++) {
        if ($i==0) {
            continue;
        }
        $current_sum = maximum($current_sum + $array[$i], $array[$i]);
        
        $max_sum = maximum($max_sum, $current_sum);
        
        echo "(max_sum: $max_sum) current_sum: ".$current_sum." \n";
    }
    
    return $max_sum;
}

/**
 * This method compares both integers and returns the greatest one
 * @param int $a
 * @param int $b
 * @return int
 */
function maximum(int $a, int $b) : int {
    if ($a >= $b) {
        return $a;
    } else {
        return $b;
    }     
}


echo "---------Kadane's Algorithm Test: ---------\n\n";

$array = array(-2, 2, 5, -11, 6);

echo "Brute Force Kadane([-2, 2, 5, -11, 6]): \n\n";
echo "\nResult: ".brute_force_kadane($array);
echo "\n-------------------------------------------\n\n";

echo "Improved Kadane([-2, 2, 5, -11, 6]): \n\n";
echo "\nResult: ".improved_kadane($array);
echo "\n-------------------------------------------\n\n";
?>