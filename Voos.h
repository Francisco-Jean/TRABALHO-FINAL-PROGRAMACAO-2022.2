/* TADs voos*/
typedef struct voo Voo;

typedef struct lista_voo ListaVoo;

void printVoo(Voo *voo);

void vooAcessa(Voo *voo, int *codigo, char *origem, char *destino);

Voo *criarVoo(int codigo, char *origem, char *destino);

Voo *editarVoo(Voo *voo, int codigo, char *origem, char *destino);

ListaVoo *listaVoo_cria();

int listaVoo_insere(ListaVoo *listaVoo, Voo *voo);

Voo *listaVoo_retira(ListaVoo *listaVoo, int codigo);

int vooIgual(Voo *voo1, Voo *voo2);

int listaVoo_libera(ListaVoo **listaVoo);

Voo *listaVoo_busca(ListaVoo *listaVoo, int codigo);
