#include <stdio.h.>
#include <stdlib.h>
#include <time.h>

void ler_aposta(int *aposta, int n){

    // funcao vai fazer a leitura dos valores informado pelo usuario
    
    for(int i = 0; i < n; i++){
        
        while(1){

            printf("Informe o %d valor:",i + 1);
            scanf("%d", &aposta[i]); // leitura dos valores

            if(aposta[i] > 1 && aposta[i] < 100){
                break; // caso o valor esteja entre o intervalo informado
            }
            else{ // caso nao esteja precisa ser informado novamente
                printf("Valor Invalido Digite Novamente!!!\n\n");
            }
        }
    }
}

void sorteia_valores(int *sorteio, int n){

    // funcao vai sortar valores aleatorios
    
    for(int i = 0; i < n; i++){
        sorteio[i] = 1 + rand() % 100; // vai receber valores entre 1 e 100
        printf("%d ",sorteio[i]); // imprime o valor sorteado
    }

}

int* compara_aposta(int *aposta, int *sorteio, int *qtdacertos, int na, int ns){

    // funcao vai comparar os valores do usuario com os sorteados
    
    int *vetor = (int*) malloc((1) * sizeof(int)); // aloca memoria para receber o primeiro acerto caso ele ocorra
    
    int cont = 0;

    for(int i = 0; i < na; i++){ // pecorre os valores do usuario
        for(int j = 0; j < ns; j++){ // pecorre os valores sorteados

            if(aposta[i] == sorteio[j]){ // caso valor do usuario seja igual ao sorteado

                vetor = (int*) realloc(vetor,(cont + 1) * sizeof(int)); // vetor guarda memoria para o próximo acerto caso ocorra
                
                vetor[cont] = sorteio[j]; // vetor recebe o valor que foi acerto
                cont++; // conta os acertos
            }
        }
    }
    *qtdacertos = cont; // atdacertos vai receber a quantidade de acertos
    return vetor; // retorna o vetor com os valores que foram acerto
}

void main(){

    srand(time(NULL));
    int quant_aposta, quant_sorteio, qtdacertos = 0, *vetor_acertos;

    while(1){

        printf("Quantos Numeros deseja Apostar(1 ate 20):");
        scanf("%d", &quant_aposta); // informa a quantidade de valores que quer apostar

        if(quant_aposta >= 1 && quant_aposta <= 20){
            break;
        }
        else{
            printf("Quantidade Invalida Digite novamente!!!\n\n");
        }
    }

    system("cls");

    int *vetor_aposta = (int*) malloc((quant_aposta) * sizeof(int));
    ler_aposta(vetor_aposta, quant_aposta);

    system("cls");

    while(1){

        printf("Quantos Numeros deseja Sortear(1 ate 20):");
        scanf("%d", &quant_sorteio);

        if(quant_sorteio >= 1 && quant_sorteio <= 20){
            break;
        }
        else{
            printf("Quantidade Invalida Digite novamwente!!!\n\n");
        }
    }

    int *vetor_sorteio = (int*) malloc((quant_sorteio) * sizeof(int));

    sorteia_valores(vetor_sorteio, quant_sorteio);
    vetor_acertos = compara_aposta(vetor_aposta, vetor_sorteio, &qtdacertos, quant_aposta, quant_sorteio);

    for(int i = 0; i < qtdacertos; i++){
        printf("\nAcertou:%d",vetor_acertos[i]);
    }

    printf("\nAcertou %d numeros", qtdacertos);

    free(vetor_aposta); // libera memoria do vetor do usuario
    free(vetor_sorteio);// libera memoria do vetor de sorteio
    free(vetor_acertos);// libera memoria do vetor de acertos
}