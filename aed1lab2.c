#include <stdio.h>
#include <stdlib.h>
// ########################## TAD X.h ######################################
#define reserva 10

struct info {
  int valor;
  int prox;
};
typedef struct info tipoInfo;

struct listaEE {
  int ultimo;
  int primeiro;
  int tamanhoLista;
  int posLivre[reserva];
  tipoInfo elemento[reserva];
  int ano[8];
};
typedef struct listaEE tipoListaEE;

int i = 0;
void inicializaLista(tipoListaEE *listaAux) {
  listaAux->tamanhoLista = 0;
  listaAux->ultimo = -1;
  listaAux->primeiro = -1;
  for(int i=0; i<8; i++){
    listaAux->ano[i] = 0;
  }
  for (i = 0; i < reserva; i++) {
    listaAux->elemento[i].valor = 0;
    listaAux->elemento[i].prox = -1;
    listaAux->posLivre[i] = 1;
  }
}

int proxPosicaoLivre(tipoListaEE *listaAux) {
  for (i = 0; i < reserva; i++) {
    if (listaAux->posLivre[i] == 1) {
      return i;
    }
  }
  return -1;
}

void insereElemento(tipoListaEE *listaAux, int posicao, int RA) {
  listaAux->elemento[posicao].valor = RA;
  if (listaAux->tamanhoLista == 0) {
    listaAux->primeiro = posicao;

  } else {
    listaAux->elemento[listaAux->ultimo].prox = posicao;
  }
  listaAux->elemento[posicao].prox = -1;
  listaAux->tamanhoLista++;
  listaAux->ultimo = posicao;

  listaAux->posLivre[posicao] = 0;
}

int j = 0;
int posicaoRA(tipoListaEE *listaAux, int RA) {
  for (j = 0; j < reserva; j++) {
    if (listaAux->posLivre[j] == 0) {
      if (listaAux->elemento[j].valor == RA) {
        return j;
      }
    }
  }
  return -1;
}

int k = 0;
int r = 0;
void removeElemento(tipoListaEE *listaAux, int posicao) {
  if (posicao != -1) {
    if (posicao == listaAux->primeiro) {
      listaAux->primeiro = listaAux->elemento[listaAux->primeiro].prox;
    } else {
      if (posicao != listaAux->primeiro && posicao != listaAux->ultimo) {
        for (k = 0; k < reserva; k++) {
          if (listaAux->elemento[k].prox == posicao) {
            listaAux->elemento[k].prox = listaAux->elemento[posicao].prox;
            break;
          }
        }
      } else {
        for (k = 0; k < reserva; k++) {
          if (listaAux->elemento[k].prox == posicao) {
            listaAux->elemento[k].prox = listaAux->elemento[posicao].prox;
            listaAux->ultimo = k;
            break;
          }
        }
      }
    }
    listaAux->tamanhoLista--;
    listaAux->posLivre[posicao] = 1;
    listaAux->elemento[posicao].prox = -1;
    listaAux->elemento[posicao].valor = 0;
  } else {
    printf("nao existe\n");
  }
}

// ###################### Funcoes e Procedimentos do programa ##############

void contaAno(int RA, tipoListaEE *listaAux) {
  if (RA >= 66000 && RA <= 66999) {
    listaAux->ano[0] += 1;
  }
  if (RA >= 76000 && RA <= 76999) {
    listaAux->ano[1] += 1;
  }
  if (RA >= 86000 && RA <= 86999) {
    listaAux->ano[2] += 1;
  }
  if (RA >= 96000 && RA <= 96999) {
    listaAux->ano[3] += 1;
  }
  if (RA >= 106000 && RA <= 106999) {
    listaAux->ano[4] += 1;
  }
  if (RA >= 116000 && RA <= 116999) {
    listaAux->ano[5] += 1;
  }
  if (RA >= 126000 && RA <= 126999) {
    listaAux->ano[6] += 1;
  }
  if (RA >= 136000 && RA <= 136999) {
    listaAux->ano[7] += 1;
  }
}

void imprimeLEE(tipoListaEE *listaAux) {

  int w = 0;
  int s;
  int v[reserva];

  for (s = 0; s < reserva; s++) {
    v[s] = 0;
  }
  if (listaAux->primeiro != -1) {
    v[0] = listaAux->elemento[listaAux->primeiro].valor;
    w = listaAux->elemento[listaAux->primeiro].prox;
    if (w != -1) {
      v[1] = listaAux->elemento[w].valor;
      s = 2;
      while (listaAux->elemento[w].prox != -1) {
        w = listaAux->elemento[w].prox;
        v[s] = listaAux->elemento[w].valor;
        s++;
      }
    }
  }

  int O[reserva];
  int maior, menor;
  int e = 0;
  maior = 0;
  for (s = 0; s < listaAux->tamanhoLista; s++) {
    if (v[s] > v[maior]) {
      maior = s;
    }
  }
  for (e = 0; e < listaAux->tamanhoLista; e++) {
    menor = 0;
    for (s = 0; s < listaAux->tamanhoLista; s++) {
      if (v[s] < v[menor]) {
        menor = s;
      }
      O[e] = v[menor];
    }
    v[menor] = v[maior];
  }

  for (s = 0; s < listaAux->tamanhoLista; s++) {
    printf("%d ", O[s]);
  }
  printf("\n");
}

// ########################### Principal ###################################

int main() {
  int i = 0;
  int MOV = 0;
  int acao = 0;
  int RA = 0;

  tipoListaEE minhaLista;
  inicializaLista(&minhaLista);
  inicializaLista(&minhaLista);
  scanf("%d", &MOV);
  if (MOV > 100 || MOV < 1) {
    scanf("%d", &MOV);
  }

  for (i = 0; i < MOV; i++) {
    scanf("%d %d", &acao, &RA);
    if (acao == 1) {
      int livre = proxPosicaoLivre(&minhaLista);
      if (livre == -1) {
        printf("lista cheia\n");
      } else {
        contaAno(RA, &minhaLista);
        insereElemento(&minhaLista, livre, RA);
      }
    } else {
      int posicao = posicaoRA(&minhaLista, RA);
      removeElemento(&minhaLista, posicao);
    }
    imprimeLEE(&minhaLista);
  }
  int ano=2011;
  for (int i = 0; i < 8; i++) {
    printf("%d: %d\n", minhaLista.ano[i], ano);
    ano++;
  }
  return 0;
}