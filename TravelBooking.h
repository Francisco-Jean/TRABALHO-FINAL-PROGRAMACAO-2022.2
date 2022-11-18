enum cod_assento {
    A0, B0, C0,
    A1, B1, C1, 
    A2, B2, C2,
    A3, B3, C3,
    A4, B4, C4,
    A5, B5, C5,
    A6, B6, C6,
    A7, B7, C7,
    A8, B8, C8, 
    A9, B9, C9
 };

typedef enum cod_assento Assento;
typedef struct data Data;
typedef struct voo Voo;
typedef struct lista_voo ListaVoo;
typedef struct passageiro Passageiro;
typedef struct lista_passageiro ListaPassageiro;
typedef struct reserva Reserva;
typedef struct agenda Agenda;
typedef struct viagem Viagem;
typedef struct tabela_viagem TabelaViagem;

/*  Função para acessar os dados do passageiro
    Recebe como parâmetro um passageiro e os dados e vai modificá-los dentro da função. */
void passageiroAcessa(Passageiro *passageiro, int *id, char *nome, char *endereco);

/*  Cria um novo passageiro novo com os dados informados
    Retorna NULL caso não seja possível criar ou o passageiro caso contrário. */
Passageiro *criarPassageiro(int id, char *nome, char *endereco);

/*  Função para editar os dados do passageiro (ID, Nome ou endereço) */
void editarDadosPassageiro(Passageiro *passageiro, int *id, char *nome, char *endereco);

/* Verifica se o ID é não negativo, e se o nome e endereco tem tamanho menor ou igual      a 51 */
int verifica_params(int id, char *nome, char *endereco);