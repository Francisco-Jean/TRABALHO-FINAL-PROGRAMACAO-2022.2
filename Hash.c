#include "Hash.h"
#include <stdio.h>
#include <stdlib.h>


struct trecho {
  Reserva *reserva;
  struct trecho *proximo;
};

struct reserva {
  int codigo;
  Data *data_viagem;
  Passageiro *passageiro;
  Voo *voo;
  Assento assento;
};

struct viagem {
  struct trecho *trechos;
};

struct tabela_viagem {
  int tamanho;
  Viagem *tabela_hash;
};

int fun_hash(int id, int codigo){
  int pos = id+codigo;
  return pos;
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
  
}
