#include "hash.h"
#include "Passageiros.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int remover_viagem(Viagem **viagem) {
  if (viagem != NULL) {
    if ((*viagem)->trechos != NULL) {
      Trecho *aux = (*viagem)->trechos;
      do {
        libera_reserva(&aux->reserva);
        aux = aux->proximo;
      } while (aux != NULL);
    }
    free(*viagem);
    *viagem = NULL;
    return 1;
  }
  return 0;
}

Reserva *viagem_busca(Viagem *viagem, int codigo) {
  if (viagem != NULL && viagem->trechos != NULL && codigo >= 0) {

    Trecho *x = viagem->trechos;
    int codigo_aux;
    Data *data;
    Passageiro *passageiro;
    Voo *voo;
    Assento assento;
    do {
      reserva_acessa(x->reserva, &codigo_aux, &data, &passageiro, &voo, &assento);
      if (codigo == codigo_aux) {
        return x->reserva;
      }
      x = x->proximo;
    } while (x != NULL);
  }
  return NULL;
}

int viagem_insere(Viagem *viagem, Reserva *reserva) {
  if (viagem == NULL || reserva == NULL) {
    return -1;
  }
  if (viagem->trechos != NULL) {
    int codigo;
    Data *data;
    Passageiro *passageiro;
    Voo *voo;
    Assento assento;
    reserva_acessa(reserva, &codigo, &data, &passageiro, &voo, &assento);
    Reserva *aux = viagem_busca(viagem, codigo);

    if (aux != NULL) {
      return 0;
    }

    Trecho *trecho_novo = cria_trecho(reserva);

    Trecho *trecho_aux = viagem->trechos;
    while (trecho_aux->proximo != NULL) {
      trecho_aux = trecho_aux->proximo;
    }
    if (trecho_valido(trecho_aux, trecho_novo) == 1) {
      trecho_aux->proximo = trecho_novo;
      return 1;
    }
  } else if (viagem->trechos == NULL) {
    Trecho *trecho_novo = cria_trecho(reserva);
    viagem->trechos = trecho_novo;
    return 1;
  }
  return 0;
}

int viagem_vazia(Viagem *viagem) {
  if (viagem == NULL) {
    return -1;
  }
  if (viagem->trechos == NULL) {
    return 1;
  }
  return 0;
}

Trecho *primeiro(Viagem *viagem) {
  if (viagem == NULL || viagem->trechos == NULL) {
    return NULL;
  }
  return viagem->trechos;
}

Trecho *viagem_retira(Viagem *viagem) {
  if (viagem == NULL || viagem->trechos == NULL) {
    return NULL;
  }
  Trecho *primeiro_trecho_aux = viagem->trechos;
  viagem->trechos = viagem->trechos->proximo;

  return primeiro_trecho_aux;
}


//▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬❴FUNÇÕES DE TABELA VIAGEM ❵▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬//
// ↓↓ Cria, aloca espaço pra tabela hash e atribui NULO pra cada
// ponteiro-posição do vetor ↓↓ //
TabelaViagem *cria_tabela_hash(int tamanho) {
  if (tamanho <= 0) {
    return NULL;
  }
  
  TabelaViagem *novaTabela = (TabelaViagem *)malloc(sizeof(TabelaViagem));
  novaTabela->tamanho = tamanho;
  novaTabela->tabela_hash = (Viagem *)malloc(tamanho * sizeof(Viagem));

  // Atribuindo nulo pra cada posição do vetor pra marcar quando tem conteúdo ou não
  for (int i = 0; i < tamanho; i++) {
    (&(novaTabela->tabela_hash))[i] = NULL;
  }

  return novaTabela;
}

int tamanho_hash(TabelaViagem *tabela) { 
  return tabela->tamanho; 
}

int insere_hash(TabelaViagem *tabela, Viagem *viagem) {
  if (tabela == NULL && viagem == NULL) {
    return 0;
  }

  int cod = funcao_hash(viagem, cod_hash);

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
int cod_hash(Viagem *viagem) {
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

int funcao_hash(TabelaViagem *tabela, int codigoHash) {
  return codigoHash % tabela->tamanho;
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
  Trecho *trechoAtual = viagem->trechos;
  // procura o último trecho da viagem (prox == NULL)
  while(trechoAtual->proximo != NULL) {
    trechoAtual = trechoAtual->proximo;
  }
  if(verifica_trecho(trechoAtual, novoTrecho) == 1) {
    trechoAtual->proximo = novoTrecho;
    return 1;
  }

  return 0;
}

int libera_trecho(Trecho **trecho) {
  if (trecho == NULL) {
    return 0;
  }

  free(*trecho);
  trecho = NULL;
  return 1;
};

int trechoAcessa(Trecho *trecho, Reserva *reserva, Trecho *proximo_trecho) {
  if (trecho == NULL) {
    return 0;
  }

  Reserva **reserva_aux = &(reserva);
  Trecho **trecho_aux = &(proximo_trecho);

  *reserva_aux = trecho->reserva;
  *trecho_aux = trecho->proximo;

  return 1;
};

int trecho_atribui(Trecho *trecho, Reserva *nova_reserva,Trecho *novo_proximo_trecho) {
  if (trecho == NULL || nova_reserva == NULL || novo_proximo_trecho == NULL) {
    return 0;
  };

  Reserva **reserva_aux = &(trecho->reserva);
  Trecho **trecho_aux = &(trecho->proximo);

  *reserva_aux = nova_reserva;
  if (trecho_valido(trecho, novo_proximo_trecho) == 1) {
    *trecho_aux = novo_proximo_trecho;
  } else {
    *trecho_aux = NULL;
  }
  return 1;
};

int trecho_igual(Trecho *trecho1, Trecho *trecho2) {
  if (trecho1 == NULL || trecho2 == NULL) {
    return -1;
  }

  int igual = reserva_igual(trecho1->reserva, trecho2->reserva);
  return igual;
}

// Se for possível inserir trecho_destino após trecho_origem, retorna 1; retorna 0, caso contrário.
int verifica_trecho(Trecho *trecho_origem, Trecho *trecho_destino) {
  //if ((trecho_origem->reserva->voo->origem =trecho_destino) && (data_compara(trecho_origem->reserva->data_viagem,trecho_destino->reserva->data_viagem)==-1)) && (trecho1->reserva)

  if(trecho_origem == NULL || trecho_destino == NULL) {
    return 0;
  }
  int codigo1;Data *data_viagem1;Passageiro *passageiro1;Voo *voo1;Assento assento1;
  reserva_acessa(trecho_origem->reserva,&codigo1,&data_viagem1,&passageiro1,&voo1,&assento1);
  int codigo2;Data *data_viagem2;Passageiro *passageiro2;Voo *voo2;Assento assento2;
  reserva_acessa(trecho_destino->reserva,&codigo2,&data_viagem2,&passageiro2,&voo2,&assento2);
  // a data do trecho de destino deve ser maior que a data do trecho de origem
  if(data_compara(data_viagem1, data_viagem2) != -1) {
    return 0;
  }

  // o passageiro do trecho de destino deve ser o mesmo do trecho de origem
  if(passageiroIgual(passageiro1, passageiro2) != 1) {
    return 0;
  }

  // o destino do voo do trecho de origem deve ser a origem do voo do trecho de destino
  if(verificaSequenciaVoos(voo1, voo2) != 1) {
    return 0;
  }

  return 1;
} 

int trecho_valido(Trecho *trecho_origem, Trecho *trecho_destino) {

  int codigo_trecho_origem;
  Data *data_trecho_origem;
  Passageiro *passageiro_trecho_origem;
  Voo *voo_trecho_origem;
  Assento assento_trecho_origem;

  int cd_trecho_destino;
  Data *dt_trecho_destino;
  Passageiro *pas_trecho_destino;
  Voo *voo_trecho_destino;
  Assento assento_trecho_destino;

  reserva_acessa(trecho_origem->reserva, &(codigo_trecho_origem),
                 &(data_trecho_origem), &(passageiro_trecho_origem),
                 &(voo_trecho_origem), &(assento_trecho_origem));
  reserva_acessa(trecho_destino->reserva, &(cd_trecho_destino),
                 &(dt_trecho_destino), &(pas_trecho_destino),
                 &(voo_trecho_destino), &(assento_trecho_destino));

  if (data(data_trecho_origem) < data(dt_trecho_destino)) {
    int id1;char nome1[30];char endereco1[30];int id2;char nome2[30];char endereco2[30];
    passageiroAcessa(passageiro_trecho_origem,&id1,nome1,endereco1);
    passageiroAcessa(pas_trecho_destino,&id2,nome2,endereco2);
    if (id1 == id2) {
      int codigo1;char origem1[30];char destino1[30];int codigo2;char origem2[30];char destino2[30];
      vooAcessa(voo_trecho_origem,&codigo1,origem1,destino1);
      vooAcessa(voo_trecho_destino,&codigo2,origem2,destino2);
      if (strcmp(destino1,origem2) == 0) {
        return 1;
      }
    }
  }
  return 0;
}

//▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬❴FUNÇÕES DE IMPRIMIR ❵▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬//
void imprimir_viagem(TabelaViagem *tabela, int indice) {

  Trecho *aux = (&(tabela->tabela_hash))[indice]->trechos;
  int ordem = 1;
  printf("\tITINERÁRIO DA VIAGEM:\n");
  int id; char nome[30];char endereco[30];
  int codigo; char origem[30];char destino[30];
  passageiroAcessa(aux->reserva->passageiro, &id, nome, endereco);
  vooAcessa(aux->reserva->voo, &codigo, origem, destino);
  printf("Nome do passageiro: %s\n", nome);
  printf("Id do passageiro: %d\n", id);
  printf("Endereço do passageiro: %s\n", endereco);
  while (aux != NULL) {
    int id; char nome[30];char endereco[30];
    int codigo; char origem[30];char destino[30];
    passageiroAcessa(aux->reserva->passageiro, &id, nome, endereco);
    vooAcessa(aux->reserva->voo, &codigo, origem, destino);
    printf("-----------------------------------------------\n");
    printf("\t Reserva %d\n", ordem);
    printf("Codigo da reserva: %d\n", aux->reserva->codigo);
    printa_data(aux->reserva->data_viagem);
    printf("Origem do voo: %s\n", origem);
    printf("Destino do voo: %s\n", destino);
    printf("Codigo do Voo: %d\n", codigo);
    printa_assento(aux->reserva->assento);
    ordem++;
    aux = aux->proximo;
  }
}

void printa_data(Data *data) {
  if(data==NULL){
    printf("Data da viagem inconsistente");
  }
  int dia1, mes1, ano1;
  int dia2, mes2, ano2;
  data_acessa(data,&dia1,&mes1,&ano1);
  
  dia2 = dia1;
  mes2 = mes1;
  ano2 = ano1;

  printf("Data da viagem: %d/%d/%d\n", dia2, mes2, ano2);
}

void printa_assento(int assento) {
  if (assento == 1) {
    printf("Assento = A%d\n", assento);
  } else if (assento % 3 == 0) {
    int aux = 3, total = 0;

    while (aux != assento) {
      aux += 3;
      total++;
    }
    printf("Assento = C%d\n", total);
  } else if ((assento - 1) % 3 == 0) {
    int aux = 1, total = 0;

    while (aux != assento) {
      aux += 3;
      total++;
    }
    printf("Assento = A%d\n", total);
  } else {
    int aux = 2, total = 0;

    while (aux != assento) {
      aux += 3;
      total++;
    }
    printf("Assento = B%d\n", total);
  }
}