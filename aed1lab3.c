//  AED 1 - Turma IC  Lab 03 \|
//  Thiago de Azevedo Zanini  RA: 148357
// ##################### Bibliotecas Externas ##############################

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// ########################## TAD X.h ######################################

struct elemento {
  int produto;
  int quantidadeProduto;
  float precoProduto, dinheiro;
  struct elemento *prox;
};

typedef struct elemento tipoElemento;

struct listaDE {
  tipoElemento *primeiro;
  tipoElemento *ultimo;
  int tamanhoLista;
};

typedef struct listaDE tipoLDE;

// ###################### Funcoes e Procedimentos do programa ##############

void inicializaLista(tipoLDE *listaAux) {
  listaAux->primeiro = NULL;
  listaAux->ultimo = NULL;
  listaAux->tamanhoLista = 0;
}

void adicionaProduto(tipoLDE *listaAux, int id, int qtd, float preco) {
  if (listaAux->tamanhoLista > 0) {
    for (tipoElemento *i = listaAux->primeiro; i != NULL; i = i->prox) {
      if (i->produto == id) {
        printf("ja existe\n");
        return;
      }
    }
  }
  tipoElemento *novoElem = malloc(sizeof(tipoElemento));
  novoElem->produto = id;
  novoElem->precoProduto = preco;
  novoElem->quantidadeProduto = qtd;
  novoElem->dinheiro = 0;
  if (listaAux->tamanhoLista == 0) {
    novoElem->prox = NULL;
    listaAux->primeiro = novoElem;
    listaAux->ultimo = novoElem;
  } else {
    novoElem->prox = NULL;
    listaAux->ultimo->prox = novoElem;
    listaAux->ultimo = novoElem;
  }
  listaAux->tamanhoLista++;
}

void aumentaQuantidade(tipoLDE *listaAux, int iD, int qtd) {
  if (listaAux->tamanhoLista == 0) {
    printf("nao existe\n");
    return;
  }
  if (listaAux->tamanhoLista == 1 && listaAux->primeiro->produto == iD) {
    listaAux->primeiro->quantidadeProduto += qtd;
    return;
  }
  if (listaAux->tamanhoLista == 1 && listaAux->primeiro->produto != iD) {
    printf("nao existe\n");
    return;
  }
  if (listaAux->tamanhoLista > 1) {
    for (tipoElemento *i = listaAux->primeiro; i != NULL || i->produto == iD;
         i = i->prox) {
      if (i->produto == iD) {
        i->quantidadeProduto += qtd;
        return;
      }
      if (i == listaAux->ultimo && i->produto != iD) {
        printf("nao existe\n");
        return;
      }
    }
  }
}

void compraProduto(tipoLDE *listaAux, int iD) {
  if (listaAux->tamanhoLista == 0) {
    printf("nao existe\n");
    return;
  }
  if (listaAux->tamanhoLista == 1 && listaAux->primeiro->produto == iD &&
      listaAux->primeiro->quantidadeProduto > 0) {
    listaAux->primeiro->quantidadeProduto--;
    listaAux->primeiro->dinheiro += listaAux->primeiro->precoProduto;
    return;
  }
  if (listaAux->tamanhoLista == 1 &&
      (listaAux->primeiro->produto != iD ||
       listaAux->primeiro->quantidadeProduto == 0)) {
    printf("nao existe\n");
    return;
  } if(listaAux->tamanhoLista > 1) {
    for (tipoElemento *i = listaAux->primeiro; i != NULL || i->produto == iD;
         i = i->prox) {
      if (i->produto == iD && i->quantidadeProduto > 0) {
        i->quantidadeProduto--;
        i->dinheiro += i->precoProduto;
        break;
      }
      if (i == listaAux->ultimo && (i->produto != iD ||
          i->produto == iD && i->quantidadeProduto == 0)) {
        printf("nao existe\n");
        break;
      }
    }
  }
  return;
}
tipoElemento *getProductById(tipoLDE *store, int id) {
  tipoElemento *curr = store->primeiro;
  while (curr != NULL && curr->produto != id)
    curr = curr->prox;
  return curr;
}

void excluiProduto(tipoLDE *listaAux, int iD) {
  if (listaAux->primeiro->produto == iD){
    free(listaAux->primeiro);
    listaAux->primeiro = listaAux->primeiro->prox;
    listaAux->tamanhoLista--;
    if(listaAux->tamanhoLista == 0)
      inicializaLista(listaAux);
    return;
  }
  tipoElemento *curr = getProductById(listaAux, iD);
  if (curr == NULL) {
    printf("nao existe\n");
    return;
  }
  tipoElemento *prev = listaAux->primeiro;
  while (prev->prox != curr)
    prev = prev->prox;

  prev->prox = curr->prox;
  if (listaAux->primeiro == curr)
    listaAux->primeiro = prev;
  if (listaAux->ultimo == curr)
    listaAux->ultimo = prev;
  free(curr);
  listaAux->tamanhoLista--;
  return;
}

void ordena(tipoLDE *listaAux) {
  tipoElemento *current = listaAux->primeiro, *index = NULL;
  int temp;
  if (listaAux->primeiro == NULL) {
    return;
  } else {
    while (current != NULL) {
      index = current->prox;
      while (index != NULL) {
        if (current->precoProduto < index->precoProduto) {
          temp = current->precoProduto;
          current->precoProduto = index->precoProduto;
          index->precoProduto = temp;
          temp = current->produto;
          current->produto = index->produto;
          index->produto = temp;
          temp = current->dinheiro;
          current->dinheiro = index->dinheiro;
          index->dinheiro = temp;
        }
        index = index->prox;
      }
      current = current->prox;
    }
  }
  return;
}

void imprime(tipoLDE *listaAux) {
  if (listaAux->tamanhoLista == 0)
    return;
  for (tipoElemento *i = listaAux->primeiro; i != listaAux->ultimo;
       i = i->prox) {
    printf("%d %f\n", i->produto, i->dinheiro);
  }
  printf("%d %f\n", listaAux->ultimo->produto, listaAux->ultimo->dinheiro);
  return;
}

// ############################ Principal ###################################

int main() {
  tipoLDE listaProdutos;
  int L, P, id, qtd;
  float preco;
  scanf("%d", &L);
  if (L > 100 || L < 1)
    return 0;
  inicializaLista(&listaProdutos);
  for (int i = 0; i < L; i++) {
    scanf("%d %d", &P, &id);
    if (P == 1) {
      scanf("%d %f", &qtd, &preco);
      adicionaProduto(&listaProdutos, id, qtd, preco);
    }
    if (P == 2) {
      scanf("%d", &qtd);
      aumentaQuantidade(&listaProdutos, id, qtd);
    }
    if (P == 3) {
      compraProduto(&listaProdutos, id);
    }
    if (P == 4) {
      excluiProduto(&listaProdutos, id);
    }
  }
  ordena(&listaProdutos);
  imprime(&listaProdutos);
  return 0;
}