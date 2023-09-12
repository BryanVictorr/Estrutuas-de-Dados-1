#include <stdio.h.>
#include <stdlib.h>
#include <time.h>

#define MAX 10000;

int menor = MAX;
int intervalo;

void preencherMatriz(int** Matriz, int colunas, int linhas){

    // Funcao vai preencher toda a matriz
    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
            Matriz[i][j] = 1 + rand() % MAX; // posicao da matriz vai receber valores de 1 ate MAX
        }
    }
}

void imprimeMatriz(int** Matriz, int colunas, int linhas){

    // Funcao vai imprimir a matriz
    for(int i = 0; i < linhas; i++){ 

        for(int j = 0; j < colunas; j++){
            printf("%d ",Matriz[i][j]); 
        }
        printf("\n");
    }
    printf("\n\n");
}

int *ocorrencias(int **mat, int l, int c){
    
    //Funcao vai registrar a quantidadede vezes que cada numero da matriz se repetiu do menor ate o maior numero

    int cont = 0, maior = 0;

    for(int i = 0; i < l; i++){
        for(int j = 0; j < c; j++){

            if(mat[i][j] > maior){
                maior = mat[i][j]; // maior vai guardar o maior valor da matriz
            }

            if(mat[i][j] < menor){
                menor = mat[i][j]; // menor vai guardar o menor valor da matriz
            }
        }
    }

    intervalo = maior - menor; // intervalo vai ser a quantidade de valores que preciso informar a ocorrência
    
    intervalo++;

    int *vetor = (int*) malloc((intervalo) * sizeof(int)); // aloco um vetor do tamanho do intervalo
    
    for(int i = 0; i < intervalo; i++){
        for(int j = 0; j < l; j++){
            for(int k = 0; k < c; k++){

                if((menor + i) == mat[j][k]){
                    cont++; // vai contar a quantidade de vezes que o valor se repetiu
                }
            }
        }

        vetor[i] = cont; // cada posição do vetor sera responsável por guardar uma quantidade de ocorrências
        
        cont = 0; // zero o contador 
    }
    return vetor; // retorno o vetor com as quantidade de ocorrências 
}

void main(){
    
    srand(time(NULL));

    int coluna, linha, *vetor;

    printf("Informe a quantidade de Colunas da Matrizes:");
    scanf("%d",&coluna);

    printf("Informe a quantidade de Linhas da Matrizes:");
    scanf("%d",&linha);

    system("cls");

    int **Matriz = (int**) malloc((linha) * sizeof(int*));
    //Aloco a quantidade de linha da matriz

    for(int i = 0; i < linha; i++){
        Matriz[i] = (int*) malloc((coluna) * sizeof(int));
        //Aloco cada coluna da matriz
    }

    preencherMatriz(Matriz, coluna, linha); // preenche a matriz

    imprimeMatriz(Matriz, coluna, linha); // imprime a matriz
    vetor = ocorrencias(Matriz, linha, coluna); // vetor vai receber as ocorrências 

    for(int i = 0; i < intervalo; i++){ // imprimo a quantidade de ocorrências do menor ate o maior valor

        printf("Valor %d ocorrencias %d\n", menor+i, vetor[i]);
    }
    free(vetor); // libero memória
}