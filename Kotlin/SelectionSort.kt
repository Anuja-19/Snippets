import java.util.stream.Stream
import kotlin.random.Random

fun selectionSort(array: IntArray) {

    val size = array.size
    var temp : Int

    for(i in size-1 downTo 0){
        var max = i

        for(j in 0 until i){
            if(array[j] > array[max]) max=j
        }

        if(i!=max){
            temp = array[i]
            array[i] = array[max]
            array[max] = temp
        }
    }

}

fun main() {
    //just generate data
    val r = Random
    val size = 10L
    val maxElement = 100
    val array: IntArray = Stream.generate { r.nextInt(maxElement) }.limit(size).toArray()
            .map { it.toString().toInt() }
            .toIntArray()

    println("Array element before selection sort : ")
    array.iterator().forEach { print("$it ") }

    selectionSort(array)

    println("\nArray element after selection sort : ")
    array.iterator().forEach { print("$it ") }
}
