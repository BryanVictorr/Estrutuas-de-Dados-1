#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void preencherMatriz(int** Matriz, int colunas, int linhas){

    // Preenche a Matriz
    
    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
            Matriz[i][j] = rand() % 10; // recebe rand vai gerar valores aleatórios entre 0 e 9
        }
    }
}

void imprimeMatriz(int** Matriz, int colunas, int linhas){

    //Imprime a Matriz
    
    for(int i = 0; i < linhas; i++){

        for(int j = 0; j < colunas; j++){
            printf("%d ",Matriz[i][j]); // onde i são as linhas e j a coluna da Matriz
        }
        printf("\n");
    }
    printf("\n\n");
}

int** soma_matriz(int** Matriz_A, int** Matriz_B, int colunas, int linhas){

    int **Matriz = (int**) malloc((linhas) * sizeof(int*));
    
    //Aloca na Matriz Resultante a quantidade de Linhas da Matriz A, ja que para executar adicao a resultante precisa ser do mesmo tamanho de Matriz A ou Matriz B

    for(int i = 0; i < linhas; i++){ // vai percorrer as linhas alocadas
    
        Matriz[i] = (int*) malloc((colunas) * sizeof(int));
        //vai alocar a quantidade de colunas em cada linha
    }

    for(int i = 0; i < linhas; i++){

        for(int j = 0; j < colunas; j++){

            Matriz[i][j] = Matriz_A[i][j] + Matriz_B[i][j];
            //Matriz Resultante na linha i e coluna j vai receber a soma da Matriz A linha i coluna j com Matriz B linha i coluna j
        }
    }

    return Matriz; // Retorna Matriz Resultante
}

int** subtrair_matriz(int** Matriz_A, int** Matriz_B, int colunas, int linhas){

    int **Matriz = (int**) malloc((linhas) * sizeof(int*));
    
    //Aloca na Matriz Resultante a quantidade de Linhas da Matriz A, ja que para executar adicao a resultante precisa ser do mesmo tamanho de Matriz A ou Matriz B


    for(int i = 0; i < linhas; i++){ // vai percorrer as linhas alocadas

        Matriz[i] = (int*) malloc((colunas) * sizeof(int));
        //vai acolunar a quantidade de colunas em cada linhas
    }

    for(int i = 0; i < linhas; i++){

        for(int j = 0; j < colunas; j++){
            Matriz[i][j] = Matriz_A[i][j] - Matriz_B[i][j];
            //Matriz Resultante na linha i e coluna j vai receber a subtração da Matriz A linha i coluna j com Matriz B linha i coluna j
        }
    }

    return Matriz; // Retorna a Matriz Resultante
}

int** multiplicar_matriz(int** Matriz_A, int** Matriz_B, int colunas_A, int linhas_A, int colunas_B, int linhas_B){

    int **Matriz = (int**) malloc((linhas_A) * sizeof(int*));
    //Matriz vai ser alocada a quantidade de linhas da Matriz A
    
    int soma = 0;

    for(int i = 0; i < colunas_B; i++){ // vai percorrer a quantidade de colunas de B
    
        Matriz[i] = (int*) malloc((colunas_B) * sizeof(int));
        //Aloca as colunas em suas respectivas linhas
    }

    for(int i = 0; i < linhas_A; i++){

        for(int j = 0; j < colunas_B; j++){
            
            for(int k = 0; k < linhas_B; k++){
                soma += Matriz_A[i][k] * Matriz_B[k][j];
                
                //soma = a Multiplicação da Matriz A linha i e coluna k * Matriz B linha j e coluna j
            }
            
            Matriz[i][j] = soma; // Matriz Resultante recebe a soma total das multiplicações 
            
            soma = 0; // zera soma para ser utilizada no proximo lanço de repetição
        }
    }

    return Matriz; // Retorna a Matriz Resultante
}

void main(){

    int coluna_A, linha_A, coluna_B, linha_B;
    srand(time(NULL));

    printf("Informe a quantidade de Colunas da Matrizes A:");
    scanf("%d",&coluna_A); // Leitura de Colunas Matriz A

    printf("Informe a quantidade de Linhas da Matrizes A:");
    scanf("%d",&linha_A); // Leitura de Linhas Matriz A

    printf("Informe a quantidade de Colunas da Matrizes B:");
    scanf("%d",&coluna_B); // Leitura de Colunas Matriz B

    printf("Informe a quantidade de Linhas da Matrizes B:");
    scanf("%d",&linha_B); // Leitura de Linhas Matriz B
    
    system("cls");

    int **Matriz_A = (int**) malloc((linha_A) * sizeof(int*));
    
    int **Matriz_B = (int**) malloc((linha_B) * sizeof(int*));
    
    // Matriz A e B vão alocar memória para um vetor de ponteiros 
    
    int **Matriz_C; // Vetor de ponteiros que vai receber a Matriz Resultante das Operações

    for(int i = 0; i < linha_A; i++){
        Matriz_A[i] = (int*) malloc((coluna_A) * sizeof(int));
        
        //aloca a quantidade de colunas nas respectivas linhas
    }
    
    for(int i = 0; i < linha_B; i++){
        Matriz_B[i] = (int*) malloc((coluna_B) * sizeof(int));
        
        //aloca a quantidade de colunas nas respectivas linhas
    }

    preencherMatriz(Matriz_A, coluna_A, linha_A);
    preencherMatriz(Matriz_B, coluna_B, linha_B);

    while(1){

        int opcao;
        
        printf("1-Adicao\n");
        printf("2-subtracao\n");
        printf("3-Multiplicar\n");
        printf("0-Sair\n");
        printf("Opcao:");
        scanf("%d",&opcao);
        system("cls");
        
        if(opcao == 0){
            break;
        }

        switch(opcao){

            case 1:

                if(coluna_A == coluna_B && linha_A == linha_B){ // Adição de Matrizes somento quando ambas tem o mesmo número de linhas e colunas 

                    Matriz_C = soma_matriz(Matriz_A, Matriz_B, coluna_A, linha_A);
                    imprimeMatriz(Matriz_A, coluna_A, linha_A);
                    imprimeMatriz(Matriz_B, coluna_B, linha_B);
                    imprimeMatriz(Matriz_C, coluna_A, linha_A);
                }
                else{
                    printf("Nao pode ser executador pois as Matrizes sao diferentes!\n\n");
                }
                break;

            case 2:

                if(coluna_A == coluna_B && linha_A == linha_B){ // Subtração de Matrizes somento quando ambas tem mesmo número de linhas e colunas
                    
                    Matriz_C = subtrair_matriz(Matriz_A, Matriz_B, coluna_B, linha_B);
                    imprimeMatriz(Matriz_A, coluna_B, linha_B);
                    imprimeMatriz(Matriz_B, coluna_B, linha_B);
                    imprimeMatriz(Matriz_C, coluna_B, linha_B);
                }
                else{
                    printf("Nao pode ser executador pois as Matrizes sao diferentes!\n\n");
                }
                break;

            case 3:

                if(coluna_A == linha_B){// multiplicacao de matriz somente quando Colunas de A igual a Linhas de B

                    Matriz_C = multiplicar_matriz(Matriz_A, Matriz_B, coluna_A, linha_A, coluna_B, linha_B);
                    imprimeMatriz(Matriz_A, coluna_A, linha_A);
                    imprimeMatriz(Matriz_B, coluna_B, linha_B);
                    imprimeMatriz(Matriz_C, linha_A, coluna_B);
                }
                else{
                    printf("O numero de colunas da Matriz A nao e igual ao de Linhas na Matriz B!\n\n");
                }
                break;
        }
    }
    free(Matriz_A);
    free(Matriz_B); // Libera o vetor de ponteiros alocado em suas respectivas Matrizes
    free(Matriz_C);
    
}
