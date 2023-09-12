#include <stdio.h.>
#include <stdlib.h>
#include <string.h>

#define TAM 100

int* repeteLetra(char* string, char letra, int* tamanho){

    int *vetor = (int*) malloc((1) * sizeof(int)); // Aloca memoria inicialmente para 1 posicao
    
    int cont = 0;

    for(int i = 0; string[i] != '\0'; i++){ // vai executar ate o fim da string

        if(string[i] == letra){ // caso alguma letra da string seja igual a letra digitada pelo usuário

            vetor[cont] = i; // vetor na posicao cont vai receber o indice da letra em relacao a palavra 
            cont++; // vai receber mais 1 para caso outra letra seja igual
            
            vetor = (int*) realloc(vetor,(cont + 1) * sizeof(int)); // vetor aloca mais uma posicao de memória para receber o indice da proxima letra igual
        }
    }
    *tamanho = cont; // tamanha vai receber cont que é a quantidade de vezes que se repetiu a letra
    
    return vetor; // retorna o vetor com os indices
}

void main(){

    char *string, letra;
    int tamanho = 0, *indice;

    string = (char*) malloc((TAM) * sizeof(char)); // alocado memoria para receber a string

    printf("Digite:");
    scanf(" %[^\n]s", string); // Leitura da String

    printf("Letra:");
    scanf(" %c",&letra); // Leitura da Letra

    indice = repeteLetra(string, letra, &tamanho); // o ponteiro indice vai receber os indices das letras

    printf("Indices:");

    for(int i = 0; i < tamanho; i++){ // imprime todos os imdices
    
        printf("[%d]", indice[i]);
    }
    printf("\nTamanho do vetor:%d", tamanho); // imprime o tamanho do vetor criado

    free(string);
}