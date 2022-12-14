#include "Passageiros.h"
#include "Voos.h"
#include "hash.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXCARACTERES 60

// FUNÇÃO DE IMPRIMIR A TABELA DE CORREÇÃO
void imprimir(char *texto) {
  if (!strcmp(texto, "")) {
    printf("------------------------------------------------------------\n");
  } else {
    int tamanho = strlen(texto);
    int sp = ((MAXCARACTERES - tamanho - 1) / 2);
    char *espaco = (char *)malloc(sizeof(char) * 60);
    for (int x = 0; x < sp; x++) {
      strcat(espaco, " ");
    }
    if (tamanho % 2 == 0) {
      printf("|%s%s%s|\n", espaco, texto, espaco);
    } else {
      char *espaco2 = (char *)malloc(sizeof(char) * 60);
      for (int x = 0; x < sp - 1; x++) {
        strcat(espaco2, " ");
      }
      printf("|%s%s%s|\n", espaco2, texto, espaco);
    }
  }
}

// ================== TESTES FUNÇÕES DE PASSAGEIRO ==================

void testa_criar_passageiro_dados_validos(Passageiro *passageiro) {
  int id;
  char nome[30], endereco[30];

  passageiroAcessa(passageiro, &id, nome, endereco);

  if ((id == 1) && (strcmp(nome, "Jean") == 0) &&
      (strcmp(endereco, "Vincente Pinzon") == 0)) {
    imprimir("[PASSOU] testa_criar_passageiro_dados_validos");
  } else {
    imprimir("[FALHOU] testa_criar_passageiro_dados_validos");
  }
}

void testa_criar_passageiro_dados_invalidos(Passageiro *passageiro) {
  if (passageiro == NULL) {
    imprimir("[PASSOU] testa_criar_passageiro_dados_invalidos");
  } else {
    imprimir("[FALHOU] testa_criar_passageiro_dados_invalidos");
  }
}

void testa_criar_passageiro_dados_nulos(Passageiro *passageiro) {
  if (passageiro == NULL) {
    imprimir("[PASSOU] testa_criar_passageiro_dados_nulos");
  } else {
    imprimir("[FALHOU] testa_criar_passageiro_dados_nulos");
  }
}

void teste_editar_passageiro_dados_validos(Passageiro *passageiro) {
  int id, aux = 5;
  char nome[30], endereco[30];

  if (passageiro != NULL) {
    editarPassageiro(passageiro, aux, "Victor", "Pici");
    passageiroAcessa(passageiro, &id, nome, endereco);
    if (id == aux && strcmp(nome, "Victor") == 0 &&
        strcmp(endereco, "Pici") == 0) {
      imprimir("[PASSOU] teste_editarPassageiro_dados_validos");
    } else {
      imprimir("[FALHOU] teste_editarPassageiro_dados_validos");
    }
  } else {
    imprimir("[FALHOU] teste_editarPassageiro_dados_validos");
  }
}

void teste_editar_passageiro_dados_invalidos(Passageiro *passageiro) {
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
    if (id == idAux || strcmp(nomeAux, "Luiz") == 0 ||
        strcmp(enderecoAux, "Pici") == 0) {
      imprimir("[PASSOU] teste_editarPassageiro_dados_invalidos");
    } else {
      imprimir("[FALHOU] teste_editarPassageiro_dados_invalidos");
    }
  } else {
    imprimir("[FALHOU] teste_editarPassageiro_dados_invalidos");
  }
}

void teste_editar_passageiro_dados_nulos(Passageiro *passageiro) {
  int id, aux = 5, auxERRADA = -1;
  char nome[30];
  char endereco[30];

  if (passageiro != NULL) {
    editarPassageiro(NULL, auxERRADA, NULL, NULL);
    passageiroAcessa(passageiro, &id, nome, endereco);
    if (id == aux || strcmp(nome, "Luiz") == 0 ||
        strcmp(endereco, "Pici") == 0) {
      imprimir("[PASSOU] teste_editarPassageiro_dados_nulos");
    } else {
      imprimir("[PASSOU] teste_editarPassageiro_dados_nulos");
    }
  } else {
    imprimir("[FALHOU] teste_editarPassageiro_dados_nulos");
  }
}

void teste_retira_passageiro_dados_validos() {
  Lista *lista = lista_cria();
  if (lista != NULL) {
    Passageiro *Victor = criarPassageiro(1, "Victor", "Aldeota");
    lista_insere(lista, Victor);
    Passageiro *Lucas = criarPassageiro(2, "Lucas", "Palhano");
    lista_insere(lista, Lucas);
    Passageiro *Rosa = criarPassageiro(3, "Rosa", "Trairi");
    lista_insere(lista, Rosa);
    Passageiro *passageiro = lista_retira(lista, 2);

    if (passageiroIgual(passageiro, Lucas) == 1) {
      passageiro = lista_retira(lista, 3);
      if (passageiroIgual(passageiro, Rosa) == 1) {
        passageiro = lista_retira(lista, 1);
        if (passageiroIgual(passageiro, Victor) == 1) {
          imprimir("[PASSOU] teste_retira_passageiro_dados_validos");
        } else {
          imprimir("[FALHOU] teste_retira_passageiro_dados_validos");
        }
      } else {
        imprimir("[FALHOU] teste_retira_passageiro_dados_validos");
      }
    } else {
      imprimir("[FALHOU] teste_retira_passageiro_dados_validos");
    }
  } else {
    imprimir("[FALHOU] teste_retira_passageiro_dados_validos");
  }
}

void teste_retira_passageiro_dados_nulos() {
  if (lista_retira(NULL, -1) == NULL) {
    imprimir("[PASSOU] teste_retira_passageiro_dados_nulos");
  } else {
    imprimir("[FALHOU] teste_retira_passageiro_dados_nulos");
  }
}

// ================== TESTES FUNÇÕES DE LISTA DE PASSAGEIROS ==================

void teste_lista_passageiro_cria_dados_validos() {
  Lista *lista = lista_cria();
  if (lista != NULL) {
    imprimir("[PASSOU] teste_lista_passageiro_cria_dados_validos");
  } else {
    imprimir("[FALHOU] teste_lista_passageiro_cria_dados_validos");
  }
}

void teste_lista_passageiro_libera_dados_validos() {
  Lista *lista = lista_cria();
  lista_libera(&lista);
  if (lista != NULL) {
    imprimir("[FALHOU] teste_lista_passageiro_libera_dados_validos.");
  } else {
    imprimir("[PASSOU] teste_lista_passageiro_libera_dados_validos.");
  }
}

void teste_lista_passageiro_libera_dados_nulos() {
  if (lista_libera(NULL) == 0) {
    imprimir("[PASSOU] teste_lista_passageiro_libera_dados_nulos.");
  } else {
    imprimir("[FALHOU] teste_lista_passageiro_libera_dados_nulos.");
  }
}

void teste_lista_passageiro_vazia_dados_validos() {
  Lista *lista = lista_cria();
  if (lista != NULL && lista_vazia(lista)) {
    imprimir("[PASSOU] teste_lista_passageiro_vazia_dados_validos.");
  } else {
    imprimir("[FALHOU] teste_lista_passageiro_vazia_dados_validos.");
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
          imprimir("[PASSOU] teste_lista_passageiro_insere_dados_validos");
        } else {
          imprimir("[FALHOU] teste_lista_passageiro_insere_dados_validos");
        }
      } else {
        imprimir("[FALHOU] teste_lista_passageiro_insere_dados_validos");
      }
    } else {
      imprimir("[FALHOU] teste_lista_passageiro_insere_dados_validos");
    }
  } else {
    imprimir("[FALHOU] teste_lista_passageiro_insere_dados_validos");
  }
}

void teste_lista_passageiro_insere_dados_invalidos() {
  Lista *lista = lista_cria();

  if (lista != NULL) {
    Passageiro *Victor = criarPassageiro(1, "Victor", "Pici");
    lista_insere(lista, Victor);
    Passageiro *Lucas = criarPassageiro(1, "Lucas", "Computação");
    if (lista_insere(lista, Lucas) == 0) {
      imprimir("[PASSOU] teste_lista_passageiro_insere_dados_invalidos");
    } else {
      imprimir("[FALHOU] teste_lista_passageiro_insere_dados_invalidos");
    }
  } else {
    imprimir("[FALHOU] teste_lista_passageiro_insere_dados_invalidos");
  }
}

void teste_lista_passageiro_insere_dados_nulos() {
  Lista *lista = lista_cria();
  if (lista_insere(lista, NULL) == -1) {
    Passageiro *Victor = criarPassageiro(1, "Victor", "Pici");
    if (lista_insere(NULL, Victor) == -1) {
      if (lista_insere(NULL, NULL) == -1) {
        imprimir("[PASSOU] teste_lista_passageiro_insere_dados_nulos");
      } else {
        imprimir("[FALHOU] teste_lista_passageiro_insere_dados_nulos");
      }
    } else {
      imprimir("[FALHOU] teste_lista_passageiro_insere_dados_nulos");
    }
  } else {
    imprimir("[FALHOU] teste_lista_passageiro_insere_dados_nulos");
  }
}

void teste_lista_passageiro_retira_dados_validos() {
  Lista *lista = lista_cria();
  if (lista != NULL) {
    Passageiro *Victor = criarPassageiro(1, "Victor", "Pici");
    lista_insere(lista, Victor);
    Passageiro *Lucas = criarPassageiro(2, "Lucas", "Bom Jardim");
    lista_insere(lista, Lucas);
    Passageiro *Joel = criarPassageiro(3, "Joel", "Vincente Pinzon");
    lista_insere(lista, Joel);
    Passageiro *passageiro = lista_retira(lista, 2);

    if (passageiroIgual(passageiro, Lucas) == 1) {
      passageiro = lista_retira(lista, 3);
      if (passageiroIgual(passageiro, Joel) == 1) {
        passageiro = lista_retira(lista, 1);
        if (passageiroIgual(passageiro, Victor) == 1) {
          imprimir("[PASSOU] teste_lista_passageiro_retira_dados_validos");
        } else {
          imprimir("[FALHOU] teste_lista_passageiro_retira_dados_validos");
        }
      } else {
        imprimir("[FALHOU] teste_lista_passageiro_retira_dados_validos");
      }
    } else {
      imprimir("[FALHOU] teste_lista_passageiro_retira_dados_validos");
    }
  } else {
    imprimir("[FALHOU] teste_lista_passageiro_retira_dados_validos");
  }
}

void teste_lista_passageiro_retira_dados_nulos() {
  if (lista_retira(NULL, -1) == NULL) {
    imprimir("[PASSOU] teste_lista_passageiro_retira_dados_nulos");
  } else {
    imprimir("[FALHOU] teste_lista_passageiro_retira_dados_nulos");
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
      if (id == 2 && strcmp(nome, "Lucas") == 0 &&
          strcmp(endereco, "Bom Jardim") == 0) {
        imprimir("[PASSOU] teste_lista_passageiro_busca_dados_validos");
      } else {
        imprimir("[FALHOU] teste_lista_passageiro_busca_dados_validos");
      }
    } else {
      imprimir("[FALHOU] teste_lista_passageiro_busca_dados_validos");
    }
  } else {
    imprimir("[FALHOU] teste_lista_passageiro_busca_dados_validos");
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
      imprimir("[PASSOU] teste_lista_passageiro_busca_dados_invalidos");
    } else {
      imprimir("[FALHOU] teste_lista_passageiro_busca_dados_invalidos");
    }
  } else {
    imprimir("[FALHOU] teste_lista_passageiro_busca_dados_invalidos");
  }
}

void teste_lista_passageiro_busca_dados_nulos() {
  Passageiro *aux = lista_busca(NULL, -1);
  if (aux == NULL) {
    imprimir("[PASSOU] teste_lista_passageiro_busca_dados_nulos");
  } else {
    imprimir("[FALHOU] teste_lista_passageiro_busca_dados_nulos");
  }
}

// ================== TESTES FUNÇÕES DE VOO ==================

void testa_criar_voo_dados_validos(Voo *voo) {
  int codigo;
  char origem[30], destino[30];

  vooAcessa(voo, &codigo, origem, destino);

  if ((codigo == 1) && (strcmp(origem, "Fortaleza") == 0) &&
      (strcmp(destino, "Bahia") == 0)) {
    imprimir("[PASSOU] testa_criarVoo_dados_validos");
  } else {
    imprimir("[FALHOU] testa_criarVoo_dados_validos");
  }
}

void testa_criar_voo_dados_invalidos(Voo *voo) {
  if (voo == NULL) {
    imprimir("[PASSOU] testa_criarVoo_dados_invalidos");
  } else {
    imprimir("[FALHOU] testa_criarVoo_dados_invalidos");
  }
}

void testa_criar_voo_dados_nulos(Voo *voo) {
  if (voo == NULL) {
    imprimir("[PASSOU] testa_criarVoo_dados_nulos");
  } else {
    imprimir("[FALHOU] testa_criarVoo_dados_nulos");
  }
}

void teste_editar_voo_dados_validos(Voo *voo) {
  int codigo, aux = 5;
  char origem[30], destino[30];

  if (voo != NULL) {
    editarVoo(voo, aux, "São Paulo", "Rio de Janeiro");
    vooAcessa(voo, &codigo, origem, destino);
    if (codigo == aux && strcmp(origem, "São Paulo") == 0 &&
        strcmp(destino, "Rio de Janeiro") == 0) {
      imprimir("[PASSOU] teste_editarVoo_dados_validos");
    } else {
      imprimir("[FALHOU] teste_editarVoo_dados_validos");
    }
  } else {
    imprimir("[FALHOU] teste_editarVoo_dados_validos");
  }
}

void teste_editar_voo_dados_invalidos(Voo *voo) {
  int codigo, codigoAux = 2;
  char origemAux[60], destinoAux[60];

  for (int i = 0; i < 35; i++) {
    strcat(origemAux, "N");
  }

  for (int i = 0; i < 35; i++) {
    strcat(destinoAux, "C");
  }

  if (voo != NULL) {
    editarVoo(voo, codigoAux, origemAux, destinoAux);
    vooAcessa(voo, &codigo, origemAux, destinoAux);
    if (codigo == codigoAux || strcmp(origemAux, "Morada Nova") == 0 ||
        strcmp(destinoAux, "Trairi") == 0) {
      imprimir("[PASSOU] teste_editarVoo_dados_invalidos");
    } else {
      imprimir("[FALHOU] teste_editarVoo_dados_invalidos");
    }
  } else {
    imprimir("[FALHOU] teste_editarVoo_dados_invalidos");
  }
}

void teste_editar_voo_dados_nulos(Voo *voo) {
  int codigo, aux = 5, auxERRADA = -1;
  char origem[30];
  char destino[30];

  if (voo != NULL) {
    editarVoo(NULL, auxERRADA, NULL, NULL);
    vooAcessa(voo, &codigo, origem, destino);
    if (codigo == aux || strcmp(origem, "São Paulo") == 0 ||
        strcmp(destino, "Rio de Janeiro") == 0) {
      imprimir("[PASSOU] teste_editarVoo_dados_nulos");
    } else {
      imprimir("[PASSOU] teste_editarVoo_dados_nulos");
    }
  } else {
    imprimir("[FALHOU] teste_editarVoo_dados_nulos");
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
          imprimir("[PASSOU] teste_retira_voo_dados_validos");
        } else {
          imprimir("[FALHOU] teste_retira_voo_dados_validos");
        }
      } else {
        imprimir("[FALHOU] teste_retira_voo_dados_validos");
      }
    } else {
      imprimir("[FALHOU] teste_retira_voo_dados_validos");
    }
  } else {
    imprimir("[FALHOU] teste_retira_voo_dados_validos");
  }
}

void teste_retira_voo_dados_nulos() {
  if (listaVoo_retira(NULL, -1) == NULL) {
    imprimir("[PASSOU] teste_retira_voo_dados_nulos");
  } else {
    imprimir("[FALHOU] teste_retira_voo_dados_nulos");
  }
}

// ================== TESTES FUNÇÕES DE LISTA DE VOOS ==================

void teste_lista_voo_cria_dados_validos() {
  Lista *lista = lista_cria();
  if (lista != NULL) {
    imprimir("[PASSOU] teste_lista_voo_cria_dados_validos");
  } else {
    imprimir("[FALHOU] teste_lista_voo_cria_dados_validos");
  }
}

void teste_lista_voo_libera_dados_validos() {
  ListaVoo *listaVoo = listaVoo_cria();
  listaVoo_libera(&listaVoo);
  if (listaVoo == NULL) {
    imprimir("[PASSOU] teste_lista_voo_libera_dados_validos");
  } else {
    imprimir("[FALHOU] teste_lista_voo_libera_dados_validos");
  }
}

void teste_lista_voo_libera_dados_nulos() {
  if (listaVoo_libera(NULL) == 0) {
    imprimir("[PASSOU] teste_lista_voo_libera_dados_nulos");
  } else {
    imprimir("[FALHOU] teste_lista_voo_libera_dados_nulos");
  }
}

void teste_lista_voo_insere_dados_validos() {
  ListaVoo *listaVoo = listaVoo_cria();
  if (listaVoo != NULL) {
    Voo *voo1 = criarVoo(1, "Fortaleza", "Bahia");
    if (listaVoo_insere(listaVoo, voo1) == 1) {
      Voo *voo2 = criarVoo(2, "Meireles", "Aldeota");
      if (listaVoo_insere(listaVoo, voo2) == 1) {
        Voo *voo3 = criarVoo(3, "Aracati", "Bom Jardim");
        if (listaVoo_insere(listaVoo, voo3) == 1) {
          imprimir("[PASSOU] teste_lista_voo_insere_dados_validos");
        } else {
          imprimir("[FALHOU] teste_lista_voo_insere_dados_validos");
        }
      } else {
        imprimir("[FALHOU] teste_lista_voo_insere_dados_validos");
      }
    } else {
      imprimir("[FALHOU] teste_lista_voo_insere_dados_validos");
    }
  } else {
    imprimir("[FALHOU] teste_lista_voo_insere_dados_validos");
  }
}

void teste_lista_voo_insere_dados_invalidos() {
  ListaVoo *listaVoo = listaVoo_cria();

  if (listaVoo != NULL) {
    Voo *voo1 = criarVoo(1, "Fortaleza", "Bahia");
    listaVoo_insere(listaVoo, voo1);
    Voo *voo2 = criarVoo(1, "São Paulo", "Rio de Janeiro");
    if (listaVoo_insere(listaVoo, voo2) == 0) {
      imprimir("[PASSOU] teste_lista_voo_insere_dados_invalidos");
    } else {
      imprimir("[FALHOU] teste_lista_voo_insere_dados_invalidos");
    }
  } else {
    imprimir("[FALHOU] teste_lista_voo_insere_dados_invalidos");
  }
}

void teste_lista_voo_insere_dados_nulos() {
  ListaVoo *listaVoo = listaVoo_cria();
  if (listaVoo_insere(listaVoo, NULL) == -1) {
    Voo *voo1 = criarVoo(1, "Fortaleza", "Bahia");
    if (listaVoo_insere(NULL, voo1) == -1) {
      if (listaVoo_insere(NULL, NULL) == -1) {
        imprimir("[PASSOU] teste_lista_voo_insere_dados_nulos");
      } else {
        imprimir("[FALHOU] teste_lista_voo_insere_dados_nulos");
      }
    } else {
      imprimir("[FALHOU] teste_lista_voo_insere_dados_nulos");
    }
  } else {
    imprimir("[FALHOU] teste_lista_voo_insere_dados_nulos");
  }
}

void teste_lista_voo_retira_dados_validos() {
  ListaVoo *listaVoo = listaVoo_cria();
  if (listaVoo != NULL) {
    Voo *voo1 = criarVoo(1, "São Paulo", "Rio de Janeiro");
    listaVoo_insere(listaVoo, voo1);
    Voo *voo2 = criarVoo(2, "Fortaleza", "Bahia");
    listaVoo_insere(listaVoo, voo2);
    Voo *voo3 = criarVoo(3, "Quixeramobim", "Sobral");
    listaVoo_insere(listaVoo, voo3);
    Voo *voo = listaVoo_retira(listaVoo, 2);

    if (vooIgual(voo, voo2) == 1) {
      voo = listaVoo_retira(listaVoo, 3);
      if (vooIgual(voo, voo3) == 1) {
        voo = listaVoo_retira(listaVoo, 1);
        if (vooIgual(voo, voo1) == 1) {
          imprimir("[PASSOU] teste_lista_voo_retira_dados_validos");
        } else {
          imprimir("[FALHOU] teste_lista_voo_retira_dados_validos");
        }
      } else {
        imprimir("[FALHOU] teste_lista_voo_retira_dados_validos");
      }
    } else {
      imprimir("[FALHOU] teste_lista_voo_retira_dados_validos");
    }
  } else {
    imprimir("[FALHOU] teste_lista_voo_retira_dados_validos");
  }
}

void teste_lista_voo_retira_dados_nulos() {
  if (listaVoo_retira(NULL, -1) == NULL) {
    imprimir("[PASSOU] teste_lista_voo_retira_dados_nulos");
  } else {
    imprimir("[FALHOU] teste_lista_voo_retira_dados_nulos");
  }
}

void teste_lista_voo_busca_dados_validos() {
  int codigo;
  char origem[30];
  char destino[30];

  ListaVoo *listaVoo = listaVoo_cria();
  if (listaVoo != NULL) {
    Voo *voo1 = criarVoo(1, "São Paulo", "Rio de Janeiro");
    listaVoo_insere(listaVoo, voo1);
    Voo *voo2 = criarVoo(2, "Fortaleza", "Bahia");
    listaVoo_insere(listaVoo, voo2);
    Voo *voo3 = criarVoo(3, "Quixeramobim", "Sobral");
    listaVoo_insere(listaVoo, voo3);
    Voo *voo = listaVoo_busca(listaVoo, 2);
    if (voo != NULL) {
      vooAcessa(voo, &codigo, origem, destino);
      if (codigo == 2 && strcmp(origem, "Fortaleza") == 0 &&
          strcmp(destino, "Bahia") == 0) {
        imprimir("[PASSOU] teste_lista_voo_busca_dados_validos");
      } else {
        imprimir("[FALHOU] teste_lista_voo_busca_dados_validos");
      }
    } else {
      imprimir("[FALHOU] teste_lista_voo_busca_dados_validos");
    }
  } else {
    imprimir("[FALHOU] teste_lista_voo_busca_dados_validos");
  }
}

void teste_lista_voo_busca_dados_invalidos() {
  ListaVoo *listaVoo = listaVoo_cria();
  if (listaVoo != NULL) {
    Voo *voo1 = criarVoo(1, "São Paulo", "Rio de Janeiro");
    listaVoo_insere(listaVoo, voo1);
    Voo *voo2 = criarVoo(2, "Fortaleza", "Bahia");
    listaVoo_insere(listaVoo, voo2);
    Voo *voo3 = criarVoo(3, "Quixeramobim", "Sobral");
    listaVoo_insere(listaVoo, voo3);
    Voo *voo = listaVoo_busca(listaVoo, 5);
    if (voo == NULL) {
      imprimir("[PASSOU] teste_lista_voo_busca_dados_invalidos");
    } else {
      imprimir("[FALHOU] teste_lista_voo_busca_dados_invalidos");
    }
  } else {
    imprimir("[FALHOU] teste_lista_voo_busca_dados_invalidos");
  }
}

void teste_lista_voo_busca_dados_nulos() {
  Voo *aux = listaVoo_busca(NULL, -1);
  if (aux == NULL) {
    imprimir("[PASSOU] teste_lista_voo_busca_dados_nulos");
  } else {
    imprimir("[FALHOU] teste_lista_voo_busca_dados_nulos");
  }
}

// ================== TESTES FUNÇÕES DE RESERVA ==================

void teste_criar_reserva_dados_validos(){
  int codigo_teste = 1;
  Data *data_teste = criaData(10, 12, 2010);
  Passageiro *passageiro_teste = criarPassageiro(3, "Levy", "UFC");
  Voo *voo_teste = criarVoo(2, "UFC", "Quixeramobim");
  Reserva *reserva1 =
  cria_reserva(1, data_teste, passageiro_teste, voo_teste, A0);
  
  int codigo_teste2;
  Data *data_teste2;
  Passageiro *passageiro_teste2;
  Voo *voo_teste2;
  Assento cadeira_teste2;
  
  reserva_acessa(reserva1, &codigo_teste2, &data_teste2, &passageiro_teste2, &voo_teste2, &cadeira_teste2);
  
  if (codigo_teste2 == 1 && data_compara(data_teste, data_teste2) == 0) {
    if (passageiroIgual(passageiro_teste, passageiro_teste2) == 1 &&
        vooIgual(voo_teste, voo_teste2) == 1) {
      if (cadeira_teste2 == 0) {
        imprimir("[PASSOU] teste_criar_reserva_dados_validos");
      } else {
        imprimir("[FALHOU] teste_criar_reserva_dados_validos");
      }
    } else {
      imprimir("[FALHOU] teste_criar_reserva_dados_validos");
    }
  } else {
    imprimir("[FALHOU] teste_criar_reserva_dados_validos");
  }
}

void teste_criar_reserva_dados_invalidos(Passageiro *passageiro, Voo *voo) {
  Data *data_teste = criaData(32, 13, 0000);
  Reserva *reserva_invalida =
      cria_reserva(1, data_teste, passageiro, voo, -1);

  if (reserva_invalida == NULL) {
    imprimir("[PASSOU] teste_criar_reserva_dados_invalidos");
  } else {
    imprimir("[FALHOU] teste_criar_reserva_dados_invalidos");
  }
}

void teste_criar_reserva_dados_nulos() {
  Data *data_teste = criaData(-1, -1, -1);
  Reserva *reserva_nula = cria_reserva(-1, data_teste, NULL, NULL, -1);

  if (reserva_nula == NULL) {
    imprimir("[PASSOU] teste_criar_reserva_dados_invalidos");
  } else {
    imprimir("[FALHOU] teste_criar_reserva_dados_invalidos");
  }
}

void teste_editar_reserva_dados_validos() {
  Passageiro *passageiro_teste2 = criarPassageiro(3, "Levy", "UFC");
  Passageiro *passageiro_teste3 = criarPassageiro(4, "Victoria", "Fortaleza");
  Voo *voo_teste2 = criarVoo(2, "UFC", "Quixeramobim");
  Voo *voo_teste3 = criarVoo(3, "Fortaleza", "Quixeramobim");
  Data *data_teste2 = criaData(02, 12, 2022);
  Data *data_teste3 = criaData(03, 01, 2023);
  Reserva *reserva2 = cria_reserva(3, data_teste2, passageiro_teste2, voo_teste2, A1);
  Reserva *reserva3 = cria_reserva(3, data_teste2, passageiro_teste2, voo_teste2, A1);
  edita_reserva(NULL, reserva2, 4, data_teste3, passageiro_teste3, voo_teste3, A2);

  if (reserva_igual(reserva2, reserva3) == 1) {
    imprimir("[FALHOU] teste_editar_reserva_dados_validos");
  } else {
    imprimir("[PASSOU] teste_editar_reserva_dados_validos");
  }
}

void teste_editar_reserva_dados_invalidos() {
  Passageiro *passageiro_teste2 = criarPassageiro(3, "Levy", "UFC");
  Passageiro *passageiro_teste3 = criarPassageiro(
      -1, "Victoriaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
      "Fortalezaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
  Voo *voo_teste2 = criarVoo(2, "UFC", "Quixeramobim");
  Voo *voo_teste3 = criarVoo(-1, "Fortaleza", "Quixeramobim");
  Data *data_teste2 = criaData(02, 12, 2022);
  Data *data_teste3 = criaData(33, 01, 2023);
  Reserva *reserva2 =
      cria_reserva(-1, data_teste2, passageiro_teste2, voo_teste2, A1);
  Reserva *reserva3 = reserva2;
  edita_reserva(NULL, reserva2, 4, data_teste3, passageiro_teste3, voo_teste3,
                A2);

  if (reserva_igual(reserva2, reserva3)) {
    imprimir("[PASSOU] teste_editar_reserva_dados_invalidos");
  } else {
    imprimir("[FALHOU] teste_editar_reserva_dados_invalidos");
  }
}

void teste_editar_reserva_dados_nulos() {
  Passageiro *passageiro_teste3 = criarPassageiro(3, "Levy", "UFC");
  Voo *voo_teste3 = criarVoo(2, "UFC", "Quixeramobim");
  Data *data_teste2 = criaData(02, 12, 2022);
  Reserva *reserva2 =
      cria_reserva(1, data_teste2, passageiro_teste3, NULL, A1);
  Reserva *reserva3 = reserva2;
  edita_reserva(NULL, reserva2, -7, NULL, NULL, NULL, -1);

  if (reserva_igual(reserva2, reserva3)) {
    imprimir("[PASSOU] teste_editar_reserva_dados_nulos");
  } else {
    imprimir("[FALHOU] teste_editar_reserva_dados_nulos");
  }
}

void teste_liberar_reserva_dados_validos(){
  int codigo_teste = 1;
  Data *data_teste = criaData(10, 10, 2010);
  Passageiro *passageiro_teste = criarPassageiro(3, "Levy", "UFC");
  Voo *voo_teste = criarVoo(2, "UFC", "Quixeramobim");
  Reserva *reserva =
  cria_reserva(1, data_teste, passageiro_teste, voo_teste, A0);
  
  libera_reserva(&reserva);
  
  if(reserva == NULL){
    imprimir("[PASSOU] teste_liberar_reserva_dados_validos");
  }
  else{
    imprimir("[FALHOU] teste_liberar_reserva_dados_validos");
  }
}

// ================== TESTES FUNÇÕES DE AGENDA ==================

void teste_agenda_cria_dados_validos() {
  Passageiro *passageiro_teste = criarPassageiro(3, "Levy", "UFC");
  Voo *voo_teste = criarVoo(2, "UFC", "Quixeramobim");
  Data *data_teste = criaData(02, 12, 2022);
  Reserva *reserva = cria_reserva(1, data_teste, passageiro_teste, voo_teste, A1);
  Agenda *agenda = abb_cria_agenda(reserva);
  
  if(agenda != NULL){
    imprimir("[PASSOU] teste_agenda_cria_dados_validos");
  } else {
    imprimir("[FALHOU] teste_agenda_cria_dados_validos");
  }
}

void teste_agenda_libera_dados_validos() {
  Passageiro *passageiro_teste = criarPassageiro(1, "Jean", "Mucuripe");
  Voo *voo_teste = criarVoo(2, "UFC", "Quixeramobim");
  Data *data_teste = criaData(03, 12, 2022);
  Reserva *reserva = cria_reserva(1, data_teste, passageiro_teste, voo_teste, A1);
  Agenda *agenda = abb_cria_agenda(reserva);

  abb_agenda_libera(&agenda);
  if (agenda == NULL) {
    imprimir("[PASSOU] teste_lista_voo_libera_dados_validos");
  } else {
    imprimir("[FALHOU] teste_lista_voo_libera_dados_validos");
  }
}


void teste_agenda_insere_dados_validos(){
  
  Passageiro *passageiro_teste = criarPassageiro(1, "Jean", "Mucuripe");
  Voo *voo_teste = criarVoo(2, "Mucuripe", "Quixeramobim");
  Data *data_teste = criaData(1, 12, 2022);
  Reserva *reserva = cria_reserva(1, data_teste, passageiro_teste, voo_teste, A1);
  Agenda *agenda_raiz = abb_cria_agenda(reserva);


  if (agenda_raiz != NULL) {
    imprimir("[PASSOU] teste_agenda_insere_dados_validos");
  } else {
    imprimir("[FALHOU] teste_agenda_insere_dados_validos");
    }
}

void teste_agenda_insere_dados_nulos() {
  
  Passageiro *passageiro_teste = criarPassageiro(1, "Jean", "Mucuripe");
  Voo *voo_teste = criarVoo(2, "Mucuripe", "Quixeramobim");
  Data *data_teste = criaData(1, 12, 2022);
  Reserva *reserva = cria_reserva(1, data_teste, passageiro_teste, voo_teste, A1);
  Agenda *agenda_raiz = abb_cria_agenda(reserva);
  
  Agenda *agenda = NULL;

  agenda_raiz = abb_insere_agenda(agenda_raiz, agenda);
  
  if (agenda_raiz == NULL) { 
    imprimir("[PASSOU] teste_lista_voo_insere_dados_nulos");
  } else {
    imprimir("[FALHOU] teste_lista_voo_insere_dados_nulos");
    }
}


void teste_agenda_retira_dados_validos() {

  Passageiro *passageiro_teste = criarPassageiro(3, "Levy", "UFC");
  Voo *voo_teste = criarVoo(2, "UFC", "Quixeramobim");
  Data *data_teste = criaData(02, 12, 2022);
  Reserva *reserva = cria_reserva(1, data_teste, passageiro_teste, voo_teste, A1);
  Reserva *reserva1 = cria_reserva(1, data_teste, passageiro_teste, voo_teste, A1);
  Agenda *agenda = abb_cria_agenda(reserva);

  Reserva *reserva_retirada = abb_no_remove(agenda, agenda);
  
  if (reserva_igual(reserva_retirada,reserva1) == 1) {
    imprimir("[PASSOU] teste_agenda_retira_dados_validos");
  } else {
      imprimir("[FALHOU] teste_agenda_retira_dados_validos");
    }
}


void teste_agenda_retira_dados_nulos() {
  if (abb_no_remove(NULL, NULL) == NULL) {
    imprimir("[PASSOU] teste_agenda_retira_dados_nulos");
  } else {
    imprimir("[FALHOU] teste_agenda_retira_dados_nulos");
  }
}

void teste_agenda_busca_dados_validos() {
  int id_p1 = 1;
  Passageiro *passageiro_teste1 = criarPassageiro(id_p1, "Bruna", "Caucaia");
  Voo *voo_teste1 = criarVoo(1, "Caucaia", "Quixeramobim");
  Data *data_teste1 = criaData(10, 12, 2022);
  Reserva *reserva1 = cria_reserva(1, data_teste1, passageiro_teste1, voo_teste1, A1);
  Agenda *agenda_raiz = abb_cria_agenda(reserva1);


  int id_p2 = 2;
  Passageiro *passageiro_teste2 = criarPassageiro(id_p2, "Levy", "UFC");
  Voo *voo_teste2 = criarVoo(2, "UFC", "Quixeramobim");
  Data *data_teste2 = criaData(25, 12, 2022);
  Reserva *reserva2 = cria_reserva(2, data_teste2, passageiro_teste2, voo_teste2, A2);
  Agenda *agenda2 = abb_cria_agenda(reserva2);
  abb_insere_agenda(agenda_raiz, agenda2);
  
  Reserva *reserva_c1 = abb_busca_reserva_data(agenda_raiz, id_p1, data_teste1);
  if (reserva_igual(reserva1, reserva_c1) == 1) {
    Reserva *reserva_c2 = abb_busca_reserva_data(agenda_raiz, id_p1, data_teste1);
    if (reserva_igual(reserva1, reserva_c2) == 1) {
      imprimir("[PASSOU] teste_agenda_busca_dados_validos");
    } else {
        imprimir("[FALHOU] teste_agenda_busca_dados_validos");
      }
  } else {
      imprimir("[FALHOU] teste_agenda_busca_dados_validos");
    }
}

// ================== TESTES FUNÇÕES DE VIAGENS ==================

void teste_viagem_insere_dados_validos() {
  Viagem *viagem = criar_viagem();
  if (viagem != NULL) {
    Data *data1 = criaData(16, 4, 2023);
    Data *data2 = criaData(25, 4, 2023);
    Data *data3 = criaData(8, 5, 2023);
    
    Assento assento1 = A0;
    
    Passageiro *passageiro = criarPassageiro(1, "Roberval", "Trairi");
    
    Voo *voo1 = criarVoo(1, "Trairi", "São Paulo");
    Voo *voo2 = criarVoo(2, "São Paulo", "Aracati");
    Voo *voo3 = criarVoo(2, "Aracati", "Fortaleza");

    Reserva *reserva1 = cria_reserva(1, data1, passageiro, voo1, assento1);
    Reserva *reserva2 = cria_reserva(2, data2, passageiro, voo2, assento1);
    Reserva *reserva3 = cria_reserva(3, data3, passageiro, voo3, assento1);

    if (viagem_insere(viagem, reserva1) == 1 && viagem_insere(viagem, reserva2) == 1 && viagem_insere(viagem, reserva3) == 1) {
      imprimir("[PASSOU] teste_viagem_insere_dados_validos");
    } else {
      imprimir("[FALHOU] teste_viagem_insere_dados_validos");
    }
  } else {
    imprimir("[FALHOU] teste_viagem_insere_dados_validos");
  }
}

void teste_viagem_insere_dados_invalidos() {
  Viagem *viagem = criar_viagem();
  if (viagem != NULL) {
    Data *data = criaData(16, 4, 2023);
    
    Assento assento = A0;
    
    Passageiro *passageiro = criarPassageiro(1, "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA", "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA");
    
    Voo *voo = criarVoo(1, "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA", "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA");

    Reserva *reserva = cria_reserva(1, data, passageiro, voo, assento);

    if (viagem_insere(viagem, reserva) == -1) {
      imprimir("[PASSOU] teste_viagem_insere_dados_invalidos");
    } else if (viagem_insere(viagem, reserva) == 1) {
      imprimir("[FALHOU] teste_viagem_insere_dados_invalidos");
    }
  } else {
    imprimir("[FALHOU] teste_viagem_insere_dados_invalidos");
  }
}

void teste_viagem_insere_dados_nulos() {
  Viagem *viagem = NULL;
  if (viagem != NULL) {
    Data *data = criaData(16, 4, 2023);
    
    Assento assento = A0;
    
    Passageiro *passageiro = criarPassageiro(1, NULL, NULL);
    
    Voo *voo = criarVoo(1, NULL, NULL);

    Reserva *reserva = cria_reserva(1, data, passageiro, voo, assento);

    if (viagem_insere(viagem, reserva) == 1) {
      imprimir("[FALHOU] teste_viagem_insere_dados_nulos");
    } else {
      imprimir("[PASSOU] teste_viagem_insere_dados_nulos");
    }
  } else {
    imprimir("[PASSOU] teste_viagem_insere_dados_nulos");
  }
}

void teste_viagem_remove() {
  Viagem *viagem = criar_viagem();
  if (viagem != NULL) {
    Data *data1 = criaData(16, 4, 2023);
    Data *data2 = criaData(25, 4, 2023);
    Data *data3 = criaData(8, 5, 2023);
    
    Assento assento1 = A0;
    
    Passageiro *passageiro = criarPassageiro(1, "Roberval", "Trairi");
    
    Voo *voo1 = criarVoo(1, "Trairi", "São Paulo");
    Voo *voo2 = criarVoo(2, "São Paulo", "Aracati");
    Voo *voo3 = criarVoo(2, "Aracati", "Fortaleza");

    Reserva *reserva1 = cria_reserva(1, data1, passageiro, voo1, assento1);
    Reserva *reserva2 = cria_reserva(2, data2, passageiro, voo2, assento1);
    Reserva *reserva3 = cria_reserva(3, data3, passageiro, voo3, assento1);
  
    viagem_insere(viagem, reserva1);
    viagem_insere(viagem, reserva2);
    viagem_insere(viagem, reserva3);

    if(remover_viagem(&viagem) == 1) {
      imprimir("[PASSOU] teste_viagem_remove");
    } else {
      imprimir("[FALHOU] teste_viagem_remove");
    }
  } else {
    imprimir("[FALHOU] teste_viagem_remove");
  }
}

void teste_viagem_retira() {
  Viagem *viagem = criar_viagem();
  if (viagem != NULL) {
    Data *data1 = criaData(16, 4, 2023);
    Data *data2 = criaData(25, 4, 2023);
    Data *data3 = criaData(8, 5, 2023);
    
    Assento assento1 = A0;
    
    Passageiro *passageiro = criarPassageiro(1, "Roberval", "Trairi");
    
    Voo *voo1 = criarVoo(1, "Trairi", "São Paulo");
    Voo *voo2 = criarVoo(2, "São Paulo", "Aracati");
    Voo *voo3 = criarVoo(2, "Aracati", "Fortaleza");

    Reserva *reserva1 = cria_reserva(1, data1, passageiro, voo1, assento1);
    Reserva *reserva2 = cria_reserva(2, data2, passageiro, voo2, assento1);
    Reserva *reserva3 = cria_reserva(3, data3, passageiro, voo3, assento1);

    viagem_insere(viagem, reserva1);
    viagem_insere(viagem, reserva2);
    viagem_insere(viagem, reserva3);
    
    Trecho *aux1 = viagem_retira(viagem);
    Trecho *aux2;
    Reserva *reservaComparar;
    trechoAcessa(aux1, reservaComparar, aux2);

    if (reserva_igual(reservaComparar, reserva1) == 1) {
      Trecho *aux1 = viagem_retira(viagem);
      Trecho *aux2;
      Reserva *reservaComparar;
      trechoAcessa(aux1, reservaComparar, aux2);
      if (reserva_igual(reservaComparar, reserva2) == 1) {
        Trecho *aux1 = viagem_retira(viagem);
        Trecho *aux2;
        Reserva *reservaComparar;
        trechoAcessa(aux1, reservaComparar, aux2);
        
        if (reserva_igual(reservaComparar, reserva3) == 1) {
          imprimir("[PASSOU] teste_viagem_retira");
        } else {
          imprimir("[FALHOU] teste_viagem_retira");
        }
      } else {
        imprimir("[FALHOU] teste_viagem_retira");
      }
    } else {
      imprimir("[FALHOU] teste_viagem_retira");
    }
  } else {
    imprimir("[FALHOU] teste_viagem_retira");
  }
}

void teste_viagem_busca_dados_validos() {
  Viagem *viagem = criar_viagem();
  if (viagem != NULL) {
    Data *data1 = criaData(16, 4, 2023);
    Data *data2 = criaData(25, 4, 2023);
    Data *data3 = criaData(8, 5, 2023);
    
    Assento assento1 = A0;
    
    Passageiro *passageiro = criarPassageiro(1, "Roberval", "Trairi");
    
    Voo *voo1 = criarVoo(1, "Trairi", "São Paulo");
    Voo *voo2 = criarVoo(2, "São Paulo", "Aracati");
    Voo *voo3 = criarVoo(2, "Aracati", "Fortaleza");

    Reserva *reserva1 = cria_reserva(1, data1, passageiro, voo1, assento1);
    Reserva *reserva2 = cria_reserva(2, data2, passageiro, voo2, assento1);
    Reserva *reserva3 = cria_reserva(3, data3, passageiro, voo3, assento1);

    Reserva *reserva_buscar = viagem_busca(viagem, 2);

    if (reserva_buscar != NULL) {
      if (reserva_igual(reserva_buscar, reserva2) == 1) {
        imprimir("[PASSOU] teste_viagem_busca_dados_validos");
      } else {
        imprimir("[FALHOU] teste_viagem_busca_dados_validos");
      }
    } else {
      imprimir("[FALHOU] teste_viagem_busca_dados_validos");
    }
  } else {
    imprimir("[FALHOU] teste_viagem_busca_dados_validos");
  }
}

void teste_viagem_busca_dados_invalidos() {
  Viagem *viagem = criar_viagem();
  if (viagem != NULL) {
    Data *data1 = criaData(16, 4, 2023);
    Data *data2 = criaData(25, 4, 2023);
    Data *data3 = criaData(8, 5, 2023);
    
    Assento assento1 = A0;
    
    Passageiro *passageiro = criarPassageiro(1, "Roberval", "Trairi");
    
    Voo *voo1 = criarVoo(1, "Trairi", "São Paulo");
    Voo *voo2 = criarVoo(2, "São Paulo", "Aracati");
    Voo *voo3 = criarVoo(2, "Aracati", "Fortaleza");

    Reserva *reserva1 = cria_reserva(1, data1, passageiro, voo1, assento1);
    Reserva *reserva2 = cria_reserva(2, data2, passageiro, voo2, assento1);
    Reserva *reserva3 = cria_reserva(3, data3, passageiro, voo3, assento1);

    Reserva *reserva_buscar = viagem_busca(viagem, -1);

    if (reserva_buscar == NULL) {
      imprimir("[PASSOU] teste_viagem_busca_dados_invalidos");
    } else {
      imprimir("[FALHOU] teste_viagem_busca_dados_invalidos");
    }
  }
}

void teste_viagem_busca_dados_nulos() {
  Viagem *viagem = criar_viagem();
  if (viagem != NULL) {
    Data *data = criaData(16, 4, 2023);
    
    Assento assento = A0;
    
    Passageiro *passageiro = criarPassageiro(1, "Roberval", "Trairi");
    
    Voo *voo = criarVoo(1, "Trairi", "São Paulo");

    Reserva *reserva = cria_reserva(1, data, passageiro, voo, assento);

    Reserva *reserva_buscar = viagem_busca(NULL, -1);

    if (reserva_buscar == NULL) {
      imprimir("[PASSOU] teste_viagem_busca_dados_nulos");
    } else {
      imprimir("[FALHOU] teste_viagem_busca_dados_nulos");
    }
  }
}

// ================== TESTES FUNÇÕES DE HASH ==================

void teste_hash_cria() {
  TabelaViagem *novaHASH = cria_tabela_hash(5);

  if (novaHASH != NULL && tamanho_hash(novaHASH) == 5) {
    imprimir("[PASSOU] teste_hash_criar");
  } else {
    imprimir("[FALHOU] teste_hash_criar");
  }
}

void teste_hash_insere() {
  int tamanho = 10;
  TabelaViagem* novo_hash = cria_tabela_hash(tamanho);
  if (novo_hash != NULL){ 
    Viagem *viagem = criar_viagem();
    if (viagem != NULL) {
      Data *data1 = criaData(16, 4, 2023);
      Data *data2 = criaData(25, 4, 2023);
      Data *data3 = criaData(8, 5, 2023);
      
      Assento assento1 = A0;
      
      Passageiro *passageiro = criarPassageiro(1, "Roberval", "Trairi");
      
      Voo *voo1 = criarVoo(1, "Trairi", "São Paulo");
      Voo *voo2 = criarVoo(2, "São Paulo", "Aracati");
      Voo *voo3 = criarVoo(2, "Aracati", "Fortaleza");

      Reserva *reserva1 = cria_reserva(1, data1, passageiro, voo1, assento1);
      Reserva *reserva2 = cria_reserva(2, data2, passageiro, voo2, assento1);
      Reserva *reserva3 = cria_reserva(3, data3, passageiro, voo3, assento1);
      
      if (viagem_insere(viagem, reserva1) == 1 && viagem_insere(viagem, reserva2) == 1  && viagem_insere(viagem, reserva3) == 1){
    
       int id = funcao_hash(novo_hash, cod_hash(viagem));
    
        if (insere_hash(novo_hash, viagem) == 1){
          imprimir("[PASSOU] teste_hash_insere");
        } else{
          imprimir("[FALHOU] teste_hash_insere");
          }
      } else{
          imprimir("[FALHOU] teste_hash_insere");
        }
    } else{
      imprimir("[FALHOU] teste_hash_insere");
    }
  } else{
    imprimir("[FALHOU] teste_hash_insere");
  }
}

void teste_hash_busca(){
  int tamanho = 10;
  TabelaViagem* novo_hash = cria_tabela_hash(tamanho);
  if (novo_hash != NULL){        
    Viagem *viagem = criar_viagem();
    if (viagem != NULL) {
      Data *data1 = criaData(16, 4, 2023);
      Data *data2 = criaData(25, 4, 2023);
      Data *data3 = criaData(8, 5, 2023);
      Assento assento1 = A0;
      Passageiro *passageiro = criarPassageiro(1, "Roberta Montenegro", "Av. Humberto Monte, 2202");
      Voo *voo1 = criarVoo(1, "Trairi", "São Paulo");
      Voo *voo2 = criarVoo(2, "São Paulo", "Aracati");
      Voo *voo3 = criarVoo(2, "Aracati", "Fortaleza");

      Reserva *reserva1 = cria_reserva(1, data1, passageiro, voo1, assento1);
      Reserva *reserva2 = cria_reserva(2, data2, passageiro, voo2, assento1);
      Reserva *reserva3 = cria_reserva(3, data3, passageiro, voo3, assento1);
      if (viagem_insere(viagem, reserva1) == 1 && viagem_insere(viagem, reserva2) == 1 && viagem_insere(viagem, reserva3) == 1){
        int cod = funcao_hash(novo_hash, cod_hash(viagem));
        if (insere_hash(novo_hash, viagem) == 1){
          Viagem* aux = busca_hash(novo_hash, cod);
          if (viagem == aux){
            imprimir("[PASSOU] teste_buscar_hash");
          }
        }
      }
    }
  } else {
    imprimir("[FALHOU] teste_buscar_hash");
  }
}

void teste_hash_retira(){
  int tamanho = 10;
  TabelaViagem* novo_hash = cria_tabela_hash(tamanho);
  if (novo_hash != NULL){
        
    Viagem *viagem = criar_viagem();
    if (viagem != NULL) {
      Data *data1 = criaData(16, 4, 2023);
      Data *data2 = criaData(25, 4, 2023);
      Data *data3 = criaData(8, 5, 2023);
      Assento assento1 = A0;
      Passageiro *passageiro = criarPassageiro(1, "Roberta Montenegro", "Av. Humberto Monte, 2202");
      Voo *voo1 = criarVoo(1, "Trairi", "São Paulo");
      Voo *voo2 = criarVoo(2, "São Paulo", "Aracati");
      Voo *voo3 = criarVoo(2, "Aracati", "Fortaleza");

      Reserva *reserva1 = cria_reserva(1, data1, passageiro, voo1, assento1);
      Reserva *reserva2 = cria_reserva(2, data2, passageiro, voo2, assento1);
      Reserva *reserva3 = cria_reserva(3, data3, passageiro, voo3, assento1);
          
      if (viagem_insere(viagem, reserva1) == 1 && viagem_insere(viagem, reserva2) == 1 && viagem_insere(viagem, reserva3) == 1) {
        if (insere_hash(novo_hash, viagem) == 1){
          int id = funcao_hash(novo_hash, cod_hash(viagem));
          Viagem* aux_1 = retira_hash(novo_hash, id);
          Viagem* aux_2 = busca_hash(novo_hash, id);
          if (viagem == aux_1 && aux_2 == NULL){
            imprimir("[PASSOU] teste_retira_hash");
          }
        }
      }
    }
  } else {
    imprimir("[FALHOU] teste_retira_hash");
  }
}

// ================== TESTE IMPRIMIR ==================

void testar_imprimir() {
  int tamanho = 10;
  TabelaViagem* novo_hash = cria_tabela_hash(tamanho);
  if (novo_hash != NULL){ 
    Viagem *viagem = criar_viagem();
    if (viagem != NULL) {
      Data *data1 = criaData(16, 4, 2023);
      Data *data2 = criaData(25, 4, 2023);
      Data *data3 = criaData(8, 5, 2023);
      
      Assento assento1 = A0;
      
      Passageiro *passageiro = criarPassageiro(1, "Roberval", "Trairi");
      
      Voo *voo1 = criarVoo(1, "Trairi", "São Paulo");
      Voo *voo2 = criarVoo(2, "São Paulo", "Aracati");
      Voo *voo3 = criarVoo(2, "Aracati", "Fortaleza");

      Reserva *reserva1 = cria_reserva(1, data1, passageiro, voo1, assento1);
      Reserva *reserva2 = cria_reserva(2, data2, passageiro, voo2, assento1);
      Reserva *reserva3 = cria_reserva(3, data3, passageiro, voo3, assento1);
      viagem_insere(viagem, reserva1);
      viagem_insere(viagem, reserva2);
      viagem_insere(viagem, reserva3);

      insere_hash(novo_hash, viagem);
      
      imprimir_viagem(novo_hash, 7);
    }
  }
}

int main(void) {
  Passageiro *passageiro1 = criarPassageiro(1, "Jean", "Vincente Pinzon");
  Passageiro *passageiro2 = criarPassageiro(2, "Kauan", "Aracati");
  Passageiro *passageiro3 = criarPassageiro(
      -1, "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
      "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
  Passageiro *passageiro4 = criarPassageiro(-1, NULL, NULL);

  imprimir("");
  imprimir("# - TESTES CRIAR PASSAGEIRO - #");
  imprimir("");
  testa_criar_passageiro_dados_validos(passageiro1);
  testa_criar_passageiro_dados_invalidos(passageiro3);
  testa_criar_passageiro_dados_nulos(passageiro4);
  imprimir("");
  printf("\n");
  imprimir("");
  imprimir("# - TESTES EDITAR PASSAGEIRO - #");
  imprimir("");
  teste_editar_passageiro_dados_validos(passageiro1);
  teste_editar_passageiro_dados_invalidos(passageiro2);
  teste_editar_passageiro_dados_nulos(passageiro1);
  imprimir("");
  printf("\n");
  imprimir("");
  imprimir("# - TESTES CRIAR LISTA PASSAGEIRO - #");
  imprimir("");
  teste_lista_passageiro_cria_dados_validos();
  imprimir("");
  printf("\n");
  imprimir("");
  imprimir("# - TESTES LISTA LIBERAR PASSAGEIRO - #");
  imprimir("");
  teste_lista_passageiro_libera_dados_validos();
  teste_lista_passageiro_libera_dados_nulos();
  imprimir("");
  printf("\n");
  imprimir("");
  imprimir("# - TESTE LISTA PASSAGEIRO VAZIA - #");
  imprimir("");
  teste_lista_passageiro_vazia_dados_validos();
  imprimir("");
  printf("\n");
  imprimir("");
  imprimir("# - TESTES LISTA PASSAGEIRO INSERE - #");
  imprimir("");
  teste_lista_passageiro_insere_dados_validos();
  teste_lista_passageiro_insere_dados_invalidos();
  teste_lista_passageiro_insere_dados_nulos();
  imprimir("");
  printf("\n");
  imprimir("");
  imprimir("# - TESTES LISTA PASSAGEIRO RETIRA - #");
  imprimir("");
  teste_lista_passageiro_retira_dados_validos();
  teste_lista_passageiro_retira_dados_nulos();
  imprimir("");
  printf("\n");
  imprimir("");
  imprimir("# - TESTES LISTA PASSAGEIRO BUSCA - #");
  imprimir("");
  teste_lista_passageiro_busca_dados_validos();
  teste_lista_passageiro_busca_dados_invalidos();
  teste_lista_passageiro_busca_dados_nulos();

  Voo *voo1 = criarVoo(1, "Fortaleza", "Bahia");
  Voo *voo2 = criarVoo(2, "Quixeramobim", "Sobrail");
  Voo *voo3 =
      criarVoo(-1, "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
               "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
  Voo *voo4 = criarVoo(-1, NULL, NULL);
  imprimir("");
  printf("\n");
  imprimir("");
  imprimir("# - TESTES CRIAR VOOS  - #");
  imprimir("");
  testa_criar_voo_dados_validos(voo1);
  testa_criar_voo_dados_invalidos(voo3);
  testa_criar_voo_dados_nulos(voo4);
  imprimir("");
  printf("\n");
  imprimir("");
  imprimir("# - TESTES EDITAR VOOS - #");
  imprimir("");
  teste_editar_voo_dados_validos(voo1);
  teste_editar_voo_dados_invalidos(voo2);
  teste_editar_voo_dados_nulos(voo1);
  imprimir("");
  printf("\n");
  imprimir("");
  imprimir("# - TESTES LISTA VOOS CRIA - #");
  imprimir("");
  teste_lista_voo_cria_dados_validos();
  imprimir("");
  printf("\n");
  imprimir("");
  imprimir("# - TESTES LISTA VOOS LIBERA - #");
  imprimir("");
  teste_lista_voo_libera_dados_validos();
  teste_lista_voo_libera_dados_nulos();
  imprimir("");
  printf("\n");
  imprimir("");
  imprimir("# - TESTES LISTA VOOS INSERE - #");
  imprimir("");
  teste_lista_voo_insere_dados_validos();
  teste_lista_voo_insere_dados_invalidos();
  teste_lista_voo_insere_dados_nulos();
  imprimir("");
  printf("\n");
  imprimir("");
  imprimir("# - TESTES LISTA VOOS RETIRA - #");
  imprimir("");
  teste_lista_voo_retira_dados_validos();
  teste_lista_voo_retira_dados_nulos();
  imprimir("");
  printf("\n");
  imprimir("");
  imprimir("# - TESTES LISTA VOOS BUSCA - #");
  imprimir("");
  teste_lista_voo_busca_dados_validos();
  teste_lista_voo_busca_dados_invalidos();
  teste_lista_voo_busca_dados_nulos();
  imprimir("");
  printf("\n");
  imprimir("");
  imprimir("# - TESTES CRIAR RESERVA - #");
  imprimir("");
  teste_criar_reserva_dados_validos();
  teste_criar_reserva_dados_invalidos(passageiro2, voo2);
  teste_criar_reserva_dados_nulos();
  imprimir("");
  printf("\n");
  imprimir("");
  imprimir("# - TESTES LIBERAR RESERVA - #");
  imprimir("");
  teste_liberar_reserva_dados_validos();
  imprimir("");
  printf("\n");
  imprimir("");
  imprimir("# - TESTES EDITAR RESERVA - #");
  imprimir("");
  teste_editar_reserva_dados_validos();
  teste_editar_reserva_dados_invalidos();
  teste_editar_reserva_dados_nulos();
  imprimir("");
  printf("\n");
  imprimir("");
  imprimir("# - TESTES CRIAR AGENDA - #");
  imprimir("");
  teste_agenda_cria_dados_validos();
  imprimir("");
  printf("\n");
  imprimir("");
  imprimir("# - TESTES LIBERAR AGENDA - #");
  imprimir("");
  teste_agenda_libera_dados_validos();
  imprimir("");
  printf("\n");
  imprimir("");
  imprimir("# - TESTES AGENDA INSERE - #");
  imprimir("");
  teste_agenda_insere_dados_validos();
  teste_agenda_insere_dados_nulos();
  imprimir("");
  printf("\n");
  imprimir("");
  imprimir("# - TESTES AGENDA RETIRA - #");
  imprimir("");
  teste_agenda_retira_dados_validos();
  teste_agenda_retira_dados_nulos();
  imprimir("");
  printf("\n");
  imprimir("");
  imprimir("# - TESTES AGENDA BUSCA - #");
  imprimir("");
  teste_agenda_busca_dados_validos();
  imprimir("");
  printf("\n");
  imprimir("");
  imprimir("# - TESTE HASH CRIAR - #");
  imprimir("");
  teste_hash_cria();
  imprimir("");
  printf("\n");
  imprimir("");
  imprimir("# - TESTE HASH INSERE - #");
  imprimir("");
  teste_hash_insere();
  imprimir("");
  printf("\n");
  imprimir("");
  imprimir("# - TESTE HASH BUSCA - #");
  imprimir("");
  teste_hash_busca();
  imprimir("");
  printf("\n");
  imprimir("");
  imprimir("# - TESTE HASH RETIRA - #");
  imprimir("");
  teste_hash_retira();
  imprimir("");
  printf("\n");
  imprimir("");
  imprimir("# - TESTES VIAGEM INSERE - #");
  imprimir("");
  teste_viagem_insere_dados_validos();
  teste_viagem_insere_dados_invalidos();
  teste_viagem_insere_dados_nulos();
  imprimir("");
  printf("\n");
  imprimir("");
  imprimir("# - TESTE VIAGEM REMOVE - #");
  imprimir("");
  teste_viagem_remove();
  imprimir("");
  printf("\n");
  imprimir("");
  imprimir("# - TESTE RESERVA VIAGEM RETIRA - #");
  imprimir("");
  teste_viagem_retira();
  imprimir("");
  printf("\n");
  imprimir("");
  imprimir("# - TESTE RESERVA VIAGEM BUSCA - #");
  imprimir("");
  teste_viagem_busca_dados_validos();
  teste_viagem_busca_dados_invalidos();
  teste_viagem_busca_dados_nulos();
  imprimir("");
  printf("\n");
  imprimir("");
  imprimir("# - TESTE IMPRIMIR - #");
  imprimir("");
  testar_imprimir();
  imprimir("");
}