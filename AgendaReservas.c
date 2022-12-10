#include "AgendaReservas.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
};

//-------------------------------------------------------------FUNÇOES DE RESERVA-----------------------------------------------------------------------------

/*Verifica se os dados passados como parametro para a reserva valem e, se valerem, cria a reserva e retorna a reserva criada ou NULL 
caso não possa ser criada a reserva*/
Reserva *cria_reserva(int codigo, Data *data_viagem,Passageiro *passageiro,Voo *voo,Assento assento){
  if(verifica_dados(codigo,data_viagem,passageiro,voo,assento) == 1){
    Reserva *reserva = (Reserva*) malloc(sizeof(Reserva));
    reserva->codigo = codigo;
    reserva->data_viagem = data_viagem;
    reserva->passageiro = passageiro;
    reserva->voo = voo;
    reserva->assento = assento;
    return reserva;
  }
  return NULL;
}

//Verifica se os dados passados como parametro para a reserva são válidos e, se forem, edita a reserva com os novos dados
void edita_reserva(Agenda *raiz,Reserva *reserva,int codigo,Data *data_viagem, Passageiro *passageiro, Voo *voo,Assento assento){
  if(raiz != NULL){
    if(reserva!= NULL && verifica_dados(codigo,data_viagem,passageiro,voo,assento) == 1 && verifica_reserva(raiz,codigo,data_viagem,passageiro,voo,assento) == 1){
      int id; char nome[30];char endereco[30];
      int codigo; char origem[30];char destino[30];
      passageiroAcessa(passageiro, &id, nome, endereco);
      vooAcessa(voo, &codigo, origem, destino);
      if(strcmp(endereco,origem) == 0){
        reserva->codigo = codigo;
        reserva->data_viagem = data_viagem;
        reserva->passageiro = passageiro;
        reserva->voo = voo;
        reserva->assento = assento;
      }
    }
  }
  if(verifica_dados(codigo,data_viagem,passageiro,voo,assento) == 1){
    reserva->codigo = codigo;
    reserva->data_viagem = data_viagem;
    reserva->passageiro = passageiro;
    reserva->voo = voo;
    reserva->assento = assento;
  }
}

//Libera a reserva e desaloca o ponteiro reserva
void libera_reserva(Reserva **reserva){
  if(reserva!=NULL){
    free(*reserva);
    *reserva = NULL;
  }
}

//copia os dados de uma derterminada reserva para os parametros indicados
void reserva_acessa(Reserva *reserva, int *codigo, Data **data_viagem,Passageiro **passageiro,Voo **voo, Assento *assento){
  if(reserva == NULL){
    
    *codigo = -1;
    *data_viagem = NULL;
    *passageiro = NULL;
    *voo= NULL;
    *assento = -1;
  }
  else{
    *codigo = reserva->codigo;
    *data_viagem = reserva->data_viagem;
    *passageiro = reserva->passageiro;
    *voo= reserva->voo;
    *assento = reserva->assento;
  }
}


// Verifica se duas reservas são iguais ou não. Caso sejam iguais, retorna 1. Caso seja NULL, retorna -1 e caso não seja igual, retorna 0.
int reserva_igual(Reserva *reserva1, Reserva *reserva2){
  if (reserva1== NULL || reserva2== NULL){
    return -1;
  }
  if(reserva1->codigo == reserva2->codigo && data(reserva1->data_viagem) == data(reserva2->data_viagem) && reserva1->passageiro == reserva2->passageiro && reserva1->voo == reserva2->voo && reserva1->assento == reserva2->assento){
    return 1;
  }
  return 0;
}
//---------------------------------------------------------------FUNÇOES DE AGENDA-------------------------------------------------------------------------

/* Aloca e retorna uma Agenda com os dados passados por parâmetro. Retorna no agenda
 * criado ou NULL caso não seja posivel criar o nó agenda. */
Agenda *abb_cria_agenda(Reserva *reserva) {
  if(reserva->codigo<0){
    return NULL;
  }
  Agenda *agenda = (Agenda*) malloc(sizeof(Agenda));
  agenda->reserva = reserva;
  agenda->esq = NULL;
  agenda->dir = NULL;
  return agenda;
}



/* Adiciona um nó à esquerda ou à direita do no raiz. Retorna a raiz da árvore
 * resultante ou NULL caso (i) a raiz e o nó sejam NULL e (ii) caso o nó possua
 * mesma chave que outro nó previamente inserido na árvore. */
Agenda *abb_insere_agenda(Agenda *raiz, Agenda *agenda) {
  
  if (agenda == NULL || raiz == NULL) {
    return NULL;
  }
  Agenda *aux1 = raiz;
  Agenda *aux2 = NULL;
  int data1 = data(agenda->reserva->data_viagem);
  int data2 = data(aux1->reserva->data_viagem);
  while (aux1 != NULL) {
    aux2 = aux1;
    if (data1 < data2) {
      aux1 = aux1->esq;
      data2 = data(aux1->reserva->data_viagem);
    }
    else if (data1 > data2) {
      aux1 = aux1->dir;
      data1 = data(agenda->reserva->data_viagem);
    }
      
    else if (data1 == data2){
      if(passageiroIgual(aux1->reserva->passageiro,agenda->reserva->passageiro) == 1){
        return NULL;
      }
      else{
        aux2->dir = agenda;
      }
    }
  }
  if(reserva_igual(agenda->reserva,aux2->reserva) == 1){
    return NULL;
  }
  if (data1 < data2) {
    aux2->esq = agenda;
  }
  else {
    aux2->dir = agenda;
  }
  return raiz;
}

/* Procura o reserva pelo id e codigo. Retorna a reserva caso a busca obtenha sucesso ou NULL
 * em caso contrário. */
Reserva *abb_busca_reserva_codigo(Agenda *raiz,int id, int codigo) {
  if(id<0 || codigo <= 0){
    return NULL;
  }
  int id_aux; char nome[30];char endereco[30];
  passageiroAcessa(raiz->reserva->passageiro, &id_aux, nome, endereco);
  Reserva *reserva = em_ordem(raiz,id_aux,codigo);
  return reserva;
}

/*Vai buscar uma reserva dado o id e a data de uma certa viagem. Retorna a reserva caso a busca obtenha sucesso ou NULL
 * em caso contrário.*/
Reserva *abb_busca_reserva_data(Agenda *raiz,int id, Data *data_viagem) {
  if(id > 0 && data_viagem != NULL){
    Agenda *agenda_aux = raiz;
    int data1 = data(data_viagem);
    int data2 = data(agenda_aux->reserva->data_viagem);
    int id_aux; char nome[30];char endereco[30];
    passageiroAcessa(agenda_aux->reserva->passageiro, &id, nome, endereco);
    
    while(agenda_aux != NULL && data1 != data2 && id_aux != id){
      passageiroAcessa(agenda_aux->reserva->passageiro, &id_aux, nome, endereco);
      data2 = data(agenda_aux->reserva->data_viagem);
      if (data1 < data2){
        agenda_aux = agenda_aux->esq;
      }
      else{
        agenda_aux = agenda_aux->dir;
      }
    }
    return agenda_aux->reserva;
  }
  printf("NULL");
  return NULL;
}

//Encontra o nó mínimo da árvore binária de busca //
Agenda *busca_minimo(Agenda *noRaiz) {
  if (noRaiz==NULL){
    return NULL;
  }
  while(noRaiz->esq != NULL){
    noRaiz=noRaiz->esq;
  }
  return noRaiz;
}

//Libera um nó da agenda e desaloca o ponteiro agenda
void abb_agenda_libera(Reserva **agenda){
  if(agenda!=NULL){
    free(*agenda);
    *agenda = NULL;
  }
}

//Remove um nó da agenda e retorna o no removido
Reserva *abb_no_remove(Agenda *raiz, Agenda* noRemover) {
  if(raiz == NULL || noRemover == NULL){
    return NULL;
  }
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

//Faz a verificação se exite os parametros são negativos ou NULL. Retorna 1 caso não haja erro ou 0 caso haja impossibilidade em algum dos parametros passados
int verifica_dados(int codigo, Data *data_viagem,Passageiro *passageiro,Voo *voo,Assento assento){
  if(codigo <= 0 || data_viagem == NULL || passageiro == NULL || voo == NULL || assento<0 ){
    return 0;
  }
  return 1;
}

//Faz a verificação se reserva ja alocada em alguma agenda com os dados passados por parametro. Retorna 1 caso haja reserva com os dados passados ou 0 caso não haja reserva já alocada com os dados passados por parametro
int verifica_reserva(Agenda *raiz,int codigo,Data *data_viagem,Passageiro *passageiro,Voo *voo,Assento assento){
  int id; char nome[30];char endereco[30];
  passageiroAcessa(passageiro, &id, nome, endereco);
  if(busca_codigo(raiz,codigo) == 0 && abb_busca_reserva_data(raiz, id,data_viagem) == NULL && abb_busca_reserva_codigo(raiz, id,codigo) == NULL){
    return 0;
  }
  return 1;
}

//Converte uma dada data criada na forma de soma de dias
int data(Data *data_viagem){
  int dia = data_viagem->dia;
  int mes = data_viagem->mes * 30;
  int ano = data_viagem->ano * 365;
  int soma = dia+mes+ano;
  return soma;
}

//verifica se há alguma reserva com o codigo fornecido como parametro. Retorna 0 caso não for encontrado o codigo fornecido nas reservas da arvore ou 1 caso o codigo da reserva tenha sido encontrado em alguma reserva da arvore.
int busca_codigo(Agenda *raiz,int codigo_reserva){
  if(codigo_reserva > 0){
    Reserva *codigo = em_ordem2(raiz,codigo_reserva);
    if(codigo != NULL){
      return 1;
    }
  }
  return 0;
}

//Busca na agendas uma reserva com o id do passageiro e o codigo da reserva fornecido. Caso a reserva tenha sido achada, retorna a reserva, caso contrario, retorna NULL.
Reserva *em_ordem(Agenda *agenda, int id,int codigo){
  if(agenda->esq != NULL){
    em_ordem(agenda->esq,id,codigo);
  }
  int id_aux; char nome[30];char endereco[30];
  passageiroAcessa(agenda->reserva->passageiro, &id_aux, nome, endereco);
  if (id_aux == id && agenda->reserva->codigo == codigo){
    return agenda->reserva;
  }
  if(agenda->dir != NULL){
    em_ordem(agenda->dir,id,codigo);
  }
  return NULL;
}

//Busca na agendas uma reserva com o codigo da reserva fornecido. Caso a reserva tenha sido achada, retorna a reserva, caso contrario, retorna NULL.
Reserva *em_ordem2(Agenda *agenda,int codigo){
  if(agenda->esq != NULL){
    em_ordem2(agenda->esq,codigo);
  }
  if (agenda->reserva->codigo == codigo){
    return agenda->reserva;
  }
  if(agenda->dir != NULL){
    em_ordem2(agenda->dir,codigo);
  }
  return NULL;
}

// Cria e aloca um dia, mes e ano como formato de data. Retorna a data caso seja possivel alocar ou NULL, caso não seja possível.
Data *criaData(int dia, int mes, int ano){
  if(dia <= 0 || mes<= 0 || ano<= 0){
    return NULL;
  }
  Data *data = (Data*) malloc(sizeof(Data));
  data->dia = dia;
  data->mes = mes;
  data->ano =ano;
  return data;
}

 //Retorna:
 //   1, se data1 > data2;
 //  -1, se data1 < data2;
 //   0, caso contrario (data1 == data2)
 
int data_compara(Data *data1, Data *data2){
  if(data2 == NULL){
    
    return -1;
  }
  if (data1->ano == data2->ano && data1->mes == data2->mes && data1->dia  == data2->dia ) {
    return 0;
  }
  int data_1 = data(data1); 
  int data_2 = data(data2);
  if(data1<data2){
    return -1;    
  }
  return 1;
}

//Encontra o sucessor de um nó passado por parâmetro da árvore binária de busca //
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