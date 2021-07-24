function binarySearch(a, beg, end, x) {
  if(end >= beg) {
    const mid = Math.floor((beg+end) / 2)
    if(a[mid] == x) return mid
    if(a[mid] > x) return binarySearch(a, beg, mid-1, x)
    return binarySearch(a, mid+1, end, x)
  }
  return -1
}

const c = [1, 2, 4, 6, 8, 20, 40, 51]
const ans = binarySearch(c, 0, c.length-1, 1)
if(ans == -1) {
  console.log("No answer")
}else {
  console.log("answer in index " + ans)
}