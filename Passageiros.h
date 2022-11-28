/* TAD: Lista (lista encadeada) */
typedef struct lista_passageiro Lista;
typedef struct passageiro Passageiro;
typedef struct no_passageiro No;

/*  Função para acessar os dados do passageiro
    Recebe como parâmetro um passageiro e os dados e vai modificá-los dentro da função. */
void passageiroAcessa(Passageiro *passageiro, int *id, char *nome, char *endereco);

/*  Cria um novo passageiro novo com os dados informados
    Retorna NULL caso não seja possível criar ou o passageiro caso contrário. */
Passageiro *criarPassageiro(int id, char *nome, char *endereco);

/*  Função para editar os dados do passageiro (ID, Nome ou endereço) */
void editarPassageiro(Passageiro *passageiro, int id, char *nome, char *endereco);

/* Verifica se o ID é não negativo, e se o nome e endereco tem tamanho menor ou igual      a 51 */
int verifica_params(int id, char *nome, char *endereco);

void removerPassageiro(Passageiro **passageiro);

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> TAD LISTA <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

/* Aloca espaço em memória e retorna uma lista */
Lista *lista_cria();

/* Libera a memória de uma lista previamente criada e atribui NULL ao ponteiro
 * lista. Retorna 1 caso seja possível fazer a liberação e 0 caso a lista
 * informada seja NULL. */
int lista_libera(Lista **lista);

/* Insere um passageiro na lista. Retorna 1 se foi possível adicionar, 0 caso já
 * exista um passageiro com a mesma matricula (nesse caso, o passageiro não pode ser
 * adicionado) e -1 caso a lista ou passageiro sejam NULL
 */
int lista_insere(Lista *lista, Passageiro *passageiro);

/* Remove um passageiro na lista. Retorna o passageiro ou NULL caso a lista esteja vazia ou
 * seja NULL */
Passageiro *lista_retira(Lista *lista, int id);

/* Recupera o primeiro passageiro da lista. Retorna o passageiro ou NULL caso a lista esteja
 * vazia ou seja NULL */
Passageiro *lista_primeiro(Lista *lista);

/* Busca passageiro pelo número de matricula. Retorna o passageiro se este estiver na
 * lista e NULL caso contrário, isto é, (i) lista vazia; (ii) não exista passageiro
 * com a matricula fornecida; ou (iii) a lista seja NULL */
Passageiro *lista_busca(Lista *lista, int matricula);

/* Verifica se a lista está vazia. Retorna 1 se a lista estiver vazia, 0 caso não
 * esteja vazia e -1 se a lista for NULL
 */
int lista_vazia(Lista *lista);

/* Computa a quantidade de passageiros passageiros na lista. Retorna a quantidade de passageiros
 * ou -1, caso a lista for NULL.
 */
int lista_quantidade(Lista *lista);

/*  Verifica se dois passageiros são iguais, recebe 2 passageiros e     
    verifica se são iguais, retornando 1 caso sejam iguais, 0 se não forem     e NULL se não houver passageiro
*/
int passageiroIgual(Passageiro *passageiro1, Passageiro *passageiro2);