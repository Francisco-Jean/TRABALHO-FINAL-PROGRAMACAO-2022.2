#include "hash.h"
#include <stdio.h>
#include <stdlib.h>

/*struct data {
  int dia;
  int mes;
  int ano;
};*/

/*struct voo {
  int codigo;
  char *origem;
  char *destino;
};*/

/*struct no_voo {
  Voo *voo;
  struct no_voo *proximo;
};*/

/*struct lista_voo {
  struct no_voo *primeiro;
};*/

/*struct passageiro {
  int id;
  char *nome;
  char *endereco;
};*/

/*struct no_passageiro {
  Passageiro *passageiro;
  struct no_passageiro *proximo;
};*/

/*struct lista_passageiro {
  struct no_passageiro *primeiro;
};*/


/*struct agenda {
  Reserva *reserva;
  Agenda *esq;
  Agenda *dir;
};*/

struct reserva {
  int codigo;
  Data *data_viagem;
  Passageiro *passageiro;
  Voo *voo;
  Assento assento;
};
struct trecho {
  Reserva *reserva;
  struct trecho *proximo;
};

struct viagem {
  struct trecho *trechos;
};

struct tabela_viagem {
  int tamanho;
  Viagem *tabela_hash;
};


//▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬❴FUNÇÕES DE TRECHO ❵▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬//
Trecho *cria_trecho(Reserva *reserva) {
  if(reserva==NULL){
    return NULL;
  }
  Trecho *novoTrecho = (Trecho *)malloc(sizeof(Trecho));
  novoTrecho->reserva = reserva;
  return novoTrecho;
}
  
//▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬❴FUNÇÕES DE TABELA VIAGEM ❵▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬//
// ↓↓ Cria, aloca espaço pra tabela hash e atribui NULO pra cada ponteiro-posição do vetor ↓↓ //
TabelaViagem *cria_tabela(int tamanho) {
  TabelaViagem *novaTabela = (TabelaViagem *)malloc(sizeof(TabelaViagem));
  novaTabela->tamanho = tamanho;
  novaTabela->tabela_hash = (Viagem *)malloc(tamanho * sizeof(Viagem));
  // Atribuindo nulo pra cada posição do vetor pra marcar quando tem conteúdo ou
  // não
  for (int i = 0; i < tamanho; i++) {
    novaTabela->tabela_hash[i].trechos = NULL;
  }
}

TabelaViagem *cria_hash(){
  TabelaViagem *tabela = (TabelaViagem*) malloc(sizeof(TabelaViagem));
  tabela->tamanho = 0;
  tabela->tabela_hash = malloc(sizeof(Viagem) *10);
  return tabela;
}

TabelaViagem *insere_hash(TabelaViagem *tabela,Viagem *tabela_hash){
  if(tabela == NULL && tabela_hash == NULL){
    return NULL;
  }
  tabela->tabela_hash = tabela_hash;
}

//▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬❴FUNÇÕES DE HASH ❵▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬//
int fun_hash(int id, int codigo){
  int pos = id+codigo;
  return pos;
}

