#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes06.h"

void inicializar(Jogador** jogadores, int n){
    
    for(int i = 0; i < n; i++){
        jogadores[i] = NULL; // inicializa todas as posicoes com NULL
    }
    system("cls");
}

void atribui(Jogador** jogadores, int n){

    if(jogadores[n] == NULL){
        jogadores[n] = malloc(sizeof(Jogador)); // caso indice nao tenha sido preenchido sera alocada memoria 
    }

    //Leitura dos Dados
    printf("Nome:");
    scanf(" %[^\n]s", jogadores[n]->nome);

    printf("Jogos:");
    scanf("%d", &jogadores[n]->jogos);

    printf("Gols:");
    scanf("%d", &jogadores[n]->gols);

    printf("Assistencias:");
    scanf("%d", &jogadores[n]->assistencias);

    system("cls");
}

void imprime(Jogador** jogadores, int n){

    int iguais, aux = 0;
    char busca[50];

    //funcao imprime os dados de algum jogador
    printf("Informe o nome do jogador:");
    scanf(" %[^\n]s", busca); // vai informar o nome do jogador para a busca

    for(int i = 0; i < n; i++){

        iguais = strcmp(jogadores[i]->nome, busca); // caso o nome de algum jogador seja igual ao de busca iguais vai receber 0

        if(iguais == 0){ // caso seja 0 será impresso os dados do jogador

            printf("Nome:%s\n", jogadores[i]->nome);
            printf("jogos:%d\n", jogadores[i]->jogos);
            printf("Gols:%d\n", jogadores[i]->gols);
            printf("Assistencias:%d\n\n", jogadores[i]->assistencias);
            aux = 1; // aux vai receber 1 caso algum jogador seja impresso
        }
    }

    if(aux == 0){
        printf("jogador nao cadastrado!\n\n"); // caso nenhum jogador seja encontrado
    }

    system("pause");
    system("cls");
}

void soma(Jogador** jogadores, int n){

    char jogador_1[50], jogador_2[50];
    int iguais_1, iguais_2, gols, jogos, assistencias, aux = 0;
    //Vai somar as estatísticas de dois jogadores
    
    if(n >= 2){ // caso o numero de jogadores seja 2 ou mais

        printf("Informe nome do 1 Jogador:");
        scanf(" %[^\n]s", jogador_1); //Leitura do nome de um jogador

        printf("Informe nome do 2 Jogador:");
        scanf(" %[^\n]s", jogador_2); // Leitura de outro nome de jogador

        for(int i = 0; i < n; i++){ // vai pecorrer todos os jogadores cadastrados

            iguais_1 = strcmp(jogadores[i]->nome, jogador_1);
            
            if(iguais_1 == 0){

                for(int j = 0; j < n; j++){

                    iguais_2 = strcmp(jogadores[j]->nome, jogador_2);

                    if(iguais_2 == 0){

                        //caso os 2 jogadores seja encontrado seja feito as somas dos valores
                        
                        gols = jogadores[i]->gols + jogadores[j]->gols;
                        jogos = jogadores[i]->jogos + jogadores[j]->jogos;
                        assistencias = jogadores[i]->assistencias + jogadores[j]->assistencias;

                        printf("Soma de Jogos:%d\n",jogos);
                        printf("Soma de Gols:%d\n",gols);
                        printf("Soma de Assistencias:%d\n\n",assistencias);
                        aux = 1; // vai receber aux caso os 2 jogadores seja encontrado
                    }
                }
            }
        }
        if(aux == 0){
            printf("Um dos jogadores informados nao existe!\n\n"); // se pelo menos um jogador nao for encontrado 
        }
    }
    else{
        printf("Quantidade minima de jogadores nao cadastradas!\n\n"); // caso o numero de iogadores seja menor que 2
    }

    system("pause");
    system("cls");
}

void ehbom(Jogador** jogadores, int n){

    int iguais, aux = 0;
    char busca[50];
    float media;

    printf("Informe o nome do jogador:");
    scanf(" %[^\n]s", busca); // Leitura do nome do jogador para busca

    for(int i = 0; i < n; i++){

        iguais = strcmp(jogadores[i]->nome, busca);

        if(iguais == 0){

            media = (float) jogadores[i]->gols / jogadores[i]->jogos;
            aux = 1;

            if(media > 0.5){ // caso a sua media de gols por partida seja maior que 0.5 ele é um bom jogador
                printf("Nome:%s e bom com %d gols\n\n", jogadores[i]->nome, jogadores[i]->gols);
            }
            else{ // caso nao seja maior que 0.5 ele nao é um jogador com boas medias de gol
                printf("Jogador nao tem Boa media de gols!!!\n\n");
            }
        }
    }

    if(aux == 0){ // caso aux seja 0 nao foi encontrado jogador com nome informado
        printf("Esse jogador nao esta cadastrado\n\n");
    }

    system("pause");
    system("cls");
}

void libera(Jogador** jogadores, int n){

    int opcao;

    printf("Deseja Apagar Todos os Jogadoresn\n");
    printf("1-Sim\n2-Nao\nOpcao:");
    scanf("%d", &opcao);

    for(int i = 0; i < n; i++){

        free(jogadores[i]); // libera a memoria de todos os jogadores alocados
        jogadores[i] = NULL; // coloca NULL em todas as posições
    }

    system("cls");
}

int Menu(int n, int cont){

    int opcao;

    printf("1-Adicionar Jogador\n");
    printf("2-Imprime um jogador\n");
    printf("3-Somar 2 Jogadores\n");
    printf("4-Verificar se Jogador e bom\n");
    printf("5-Deletar Jogadores\n");
    printf("0-sair\nOpcao:");
    scanf("%d", &opcao);
    system("cls");

    if(opcao == 0){
        return 0;
    }

    switch(opcao){

        case 1:

            if(cont < n){

                return 1;
                break;
            }
            else{
                printf("Limite de jogadores cadastrados!\n\n");
                system("pause");
                system("cls");
                return -1;
                break;
            }

        case 2:

            return 2;
            break;

        case 3:

            return 3;
            break;

        case 4:

            return 4;
            break;

        case 5:
            
            return 5;
            break;
    }
    return 0;
}
