#include "TravelBooking.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void testa_cadastrarPassageiro_dados_validos(Passageiro *passageiro) {  
  int id;
  char nome[50], endereco[50];
  
  passageiroAcessa(passageiro, id, nome, endereco);

  Passageiro *auxiliar = lista_passageiro->primeiro;

  if ((id == 1) && strcmp(nome, "Jean") && strcmp(endereco, "Vincente Pinzon")) {
    printf("[PASSOU] testa_cadastrarPassageiro_dados_validos.");
  } else {
    printf("[FALHOU] testa_cadastrarPassageiro_dados_validos.");
  }
}

void testa_cadastrarPassageiro_dados_invalidos(Passageiro *passageiro) {
  if (passageiro != NULL) {
    printf("[FALHOU] testa_cadastrarPassageiro_dados_invalidos.");
  } else {
    printf("[PASSOU] testa_cadastrarPassageiro_dados_invalidos.");
  }
}

int main(void) {
  Passageiro *passageiro1 = criarPassageiro(1, "Jean", "Vincente Pinzon");
  Passageiro *passageiro2 = criarPassageiro(2, "Kauan", "Parquelandia");
  Passageiro *passageiro3 = criarPassageiro(1, "Gustavo", "Trairi");

  printf("=-=-=-=-=-=-=-=-=-=-= BATERIA DE TESTES 1 =-=-=-=-=-=-=-=-=-=-=");
  testa_cadastrarPassageiro_dados_validos(passageiro1);
  printf("=-=-=-=-=-=-=-=-=-=-= BATERIA DE TESTES 2 =-=-=-=-=-=-=-=-=-=-=");
  testa_cadastrarPassageiro_dados_invalidos(passageiro3);
  
}