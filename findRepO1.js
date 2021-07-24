function findRep(x, n) {
  let ant = 0
  let prox = x[ant] % n 
  
  while(ant != prox) {
    if(ant == x[prox] % n) break;
    ant = prox
    prox = x[ant] % n
  }
  return x[prox]
}

const a = [1,4,3,2,5,5]

console.log(findRep(a, a.length))