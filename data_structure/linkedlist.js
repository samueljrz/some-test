class Node {
  constructor(data) {
    this.data = data
    this.next = null
  }
}

class LinkedList {
  constructor() {
    this.head = null
    this.size = 0
  }

  add(element) {
    let node = new Node(element)
    
    node.next = this.head
    this.head = node
    
    this.size++
  }

  addAt(element, index) {
    if(index < 0 && index > this.size) return console.log("Error")

    let node = new Node(element)
    let prevNode, currNode

    currNode = this.head

    if(index === 0) {
      node.next = this.head
      this.head = node
    } else {
      currNode = this.head
      let it = 0

      while(it < index) {
        it++
        prevNode = currNode
        currNode = currNode.next
      }

      node.next = currNode
      prevNode.next = node
    }

    this.size++
  }

  removeAt(index) {
    if(index < 0 && index > this.size) return console.log("Error")
    
    let prevNode, currNode

    currNode = prevNode = this.head

    if(index === 0) {
      this.head = this.head.next
    } else {
      let it = 0

      while(it < index) {
        it++
        prevNode = currNode
        currNode = currNode.next
      }

      prevNode = currNode.next
    }

    this.size--
    return currNode.data;
  }

  remove(element) {
    let prevNode, currNode

    currNode = this.head
    prevNode = null

    while(currNode != null) {
      if(currNode.data === element) {
        prevNode === null ? this.head = currNode.next : prevNode.next = currNode.next
        this.size--
        return currNode.data
      }
      prevNode = currNode;
      currNode = currNode.next
    }

    return false
  }

  indexOf(element) {
    let count = 0
    let currentNode = this.head

    while(currentNode != null) {
      if(currentNode.data === element) return count
      count++
      currentNode = currentNode.next 
    }

    return false
  }

  isEmpty() {
    if(this.head === null) return true
    return false
  }

  size() {
    return this.size
  }

  printList() {
    let currentNode = this.head
    let ans = ""

    while (currentNode) {
      ans += currentNode.data + " ";
      currentNode = currentNode.next;
    }

    console.log(ans);
  }
}

let list = new LinkedList()

list.add(1)
list.add(2)
list.add(3)

list.printList()

list.remove(2)

list.printList()
