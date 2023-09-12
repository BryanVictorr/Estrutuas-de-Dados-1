struct jogador {

    char nome[50];
    int jogos;
    int gols;
    int assistencias;
};

typedef struct jogador Jogador;

int Menu(int n, int cont);

void atribui(Jogador** jogadores, int n);

void imprime(Jogador** jogadores, int n);

void soma(Jogador** jogadores, int n);

void ehbom(Jogador** jogadores, int n);

void libera(Jogador** jogadores, int n);

void inicializar(Jogador** jogadores, int n);