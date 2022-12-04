#include "Passageiros.h"
#include "Voos.h"

enum cod_assento {
    A0, B0, C0,
    A1, B1, C1, 
    A2, B2, C2,
    A3, B3, C3,
    A4, B4, C4,
    A5, B5, C5,
    A6, B6, C6,
    A7, B7, C7,
    A8, B8, C8, 
    A9, B9, C9
 };

typedef enum cod_assento Assento;
typedef struct data Data;
typedef struct reserva Reserva;
typedef struct agenda Agenda;
typedef struct passageiro Passageiro;

/* Aloca e retorna um No com os dados passados por parâmetro. Retorna no nó
 * criado ou NULL caso não seja posivel criar o nó. */
No *abb_cria_no(Reserva *reserva);

Agenda *abb_insere_agenda(Agenda *raiz, Agenda *agenda);

Reserva *em_ordem(Agenda *agenda, int id, int codigo);

void print_data(Data *data);

int data_compara(Data *data1, Data *data2);

Data * data_cria(int dia, int mes, int ano);