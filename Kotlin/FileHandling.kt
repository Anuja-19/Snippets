import java.io.File

fun readTextFile (filepath: String){
    var file = File(filepath)
    if(file.exists())
        file.forEachLine { println(it) }
    else
        println("$filepath is not exist.")
}

fun createTextFileWithContent (filepath: String, content: String) {
    var file = File(filepath)
    if(file.exists().not()) {
        file.createNewFile()
        println("Creating file: $filepath")
    }  else {
        println("$filepath is already exist!!!")
        println("Replacing existing content.")
    }
    file.writeText(content)

}
fun main() {
    createTextFileWithContent("test.txt", "Test creating text with content.\nTest Test !!!")
    readTextFile("test.txt")

}