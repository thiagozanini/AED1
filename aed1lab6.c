//  AED 1 - Turma IC  Lab 06 \|
//  Thiago de Azevedo Zanini  RA: 148357

// ##################### Bibliotecas Externas ##############################

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// ########################## TAD X.h ######################################

struct pilha {
  int elementos[50];
  int topo;
};
typedef struct pilha tipoPilha;
tipoPilha pilhaNumeros;

// ###################### Funcoes e Procedimentos do programa ##############

void inicializaPilha(tipoPilha *pilhaAux) {
  int i;
  for (i = 0; i <= 50 - 1; i++)
    pilhaAux->elementos[i] = 0;
  pilhaAux->topo = -1;
}

int push(tipoPilha *pilhaAux, int val) {
  if (pilhaAux->topo >= 50 - 1)
    return -1;
  else {
    pilhaAux->topo++;
    pilhaAux->elementos[pilhaAux->topo] = val;
    return 0;
  }
}
void pop(tipoPilha *pilhaAux) {
  if (pilhaAux->topo == -1)
    return;
  else {
    pilhaAux->elementos[pilhaAux->topo] = 0;
    pilhaAux->topo--;
  }
}

void numDecTrans(tipoPilha *pilhaAux, int dec) {
  int num, vetbin[32], i = 0, j;
  num = dec;
  while (num > 0) {
    vetbin[i] = num % 2;
    i++;
    num = num / 2;
  }
  num = 0;
  long aux = pow(10, i - 1);
  for (j = i - 1; j >= 0; j--) {
    if (vetbin[j] == 0)
      num = num + (1 * aux);
    aux /= 10;
  }
  j = 0;
  i = 0;
  aux = 0;
  while (num != 0) {
    aux = num % 10;
    num /= 10;
    i += aux * pow(2, j);
    ++j;
  }
  push(pilhaAux, i);
  push(pilhaAux, 9999);
}
void numBin(tipoPilha *pilhaAux, int dec) {
  int num, vetbin[32], i = 0, j;
  num = dec;
  while (num > 0) {
    vetbin[i] = num % 2;
    i++;
    num = num / 2;
  }
  num = 0;
  for (j = 0; j < i; j++) {
    if (vetbin[j] == 1)
      push(pilhaAux, 1);
    else
      push(pilhaAux, 0);
  }
  push(pilhaAux, 9999);
}
void numBinTrans(tipoPilha *pilhaAux, int dec) {
  int num, vetbin[20], i = 0, j;
  num = dec;
  while (num > 0) {
    vetbin[i] = num % 2;
    i++;
    num = num / 2;
  }
  num = 0;
  int aux = pow(10, i - 1);
  for (j = 0; j < i; j++) {
    if (vetbin[j] == 1)
      push(pilhaAux, 0);
    else
      push(pilhaAux, 1);
  }
  push(pilhaAux, 9999);
}
void imprime(tipoPilha *pilhaAux) {
  while (pilhaAux->topo != -1) {
    if (pilhaAux->elementos[pilhaAux->topo] == 9999)
      printf(" ");
    else
      printf("%d", pilhaNumeros.elementos[pilhaNumeros.topo]);
    pop(pilhaAux);
  }
  printf("\n");
}
// ############################ Principal ###################################

int main() {
  int L, num;
  inicializaPilha(&pilhaNumeros);
  scanf("%d", &L);
  for (int i = 0; i < L; i++) {
    scanf("%d", &num);
    numDecTrans(&pilhaNumeros, num);
    numBinTrans(&pilhaNumeros, num);
    numBin(&pilhaNumeros, num);
    push(&pilhaNumeros, num);
    imprime(&pilhaNumeros);
    inicializaPilha(&pilhaNumeros);
  }
  return 0;
}