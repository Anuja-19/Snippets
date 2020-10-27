fun insertionSort(array: IntArray) {
    for (i in array.indices) {
        val tmp = array[i]
        var j = i
        while(j > 0 && array[j-1] > tmp){
            array[j] = array[j-1]
            j -= 1
        }
        array[j] = tmp
    }
}

fun main() {
    var input = intArrayOf(42,27,5,7,0,15,2,99,1)
    print("Original list: ")
    input.iterator().forEach { print("$it ") }
    println()
    print("Sorted list: ")
    insertionSort(input)
    input.iterator().forEach { print("$it ") }
}