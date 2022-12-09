#include "AgendaReservas.h"
#include "Passageiros.h"
#include "Voos.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct reserva Reserva;
typedef struct viagem Viagem;
typedef struct tabela_viagem TabelaViagem;
typedef struct trecho Trecho;


TabelaViagem *cria_tabela_hash(int tamanho);

Trecho *cria_trecho(Reserva *reserva);

int funcao_hash(Viagem *viagem);