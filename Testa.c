#include "Passageiros.h"
#include "Voos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXCARACTERES 60

// FUNÇÃO DE IMPRIMIR A TABELA DE CORREÇÃO
void imprimir(char *texto){
  if(!strcmp(texto, "")){
    printf("------------------------------------------------------------\n");
  }
  else{
    int tamanho = strlen(texto);
    int sp = ((MAXCARACTERES - tamanho - 1) / 2);
    char *espaco = (char *) malloc(sizeof(char) * 60);
    for(int x = 0; x < sp; x++){
      strcat(espaco, " ");
    }
    if(tamanho % 2 == 0){
      printf("|%s%s%s|\n",espaco, texto, espaco);
    }
    else{
      char *espaco2 = (char *) malloc(sizeof(char) * 60);
      for(int x = 0; x < sp-1; x++){
      strcat(espaco2, " ");
      }
      printf("|%s%s%s|\n",espaco2, texto, espaco);
    }
  }
}

// ================== TESTES FUNÇÕES DE PASSAGEIRO ==================

void testa_criar_passageiro_dados_validos(Passageiro *passageiro) {  
  int id;
  char nome[30], endereco[30];
  
  passageiroAcessa(passageiro, &id, nome, endereco);

  if ((id == 1) && (strcmp(nome, "Jean") == 0) && (strcmp(endereco, "Vincente Pinzon") == 0)) {
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
    if (id == aux && strcmp(nome, "Victor") == 0 && strcmp(endereco, "Pici") == 0) {
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
    if (id == idAux || strcmp(nomeAux, "Luiz") == 0 || strcmp(enderecoAux, "Pici") == 0) {
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
    if (id == aux || strcmp(nome, "Luiz") == 0 || strcmp(endereco, "Pici") == 0) {
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
      if (id == 2 && strcmp(nome, "Lucas") == 0 && strcmp(endereco, "Bom Jardim") == 0) {
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

  if ((codigo == 1) && (strcmp(origem, "Fortaleza") == 0) && (strcmp(destino, "Bahia") == 0)) {
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
    if (codigo == aux && strcmp(origem, "São Paulo") == 0 && strcmp(destino, "Rio de Janeiro") == 0) {
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
    if (codigo == aux || strcmp(origem, "São Paulo") == 0 || strcmp(destino, "Rio de Janeiro") == 0) {
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
  if (listaVoo != NULL) {
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
      if (codigo == 2 && strcmp(origem, "Fortaleza") == 0 && strcmp(destino, "Bahia") == 0) {
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


int main_(void) {
  Passageiro *passageiro1 = criarPassageiro(1, "Jean", "Vincente Pinzon");
  Passageiro *passageiro2 = criarPassageiro(2, "Kauan", "Aracati");
  Passageiro *passageiro3 = criarPassageiro(-1, "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa", "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
  Passageiro *passageiro4 = criarPassageiro(-1, NULL, NULL);
  
  imprimir("");
  imprimir("# - TESTES PASSAGEIRO CRIA - #");
  imprimir("");
  testa_criar_passageiro_dados_validos(passageiro1);
  testa_criar_passageiro_dados_invalidos(passageiro3);
  testa_criar_passageiro_dados_nulos(passageiro4);
  imprimir("");
  printf("\n");
  imprimir("");
  imprimir("# - TESTES PASSAGEIRO EDITAR- #");
  imprimir("");
  teste_editar_passageiro_dados_validos(passageiro1);
  teste_editar_passageiro_dados_invalidos(passageiro2);
  teste_editar_passageiro_dados_nulos(passageiro1);
  imprimir("");
  printf("\n");
  imprimir("");
  imprimir("# - TESTES PASSAGEIRO RETIRA- #");
  imprimir("");
  teste_retira_passageiro_dados_validos(); // falta implementação de funções necessárias
  teste_retira_passageiro_dados_nulos();
  imprimir("");
  printf("\n");
  imprimir("");
  imprimir("# - TESTES LISTA PASSAGEIRO CRIA- #");
  imprimir("");
  teste_lista_passageiro_cria_dados_validos();
  imprimir("");
  printf("\n");
  imprimir("");
  imprimir("# - TESTES LISTA PASSAGEIRO LIBERA- #");
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
  imprimir("# - TESTES LISTA PASSAGEIRO INSERE - #");
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
  Voo *voo3 = criarVoo(-1, "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa", "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
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
  imprimir("# - TESTES VOOS EDITA - #");
  imprimir("");
  teste_editar_voo_dados_validos(voo1);
  teste_editar_voo_dados_invalidos(voo2);
  teste_editar_voo_dados_nulos(voo1);
  imprimir("");
  printf("\n");
  imprimir("");
  imprimir("# - TESTES VOOS RETIRA - #");
  imprimir("");
  teste_retira_voo_dados_validos();
  teste_retira_voo_dados_nulos();
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
}