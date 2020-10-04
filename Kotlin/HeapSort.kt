
import java.util.stream.Stream
import kotlin.random.Random


private fun buildMaxHeap(array: IntArray) {
    for (i in ((array.size / 2) - 1) downTo 0) {
        maxHeap(array, i)
    }
}

private fun maxHeap(array: IntArray, rootIndex: Int, heapSize: Int = array.size - 1) {
    val leftChildIndex = (2 * rootIndex) + 1
    val rightChildIndex = (2 * rootIndex) + 2
    var largestElementIndex = rootIndex

    if (leftChildIndex <= heapSize && array[leftChildIndex] > array[rootIndex]) {
        largestElementIndex = leftChildIndex
    }

    if (rightChildIndex <= heapSize && array[rightChildIndex] > array[largestElementIndex]) {
        largestElementIndex = rightChildIndex
    }

    if (largestElementIndex != rootIndex) {
        val temp = array[rootIndex]
        array[rootIndex] = array[largestElementIndex]
        array[largestElementIndex] = temp
        maxHeap(array, largestElementIndex, heapSize)
    }
}

fun main() {
    //just generate data
    val r = Random
    val size = 30L
    val maxElement = 500
    val array: IntArray = Stream.generate { r.nextInt(maxElement) }.limit(size).toArray()
            .map { it.toString().toInt() }
            .toIntArray()

    buildMaxHeap(array)

    println("Array element before heap sort : ")
    array.iterator().forEach { print("$it ") }

    for (i in array.size - 1 downTo 1) {
        val temp = array[0]
        array[0] = array[i]
        array[i] = temp
        maxHeap(array, 0, i - 1)
    }

    println("\nArray element after heap sort : ")
    array.iterator().forEach { print("$it ") }
}