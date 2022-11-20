#include "Passageiros.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void testa_criarPassageiro_dados_validos(Passageiro *passageiro) {  
  int id;
  char nome[50], endereco[50];
  
  passageiroAcessa(passageiro, &id, nome, endereco);

  if ((id == 1) && strcmp(nome, "Jean") == 0 && strcmp(endereco, "Vincente Pinzon") == 0) {
    printf("[PASSOU] testa_criar_passageiro_dados_validos.");
  } else {
    printf("[FALHOU] testa_criar_passageiro_dados_validos.");
  } 
}

void testa_criarPassageiro_dados_invalidos(Passageiro *passageiro) {
  if (passageiro != NULL) {
    printf("[FALHOU] testa_criar_passageiro_dados_invalidos.");
  } else {
    printf("[PASSOU] testa_criar_passageiro_dados_invalidos.");
  }
}

void testa_criarPassageiro_dados_nulos(Passageiro *passageiro) {
  if (passageiro == NULL) {
    printf("[PASSOU] testa_criar_passageiro_dados_nulos.");
  } else {
    printf("[FALHOU] testa_criar_passageiro_dados_nulos.");
  }
}

void teste_editarPassageiro_dados_validos(Passageiro *passageiro) {
  int id, aux = 5;
  char nome[50], endereco[50];
  
  if (passageiro != NULL) {
    editarPassageiro(passageiro, aux, "Jacó", "Pici");
    passageiroAcessa(passageiro, &id, nome, endereco);
    if (id == aux && strcmp(nome, "Jacó") == 0 && strcmp(endereco, "Pici") == 0) {
      printf("[PASSOU] teste_editarDadosPassageiro_dados_validos.");
    } else {
      printf("[FALHOU] teste_editarDadosPassageiro_dados_validos.");
    }
  } else {
    printf("[FALHOU] teste_editarDadosPassageiro_dados_validos.");
  }
}

void teste_editarPassageiro_dados_invalidos(Passageiro *passageiro) {
  int id, aux = 5;
  
  char nome[55] = "N";
  char endereco[55] = "C";

  for (int i = 0; i < 55; i++) {
    strcat(nome, "N");
  }
  for (int i = 0; i < 55; i++) {
    strcat(endereco, "C");
  }
  
  if (passageiro != NULL) {
    editarPassageiro(passageiro, aux, nome, endereco);
    passageiroAcessa(passageiro, &id, nome, endereco);
    if (id == aux || strcmp(nome, "Jacó") == 0 || strcmp(endereco, "Pici") == 0) {
      printf("[PASSOU] teste_editarDadosPassageiro_dados_invalidos.");
    } else {
      printf("[FALHOU] teste_editarDadosPassageiro_dados_invalidos.");
    }
  } else {
      printf("[FALHOU] teste_editarDadosPassageiro_dados_invalidos.");
  }
}

void teste_editarPassageiro_dados_nulos(Passageiro *passageiro) {
  int id, aux = 5, auxERRADA = -1;
  char nome[50];
  char endereco[50];
  
  if (passageiro != NULL) {
    editarPassageiro(NULL, auxERRADA, NULL, NULL);
    passageiroAcessa(passageiro, &id, nome, endereco);
    if (id == aux || strcmp(nome, "Jacó") == 0 || strcmp(endereco, "Pici") == 0) {
      printf("[PASSOU] teste_editarDadosPassageiro_dados_nulos.");
    } else {
      printf("[PASSOU] teste_editarDadosPassageiro_dados_nulos.");
    }
  } else {
    printf("[FALHOU] teste_editarDadosPassageiro_dados_nulos.");
  }
}

void teste_removePassageiro_dados_validos() {
  Lista *lista = lista_cria();
  if (lista != NULL) {
    Passageiro *abraao = criarPassageiro(1, "Abraão", "Computação");
    lista_insere(lista, abraao);
    Passageiro *jaco = criarPassageiro(2, "Jaco", "Computação");
    lista_insere(lista, jaco);
    Passageiro *jose = criarPassageiro(3, "Jose", "Computação");
    lista_insere(lista, jose);
    Passageiro *passageiro = lista_retira(lista);

    if (passageiroIgual(passageiro, abraao) == 1) {
      passageiro = lista_retira(lista);
      if (passageiroIgual(passageiro, jaco) == 1) {
        passageiro = lista_retira(lista);
        if (passageiroIgual(passageiro, jose) == 1) {
          printf("[PASSOU] teste_removePassageiro_dados_validos.");
        } else {
          printf("[FALHOU] teste_removePassageiro_dados_validos.");
        }
      } else {
        printf("[FALHOU] teste_removePassageiro_dados_validos.");
      }
    } else {
      printf("[FALHOU] teste_removePassageiro_dados_validos.");
    }
  } else {
    printf("[FALHOU] teste_removePassageiro_dados_validos.");
  }
}

void teste_remove_passageiro_dados_invalidos(Passageiro *passageiro) {
  if (lista_retira(NULL) == NULL) {
    printf("[PASSOU] teste_removePassageiro_dados_validos.");
  } else {
    printf("[FALHOU] teste_removePassageiro_dados_validos.");
  }
}

int main(void) {
  Passageiro *passageiro1 = criarPassageiro(1, "Jean", "Vincente Pinzon");
  Passageiro *passageiro2 = criarPassageiro(2, "Kauan", "Aracati");
  Passageiro *passageiro3 = criarPassageiro(1, "Gustavo", "Trairi");
  Passageiro *passageiro4 = criarPassageiro(-1, NULL, NULL);

  printf("=-=-=-=-=-=-=-=-=-=-= BATERIA DE TESTES 1 =-=-=-=-=-=-=-=-=-=-=");
  testa_criarPassageiro_dados_validos(passageiro1);
  testa_criarPassageiro_dados_invalidos(passageiro3);
  testa_criarPassageiro_dados_nulos(passageiro4);
  printf("=-=-=-=-=-=-=-=-=-=-= BATERIA DE TESTES 2 =-=-=-=-=-=-=-=-=-=-=");
  teste_editarPassageiro_dados_validos(passageiro1);
  teste_editarPassageiro_dados_invalidos(passageiro3);
  teste_editarPassageiro_dados_nulos(passageiro1);
}