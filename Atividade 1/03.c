#include <stdio.h>
#include <stdlib.h>

void media_aluno(float notas[], float *media){

    float soma = 0.0;
    int i;

    for(i=1; i<=3; i++){

        soma += notas[i-1]; // a variável soma vai receber ela mais o valor do vetor notas, fazendo assim a soma total dos valores
    
    }

    *media = soma/3; // media vai receber a soma dividido pela quantidade de notas

}

void main(){

    float notas[3];
    float *M;

    M = (float *) malloc(sizeof(float)); //Fazendo alocação dinâmica no espaço de memória para uma variável float

    int i;

    for(i = 1; i <= 3; i++){

        float x;

        printf("\nDigite a nota %d: ",i);
        scanf("%f",&x); // preenchendo o vetor notas

        notas[i-1] = x;

    }

    media_aluno(notas,M); // chamando a função e passando os parâmetros
    
    if(*M >= 7){ //Caso o valor que *M aponta seja maior ou igual a 7 o aluno foi aprovado

        printf("Aluno Aprovado com media %.1f",*M);

    }else{ // se não o aluno foi reprovado pois o valor que *M aponta é menos que 7

        printf("Aluno Reprovado com media %.1f",*M);
    }

}