#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct elemento{

    char placa[10];
    int vezesManobrado;

}Carros;

int inserirCarro(Carros *estacionamento, char *placa, int *fim){ // vai inserir um novo carro no estacionamento

    if(*fim < 9){ // caso o tatal de carros seja menor que o limite

        *fim += 1; // total de carros aumenta em 1

        strcpy(estacionamento[*fim].placa, placa);
        estacionamento[*fim].vezesManobrado = 0;
        return 1; // retorna 1 para informar que um carro foi adicionado
    }
    return 0;  // retorna 0 para informar que o total ja foi preenchido
}

int removerCarro(Carros *estacionamento, char *placa, int *fim){ // remove um carro do estacionamento após o usuario informar uma placa

    int verificar;

    for(int i = 0; i <= *fim; i++){ // vai pecorrer todos os carros do estacionamento

        verificar = strcmp(estacionamento[i].placa, placa); // verificar vai receber 0 caso a Placa do carro atual seja igual a informada

        if(verificar == 0){ // caso verificar seja 0

            if(i == *fim){ // verificar se o carro a ser removido é o ultimo

                printf("Carro Removido foi Manobrado %d vezes para fora do Estacionamento!\n", estacionamento[*fim].vezesManobrado);
                printf("Foram Manobrados %d Carros para ser Removido!\n", i);

                *fim -= 1; // total de carros diminui em 1
                return 1; // retorna 1 caso o carro tenha sido removido
            }
            else{ // caso o carro esteja no inicio ou meio

                for(int j = i; j < *fim; j++){ // vai receber o indice do carro a ser removido em J
                    strcpy(estacionamento[j].placa, estacionamento[j+1].placa);
                    estacionamento[j].vezesManobrado = estacionamento[j+1].vezesManobrado;
                }

                printf("Carro Removido foi Manobrado %d vezes para fora do Estacionamento!\n", estacionamento[i].vezesManobrado);
                printf("Foram Manobrados %d Carros para ser Removido!\n", i);

                *fim -= 1; // total de carros diminui em 1
                return 1; // retorna 1 caso o carro tenha sido removido
            }
        }
    }
    return 0; // retorna 0 caso Placa nao seja encotrada no estacionamento
}

void manobrar(Carros *estacionamento, int *fim){ // vai adicionar +1 em todos os carros a serem manobrados

    for(int i = 0; i <= *fim; i++){ // pecorre todos os carros
        estacionamento[i].vezesManobrado += 1; // adiciona +1 na quantidade de vezesManobrado
    }
}

int verificarPlaca(Carros *estacionamento, char *placa){ // vai verificar se o carro a ser removido é o primeiro a saida

    int verificar = strcmp(estacionamento[0].placa, placa);

    if(verificar == 0){
        return 1; // retorna 1 caso seja o mais proximo a saida
    }
    return 0; // retorna 0 caso nao seja o mais proximo a saida
}

void imprimeEstacionamento(Carros *estacionamento, int fim){ // imprime todos os carros no estacionamento

    if(fim == -1){ // caso o total de carros seja -1, informado que estacionamento está vazia

        printf("Estacionamento Vazia!\n\n");
        return; // return somente para encerrar a funcao
    }

    printf("Estacionamento\n\n");

    for(int i = 0; i <= fim; i++){ // vai pecorrer todos os carros

        printf("Carro:%d - Placa:[%s]\n", i+1, estacionamento[i].placa);
    }
    printf("\n\n");
}

void main(){

    int retorno, retornoPlaca, fim = -1;
    char placa[10], op = '1';

    Carros estacionamento[10];

    while(op != '0'){

        printf("******Estacionamento******\n");
        printf("E - Entrar\n");
        printf("S - Sair\n");
        printf("1 - Mostrar Estacionamento\n");
        printf("2 - Zerar Estacionamento\n");
        printf("0 - Sair\n");
        printf("*************************\n");
        printf("opcao:");
        scanf(" %c", &op);
        system("cls");

        switch(op){

            case 'E':

                if(fim < 9){

                    printf("Existem Vagas!\n");
                    printf("Informe a Placa:");
                    scanf(" %s", placa);

                    retorno = inserirCarro(estacionamento, placa, &fim);

                    if(retorno == 1){
                        printf("Carro entrou no Estacionamento!\n\n");
                    }
                }
                else{
                    printf("Nao ha vagas no Estacionamento!\n\n");
                }
                break;

            case 'S':

                if(fim > -1){
                    
                    printf("Informe a Placa:");
                    scanf(" %s", placa);

                    retornoPlaca = verificarPlaca(estacionamento, placa);
                    retorno = removerCarro(estacionamento, placa, &fim);

                    if(retorno == 1){

                        printf("Carro Saiu!\n\n");

                        if(retornoPlaca != 1){ // caso o carro removido nao seja o primeiros os demais precisam ser manobrados
                            manobrar(estacionamento, &fim);
                        }
                    }
                    else{
                        printf("Carro nao existe no Estacionamento!\n\n");
                    }
                }
                else{
                    printf("Estacionamento Vazio!\n\n");
                }
                break;

            case '1':

                imprimeEstacionamento(estacionamento, fim);
                break;
                
            case '2':
            
                fim = -1;
                printf("Estacionamento Esvaziado!\n\n");
                break;

            case '0':
                break;
        }
    }
}
