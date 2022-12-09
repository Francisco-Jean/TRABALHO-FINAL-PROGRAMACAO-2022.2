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

int remover_viagem(Viagem **viagem);

Trecho *cria_trecho(Reserva *reserva);

TabelaViagem *cria_tabela_hash(int tamanho);

int tamanho_hash(TabelaViagem *tabela);

int insere_hash(TabelaViagem *tabela, Viagem *viagem);

Viagem* busca_hash(TabelaViagem* tabela, int cod);

Viagem* retira_hash(TabelaViagem* tabela, int cod);

int funcao_hash(TabelaViagem *tabela, int codigoHash);

int cod_hash(Viagem *viagem);

Trecho *cria_trecho(Reserva *reserva);

int insere_trecho(Viagem *viagem, Trecho *novoTrecho);

int verifica_trecho(Trecho *trechoOrigem, Trecho *trechoDestino);

int trecho_valido(Trecho *trecho_origem, Trecho *trecho_destino);