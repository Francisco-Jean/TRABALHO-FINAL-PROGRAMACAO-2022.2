#include "AgendaReservas.h"
#include "Passageiros.h"
#include "Voos.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct reserva Reserva;
typedef struct viagem Viagem;
typedef struct tabela_viagem TabelaViagem;
typedef struct trecho Trecho;

Viagem *criar_viagem();

void remover_viagem(Viagem **viagem);

Trecho *cria_trecho(Reserva *reserva);

TabelaViagem *cria_tabela_hash(int tamanho);

int insere_hash(TabelaViagem *tabela, Viagem *viagem);

Viagem* busca_hash(TabelaViagem* tabela, int cod);

Viagem* retira_hash(TabelaViagem* tabela, int cod){

int funcao_hash(Viagem *viagem);
