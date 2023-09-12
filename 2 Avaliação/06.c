#include <stdio.h>
#include <stdlib.h>
#include "funcoes06.c"

int main(){

    Jogador **jogadores;
    int MAX, cont = 0, retorno;

    printf("Informe a quantidade de jogadores Maxima:");
    scanf("%d", &MAX);

    jogadores = malloc((MAX) * sizeof(Jogador*)); //aloca memoria para a quantidade de jogadores informados

    inicializar(jogadores, MAX); // inicializa as posicoes

    system("cls");

    while(1){

        retorno = Menu(MAX, cont);

        system("cls");

        if(retorno == 1){
            atribui(jogadores, cont);
            cont++;
        }

        else if(retorno == 2){
            imprime(jogadores, cont);
        }

        else if(retorno == 3){
            soma(jogadores, cont);
        }

        else if(retorno == 4){
            ehbom(jogadores, cont);
        }

        else if(retorno == 5){
            libera(jogadores, cont);
            cont = 0;
        }

        else if(retorno == -1){
            retorno = Menu(MAX, cont);
        }

        else if(retorno == 0){
            break;
        }
    }
    return 0;
}
