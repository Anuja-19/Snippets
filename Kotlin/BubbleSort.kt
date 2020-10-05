import java.util.stream.Stream
import kotlin.random.Random

fun bubbleSort(array: IntArray) {
    for (pass in 0 until (array.size - 1)) {
        for (currentPosition in 0 until (array.size - pass - 1)) {
            if (array[currentPosition] > array[currentPosition + 1]) {
                val temp = array[currentPosition]
                array[currentPosition] = array[currentPosition + 1]
                array[currentPosition + 1] = temp
            }
        }
    }
}

fun main() {
    //just generate data
    val random = Random
    val size = 10L
    val maxElement = 100
    val array: IntArray = Stream.generate { random.nextInt(maxElement) }.limit(size).toArray()
            .map { it.toString().toInt() }
            .toIntArray()

    println("Array element before bubble sort : ")
    array.iterator().forEach { print("$it ") }

    bubbleSort(array)

    println("\nArray element after bubble sort : ")
    array.iterator().forEach { print("$it ") }
}