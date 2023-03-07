//  AED 1 - Turma IC  Lab 01
//  Thiago de Azevedo Zanini  RA: 148357

// ##################### Bibliotecas Externas ##############################

#include <stdio.h>
#include <stdlib.h>

// ########################## TAD X.h ######################################

typedef struct{
  int ultimo;
  int contador[2];
  int lista[11];
} tipoLista;
tipoLista listaLivro;

// ###################### Funcoes e Procedimentos do programa ##############

void zeralista(int lista[]) {
  for (int k = 0; k < 10; k++) {
    lista[k] = 0;
  }
}

void movimentacaoLivros(int livro, int movimentacao, int i) {
  if (movimentacao == 1) {
    for (int j = 0; j < 11; j++) {
      if (listaLivro.lista[j] == 0 && j != 10) {
        listaLivro.lista[j] = livro;
        listaLivro.contador[0] += 1;
        printf("Sua reserva foi realizada\n");
        return;
      }
      else if(listaLivro.lista[j] != 0 && j == 9){
        printf("Lista de reserva cheia\n");
        return;
        }
    }
  }
  if (movimentacao == 2){
    for (int j = 0; j < 10; j++){
      if(listaLivro.lista[j] == livro){
        printf("O livro foi retirado com sucesso\n");
        listaLivro.lista[j] = 0;
        listaLivro.contador[1] += 1;
        return;
      }
      else if (listaLivro.lista[j] != livro && j == 9){
        printf("Voce nao possui reserva desse livro\n");
        return;
      }
    }
  }
}

// ############################ Principal ###################################

int main() {
  int L, N, Movimenta;
  scanf("%d", &L);
  zeralista(listaLivro.lista);
  listaLivro.contador[0] = 0;
  listaLivro.contador[1] = 0;
  if (L > 100 || L < 1)
    return 0;
  for (int i = 0; i < L; i++) {
    scanf("%d %d", &Movimenta, &N);
    movimentacaoLivros(N, Movimenta, i);
  }
  printf("Voce realizou %d reservas e %d retiradas\n", listaLivro.contador[0], listaLivro.contador[1]);
  return 0;
}