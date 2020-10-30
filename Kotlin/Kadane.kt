import java.util.*

fun maxSumSubArray (array: IntArray): Int {
    var local_max = 0
    var global_max = Int.MIN_VALUE
    for (i in array.indices) {
        local_max = maxOf(array[i], array[i] + local_max)
        if(local_max > global_max)
            global_max = local_max;
    }
    return global_max
}

fun main() {
    var array = intArrayOf(2, -1, 4, 5, -4, 1, 2, -3, 5, 4, 1, -5, 3, -4)
    println("Input array: ${Arrays.toString(array)}")
    println("The maximum sum of contiguous subarray is ${maxSumSubArray(array)}.")

    var array2 = intArrayOf(-2, -3, 4, -1, -2, 1, 5, -3)
    println("Input array: ${Arrays.toString(array2)}")
    println("The maximum sum of contiguous  subarray is ${maxSumSubArray(array2)}.")
}