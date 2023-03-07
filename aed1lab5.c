//  AED 1 - Turma IC  Lab 05
//  Thiago de Azevedo Zanini  RA: 148357
// ##################### Bibliotecas Externas ##############################

#include <stdio.h>
#include <stdlib.h>

// ########################## TAD X.h ######################################

struct filaCircular {
  int primeiro;
  int ultimo;
  int tamanhofila;
  int elementos[100];
};
typedef struct filaCircular tipoFC;
tipoFC filaTarefas;

// ###################### Funcoes e Procedimentos do programa ##############

void inicializaFila(tipoFC *filaAux) {
  filaAux->primeiro = -1;
  filaAux->ultimo = -1;
  filaAux->tamanhofila = 0;
  for (int i = 0; i < 100; i++)
    filaAux->elementos[i] = 0;
}
int filaCheia(tipoFC *filaAux) {
  if (((filaAux->ultimo + 1) % 100) == filaAux->primeiro)
    return 1;
  else
    return 0;
}
int filaVazia(tipoFC *filaAux) {
  if ((filaAux->primeiro == filaAux->ultimo) && (filaAux->ultimo == -1))
    return 1;
  else
    return 0;
}
void insereElemento(tipoFC *filaAux, int info) {
  if (filaVazia(filaAux) == 1) {
    filaAux->primeiro = 0;
    filaAux->ultimo = 0;
    filaAux->elementos[0] = info;
  } else if (filaCheia(filaAux) == 0) {
    int posicao = ((filaAux->ultimo + 1) % 100);
    filaAux->elementos[posicao] = info;
    filaAux->ultimo = posicao;
  }
  filaAux->tamanhofila = filaAux->tamanhofila + 1;
  return;
}
void removeElemento(tipoFC *filaAux) {
  int i = filaAux->primeiro;
  filaAux->elementos[filaAux->primeiro] = 0;
  filaAux->primeiro = ((i + 1) % 100);
  filaAux->tamanhofila = filaAux->tamanhofila - 1;
  return;
}

void concluiElemento(tipoFC *filaAux) {
  int posicao = ((filaAux->ultimo + 1) % 100);
  filaAux->elementos[posicao] = filaAux->elementos[filaAux->primeiro];
  filaAux->ultimo = posicao;
  filaAux->elementos[filaAux->primeiro] = 0;
  filaAux->primeiro = ((filaAux->primeiro + 1) % 100);
  return;
}

void imprimeFila(tipoFC *filaAux) {
  if (filaAux->tamanhofila == 0) {
    printf("vazia\n");
    return;
  }
  if (filaAux->primeiro == filaAux->ultimo) {
    printf("%d\n", filaAux->elementos[filaAux->primeiro]);
    return;
  } else {
    for (int i = filaAux->ultimo;
         i != filaAux->primeiro || filaAux->elementos[i] == 0;
         i = ((i - 1) % 100)) {
      printf("%d ", filaAux->elementos[i]);
    }
    printf("%d\n", filaAux->elementos[filaAux->primeiro]);
    return;
  }
  return;
}
// ############################ Principal ###################################

int main() {
  int L, V, num;
  inicializaFila(&filaTarefas);
  scanf("%d", &L);
  for (int i = 0; i < L; i++) {
    scanf("%d", &V);
    if (V == 1) {
      scanf("%d", &num);
      insereElemento(&filaTarefas, num);
    }
    if (V == 2) {
      if (filaTarefas.tamanhofila == 0)
        printf("vazia\n");
      else {
        removeElemento(&filaTarefas);
      }
    }
    if (V == 3) {
      if (filaTarefas.tamanhofila == 0)
        printf("vazia\n");
      else if (filaTarefas.tamanhofila == 1) {
        NULL;
      } else {
        concluiElemento(&filaTarefas);
      }
    }
    if (filaTarefas.tamanhofila == 0) {
      inicializaFila(&filaTarefas);
    }
  }
  imprimeFila(&filaTarefas);
  return 0;
}