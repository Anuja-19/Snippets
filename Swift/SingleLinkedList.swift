//
//  SingleLinkedList.swift
//  Hacktoberfest
//
//  Created by Dipankar Goswami on 03/10/20.
//

import Foundation

class LinkedListNode {
    var data: Int
    var link: LinkedListNode?
    init(data: Int) {
        self.data = data
    }
}

class LinkedList {
    var head: LinkedListNode?
    
    func insertNodeAtEnd(data: Int) {
        let node = LinkedListNode(data: data)
        if var temp = head {
            while temp.link != nil {
                temp = temp.link!
            }
            temp.link = node
        } else {
            head = node
        }
    }
 
    func insertNodeAtBegin(data: Int) {
        let node = LinkedListNode(data: data)
        node.link = head
        head = node
    }

    func insertNodeAtPosn(data: Int, pos: Int) {
        if pos < 1 {
            return
        } else if pos == 1 {
            return insertNodeAtBegin(data: data)
        }

        let node = LinkedListNode(data: data)

        var tmp = head
        var counter = 1
        while counter < pos - 1, let _ = tmp?.link {
            if let _ = tmp {
                tmp = tmp?.link
            }
            counter += 1
        }
        
        node.link = tmp?.link
        tmp?.link = node
    }

    func deleteNodeAtEnd() {
        var temp = head
        var predNode: LinkedListNode?
        while let _ = temp?.link {
            predNode = temp
            temp = temp!.link
        }
        temp = nil
        if let _ = predNode {
            predNode?.link = nil
        } else {
            head = nil
        }
    }
 
    func deleteNodeAtBegin() {
        if let _ = head {
            let tmp = head?.link
            head = nil
            head = tmp
        }
    }

    func deleteNodeAtPosn(pos: Int) {
        if pos < 1 {
            return
        } else if pos == 1 {
            return deleteNodeAtBegin()
        }

        var tmp = head
        var counter = 1
        while counter < pos - 1, let _ = tmp?.link {
            if let _ = tmp {
                tmp = tmp?.link
            }
            counter += 1
        }
        
        let nextNode = tmp?.link?.link
        tmp?.link = nil
        tmp?.link = nextNode
    }

    func printList() {
        var temp = head
        while let _ = temp {
            print("\(temp!.data) -> ", terminator: "")
            temp = temp!.link
        }
        print()
    }
}

var l = LinkedList()

print("""
    Please Find the supported operations -
    1. Insert a new Node at the end
    2. Insert a new Node at the beginning
    3. Insert a new node at specific position
    4. Delete the first node
    5. Delete the last node
    6. Delete node at a specific position
    7. Print the list
    8. Exit
    """)

print("Enter your choice : ")
var ch = Int(readLine()!)!

while ch != 8 {
    switch ch {
    case 1:
        print("Enter the value of the node you want to insert: ")
        let data = Int(readLine()!)!
        l.insertNodeAtEnd(data: data)
    case 2:
        print("Enter the value of the node you want to insert: ")
        let data = Int(readLine()!)!
        l.insertNodeAtBegin(data: data)
    case 3:
        print("Enter the value of the node, followed by position you want to insert: ")
        let data = Int(readLine()!)!
        let pos = Int(readLine()!)!
        l.insertNodeAtPosn(data: data, pos: pos)
    case 4:
        l.deleteNodeAtBegin()
    case 5:
        l.deleteNodeAtEnd()
    case 6:
        print("Enter the position of the node you want to delete: ")
        let pos = Int(readLine()!)!
        l.deleteNodeAtPosn(pos: pos)
    case 7:
        l.printList()
    case 8:
        break
    default:
        print("Invalid option !!!")
    }
    print("Enter your choice : ")
    ch = Int(readLine()!)!
}

