#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

typedef struct elemento{
    
    float valor;
    struct elemento *proximo;
}No;

int verificarExpressao(char *expressao){

    int tamanho = strlen(expressao);

    if(tamanho <= MAX){
        
        for(int i = 0; i < tamanho; i++){
            
            if(expressao[i] >= '0' && expressao[i] <= '9'){
                continue;
            }
            else if(expressao[i] == ' '){
                continue;
            }
            else if(expressao[i] == '+' || expressao[i] == '-' || expressao[i] == '*' || expressao[i] == '/'){
                continue;
            }
            else{
                return 0;
            }
        }
        return 1;
    }
    return 0;
}

No *inserePilha(No *pilha, int valor){
    
    No *novo = (No*) malloc(sizeof(No));
    
    novo->valor = valor;
    novo->proximo = pilha;
    return novo;
}

No *removePilha(No **pilha){
    
    No *inicioPilha = NULL;
    
    if(*pilha != NULL){
        
        inicioPilha = *pilha;
        *pilha = inicioPilha->proximo;
        return inicioPilha;
    }
    else{
        return NULL;
    }
}


float realizarOperacao(char operador, float valor1, float valor2) {

    switch (operador) {
        
        case '+':
        return valor1 + valor2;

        case '-':
        return valor1 - valor2;

        case '*':
        return valor1 * valor2;

        case '/':
        return valor1 / valor2;
    }
}

float resolverExpressao(char *expressao, No *pilha){
    
    char *aux;
    float resultado;
    
    No *A;
    No *B;
    
    aux = strtok(expressao, " ");
    
    while(aux != NULL){
        
        if(aux[0] == '+' || aux[0] == '-' || aux[0] == '*' || aux[0] == '/'){
            
            A = removePilha(&pilha);
            B = removePilha(&pilha);
            
            resultado = realizarOperacao(aux[0], B->valor, A->valor);
            pilha = inserePilha(pilha, resultado);
        }
        else{
            
            resultado = strtol(aux, NULL, 10);
            pilha = inserePilha(pilha, resultado);
        }
        aux = strtok(NULL, " ");
    }
    
    A = removePilha(&pilha);
    resultado = A->valor;
    return resultado;
}

void main(){
    
    int verificar;
    float resultado;
    char expressao = (char*) malloc((MAX) * sizeof(char));
    
    No *pilha = NULL;
    
    while(1){

        printf("Digite a Expressao ou 0 para encerrar:");
        scanf(" %[^\n]s", expressao);
        
        if(expressao[0] == '0'){
            break;
        }
        
        int verificar = verificarExpressao(expressao);
        
        if(verificar != 0){
            
            resultado = resolverExpressao(expressao, pilha);
            printf("Resultado:%.2f\n\n", resultado);
        }
        else{
            
            printf("Expressao Invalida!\n\n");
        }
        system("pause");
        system("cls");
    }
    free(expressao);
    free(pilha);
}
