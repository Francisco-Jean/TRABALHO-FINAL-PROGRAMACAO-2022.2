#include "hash.h"
#include "Passageiros.h"
#include "Voos.h"
#include <stdio.h>
#include <stdlib.h>

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

//▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬❴FUNÇÕES DE VIAGEM ❵▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬//
Viagem *criar_viagem() {
  Viagem *viagem = (Viagem *)malloc(sizeof(Viagem));
  viagem->trechos = NULL;

  return viagem;
}

void remover_viagem(Viagem **viagem) {
  if (viagem != NULL) {
    free(*viagem);
    *viagem = NULL;
  }
}

//▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬❴FUNÇÕES DE TRECHO ❵▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬//
Trecho *cria_trecho(Reserva *reserva) {
  if (reserva == NULL) {
    return NULL;
  }
  Trecho *novoTrecho = (Trecho *)malloc(sizeof(Trecho));
  novoTrecho->reserva = reserva;
  novoTrecho->proximo = NULL;

  return novoTrecho;
}

// Insere o trecho na última posição da lista encadeada de trechos de uma Viagem
// Retorna 1 se sucesso na inserção; 0, caso contrário.
int insere_trecho(Viagem *viagem, Trecho *novoTrecho) {
  if(viagem == NULL || novoTrecho == NULL) {
    return 0;
  }

  // não há nenhum trecho na viagem ainda
  if(viagem->trechos == NULL) {
    viagem->trechos = novoTrecho;
    return 1;
  }

  // se já há algum trecho na viagem
  Trecho trechoAtual = viagem->trechos;
  // procura o último trecho da viagem (prox == NULL)
  while(trechoAtual->prox != NULL) {
    trechoAtual = trechoAtual->proximo;
  }
  if(verifica_trecho(trechoAtual, novoTrecho) == 1) {
    trechoAtual->proximo = novoTrecho;
    return 1;
  }

  return 0;
}

// Se for possível inserir trechoDestino após trechoOrigem, retorna 1; retorna 0, caso contrário.
int verifica_trecho(Trecho *trechoOrigem, Trecho *trechoDestino) {
  //if ((trechoOrigem->reserva->voo->origem =trechoDestino) && (data_compara(trechoOrigem->reserva->data_viagem,trechoDestino->reserva->data_viagem)==-1)) && (trecho1->reserva)

  if(trechoOrigem == NULL || trechoDestino == NULL) {
    return 0;
  }

  // a data do trecho de destino deve ser maior que a data do trecho de origem
  if(data_compara(trechoOrigem->reserva->data_viagem, trechoDestino->reserva->dataViagem) != -1) {
    printf("ERRO: a data do trecho de destino deve ser maior que a data do trecho de origem!\n");
    return 0;
  }

  // o passageiro do trecho de destino deve ser o mesmo do trecho de origem
  if(passageiroIgual(trechoDestino->reserva->passageiro, trechoOrigem->reserva->passageiro) != 1) {
    printf("ERRO: o passageiro do trecho de destino deve ser o mesmo do trecho de origem!\n");
    return 0;
  }

  // o destino do voo do trecho de origem deve ser a origem do voo do trecho de destino
  if(verificaSequenciaVoos(trechoOrigem->voo, trechoDestino->voo) != 1) {
    printf("ERRO: o destino do voo do trecho de origem deve coincidir com a orugem do voo do trecho de destino!\n");
    return 0;
  }

  return 1;
} 
//▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬❴FUNÇÕES DE TABELA VIAGEM ❵▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬//
// ↓↓ Cria, aloca espaço pra tabela hash e atribui NULO pra cada
// ponteiro-posição do vetor ↓↓ //
TabelaViagem *cria_tabela_hash(int tamanho) {
  TabelaViagem *novaTabela = (TabelaViagem *)malloc(sizeof(TabelaViagem));
  novaTabela->tamanho = tamanho;
  novaTabela->tabela_hash = (Viagem *)malloc(tamanho * sizeof(Viagem));

  // Atribuindo nulo pra cada posição do vetor pra marcar quando tem conteúdo ou não
  for (int i = 0; i < tamanho; i++) {
    (&(novaTabela->tabela_hash))[i] = NULL;
  }

  return novaTabela;
}

int insere_hash(TabelaViagem *tabela, Viagem *viagem) {
  if (tabela == NULL && viagem == NULL) {
    return 0;
  }

  int cod = funcao_hash(viagem);

  if((&(tabela -> tabela_hash))[cod] == NULL){
   (&(tabela -> tabela_hash))[cod] = viagem;
    return 1;
  }
  return 0;
}

Viagem* busca_hash(TabelaViagem* tabela, int cod) {
  if (tabela == NULL || cod < 0) {
    return NULL;
  }
  
  if((&(tabela->tabela_hash))[cod] != NULL){
    return &(tabela->tabela_hash[cod]);
  }
  return NULL;
} 

Viagem* retira_hash(TabelaViagem* tabela, int cod){
  if (tabela == NULL || cod < 0) {
    return NULL;
  }
  
  Viagem* aux;
  if ((&(tabela->tabela_hash))[cod] != NULL) {
    aux = (&(tabela->tabela_hash))[cod];
    (&(tabela->tabela_hash))[cod] = NULL;
  } else{
    return NULL;
  }
  
  return aux;
}

//▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬❴FUNÇÕES DE HASH ❵▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬//
int funcao_hash(Viagem *viagem) {
  int soma = 0, id;
  char nome[30], endereco[30];

  Trecho *aux = viagem->trechos;

  while (aux->proximo != NULL) {
    soma += aux->reserva->codigo;
    aux = aux->proximo;
  }

  passageiroAcessa(aux->reserva->passageiro, &id, nome, endereco);

  soma += aux->reserva->codigo;
  soma += id;

  return soma;
}
