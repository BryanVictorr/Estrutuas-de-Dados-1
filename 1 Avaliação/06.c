#include <stdio.h>

void troca(int *Vetor, int i, int j){ // Função responsável por fazer a troca dos valores dentro do vetor

    int temp;

    temp = *(Vetor + i); // Temp vai guardar um valor temporário do Vetor na posição i
    
    *(Vetor + i) = *(Vetor + j); // Vetor na posição i vai receber vetor na posição j
    
    *(Vetor + j) = temp; //Vetor na posição j vai receber valor temporário
}

void juntar(int *Vetor, int *Vetor_C, int inicio, int tam){

    if(inicio < tam){ // caso inicio seja igual ao final da string ele não irar executar
        
        *(Vetor_C) = *(Vetor); // Vetor C vai receber o conteúdo de Vetor
        
        juntar(Vetor + 1, Vetor_C + 1, inicio + 1, tam); // chamo a Função recursiva passando os novos indici e inicio que representa a posição atual + 1
    }
}

void quick_sort(int *Vetor, int inicio, int fim){

    if (inicio < fim) { // caso o inicio seja igual ao fim do vetor a função não vai ser executada

        int q;
        
        q = dividir_vetor(Vetor, inicio, fim); // função vai me retornar o indice que representa o meio do Vetor
        
        quick_sort(Vetor, inicio, q - 1); // chamo a função recursiva passando o vetor e o índice que representa o meio - 1 como o final do vetor (lado esquerdo do vetor)
        
        quick_sort(Vetor, q + 1, fim); // chamo a função recursiva passando o vetor e o indice que representa o meio + 1 como o começo do vetor (lado direito)
    }
}

int dividir_vetor(int *Vetor, int inicio, int fim){

    int pivo,i,j;

    pivo = *(Vetor + inicio); // pivo vai receber o valor do vetor na posição considerada como início
    
    i = inicio + 1; // i vai receber a posição considerada como inicio + 1 (ou seja uma a frente de pivo)
    
    j = fim; // j vai receber a posição considerada como fim do vetor

    while (i <= j) { // Enquanto o inicio for menor igual ao fim vai ser executado

        while (i <= j && *(Vetor + i) <= pivo){ // enquanto o valor de vetor + indice i for menor iguam ao pivo sera executado até encontrar qual indice possui valor maior que pivo
        
            i = i + 1;
        }
        
        while (i <= j && *(Vetor + j) > pivo){ // enquanto o valor de vetor + indice j for maior que que o pivo sera executado até encontrar qual indice possui valor menor que pivo
        
            j = j - 1;
        }
        
        if (i < j) {
            troca(Vetor, i, j); // funcao troca sera responsável por trocar os valores de posição baseado nos indices encotrados
        }
    }

    troca(Vetor, inicio, j);
    
    return j; // irei retorna em j o indice que representa o meio desse vetor
}


void main(){

    int tam_01,tam_02,i;

    printf("Informe o tamanho do Vetor A:");
    scanf("%d",&tam_01);

    printf("Informe o tamanho do Vetor B:");
    scanf("%d",&tam_02);

    int vetor_A[tam_01],vetor_B[tam_02],vetor_C[tam_01 + tam_02];

    printf("\nPreencha o Vetor A\n");

    for(i = 0; i < tam_01; i++){

        printf("Digite o %d valor:",i+1);
        scanf("%d", &vetor_A[i]);
    }

    printf("\nPreencha o Vetor B\n");

    for(i = 0; i < tam_02; i++){

        printf("Digite o %d valor:",i+1);
        scanf("%d",&vetor_B[i]);
    }

    quick_sort(vetor_A, 0, tam_01 - 1);
    quick_sort(vetor_B, 0, tam_02 - 1);
    
    juntar(vetor_A, vetor_C, 0, tam_01);
    juntar(vetor_B, vetor_C + tam_01, 0, tam_02);
    
    quick_sort(vetor_C, 0, tam_01 + tam_02 - 1);

    printf("\nVetor A Ordenado:");

    for(i = 0; i < tam_01; i++){
        printf("[%d] ",vetor_A[i]);
    }

    printf("\n\nVetor B Ordenado:");

    for(i = 0; i < tam_02; i++){
        printf("[%d] ",vetor_B[i]);
    }

    printf("\n\nVetor A + B Ordenado:");

    for(i = 0; i < tam_01 + tam_02; i++){
        printf("[%d] ",vetor_C[i]);
    }
}