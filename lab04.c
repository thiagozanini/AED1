//  AED 1 - Turma IC  Lab 04 \|
//  Thiago de Azevedo Zanini  RA: 148357
// ##################### Bibliotecas Externas ##############################

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// ########################## TAD X.h ######################################

struct elemento {
  int numero;
  struct elemento *prox;
  struct elemento *ant;
};

typedef struct elemento tipoElemento;

struct estruturaLDDE {
  tipoElemento *primeiro;
  tipoElemento *ultimo;
  int tamanhoLista;
};

typedef struct estruturaLDDE tipoLDDE;
tipoLDDE listaJogo;

// ###################### Funcoes e Procedimentos do programa ##############

void inicializaLista(tipoLDDE *listaAux) {

  listaAux->primeiro = NULL;
  listaAux->ultimo = NULL;
  listaAux->tamanhoLista = 0;
}

void insereElementoFinal(tipoLDDE *listaAux, int num) {
  tipoElemento *novo = malloc(sizeof(tipoElemento));
  novo->numero = num;
  if (listaAux->tamanhoLista == 0) {
    novo->prox = novo;
    novo->ant = novo;
    listaAux->primeiro = novo;
    listaAux->ultimo = novo;
  } else {
    novo->prox = listaAux->primeiro;
    novo->ant = listaAux->ultimo;
    listaAux->ultimo->prox = novo;
    listaAux->ultimo = novo;
    listaAux->primeiro->ant = novo;
  }
  listaAux->tamanhoLista++;
}
void insereDepois(tipoLDDE *listaAux, int posicao, int novo) {
  int cont = 0;
  tipoElemento *aux;
  if (posicao == 0) {
    tipoElemento *novoele = (tipoElemento *)malloc(sizeof(tipoElemento));
    novoele->prox = listaAux->primeiro;
    novoele->ant = listaAux->ultimo;
    listaAux->ultimo->prox = novoele;
    listaAux->primeiro->ant = novoele;
    listaAux->primeiro = novoele;
    novoele->numero = novo;
    return;
  }
  for (tipoElemento *j = listaAux->primeiro; j != listaAux->ultimo;
       j = j->prox) {
    if (cont + 1 == posicao) {
      aux = j;
    }
    if (cont == posicao && j == listaAux->ultimo) {
      tipoElemento *novoele = (tipoElemento *)malloc(sizeof(tipoElemento));
      novoele->prox = listaAux->primeiro;
      novoele->ant = listaAux->ultimo;
      listaAux->ultimo->prox = novoele;
      listaAux->primeiro->ant = novoele;
      listaAux->ultimo = novoele;
      novoele->numero = novo;
      return;
    }
    if (cont == posicao) {
      tipoElemento *novoele = (tipoElemento *)malloc(sizeof(tipoElemento));
      novoele->prox = j->prox;
      novoele->ant = j;
      novoele->prox->ant = novoele;
      j->prox = novoele;
      novoele->numero = novo;
      listaAux->tamanhoLista++;
      break;
    }
    cont++;
  }
}
void checkList(tipoLDDE *listaAux) {
  int aux;
  for (tipoElemento *i = listaAux->primeiro; i != listaAux->ultimo;
       i = i->prox) {
    if (listaAux->tamanhoLista > 2) {
      aux = i->numero + i->ant->numero + i->prox->numero;
      if (aux == 10) {
        i->prox->prox->ant = i->ant->ant;
        i->ant->ant->prox = i->prox->prox;
        if (i == listaAux->primeiro) {
          listaAux->primeiro = i->prox->prox;
        }
        if (i == listaAux->ultimo) {
          listaAux->ultimo = i->ant->ant;
        }
        free(i->ant);
        free(i->prox);
        free(i);
        listaAux->tamanhoLista -= 3;
        if (listaAux->tamanhoLista == 0)
          printf("ganhou\n");
        break;
      }
    }
  }
  for (tipoElemento *i = listaAux->primeiro; i->prox != listaAux->ultimo;
       i = i->prox)
    printf("%d ", i->numero);
  printf("%d\n", listaAux->ultimo->numero);
}

// ############################ Principal ###################################

int main() {
  int P, aux;
  inicializaLista(&listaJogo);
  for (int i = 0; i < 10; i++) {
    scanf("%d", &aux);
    insereElementoFinal(&listaJogo, aux);
  }
  for (int i = 0; i < 5; i++) {
    scanf("%d %d", &aux, &P);
    insereDepois(&listaJogo, P, aux);
    checkList(&listaJogo);
  }
  if (listaJogo.tamanhoLista > 0)
    printf("perdeu\n");
  return 0;
}