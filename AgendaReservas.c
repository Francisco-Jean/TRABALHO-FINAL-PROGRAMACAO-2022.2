#include "AgendaReservas.h"
#include <stdio.h>
#include <stdlib.h>
// TEMPORARIAMENTE, ENQUANTO TESTA A EXCLUSAO
#include "Voos.h"
#include "Passageiros.h"

//arvore binaria de busca
struct data {
  int dia;
  int mes;
  int ano;
};

struct reserva {
  int codigo;
  Data *data_viagem;
  Passageiro *passageiro;
  Voo *voo;
  Assento assento;
};

struct agenda {
  Reserva *reserva;
  Agenda *esq;
  Agenda *dir;
  Agenda *pai;
  // Dúvida: o que é a raiz, neste caso?
  Agenda *raiz;
};

struct passageiro {
int id;
char *nome;
char *endereco;
};

struct no_passageiro {
  Passageiro *passageiro;
  struct no_passageiro *proximo;
};

/* Aloca e retorna uma Agenda com os dados passados por parâmetro. Retorna no nó
 * criado ou NULL caso não seja posivel criar o nó. */
Agenda *abb_cria_agenda(Reserva *reserva) {
  if(reserva->codigo<0){
    return NULL;
  }
  Agenda *agenda = (Agenda*) malloc(sizeof(Agenda));
  agenda->reserva = reserva;
  agenda->esq = NULL;
  agenda->dir = NULL;
  agenda->pai = NULL;
  return agenda;
}

/* Retorna o codigo da reserva ou '#' caso o nó seja NULL. */
int abb_codigo_reserva(Reserva *reserva) {
  if(reserva == NULL){
    return '#';
  }
  return reserva->codigo;
}

/* Adiciona um nó à esquerda ou à direita do no raiz. Retorna a raiz da árvore
 * resultante ou NULL caso (i) a raiz e o nó sejam NULL e (ii) caso o nó possua
 * mesma chave que outro nó previamente inserido na árvore. */
Agenda *abb_insere_agenda(Agenda *raiz, Agenda *agenda) {
  if (raiz == NULL && agenda == NULL) {
    return NULL;
  }
  Agenda *aux2 = NULL;
  Agenda *aux1 = raiz;

  while (aux1 != NULL) {
    aux2 = aux1;
    //if (agenda->reserva->data_viagem < aux1->reserva->data_viagem) {
    if (agenda->reserva->data_viagem <= aux1->reserva->data_viagem) {
      aux1 = aux1->esq;
    }
    else if (agenda->reserva->data_viagem > aux1->reserva->data_viagem) {
      aux1 = aux1->dir;
    }
    // Dúvida: pq eu náo posso ter duas reservas de passageiros diferentes com a mesma data 
    //else if (agenda->reserva->data_viagem == aux2->reserva->data_viagem){
    else if (0){
      return NULL;
    }
  }
  if (raiz != NULL) {
    if (agenda->reserva->data_viagem < aux2->reserva->data_viagem) {
      aux2->esq = agenda;
    }
    else {
      aux2->dir = agenda;
    }
    agenda->pai = aux2;
  }
  else {
    raiz = agenda;
  }
  return raiz;
}

/* Procura o reserva pelo id e codigo. Retorna a reserva caso a busca obtenha sucesso ou NULL
 * em caso contrário. */

//duvida= a fun;ao retorna somente 1 r
Reserva *abb_busca_reserva(Agenda *raiz,int id, int codigo, Data *data_viagem) {
  if(id<0 || codigo<0 || data_viagem == NULL){
    return NULL;
  }
  if(id != 0 && codigo != 0 && data_viagem == NULL){
    Reserva *reserva = em_ordem(raiz,id,codigo);
    return reserva;
  }
  else if(id != 0 && codigo == 0 && data_viagem != NULL){
    Agenda *agenda_aux = raiz;
    while(agenda_aux->reserva->data_viagem != data_viagem && agenda_aux->reserva->passageiro->id != id){
      if (agenda_aux->reserva->data_viagem <= data_viagem){
        agenda_aux = agenda_aux->esq;
      }
      else{
        agenda_aux = agenda_aux->dir;
      }
    }
    return agenda_aux->reserva;
  }
  return NULL;
}

Reserva *em_ordem(Agenda *agenda, int id, int codigo){
  if(agenda->esq != NULL){
    em_ordem(agenda->esq,id,codigo);
  }
  if (agenda->reserva->codigo == codigo && agenda->reserva->passageiro->id == id){
    return agenda->reserva;
  }
  if(agenda->dir != NULL){
    em_ordem(agenda->dir,id,codigo);
  }
  return NULL;
}

Agenda *busca_codigo_pre_ordem(Agenda *noRaiz, int codigo_reserva) {
  if(noRaiz == NULL) {
    return NULL;
  }

  if(noRaiz->reserva->codigo == codigo_reserva) {
    return noRaiz;
  }

  Agenda *resultado_esquerda = busca_codigo_pre_ordem(noRaiz->esq, codigo_reserva);
  if(resultado_esquerda != NULL) {
    return resultado_esquerda;
  }

  Agenda *resultado_direita = busca_codigo_pre_ordem(noRaiz->dir, codigo_reserva);
  if(resultado_direita != NULL) {
    return resultado_direita;
  }

  return NULL;
}

Agenda *busca_minimo(Agenda *noRaiz) {
  if (noRaiz==NULL){
    return NULL;
  }
  while(noRaiz->esq != NULL){
    noRaiz=noRaiz->esq;
  }
  return noRaiz;
}

Agenda *busca_sucessor(Agenda *no) {
  if (no->dir != NULL){
    return busca_minimo(no->dir);
  }
  Agenda * noPai=no->pai;
  while(noPai!=NULL && no==noPai->dir){
    no=noPai;
    noPai=no->pai;
  }
  return noPai;
}

// v: noOrigem
// u: noDestino
void transplantar(Agenda **noRaiz, Agenda *noDestino, Agenda *noOrigem){
  if (noDestino->pai == NULL){
    *noRaiz=noOrigem;
  }
  else{
    if(noDestino==noDestino->pai->esq){
      noDestino->pai->esq=noOrigem;
    }
    else{
      noDestino->pai->dir=noOrigem;
    }
    if (noOrigem!=NULL){
      noOrigem->pai=noDestino->pai;
    }
  }
}

Reserva *abb_no_remove(Agenda *raiz, Agenda* noRemover) {
  if (noRemover->esq==NULL){
    transplantar(&raiz,noRemover,noRemover->dir);
  }
  else{
    if(noRemover->dir==NULL){
      transplantar(&raiz,noRemover,noRemover->esq);
    }
    else{
      Agenda *y=busca_minimo(noRemover->dir);
      if(y->pai != noRemover){
        transplantar(&raiz,y,y->dir);
        y->dir=noRemover->dir;
        y->dir->pai=y;
      }
      transplantar(&raiz,noRemover,y);
      y->esq=noRemover->esq;
      y->esq->pai=y;
      
    }
  }
  return noRemover->reserva;
}


  
Data * data_cria(int dia, int mes, int ano){
  Data *novaData=(Data *)malloc(sizeof(Data));
  novaData->dia=dia;
  novaData->mes=mes;
  novaData->ano=ano;
  return novaData;
}

void print_data(Data *data) {
  if(data != NULL) {
    printf("Data: %p\n", data);
    printf("\t.Dia=%d\n", data->dia);
    printf("\t.Mes=%d\n", data->mes);
    printf("\t.Ano=%d\n", data->ano);
  }
}
    
/*
 * Retorna:
 *    1, se data1 > data2;
 *   -1, se data1 < data2;
 *    0, caso contrario (data1 == data2)
 */
int data_compara(Data *data1, Data *data2){
  if (data1->ano > data2->ano) {
    return 1;
  }
  if(data1->ano < data2->ano) {
    return -1;
  }
  if(data1->mes > data2->mes) {
    return 1;
  }
  if(data1->mes < data2->mes) {
    return -1;
  }
  if(data1->dia > data2->dia) {
    return 1;
  }
  if(data1->dia < data2->dia) {
    return -1;
  }
  return 0;
}

Reserva * criarReserva(int codigo, Data *data, Passageiro *passageiro, Voo *voo, Assento assento) {
  Reserva *reserva = (Reserva *) malloc(sizeof(Reserva));

  reserva->codigo = codigo;
  reserva->data_viagem = data;
  reserva->passageiro = passageiro;
  reserva->voo = voo;
  reserva->assento = assento;

  return reserva;
}

void print_agenda(Agenda *agenda) {
  printf("-----------------------------------\n");
  printf("Agenda: %p, Reserva: %d\n", agenda, agenda->reserva->codigo);
  print_data(agenda->reserva->data_viagem);
  printf("-----------------------------------\n");
}

void print_arvore_pre_ordem(Agenda *raiz) {
  if(raiz == NULL) {
    return;
  }

  print_agenda(raiz);
  print_arvore_pre_ordem(raiz->esq);
  print_arvore_pre_ordem(raiz->dir);
}

void testeExclusao() {
  printf("Teste exclusao da arvore binaria de busca\n");

  Passageiro *p1 = criarPassageiro(1, "Jose da Silva", "Rua um, 123");
  Passageiro *p2 = criarPassageiro(2, "Maria Ferreira", "Rua dois, 45");
  Passageiro *p3 = criarPassageiro(3, "Raimundo Souza", "Rua tres, 67");

  Voo *v1 = criarVoo(11, "FOR", "GRU");
  Voo *v2 = criarVoo(12, "RJO", "SAO");
  Voo *v3 = criarVoo(13, "NAT", "POA");
  Voo *v4 = criarVoo(14, "REC", "SDR");
  Voo *v5 = criarVoo(15, "SAO", "BSA");

  Data *d1 = data_cria(22, 1, 2023);
  Data *d2 = data_cria(23, 1, 2023);
  Data *d3 = data_cria(24, 1, 2023);
  Data *d4 = data_cria(1, 2, 2023);
  Data *d5 = data_cria(2, 2, 2024);

  Reserva *r1 = criarReserva(101, d1, p1, v1, A0);
  Reserva *r2 = criarReserva(102, d2, p2, v2, A0);
  Reserva *r3 = criarReserva(103, d3, p3, v3, A0);
  Reserva *r4 = criarReserva(104, d4, p1, v4, A0);
  Reserva *r5 = criarReserva(105, d5, p2, v5, A0);
  Reserva *r6 = criarReserva(106, d1, p3, v1, A0);
  Reserva *r7 = criarReserva(107, d2, p1, v2, A0);
  Reserva *r8 = criarReserva(108, d3, p2, v3, A0);
  Reserva *r9 = criarReserva(109, d4, p3, v4, A0);

  Agenda *a1 = abb_cria_agenda(r1);
  Agenda *a2 = abb_cria_agenda(r2);
  Agenda *a3 = abb_cria_agenda(r3);
  Agenda *a4 = abb_cria_agenda(r4);
  Agenda *a5 = abb_cria_agenda(r5);
  Agenda *a6 = abb_cria_agenda(r6);
  Agenda *a7 = abb_cria_agenda(r7);
  Agenda *a8 = abb_cria_agenda(r8);
  Agenda *a9 = abb_cria_agenda(r9);

  abb_insere_agenda(a7, a6);
  abb_insere_agenda(a7, a9);
  abb_insere_agenda(a7, a1);
  abb_insere_agenda(a7, a2);
  abb_insere_agenda(a7, a8);
  abb_insere_agenda(a7, a5);
  abb_insere_agenda(a7, a3);
  abb_insere_agenda(a7, a4);

  print_arvore_pre_ordem(a7);

  printf("#########################################\n");
  printf("Testando a exclusao\n");

  Agenda * noRemover = busca_codigo_pre_ordem(a7, 108);
  Reserva *reservaRemovida = abb_no_remove(a7, noRemover);

  print_arvore_pre_ordem(a7);
  printf("Reserva removida: %d\n", reservaRemovida->codigo);
}