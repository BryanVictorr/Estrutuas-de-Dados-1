#include <stdio.h>
#include <stdlib.h>

#define TAM 5 // Declara o tamanho do Vetor

void imprimeVetor(int* V,int meio){
    
    printf(" %d\n",V[meio]); // Imprime o valor que se encontra no meio do vetor;
    
    for(int i = 1; i <= meio; i++){ // vai percorrer as posições de 1 até o tamanho referente ao meio, pois é a quantidade de valores que falto;
    
        printf("%d %d\n",V[meio - i],V[meio + i]); // imprime o valor na posição meio - 1 ou seja do meio para o inicio e meio + 1 ou seja do meio para o fim
    }
}

void main(){
    
    int *V, meio;
    
    V = (int*) malloc((TAM) * sizeof(int)); // aloco memória para receber os elementos
    
    for(int i = 0; i < TAM; i++){ // preenche o vetor com valores de 1 ate o tamanho
    
        V[i] = i + 1;
    }

    meio = TAM / 2; // meio recebe o tamanho do vetor dividido por 2
    
    imprimeVetor(V,meio);

    free(V); // libera a memória do vetor pois não é mais utilizado 
}
