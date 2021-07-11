class MinHeap {
  constructor(msize) {
    this.heap = []
    this.heap.length = msize
    this.size = 0
    this.maxsize = msize
  }

  parentIndex(pos) { return Math.floor((pos-1)/2) }
  leftChildIndex(pos) { return 2*pos+1 }
  rightChildIndex(pos) { return 2*pos+2 }

  hasLeftChild(pos) { return this.leftChildIndex(pos) < this.size }
  hasRightChild(pos) { return this.rightChildIndex(pos) < this.size }
  hasParent(pos) { return this.parentIndex(pos) >= 0 }

  leftChild(pos) { return this.heap[this.leftChildIndex(pos)] }
  rightChild(pos) { return this.heap[this.rightChildIndex(pos)] }
  parent(pos) { return this.heap[this.parentIndex(pos)] } 

  swap(idx1, idx2) {
    const aux = this.heap[idx1]
    this.heap[idx1] = this.heap[idx2]
    this.heap[idx2] = aux
  }

  ensureExtraCapacity() {
    if(this.size == this.maxsize) {
      this.maxsize *=2
      this.heap.length *=2  
    }
  }

  peekMin() { return size != 0 && item[0] }

  poll() {
    if(size == 0) return false
    let aux = this.heap[0]
    this.heap[0] = this.heap[size - 1]
    size--
    this.heapfyDown()
    return aux
  }

  add(value) {
    this.ensureExtraCapacity()
    this.heap[this.size] = value
    this.size++
    this.heapfyUp()
  }

  heapfyUp() {
    let index = this.size - 1
    while(this.hasParent(index) && this.parent(index) > this.heap[index]) {
      this.swap(this.parentIndex(index), index)
      index = this.parentIndex(index)
    }
  }

  heapfyDown() {
    let index = 0
    while(this.hasLeftChild(index)) {
      let smallChildIndex = this.leftChildIndex(index)
      if(this.hasRightChild(index) && this.rightChild(index) < this.leftChild(index)) { smallChildIndex = this.rightChildIndex(index) }
      
      if(this.heap[index] < this.heap[smallChildIndex]) { break }
      else { this.swap(index, smallChildIndex) }
      index = smallChildIndex
    }
  }

  printHeap() {
    let aux = 0
    let ans = ''
    while(aux < this.size) {
      ans += this.heap[aux] + " "
      aux++
    }
    return ans
  }
}

let heap = new MinHeap(10)

heap.add(1)
heap.add(3)
heap.add(5)
heap.add(4)
heap.add(2)
heap.add(0)


console.log(heap.printHeap())