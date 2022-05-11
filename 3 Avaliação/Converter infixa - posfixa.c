#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct elemento{

    char expressao[MAX];
}Pilha;

int verificarExpressao(char *expressao){ // vai verificar se a expressao informada é valida

    int tamanho = strlen(expressao); // tamanho vai receber o tamanho da expressao
    int cont_1 = 0, cont_2 = 0; // cont_1 vai contar a quantidade '(' e cont_2 vai contar a quantidade de ')

    if(tamanho <= MAX){ // se o tamanho da expressao for menor igual o tamanho permitido
        
        for(int i = 0; i < tamanho; i++){ // vai pecorrer cada caractere da expressao

            if(expressao[i] == '(' ){
                cont_1++;
            }
            else if(expressao[i] == ')' ){
                cont_2++;
            }
            else if(expressao[i] >= '0' && expressao[i] <= '9'){ // caso o carectere seja um numero
                continue;
            }
            else if(expressao[i] == ' '){ // caso carectere seja um espaço
                continue;
            }
            else if(expressao[i] != '+' && expressao[i] != '-' && expressao[i] != '*' && expressao[i] != '/'){
                return 0; // caso o carectere nao seja um dos permitidos ou operaçôes vai retornar 0 para indicar expressao invalida
            }
        }
        if(cont_1 == cont_2){
            return cont_1; // caso o numero de '(' seja igual ao de ')' informado que expressao é valida
        }
        else{
            return 0; // caso o numero de '(' seja diferente de ')'
        }
    }
    return -1; // retorna -1 caso a expressao seja maior do que o permitido
}

int operacao(char operador) { // vai verificar qual operador tem maior procedencia

    switch (operador){

        case '+':
        return 1;

        case '-':
        return 1;

        case '*':
        return 2;

        case '/':
        return 2;
    }
}

void posFixa(char *expressao, Pilha *pilha){ // transforma a expressao infixa em posfixa/polonesa reversa

    char novaExpressao[MAX], caracter; // nova expressao vai armazenar '()' e operacoes "+ - * /"
    int i, aux = 0, topo = -1; // topo incializado com -1

    for(i = 0; expressao[i] != '\0'; i++){ // vai pecorrer toda a expressao

        caracter = expressao[i]; // carectere vai recebendo cada digito da expressao

        if(caracter == ' '){
            continue;
        }

        // oberseve que vai ser ultilizado bastante pre e pos encremento

        if(caracter == '('){ // caso o caractere seja um '('
            novaExpressao[++topo] = caracter; // será armazenado no topo da nova expressao
        }

        else if(caracter == ')'){ // caso o caractere seja um ')'

            // vai adicionado as operacoes a pilha enquanto o topo seja maior que -1 e o caractere nao seja um ')'

            while(topo > -1 && novaExpressao[topo] != '(' ){
                pilha->expressao[aux++] = novaExpressao[topo--];
            }
            topo--;
        }

        else if((caracter >= '0' && caracter <= '9')){ // caso carectere seja um valor numerico
            pilha->expressao[aux++] = caracter; // pilha vai receber o caractere
        }

        else{ // caso nao seja um desses caractere será uma operação

            //enquanto topo maior que -1 e a lista de () e operacoes nao seja um '(' e a operacao do topo seja maior ou igual a oepracao atual
            while(topo > -1 && novaExpressao[topo] != '(' && operacao(novaExpressao[topo]) >= operacao(caracter)){
                
                pilha->expressao[aux++] = novaExpressao[topo--]; // pilha vai receber a operacao de maior procendecia
            }
            novaExpressao[++topo] = caracter; // lista de () e operacoes vai receber operacao atual
            pilha->expressao[aux++] = ' '; // pilha vai receber espaço para separar os valores
        }
    }

    while(topo > -1){
        pilha->expressao[aux++] = novaExpressao[topo--];
    }
    pilha->expressao[aux++] = '\0'; // expressao da pilha vai receber '\0' para indicar que chegou ao fim
}

int main(){

    char *expressao = (char*) malloc((MAX) * sizeof(char)); // aloca memoria para receber a expressao de ate 1028 caracte
    Pilha *pilha = (Pilha*) malloc(sizeof(Pilha)); /// aloca memoria para a pilha
    
    while(1){
        
        printf("Digite a Expressao ou 0 para encerrar:");
        scanf(" %[^\n]s", expressao);
        
        if(expressao[0] == '0'){
            break;
        }
        
        int verificar = verificarExpressao(expressao);
        
        if(verificar > 0){
            
            posFixa(expressao, pilha);
            printf("Expressao no Pos Fixa:%s\n\n", pilha->expressao);
        }
        else{
            
            printf("Expressao Invalida!\n\n");
        }
        system("pause");
        system("cls");
    }
    return 0;
}