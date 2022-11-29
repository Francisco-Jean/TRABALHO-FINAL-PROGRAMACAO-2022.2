#include "Voos.h"
#include <stdio.h>
#include <stdlib.h>

struct voo {
  int codigo;
  char *origem;
  char *destino;
};

struct no_voo {
  Voo *voo;
  struct no_voo *proximo;
};

struct lista_voo {
  struct no_voo *primeiro;
};

void vooAcessa(Voo *voo, int *código, char *origem, char *destino) {
  printf("Ola");
}

Voo *criarVoo(int codigo, char *origem, char *destino) {
  return NULL;
}

Voo *editarVoo(Voo *voo, int codigo, char *origem, char *destino) {
  return NULL;
}

ListaVoo *listaVoo_cria() {
  return NULL;
}

int listaVoo_insere(ListaVoo *listaVoo, Voo *voo) {
  return 0;
}

Voo *listaVoo_retira(ListaVoo *listaVoo, int codigo) {
  return 0;
}

int vooIgual(Voo *voo1, Voo *voo2) {
  return 0;
}

int listaVoo_libera(ListaVoo **listaVoo) {
  return 0;
}

Voo *listaVoo_busca(ListaVoo *listaVoo, int codigo) {
  return NULL;
}
