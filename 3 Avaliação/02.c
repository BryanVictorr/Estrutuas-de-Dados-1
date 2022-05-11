#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct elemento{

    char placa[10];
    int vezesManobrado;
    struct elemento *proximo; // ponteiro para o proximo nó
    struct elemento *inicio; // ponteiro para o nó incial 
    struct elemento *fim; // ponteiro para o último nó
    
}No;

No *inicializar(){ // retorna NULL para inicializar a fila
    return NULL;
}

No *inserirCarro(No *fila, char *placa){ // vai inserir um carro ao estacionamento

    No *novo = (No*) malloc(sizeof(No)); // aloca memoria para o novo carro
	strcpy(novo->placa, placa);
    novo->vezesManobrado = 0; // inicializa as vezes que o carro novo foi manobrado com 0
	
	if(fila == NULL){ // caso o estacionamento esteja vazio

		novo->inicio = novo;
		novo->fim = novo;
        novo->proximo = NULL;
		return novo; // retorna o novo carro para a fila
	}
    else{

        No *aux;

        novo->inicio = fila;
	    novo->fim = novo; // ultimo carro será o novo adicionado
        novo->proximo = NULL; // proximo carro depois do novo será NULL

	    for(aux = fila; aux->proximo != NULL; aux= aux->proximo); // vai peccorer todos os carros

	    aux->proximo = novo; // proximo carro apos o ultimo será o novo
	    aux->fim = novo; // novo fim será o novo carro adicionado
	    return fila; // retorna a fila com o novo carro adicionado
    }
}

No *removerCarro(No *fila, char *placa, int *carrosNaFrente){ // remove um carro a partir de uma placa informada

    if(fila == NULL){
        return NULL; // retorna NULL caso o estacionamento esteja vazio
    }

    *carrosNaFrente = -1; // carros na frente do que será removido recebe -1 para informar que nao foi encotrado o carro ainda
    No *aux;
    No *inicioNovaLista = (No*) malloc(sizeof(No)); // aloca memoria para criar o novo estacionamento sem o carro informado
    No *novaLista = NULL;
    int verificar, cont = 0; // cont vai ser receber quantos carros tinha a frente do que vai ser removido
    
    for(aux = fila; aux != NULL; aux = aux->proximo){ // vai pecorrer todos os carros

        verificar = strcmp(aux->placa, placa); // verifica se a Placa do carro é igual a informada

        if(verificar != 0){ // caso verificar seja diferente de 0 queremos adicionar o carro ao novo estacionamento

            if(novaLista == NULL){ // caso novo estacionamento esteja vazio

                cont = 1; // contador de carros a frente vai receber 1
                strcpy(inicioNovaLista->placa, aux->placa);
                inicioNovaLista->vezesManobrado = aux->vezesManobrado;

                inicioNovaLista->inicio = inicioNovaLista; // inicio do novo estacionamento vai receber primeiro carro adicionado
                inicioNovaLista->fim = inicioNovaLista; // fim do novo estacionamento vai receber novo carro adicionado
                inicioNovaLista->proximo = NULL; // proximo carro apos o novo adicionado será NULL

                novaLista = inicioNovaLista; // nova lista vai receber novo estacionamento
            }
            else{ // caso o novo estacionamento nao estaja vazio

                No *copia = (No*) malloc(sizeof(No)); // aloca memoria para o carro que sera copiado do antigo para o novo

                cont++; // contador de carros a frente recebe +1

                // copia os dados do antigo carro para o novo estacionamento
                strcpy(copia->placa, aux->placa);
                copia->vezesManobrado = aux->vezesManobrado;

                copia->proximo = NULL; // proximo carro depois do novo adicionado sera NULL
                novaLista->proximo = copia; // proximo carro apos o ultimo vai receber o novo
                novaLista->fim = copia; // fim do novo estacionamento vai receber novo carro adicionado
                novaLista = novaLista->proximo; // nova lista vai receber a nova lista a frente
            }
        }
        else{ // caso o carro seja o que queremos remover

            //mostrar as manobras que esse carro fez para sair
            *carrosNaFrente = cont;
            printf("Carro foi Manobrado %d vezes para fora do Estacionamento!\n", aux->vezesManobrado);

        }
    }
    return inicioNovaLista; // retorna no antigo estacionamento o novo estacionamento criado
}

void imprimeEstacionamento(No *fila){ // imprime todos os carros do estacionamento

	if(fila == NULL){ // caso o estacionamento esteja vazio
        printf("Estacionamento Vazio!");
	}
    else{ // caso exista carros no estacionamento

        int i = 1; // vai informar qual a posicao do carro
        printf("Estacionamento\n\n");

        No *aux = fila; // aux recebe inicio do estacionamento

		while(aux != NULL){ // vai imprime os carros ate que esteva vazio

			printf("Carro:%d - Placa:[%s]\n", i, aux->placa);
            aux = aux->proximo;
            i++;
		}
	}
    printf("\n\n");
}

void manobrar(No *fila){ // Manobra todos os carros

    No *aux = fila; // aux vai receber inicio do estacionamento

    while(aux != NULL){ // vai pecorrer todos os carros ate que esteja vazio
        aux->vezesManobrado += 1; // quantidades de vezes do carro recebe +1
        aux = aux->proximo;
    }
}

int verificarPlaca(No *fila, char *placa){ // vai verificar se o carro a ser removido é o primeiro a saida

    int verificar = strcmp(fila->placa, placa);

    if(verificar == 0){
        return 1; // retorna 1 caso seja o mais proximo a saida
    }
    return 0; // retorna 0 caso nao seja o mais proximo a saida
}

void liberar(No *fila){ // vai liberar a memoria alocada para os elementos da pilha

    No *aux = fila;
    No *proximo;

    while(aux != NULL){

        proximo = aux->proximo;
        free(aux);
        aux = proximo;
    }
}

void main(){

    int carrosNaFrente, retornoPlaca;
    char *placa = (char*) malloc((10) * sizeof(char)), op = '1';

    No *fila;
    fila = inicializar();

    while(op != '0'){

        printf("******Estacionamento******\n");
        printf("E - Entrar\n");
        printf("S - Sair\n");
        printf("1 - Mostrar Estacionamento\n");
        printf("2 - Zerar Estacionamento\n");
        printf("0 - Sair\n");
        printf("*************************\n");
        printf("opcao:");
        scanf(" %c", &op);
        system("cls");

        switch(op){

            case 'E':

                printf("Informe a Placa:");
                scanf(" %s", placa);

                fila = inserirCarro(fila, placa);
                printf("Carro Entrou!\n\n");
                break;

            case 'S':

                printf("Informe a Placa:");
                scanf(" %s", placa);

                retornoPlaca = verificarPlaca(fila, placa);
                fila = removerCarro(fila, placa, &carrosNaFrente);

                if(fila == NULL){

                    printf("Estacionamento Vazio!\n\n");
                    break;
                }

                if(carrosNaFrente == -1){
                    printf("Placa nao Encontrada!\n\n");
                }
                else{

                    if(retornoPlaca != 1){
                        manobrar(fila);
                    }

                    printf("Carros Manobrados para esse ser removido %d!\n", carrosNaFrente);
                    printf("Carro Saiu\n\n");
                }
                break;

            case '1':

                imprimeEstacionamento(fila);
                break;

            case '2':

                liberar(fila);
                fila = inicializar();

                printf("Estacionamento Esvaziado!\n\n");
                break;

            case 0:
                break;
        }
    }
}