#include "Passageiros.h"
#include "Voos.h"
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
      printf("[PASSOU] teste_editarPassageiro_dados_validos.\n");
    } else {
      printf("[FALHOU] teste_editarPassageiro_dados_validos.\n");
    }
  } else {
    printf("[FALHOU] teste_editarPassageiro_dados_validos.\n");
  }
}

void teste_editarPassageiro_dados_invalidos(Passageiro *passageiro) {
  int id, idAux = 2;
  
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
      printf("[PASSOU] teste_editarPassageiro_dados_invalidos.\n");
    } else {
      printf("[FALHOU] teste_editarPassageiro_dados_invalidos.\n");
    }
  } else {
      printf("[FALHOU] teste_editarPassageiro_dados_invalidos.\n");
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
      printf("[PASSOU] teste_editarPassageiro_dados_nulos.\n");
    } else {
      printf("[PASSOU] teste_editarPassageiro_dados_nulos.\n");
    }
  } else {
    printf("[FALHOU] teste_editarPassageiro_dados_nulos.\n");
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

void teste_lista_passageiro_cria_dados_validos() {
  Lista *lista = lista_cria();
  if (lista != NULL) {
    printf("[PASSOU] teste_lista_passageiro_cria_dados_validos.\n");
  } else {
    printf("[FALHOU] teste_lista_passageiro_cria_dados_validos.\n");
  }
}

void teste_lista_passageiro_libera_dados_validos() {
  Lista *lista = lista_cria();
  lista_libera(&lista);
  if (lista != NULL) {
    printf("[PASSOU] teste_lista_passageiro_libera_dados_validos.\n");
  } else {
    printf("[FALHOU] teste_lista_passageiro_libera_dados_validos.\n");
  }
}

void teste_lista_passageiro_libera_dados_nulos() {
  if (lista_libera(NULL) == 0) {
    printf("[PASSOU] teste_lista_passageiro_libera_dados_nulos.\n");
  } else {
    printf("[FALHOU] teste_lista_passageiro_libera_dados_nulos.\n");
  }
}

void teste_lista_passageiro_vazia_dados_validos() {
  Lista *lista = lista_cria();
  if (lista != NULL && lista_vazia(lista)) {
    printf("[PASSOU] teste_lista_passageiro_vazia_dados_validos.\n");
  } else {
    printf("[FALHOU] teste_lista_passageiro_vazia_dados_validos.\n");
  }
}

void teste_lista_passageiro_insere_dados_validos() {
  Lista *lista = lista_cria();
  if (lista != NULL) {
    Passageiro *Victor = criarPassageiro(1, "Victor", "Pici");
    if (lista_insere(lista, Victor) == 1) {
      Passageiro *Lincoln = criarPassageiro(2, "Lincoln", "Aldeota");
      if (lista_insere(lista, Lincoln) == 1) {
        Passageiro *Neto = criarPassageiro(3, "Neto", "Bom Jardim");
        if (lista_insere(lista, Neto) == 1) {
          printf("[PASSOU] teste_lista_passageiro_insere_dados_validos.\n");
        } else {
          printf("[FALHOU] teste_lista_passageiro_insere_dados_validos.\n");
        }
      } else {
        printf("[FALHOU] teste_lista_passageiro_insere_dados_validos.\n");
      }
    } else {
      printf("[FALHOU] teste_lista_passageiro_insere_dados_validos.\n");
    }
  } else {
    printf("[FALHOU] teste_lista_passageiro_insere_dados_validos.\n");
  }
}

void teste_lista_passageiro_insere_dados_invalidos() {
  Lista *lista = lista_cria();

  if (lista != NULL) {
    Passageiro *Victor = criarPassageiro(1, "Victor", "Pici");
    lista_insere(lista, Victor);
    Passageiro *Lucas = criarPassageiro(1, "Lucas", "Computação");
    if (lista_insere(lista, Lucas) == 0) {
      printf("[PASSOU] teste_lista_passageiro_insere_dados_invalidos\n");
    } else {
      printf("[FALHOU] teste_lista_passageiro_insere_dados_invalidos\n");
    }
  } else {
    printf("[FALHOU] teste_lista_passageiro_insere_dados_invalidos\n");
  }
}

void teste_lista_passageiro_insere_dados_nulos() {
  Lista *lista = lista_cria();
  if (lista_insere(lista, NULL) == -1) {
    Passageiro *Victor = criarPassageiro(1, "Victor", "Pici");
    if (lista_insere(NULL, Victor) == -1) {
      if (lista_insere(NULL, NULL) == -1) {
        printf("[PASSOU] teste_lista_passageiro_insere_dados_nulos\n");
      } else {
        printf("[FALHOU] teste_lista_passageiro_insere_dados_nulos\n");
      }
    } else {
      printf("[FALHOU] teste_lista_passageiro_insere_dados_nulos\n");
    }
  } else {
    printf("[FALHOU] teste_lista_passageiro_insere_dados_nulos\n");
  }
}

void teste_lista_passageiro_retira_dados_validos() {
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
          printf("[PASSOU] teste_lista_passageiro_retira_dados_validos\n");
        } else {
          printf("[FALHOU] teste_lista_passageiro_retira_dados_validos\n");
        }
      } else {
        printf("[FALHOU] teste_lista_passageiro_retira_dados_validos\n");
      }
    } else {
      printf("[FALHOU] teste_lista_passageiro_retira_dados_validos\n");
    }
  } else {
    printf("[FALHOU] teste_lista_passageiro_retira_dados_validos\n");
  }
}

void teste_lista_passageiro_retira_dados_nulos() {
  if (lista_retira(NULL, -1) == NULL) {
    printf("[PASSOU] teste_lista_passageiro_retira_dados_nulos\n");
  } else {
    printf("[FALHOU] teste_lista_passageiro_retira_dados_nulos\n");
  }
}

void teste_lista_passageiro_busca_dados_validos() {
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
        printf("[PASSOU] teste_lista_passageiro_busca_dados_validos\n");
      } else {
        printf("[FALHOU] teste_lista_passageiro_busca_dados_validos\n");
      }
    } else {
      printf("[FALHOU] teste_lista_passageiro_busca_dados_validos\n");
    }
  } else {
    printf("[FALHOU] teste_lista_passageiro_busca_dados_validos\n");
  }
}

void teste_lista_passageiro_busca_dados_invalidos() {
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
      printf("[PASSOU] teste_lista_passageiro_busca_dados_invalidos\n");
    } else {
      printf("[FALHOU] teste_lista_passageiro_busca_dados_invalidos\n");
    }
  } else {
    printf("[FALHOU] teste_lista_passageiro_busca_dados_invalidos\n");
  }
}

void teste_lista_passageiro_busca_dados_nulos() {
  Passageiro *aux = fila_busca(NULL, -1);
  if (aux == NULL) {
    printf("[PASSOU] teste_lista_passageiro_busca_dados_nulos");
  } else {
    printf("[FALHOU] teste_lista_passageiro_busca_dados_nulos");
  }
}

// ================== TESTES FUNÇÕES DE VOO ==================

void testa_criarVoo_dados_validos(Voo *voo) {  
  int codigo;
  char origem[30], destino[30];
  
  vooAcessa(voo, &codigo, origem, destino);

  if ((codigo == 1) && (strcmp(origem, "Fortaleza") == 0) && (strcmp(destino, "Bahia") == 0)) {
    printf("[PASSOU] testa_criarVoo_dados_validos.\n");
  } else {
    printf("[FALHOU] testa_criarVoo_dados_validos.\n");
  } 
}

void testa_criarVoo_dados_invalidos(Voo *voo) {
  if (voo == NULL) {
    printf("[PASSOU] testa_criarVoo_dados_invalidos.\n");
  } else {
    printf("[FALHOU] testa_criarVoo_dados_invalidos.\n");
  }
}

void testa_criarVoo_dados_nulos(Voo *voo) {
  if (voo == NULL) {
    printf("[PASSOU] testa_criarVoo_dados_nulos.\n");
  } else {
    printf("[FALHOU] testa_criarVoo_dados_nulos.\n");
  }
}

void teste_editarVoo_dados_validos(Voo *voo) {
  int codigo, aux = 5;
  char origem[30], destino[30];
  
  if (voo != NULL) {
    editarVoo(voo, aux, "São Paulo", "Rio de Janeiro");
    vooAcessa(voo, &codigo, origem, destino);
    if (codigo == aux && strcmp(origem, "São Paulo") == 0 && strcmp(destino, "Rio de Janeiro") == 0) {
      printf("[PASSOU] teste_editarVoo_dados_validos.\n");
    } else {
      printf("[FALHOU] teste_editarVoo_dados_validos.\n");
    }
  } else {
    printf("[FALHOU] teste_editarVoo_dados_validos.\n");
  }
}

void teste_editarVoo_dados_invalidos(Voo *voo) {
  int codigo, codigoAux = 2;
  
  char origemAux[40], destinoAux[40];

  for (int i = 0; i < 35; i++) {
    strcat(origemAux, "N");
  }
  
  for (int i = 0; i < 35; i++) {
    strcat(destinoAux, "C");
  }
  
  if (voo != NULL) {
    editarVoo(voo, codigoAux, origemAux, destinoAux);
    vooAcessa(voo, &codigo, origemAux, destinoAux);
    if (codigo == codigoAux || strcmp(origemAux, "Morada Nova") == 0 || strcmp(destinoAux, "Trairi") == 0) {
      printf("[PASSOU] teste_editarVoo_dados_invalidos.\n");
    } else {
      printf("[FALHOU] teste_editarVoo_dados_invalidos.\n");
    }
  } else {
      printf("[FALHOU] teste_editarVoo_dados_invalidos.\n");
  }
}

void teste_editarVoo_dados_nulos(Voo *voo) {
  int codigo, aux = 5, auxERRADA = -1;
  char origem[30];
  char destino[30];
  
  if (voo != NULL) {
    editarVoo(NULL, auxERRADA, NULL, NULL);
    vooAcessa(voo, &codigo, origem, destino);
    if (codigo == aux || strcmp(origem, "São Paulo") == 0 || strcmp(destino, "Rio de Janeiro") == 0) {
      printf("[PASSOU] teste_editarVoo_dados_nulos.\n");
    } else {
      printf("[PASSOU] teste_editarVoo_dados_nulos.\n");
    }
  } else {
    printf("[FALHOU] teste_editarVoo_dados_nulos.\n");
  }
}

void teste_retira_voo_dados_validos() {
  ListaVoo *listaVoo = listaVoo_cria();
  if (listaVoo != NULL) {
    Voo *voo1 = criarVoo(1, "Juazeiro do Norte", "Bahia");
    listaVoo_insere(listaVoo, voo1);
    Voo *voo2 = criarVoo(2, "São Paulo", "Pindoretama");
    listaVoo_insere(listaVoo, voo2);
    Voo *voo3 = criarVoo(3, "Itaitinga", "Sobral");
    listaVoo_insere(listaVoo, voo3);
    Voo *voo = listaVoo_retira(listaVoo, 2);

    if (vooIgual(voo, voo2) == 1) {
      voo = listaVoo_retira(listaVoo, 3);
      if (vooIgual(voo, voo3) == 1) {
        voo = listaVoo_retira(listaVoo, 1);
        if (vooIgual(voo, voo1) == 1) {
          printf("[PASSOU] teste_retira_voo_dados_validos.\n");
        } else {
          printf("[FALHOU] teste_retira_voo_dados_validos.\n");
        }
      } else {
        printf("[FALHOU] teste_retira_voo_dados_validos.\n");
      }
    } else {
      printf("[FALHOU] teste_retira_voo_dados_validos.\n");
    }
  } else {
    printf("[FALHOU] teste_retira_voo_dados_validos.\n");
  }
}

void teste_retira_voo_dados_invalidos(Passageiro *passageiro) {
  if (listaVoo_retira(NULL, -1) == NULL) {
    printf("[PASSOU] teste_retira_voo_dados_invalidos.\n");
  } else {
    printf("[FALHOU] teste_retira_voo_dados_invalidos.\n");
  }
}

// ================== TESTES FUNÇÕES DE LISTA DE VOOS ==================


int main(void) {
  Passageiro *passageiro1 = criarPassageiro(1, "Jean", "Vincente Pinzon");
  Passageiro *passageiro2 = criarPassageiro(2, "Kauan", "Aracati");
  Passageiro *passageiro3 = criarPassageiro(1, "Gustavo", "Trairi");
  Passageiro *passageiro4 = criarPassageiro(-1, NULL, NULL);
  
  printf("=-=-=-=-=-=-=-=-=-=-= BATERIA DE TESTES CRIAR PASSAGEIRO =-=-=-=-=-=-=-=-=-=-=\n");
  testa_criarPassageiro_dados_validos(passageiro1);
  testa_criarPassageiro_dados_invalidos(passageiro3);
  testa_criarPassageiro_dados_nulos(passageiro4);
  printf("=-=-=-=-=-=-=-=-=-=-= BATERIA DE TESTES EDITAR PASSAGEIRO =-=-=-=-=-=-=-=-=-=-=\n");
  teste_editarPassageiro_dados_validos(passageiro1);
  teste_editarPassageiro_dados_invalidos(passageiro2);
  teste_editarPassageiro_dados_nulos(passageiro1);
  printf("=-=-=-=-=-=-=-=-=-=-= BATERIA DE TESTES RETIRA PASSAGEIRO =-=-=-=-=-=-=-=-=-=-=\n");
  teste_retira_passageiro_dados_validos(); // falta implementação de funções necessárias
  teste_retira_passageiro_dados_invalidos(passageiro4);
  printf("=-=-=-=-=-=-=-=-=-=-= BATERIA DE TESTES LISTA PASSAGEIROS CRIA =-=-=-=-=-=-=-=-=-=-=\n");
  teste_lista_passageiro_cria_dados_validos();
  printf("=-=-=-=-=-=-=-=-=-=-= BATERIA DE TESTES LISTA PASSAGEIROS LIBERA =-=-=-=-=-=-=-=-=-=-=\n");
  teste_lista_passageiro_libera_dados_validos();
  teste_lista_passageiro_libera_dados_nulos();
  printf("=-=-=-=-=-=-=-=-=-=-= BATERIA DE TESTES LISTA PASSAGEIROS VAZIA =-=-=-=-=-=-=-=-=-=-=\n");
  teste_lista_passageiro_vazia_dados_validos();
  printf("=-=-=-=-=-=-=-=-=-=-= BATERIA DE TESTES LISTA PASSAGEIROS INSERE =-=-=-=-=-=-=-=-=-=-=\n");
  teste_lista_passageiro_insere_dados_validos();
  teste_lista_passageiro_insere_dados_invalidos();
  teste_lista_passageiro_insere_dados_nulos();
  printf("=-=-=-=-=-=-=-=-=-=-= BATERIA DE TESTES LISTA PASSAGEIROS RETIRA =-=-=-=-=-=-=-=-=-=-=\n");
  teste_lista_passageiro_retira_dados_validos();
  teste_lista_passageiro_retira_dados_nulos();
  printf("=-=-=-=-=-=-=-=-=-=-= BATERIA DE TESTES LISTA PASSAGEIROS BUSCA =-=-=-=-=-=-=-=-=-=-=\n");
  teste_lista_passageiro_busca_dados_validos();
  teste_lista_passageiro_busca_dados_invalidos();
  teste_lista_passageiro_busca_dados_nulos();  
  
  Voo *voo1 = criarVoo(1, "Fortaleza", "Bahia");
  Voo *voo2 = criarVoo(2, "Quixeramobim", "Sobrail");
  Voo *voo3 = criarVoo(1, "Morada Nova", "Trairi");
  Voo *voo4 = criarVoo(-1, NULL, NULL);
  
  printf("=-=-=-=-=-=-=-=-=-=-= BATERIA DE TESTES CRIAR VOO =-=-=-=-=-=-=-=-=-=-=\n");
  testa_criarVoo_dados_validos(voo1);
  testa_criarVoo_dados_invalidos(voo3);
  testa_criarVoo_dados_nulos(voo4);
  printf("=-=-=-=-=-=-=-=-=-=-= BATERIA DE TESTES EDITAR PASSAGEIRO =-=-=-=-=-=-=-=-=-=-=\n");
  teste_editarVoo_dados_validos(voo1);
  teste_editarVoo_dados_invalidos(voo2);
  teste_editarVoo_dados_nulos(voo1);
}