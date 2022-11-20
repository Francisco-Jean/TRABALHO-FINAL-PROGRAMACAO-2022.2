#include "Passageiros.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void testa_criarPassageiro_dados_validos(Passageiro *passageiro) {  
  int id;
  char nome[30], endereco[30];
  
  passageiroAcessa(passageiro, &id, nome, endereco);

  if ((id == 1) && (strcmp(nome, "Jean") == 0) && (strcmp(endereco, "Vincente Pinzon") == 0)) {
    printf("[PASSOU] testa_criar_passageiro_dados_validos.\n");
  } else {
    printf("[FALHOU] testa_criar_passageiro_dados_validos.\n");
  } 
}

void testa_criarPassageiro_dados_invalidos(Passageiro *passageiro) {
  if (passageiro != NULL) {
    printf("[FALHOU] testa_criar_passageiro_dados_invalidos.\n");
  } else {
    printf("[PASSOU] testa_criar_passageiro_dados_invalidos.\n");
  }
}

void testa_criarPassageiro_dados_nulos(Passageiro *passageiro) {
  if (passageiro == NULL) {
    printf("[PASSOU] testa_criar_passageiro_dados_nulos.\n");
  } else {
    printf("[FALHOU] testa_criar_passageiro_dados_nulos.\n");
  }
}

void teste_editarPassageiro_dados_validos(Passageiro *passageiro) {
  int id, aux = 5;
  char nome[30], endereco[30];
  
  if (passageiro != NULL) {
    editarPassageiro(passageiro, aux, "Victor", "Pici");
    passageiroAcessa(passageiro, &id, nome, endereco);
    if (id == aux && strcmp(nome, "Victor") == 0 && strcmp(endereco, "Pici") == 0) {
      printf("[PASSOU] teste_editarDadosPassageiro_dados_validos.\n");
    } else {
      printf("[FALHOU] teste_editarDadosPassageiro_dados_validos.\n");
    }
  } else {
    printf("[FALHOU] teste_editarDadosPassageiro_dados_validos.\n");
  }
}

void teste_editarPassageiro_dados_invalidos(Passageiro *passageiro) {
  int id, idAux = 5;
  
  char nomeAux[40], enderecoAux[40];

  for (int i = 0; i < 35; i++) {
    strcat(nomeAux, "N");
  }
  
  for (int i = 0; i < 35; i++) {
    strcat(enderecoAux, "C");
  }
  
  if (passageiro != NULL) {
    editarPassageiro(passageiro, idAux, nomeAux, enderecoAux);
    passageiroAcessa(passageiro, &id, nomeAux, enderecoAux);
    if (id == idAux || strcmp(nomeAux, "Luiz") == 0 || strcmp(enderecoAux, "Pici") == 0) {
      printf("[PASSOU] teste_editarDadosPassageiro_dados_invalidos.\n");
    } else {
      printf("[FALHOU] teste_editarDadosPassageiro_dados_invalidos.\n");
    }
  } else {
      printf("[FALHOU] teste_editarDadosPassageiro_dados_invalidos.\n");
  }
}

void teste_editarPassageiro_dados_nulos(Passageiro *passageiro) {
  int id, aux = 5, auxERRADA = -1;
  char nome[30];
  char endereco[30];
  
  if (passageiro != NULL) {
    editarPassageiro(NULL, auxERRADA, NULL, NULL);
    passageiroAcessa(passageiro, &id, nome, endereco);
    if (id == aux || strcmp(nome, "Luiz") == 0 || strcmp(endereco, "Pici") == 0) {
      printf("[PASSOU] teste_editarDadosPassageiro_dados_nulos.\n");
    } else {
      printf("[PASSOU] teste_editarDadosPassageiro_dados_nulos.\n");
    }
  } else {
    printf("[FALHOU] teste_editarDadosPassageiro_dados_nulos.\n");
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
          printf("[PASSOU] teste_removePassageiro_dados_validos.\n");
        } else {
          printf("[FALHOU] teste_removePassageiro_dados_validos.\n");
        }
      } else {
        printf("[FALHOU] teste_removePassageiro_dados_validos.\n");
      }
    } else {
      printf("[FALHOU] teste_removePassageiro_dados_validos.\n");
    }
  } else {
    printf("[FALHOU] teste_removePassageiro_dados_validos.\n");
  }
}

void teste_remove_passageiro_dados_invalidos(Passageiro *passageiro) {
  if (lista_retira(NULL) == NULL) {
    printf("[PASSOU] teste_removePassageiro_dados_validos.\n");
  } else {
    printf("[FALHOU] teste_removePassageiro_dados_validos.\n");
  }
}

int main(void) {
  Passageiro *passageiro1 = criarPassageiro(1, "Jean", "Vincente Pinzon");
  Passageiro *passageiro2 = criarPassageiro(2, "Kauan", "Aracati");
  Passageiro *passageiro3 = criarPassageiro(1, "Gustavo", "Trairi");
  Passageiro *passageiro4 = criarPassageiro(-1, NULL, NULL);

  printf("=-=-=-=-=-=-=-=-=-=-= BATERIA DE TESTES 1 =-=-=-=-=-=-=-=-=-=-=\n");
  testa_criarPassageiro_dados_validos(passageiro1);
  testa_criarPassageiro_dados_invalidos(passageiro3);
  testa_criarPassageiro_dados_nulos(passageiro4);
  printf("=-=-=-=-=-=-=-=-=-=-= BATERIA DE TESTES 2 =-=-=-=-=-=-=-=-=-=-=\n");
  teste_editarPassageiro_dados_validos(passageiro1);
  teste_editarPassageiro_dados_invalidos(passageiro2);
  teste_editarPassageiro_dados_nulos(passageiro1);
}