#include <stdio.h>
#include <stdlib.h>

typedef struct elemento{

    int valor;
    struct elemento *proximo; // ponteiro para o proximo nó
    struct elemento *inicio; // ponteiro para o nó incial
    struct elemento *fim; // ponteiro para o último nó
    
}No;

No *inicializar(){ // inicializa pilha ou fila com NULL
    return NULL;
}

No *inserirPilha(No *pilha, int valor){

    No *novo = (No*) malloc(sizeof(No)); // aloca memória para o novo nó
    novo->valor = valor; // novo nó recebe valor informado

    if(pilha == NULL){ // caso a pilha esteja vazia

        novo->inicio = novo; // novo inicio vai receber novo nó
        novo->fim = novo; // novo fim vai receber novo nó
        novo->proximo = NULL; // proximo elemento apos o novo será NULL
        return novo; // retorna novo nó
    }
    else{ // caso a pilha nao esteja vazia

        No *aux = pilha; // aux vai receber inicio da pilha
        novo->proximo = pilha; // proximo nó apos o novo vai ser o inicio da pilha
	novo->fim = pilha->fim; // novo fim vai receber pilha fim que foi o primeiro elemento adicionado

        do{ 
		    aux->inicio = novo; // aux que era o inicio da pilha vai receber novo elemento
		    aux = aux->proximo; // aux que era o inicio vai receber aux proximo que é o elemento seguinte
	    }while(aux!=NULL);
	
	    return novo; // retorna novo nó adicionado
    }
}

No *inserirFila(No *fila, int valor){ 

    No *novo = (No*) malloc(sizeof(No)); // aloca memoria para o novo nó
	novo->valor = valor; // novo valor vai receber valor informado pelo usuario
	
	if(fila == NULL){ // caso a fila esteja vazia

		novo->inicio = novo; // novo inicio vai receber novo elemento adicionado
		novo->fim = novo; // novo fim vai receber novo elemento adicionado
        	novo->proximo = NULL; // proximo elemento a frente do novo vai receber NULL
		return novo;
	}
    else{ // caso a fila nao esteja vazio

        No *aux;
        novo->inicio = fila; // novo inicio vai receber o inicio da fila
	novo->fim = novo; // novo fim vai receber o novo elemento
        novo->proximo = NULL; // elemento seguinte ao novo vai receber NULL

	    for(aux = fila; aux->proximo != NULL; aux= aux->proximo); // vai pecorrer ate o ultimo elemento da fila e guardar em aux

	    aux->proximo = novo; // aux proximo vai receber novo elemento
	    aux->fim = novo; // aux fim vai receber novo elemento
	    return fila; // retorna o inicio da fila que ja foi incremetada
    }
}

void imprimePilha(No *pilha){ // imprime toda a pilha

	if(pilha == NULL){ // caso a pilha esteja vazia
		printf("Pilha Vazia!\n\n");
	}
    else{ // caso a pilha tenha elementos

        printf("Valores da Pilha:");

		for(;pilha->proximo != NULL; pilha = pilha->proximo){ // vai pecorrer todos os elementos da pilha
			printf("[%d]", pilha->valor);
		}
		printf("[%d]\n\n", pilha->valor);
	}
}

void imprimeFila(No *fila){ // imprime toda a fila

	if(fila == NULL){ // caso a fila esteja vazia
		printf("Fila Vazia!\n\n");
	}
    else{

        printf("Valores da Fila:");

		for(;fila->proximo != NULL; fila = fila->proximo){ // vai pecorrer todos os elementos da fila
			printf("[%d]",fila->valor);
		}
		printf("[%d]\n\n",fila->valor);
	}
}

No *intercalar(No *pilha, No *fila){ // vai intercalar a fila e a pilha em uma nova pilha
    
    No *auxFila; // auxFila vai pecorrer os elementos da fila
    No *auxPilha = pilha; // auxPilha vai receber inicio da pilha
    No *novaPilha = inicializar(); // inicializo nova pilha
    
    for(auxFila = fila; auxFila != NULL; auxFila = auxFila->proximo){ // pecorre todos os elementos da fila
        
        if((auxFila->valor % 2) == 0){ // caso o valor da fila seja par
            
            novaPilha = inserirPilha(novaPilha, auxFila->valor); // vai ser inserido na nova pilha primeiro o valor da fila
            novaPilha = inserirPilha(novaPilha, auxPilha->valor); // vai ser inserido na nova pilha o valor do topo da pilha
            auxPilha = auxPilha->proximo; // auxPilha que é o topo da pilha vai receber o elementos seguinte
        }
        else{ // caso valor da fila seja impar
            
            novaPilha = inserirPilha(novaPilha, auxPilha->valor); // vai ser inserido na nova pilha primeiro o valor da pilha
            novaPilha = inserirPilha(novaPilha, auxFila->valor); // vai ser inserido na nova pilha o valor da fila
            auxPilha = auxPilha->proximo; // auxPilha que é o topo da pilha vai receber o elementos seguinte
        }
    }
    return novaPilha; // retorna a nova pilha
}

void liberar(No *valores){ // vai liberar todos os espaços de memoria alocado para os nó
    
    No *atual = valores; // ponteiro atual vai receber inicio da lista
    No *proximo = NULL; // ponteiro proximo será um ponteiro auxiliar
    
    while(atual != NULL){ // vai ser executador enquanto o nó atual nao seja NULL
        
        proximo = atual->proximo; // ponteiro proximo vai receber um nó a frente do atual
        free(atual); // libera a memoria do nó atual
        atual = proximo; // atual recebe o proximo nó
    }
}

void main(){

    No *pilha;
    No *fila;
    No *novaPilha;

    pilha = inicializar(); // inicializa a pilha
    fila = inicializar(); // inicializa a fila
    novaPilha = inicializar(); // inicializa a nova pilha

    int op = 1, valor;

    while(op != 0){

        printf("1 - Inserir na Pilha\n");
        printf("2 - Inserir na Fila\n");
        printf("3 - Mostrar Pilha\n");
        printf("4 - Mostrar Fila\n");
        printf("5 - Juntar Pilha e Fila\n");
        printf("6 - Mostrar Nova Pilha Intercalada\n");
        printf("7 - Zerar Pilha Intercalada\n");
        printf("0 - Sair\n");
        printf("opcao:");
        scanf("%d", &op);
        system("cls");

        switch(op){

            case 1:

                printf("Informe um Valor:");
                scanf("%d", &valor);

                pilha = inserirPilha(pilha, valor);
                printf("Valor inserido com Sucesso\n\n");
                
                break;

            case 2:

                printf("Informe um Valor:");
                scanf("%d", &valor);

                fila = inserirFila(fila, valor);
                printf("Valor inserido com Sucesso\n\n");
                
                break;

            case 3:

                imprimePilha(pilha);
                break;

            case 4:

                imprimeFila(fila);
                break;

            case 5:

                if(pilha == NULL || fila == NULL){
                    printf("Pilha ou Fila Vazia!\n\n");
                }
                else{
                    
                    novaPilha = intercalar(pilha, fila);

                    printf("Nova Pilha Intercalada Criada!\n\n");
                    liberar(pilha);
                    liberar(fila);

                    pilha = inicializar();
                    fila = inicializar();
                }
                break;

            case 6:

                imprimePilha(novaPilha);
                break;
            
            case 7:

                novaPilha = inicializar();
                break;

            case 0:
                break;
        }
    }
}
