#include "Passageiros.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ================== TESTES FUNÇÕES DE PASSAGEIRO ==================


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
  /*char nome[55] = "N";
  char endereco[35] = "C";

  for (int i = 0; i < 53; i++) {
    strcat(nome, "N");
  }

  for (int i = 0; i < 33; i++) {
    strcat(endereco, "C");
  }*/

  if (passageiro == NULL) {
    printf("[PASSOU] testa_criar_passageiro_dados_invalidos.\n");
  } else {
    printf("[FALHOU] testa_criar_passageiro_dados_invalidos.\n");
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


void teste_retira_passageiro_dados_validos() {
  Lista *lista = lista_cria();
  if (lista != NULL) {
    Passageiro *abraao = criarPassageiro(1, "Abraão", "Computação");
    lista_insere(lista, abraao);
    Passageiro *jaco = criarPassageiro(2, "Jaco", "Computação");
    lista_insere(lista, jaco);
    Passageiro *jose = criarPassageiro(3, "Jose", "Computação");
    lista_insere(lista, jose);
    Passageiro *passageiro = lista_retira(lista, 2);

    if (passageiroIgual(passageiro, jaco) == 1) {
      passageiro = lista_retira(lista, 3);
      if (passageiroIgual(passageiro, jose) == 1) {
        passageiro = lista_retira(lista, 1);
        if (passageiroIgual(passageiro, abraao) == 1) {
          printf("[PASSOU] teste_retira_passageiro_dados_validos.\n");
        } else {
          printf("[FALHOU] teste_retira_passageiro_dados_validos.\n");
        }
      } else {
        printf("[FALHOU] teste_retira_passageiro_dados_validos.\n");
      }
    } else {
      printf("[FALHOU] teste_retira_passageiro_dados_validos.\n");
    }
  } else {
    printf("[FALHOU] teste_retira_passageiro_dados_validos.\n");
  }
}

void teste_retira_passageiro_dados_invalidos(Passageiro *passageiro) {
  if (lista_retira(NULL, -1) == NULL) {
    printf("[PASSOU] teste_retira_passageiro_dados_invalidos.\n");
  } else {
    printf("[FALHOU] teste_retira_passageiro_dados_invalidos.\n");
  }
}

// ================== TESTES FUNÇÕES DE LISTA DE PASSAGEIROS ==================

void teste_lista_cria_dados_validos() {
  Lista *lista = lista_cria();
  if (lista != NULL) {
    printf("[PASSOU] teste_lista_cria_dados_validos.\n");
  } else {
    printf("[FALHOU] teste_lista_cria_dados_validos.\n");
  }
}

void teste_lista_libera_dados_validos() {
  Lista *lista = lista_cria();
  lista_libera(&lista);
  if (lista != NULL) {
    printf("[PASSOU] teste_lista_libera_dados_validos.\n");
  } else {
    printf("[FALHOU] teste_lista_libera_dados_validos.\n");
  }
}

void teste_lista_libera_dados_nulos() {
  if (lista_libera(NULL) == 0) {
    printf("[PASSOU] teste_lista_libera_dados_nulos.\n");
  } else {
    printf("[FALHOU] teste_lista_libera_dados_nulos.\n");
  }
}

void teste_lista_vazia_dados_validos() {
  Lista *lista = lista_cria();
  if (lista != NULL && lista_vazia(lista)) {
    printf("[PASSOU] teste_lista_vazia_dados_validos.\n");
  } else {
    printf("[FALHOU] teste_lista_vazia_dados_validos.\n");
  }
}

void teste_lista_insere_dados_validos() {
  Lista *lista = lista_cria();
  if (lista != NULL) {
    Passageiro *Victor = criarPassageiro(1, "Victor", "Pici");
    if (lista_insere(lista, Victor) == 1) {
      Passageiro *Lincoln = criarPassageiro(2, "Lincoln", "Aldeota");
      if (lista_insere(lista, Lincoln) == 1) {
        Passageiro *Neto = criarPassageiro(3, "Neto", "Bom Jardim");
        if (lista_insere(lista, Neto) == 1) {
          printf("[PASSOU] teste_lista_insere_dados_validos.\n");
        } else {
          printf("[FALHOU] teste_lista_insere_dados_validos.\n");
        }
      } else {
        printf("[FALHOU] teste_lista_insere_dados_validos.\n");
      }
    } else {
      printf("[FALHOU] teste_lista_insere_dados_validos.\n");
    }
  } else {
    printf("[FALHOU] teste_lista_insere_dados_validos.\n");
  }
}

void teste_lista_insere_dados_invalidos() {
  Lista *lista = lista_cria();

  if (lista != NULL) {
    Passageiro *Victor = criarPassageiro(1, "Victor", "Pici");
    lista_insere(lista, Victor);
    Passageiro *Lucas = criarPassageiro(1, "Lucas", "Computação");
    if (lista_insere(lista, Lucas) == 0) {
      printf("[PASSOU] teste_lista_insere_dados_invalidos\n");
    } else {
      printf("[FALHOU] teste_lista_insere_dados_invalidos\n");
    }
  } else {
    printf("[FALHOU] teste_lista_insere_dados_invalidos\n");
  }
}

void teste_lista_insere_dados_nulos() {
  Lista *lista = lista_cria();
  if (lista_insere(lista, NULL) == -1) {
    Passageiro *Victor = criarPassageiro(1, "Victor", "Pici");
    if (lista_insere(NULL, Victor) == -1) {
      if (lista_insere(NULL, NULL) == -1) {
        printf("[PASSOU] teste_lista_insere_dados_nulos\n");
      } else {
        printf("[FALHOU] teste_lista_insere_dados_nulos\n");
      }
    } else {
      printf("[FALHOU] teste_lista_insere_dados_nulos\n");
    }
  } else {
    printf("[FALHOU] teste_lista_insere_dados_nulos\n");
  }
}

void teste_lista_retira_dados_validos() {
  Lista *lista = lista_cria();
  if (lista != NULL) {
    Passageiro *abraao = criarPassageiro(1, "Victor", "Pici");
    lista_insere(lista, abraao);
    Passageiro *jaco = criarPassageiro(2, "Lucas", "Bom Jardim");
    lista_insere(lista, jaco);
    Passageiro *jose = criarPassageiro(3, "Joel", "Vincente Pinzon");
    lista_insere(lista, jose);
    Passageiro *passageiro = lista_retira(lista, 2);

    if (passageiroIgual(passageiro, abraao) == 1) {
      passageiro = lista_retira(lista, 3);
      if (passageiroIgual(passageiro, jaco) == 1) {
        passageiro = lista_retira(lista, 1);
        if (passageiroIgual(passageiro, jose) == 1) {
          printf("[PASSOU] teste_lista_retira_dados_validos\n");
        } else {
          printf("[FALHOU] teste_lista_retira_dados_validos\n");
        }
      } else {
        printf("[FALHOU] teste_lista_retira_dados_validos\n");
      }
    } else {
      printf("[FALHOU] teste_lista_retira_dados_validos\n");
    }
  } else {
    printf("[FALHOU] teste_lista_retira_dados_validos\n");
  }
}

void teste_lista_retira_dados_nulos() {
  if (lista_retira(NULL, -1) == NULL) {
    printf("[PASSOU] teste_lista_retira_dados_nulos\n");
  } else {
    printf("[FALHOU] teste_lista_retira_dados_nulos\n");
  }
}

void teste_lista_busca_dados_validos() {
  int id;
  char nome[30];
  char endereco[30];

  Lista *lista = lista_cria();
  if (lista != NULL) {
    Passageiro *Victor = criarPassageiro(1, "Victor", "Pici");
    lista_insere(lista, Victor);
    Passageiro *Lucas = criarPassageiro(2, "Lucas", "Bom Jardim");
    lista_insere(lista, Lucas);
    Passageiro *Joel = criarPassageiro(3, "Joel", "Vincente Pinzon");
    lista_insere(lista, Joel);
    Passageiro *aux = lista_busca(lista, 2);
    if (aux != NULL) {
      passageiroAcessa(aux, &id, nome, endereco);
      if (id == 2 && strcmp(nome, "Lucas") == 0 && strcmp(endereco, "Bom Jardim") == 0) {
        printf("[PASSOU] teste_lista_busca_dados_validos\n");
      } else {
        printf("[FALHOU] teste_lista_busca_dados_validos\n");
      }
    } else {
      printf("[FALHOU] teste_lista_busca_dados_validos\n");
    }
  } else {
    printf("[FALHOU] teste_lista_busca_dados_validos\n");
  }
}

void teste_lista_busca_dados_invalidos() {
  Lista *lista = lista_cria();
  if (lista != NULL) {
    Passageiro *Victor = criarPassageiro(1, "Victor", "Pici");
    lista_insere(lista, Victor);
    Passageiro *Lucas = criarPassageiro(2, "Lucas", "Bom Jardim");
    lista_insere(lista, Lucas);
    Passageiro *Joel = criarPassageiro(3, "Joel", "Vincente Pinzon");
    lista_insere(lista, Joel);
    Passageiro *aux = lista_busca(lista, 5);
    if (aux == NULL) {
      printf("[PASSOU] teste_lista_busca_dados_invalidos\n");
    } else {
      printf("[FALHOU] teste_lista_busca_dados_invalidos\n");
    }
  } else {
    printf("[FALHOU] teste_lista_busca_dados_invalidos\n");
  }
}

void teste_lista_busca_dados_nulos() {
  Passageiro *aux = fila_busca(NULL, -1);
  if (aux == NULL) {
    printf("[PASSOU] teste_lista_busca_dados_nulos");
  } else {
    printf("[FALHOU] teste_lista_busca_dados_nulos");
  }
}

int main(void) {
  Passageiro *passageiro1 = criarPassageiro(1, "Jean", "Vincente Pinzon");
  Passageiro *passageiro2 = criarPassageiro(2, "Kauan", "Aracati");
  Passageiro *passageiro3 = criarPassageiro(1, "Gustavo", "Trairi");
  Passageiro *passageiro4 = criarPassageiro(-1, NULL, NULL);

  printf("=-=-=-=-=-=-=-=-=-=-= BATERIA DE TESTES 1 =-=-=-=-=-=-=-=-=-=-=\n");
  testa_criarPassageiro_dados_validos(passageiro1);
  testa_criarPassageiro_dados_invalidos(passageiro4);
  testa_criarPassageiro_dados_nulos(passageiro4);
  printf("=-=-=-=-=-=-=-=-=-=-= BATERIA DE TESTES 2 =-=-=-=-=-=-=-=-=-=-=\n");
  teste_editarPassageiro_dados_validos(passageiro1);
  teste_editarPassageiro_dados_invalidos(passageiro2);
  teste_editarPassageiro_dados_nulos(passageiro1);
  printf("=-=-=-=-=-=-=-=-=-=-= BATERIA DE TESTES 3 =-=-=-=-=-=-=-=-=-=-=\n");
  teste_retira_passageiro_dados_validos(); // falta implementação de funções necessárias
  teste_retira_passageiro_dados_invalidos(passageiro4);
  printf("=-=-=-=-=-=-=-=-=-=-= BATERIA DE TESTES 4 =-=-=-=-=-=-=-=-=-=-=\n");
  teste_lista_cria_dados_validos();
  printf("=-=-=-=-=-=-=-=-=-=-= BATERIA DE TESTES 5 =-=-=-=-=-=-=-=-=-=-=\n");
  teste_lista_libera_dados_validos();
  teste_lista_libera_dados_nulos();
  printf("=-=-=-=-=-=-=-=-=-=-= BATERIA DE TESTES 6 =-=-=-=-=-=-=-=-=-=-=\n");
  teste_lista_vazia_dados_validos();
  printf("=-=-=-=-=-=-=-=-=-=-= BATERIA DE TESTES 7 =-=-=-=-=-=-=-=-=-=-=\n");
  teste_lista_insere_dados_validos();
  teste_lista_insere_dados_invalidos();
  teste_lista_insere_dados_nulos();
  printf("=-=-=-=-=-=-=-=-=-=-= BATERIA DE TESTES 8 =-=-=-=-=-=-=-=-=-=-=\n");
  teste_lista_retira_dados_validos();
  teste_lista_retira_dados_nulos();
  printf("=-=-=-=-=-=-=-=-=-=-= BATERIA DE TESTES 9 =-=-=-=-=-=-=-=-=-=-=\n");
  teste_lista_busca_dados_validos();
  teste_lista_busca_dados_invalidos();
  teste_lista_busca_dados_nulos();  
}