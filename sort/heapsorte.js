// create max heap
function maxHeap(input, i) {
  const left = 2 * i + 1
  const right = 2 * i + 2

  let max = i

  if (left < arrLength && input[left] > input[max]) {
      max = left
  }

  if (right < arrLength && input[right] > input[max])     {
      max = right
  }

  if (max != i) {
      swap(input, i, max)
      maxHeap(input, max)
  }
}

function swap(input, indexA, indexB) {
  const temp = input[indexA]

  input[indexA] = input[indexB]
  input[indexB] = temp
}

function heapSort(input) {   
  arrLength = input.length

  for (let i = Math.floor(arrLength / 2); i >= 0; i -= 1)      {
      maxHeap(input, i)
    }

  for (i = input.length - 1; i > 0; i--) {
      swap(input, 0, i)
      arrLength--

      maxHeap(input, 0)
  }
  return
}

let arrLength

const list = [4, 2, 3, 1, 5, 10, 2, 0, 1 , 21, 1 ,192, 4, 5, 5, 10 , 9]

const sorted = heapSort(list)

console.log(list)