const carrinho = {}
let preco = 0
const produtos = {}

interface Prod {
  id: string,
  valor: number,
  quantidade: number,
}

function add(id: string) {
  if(id in carrinho) {
    carrinho[id].quantidade++
  }

  carrinho[id] = {
    id,
    preco: produtos[id].preco,
    quantidade: 1
  }
}