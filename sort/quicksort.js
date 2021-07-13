function quicksort(vec, ini=0, fim=vec.length-1) {
  if(ini < fim) {
    let pivo = partition(vec, ini, fim)
    quicksort(vec, ini, pivo-1)
    quicksort(vec, pivo+1, fim)
  }
}

function partition(vec, ini, fim) {
  const pivo = vec[fim]
  let aux = ini
  for(let i=ini; i<fim; i++) {
    if(vec[i] <= pivo) {
      swap(vec, i, aux)
      aux++
    }
  }
  swap(vec, aux, fim)
  return aux
}

function swap(vec, idx1, idx2) {
  const aux = vec[idx1]
  vec[idx1] = vec[idx2]
  vec[idx2] = aux 
}

let a = [1, 2, 3, 4, 5, 6]
let b = [6, 5, 4, 3, 2, 1, 7]
let c = [1, 1, 2, 3, 4, 4, 5, 6, 7, 10, 20, 1, 0, 23]

quicksort(b)

console.log(b)