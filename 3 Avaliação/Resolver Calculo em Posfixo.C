#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

typedef struct elemento{
    
    float valor;
    struct elemento *proximo;
}No;

int verificarExpressao(char *expressao){ // verifca se a expressao informada é valida

    int tamanho = strlen(expressao); // tamanho vai receber tamanho da expressao

    if(tamanho <= MAX){ // caso o tamanho seja menor ou igual ao tamanho maximo
        
        for(int i = 0; i < tamanho; i++){ // vai pecorrer cada caracte da expressao
            
            if(expressao[i] >= '0' && expressao[i] <= '9'){ //caso seja um carecte numerico
                continue;
            }
            else if(expressao[i] == ' '){ // caso seja um espaço
                continue;
            }
            else if(expressao[i] == '+' || expressao[i] == '-' || expressao[i] == '*' || expressao[i] == '/'){// caso seja uma operacao
                continue;
            }
            else{ // caso nao seja um desses caracte
                return 0; // retorna 0 para indicar que expressao é invalida
            }
        }
        return 1; // retorna 1 para inficar que expressao é valida
    }
    return -1; // retorna -1 para indicar que a expressao é maior que o permitido
}

No *inserePilha(No *pilha, int valor){ // insere nova valor ao topo da pilha
    
    No *novo = (No*) malloc(sizeof(No));
    
    novo->valor = valor;
    novo->proximo = pilha;
    return novo;
}

No *removePilha(No **pilha){ // remove valor do topo da pilha
    
    No *inicioPilha = NULL; // inicio da pilha auxiliar recebe NULL
    
    if(*pilha != NULL){ // caso pilha nao esteja vazia
        
        inicioPilha = *pilha; // inicio da pilha aux vai receber topo da pilha
        *pilha = inicioPilha->proximo; // novo topo vai receber o elemento do topo um a frente
        return inicioPilha; // retorna novo topo
    }
    else{
        return NULL; // retorna NULL para indicar que nao foi removido elemento do Topo
    }
}

float realizarOperacao(char operador, float valorA, float valorB){ // realiza uma operacao entre 2 valores

    switch(operador){
        
        case '+':
            return valorA + valorB;
            break;

        case '-':
            return valorA - valorB;
            break;

        case '*':
            return valorA * valorB;
            break;

        case '/':
            return valorA / valorB;
            break;
    }
}

float resolverExpressao(char *expressao, No *pilha){ // vai devolver o resultado da expressao informada
    
    char *aux;
    float resultado; // resultado vai receber o resultado dos 2 valores ao encontra uma operacao
    
    // vai armazenar 2 valores da pilha
    No *A;
    No *B;
    
    aux = strtok(expressao, " "); // vai transformar aux em um vetor quebrando a string sempre ao encontrar espaço
    
    while(aux != NULL){ // caso aux nao esteja vazio
        
        if(aux[0] == '+' || aux[0] == '-' || aux[0] == '*' || aux[0] == '/'){ // caso caracte de aux seja uma operacao
            
            A = removePilha(&pilha); // A vai receber elemento do topo
            B = removePilha(&pilha); // B vai receber novo elemento do topo
            
            resultado = realizarOperacao(aux[0], B->valor, A->valor); // resultado vai receber o valor da operacao contida em aux
            pilha = inserePilha(pilha, resultado); // insere esse resultado na pilha
        }
        else{ // caso nao seja uma operacao é um valor numerico
            
            resultado = strtol(aux, NULL, 10); // resultado vai receber aux que é um vetor de string numerica e converter para decimal(10)
            pilha = inserePilha(pilha, resultado); // insere resultado na pilha
        }
        aux = strtok(NULL, " "); // aux vai receber a string seguinte a seu vetor
    }
    
    A = removePilha(&pilha); // A vai receber ultimo elemento da pilha
    resultado = A->valor; // resultado vai receber valor do ultimo elemento da pilha
    return resultado; // retorna o resultado dessa expressao que estava no final da pilha
}

int main() {
    
    int verificar;
    float resultado;

    char *expressao = (char*) malloc((MAX) * sizeof(char)); // aloca memoria para receber a expressao
    No *pilha = NULL; // pilha inicializada com NULL
    
    while(1){

        printf("Digite a Expressao ou 0 para encerrar:");
        scanf(" %[^\n]s", expressao);
        
        if(expressao[0] == '0'){
            break;
        }
        
        verificar = verificarExpressao(expressao);
        
        if(verificar > 0){
            
            resultado = resolverExpressao(expressao, pilha);
            printf("Resultado:%.2f\n\n", resultado);
        }
        else{
            
            printf("Expressao Invalida!\n\n");
        }
        system("pause");
        system("cls");
    }
    return 0;
}