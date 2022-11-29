#include "Passageiros.h"
#include "Voos.h"
#include "AgendaReservas.h"

typedef struct reserva Reserva;
typedef struct tabela_viagem TabelaViagem;
typedef struct viagem Viagem;
typedef struct trecho Trecho;

int fun_hash(int id, int codigo);

TabelaViagem *cria_hash();

TabelaViagem *insere_hash(TabelaViagem *tabela,Viagem *tabela_hash);