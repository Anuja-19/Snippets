class ReverseLinkedList {
    var head: Node? = null

    class Node(var data: Int, var next: Node? = null)

    /* Function to reverse the linked list */
    fun reverse(node: Node?): Node? {
        var newNode = node
        var prev: Node? = null
        var curr = newNode
        var next: Node?
        while (curr != null) {
            next = curr.next
            curr.next = prev
            prev = curr
            curr = next
        }
        newNode = prev
        return newNode
    }

    // prints content of double linked list
    fun printList(node: Node?) {
        var newNode = node
        while (newNode != null) {
            print(newNode.data.toString() + " ")
            newNode = newNode.next
        }
    }
}

fun main() {
    val list = ReverseLinkedList()
    list.head = ReverseLinkedList.Node(15)
    list.head!!.next = ReverseLinkedList.Node(20)
    list.head!!.next!!.next = ReverseLinkedList.Node(25)
    list.head!!.next!!.next!!.next = ReverseLinkedList.Node(30)
    println("Original Linked list")
    list.printList(list.head)
    list.head = list.reverse(list.head)
    println()
    println("Reversed linked list ")
    list.printList(list.head)
}
