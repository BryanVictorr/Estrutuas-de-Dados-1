#include <stdio.h>
#include <stdlib.h>

typedef struct elemento{
    
    int valor;
    struct elemento *proximo; // Ponteiro que vai indicar o proximo nó
    struct elemento *anterior; // Ponteiro que vai indicar o nó anterior
    
}No;

typedef struct{
    
    No *inicio; // ponteiro do tipo nó que vai indicar o inicio da lista de nó
    No *fim; // ponteiro do tipo nó que vai indicar o fim da lista de nó
    int tam; // variavel que indica a quantidade de nó ou tamanho da lsita
    
}Lista;

void inicializar(Lista *lista){ // funçao vai iniciar o ponteiro inicio da lista e fim da lista com valores NULL
    
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->tam = 0; // tamanho da lista inicializado com 0
}

int inserir(Lista *lista, int valor){ // funçao responsavel por adicionar nó com valores sempre ao final da lista
    
    No *novo = (No*) malloc(sizeof(No)); // aloca memoria para o novo nó
    No *atual; // ponteiro auxiliar que vai indicar o nó atual da lista
    
    if(novo == NULL){
        return -1; // caso o novo nó nao seja alocado com sucesso
    }
    
    novo->valor = valor; // atribuido o valor ao novo nó
    novo->proximo = NULL; // ponteiro que indica o proximo nó recebe NULLL
    
    if(lista->inicio == NULL){ // caso a lista esteja vazia
        
        novo->anterior = NULL; // ponteiro que indica o nó anterior vai receber NULL pois é o primeiro nó
        lista->inicio = novo; // ponteiro inicio vai apontar para o novo nó
        lista->fim = novo; // ponteiro fim vai apontar para o novo nó;
    }
    else{ // caso a lista não esteja vazia

        atual = lista->inicio; // ponteiro atual vai receber o inicio da lista

        while(atual->proximo){ // enquanto nao for o fim da lista
            atual = atual->proximo; // nó atual vai receber proximo nó
        }

        novo->anterior = atual; // ponterio anterior do novo nó vai receber nó atual
        lista->fim->proximo = novo; // ponterio que indica o fim da lista um nó a frente vai receber novo nó
        lista->fim = novo; // ponteiro que indica o fim da lista vai receber novo nó
    }
    
    lista->tam += 1; // tamanho da lista recebe mais 1
    return 0; // retorna 0 para indicar que tudo ocorreu bem
}

int remover(Lista *lista, int valor){ // funcao vai remover um valor informado
    
    No *atual = lista->inicio; // ponteiro atual vai receber inicio da lista
    No *aRemover = NULL; // ponteiro aRemover vai indicar qual nó deverá ser removido
    
    if(atual != NULL && lista->inicio->valor == valor){ // caso o valor esteja no primeiro nó
        
        aRemover = lista->inicio; // ponteiro aRemover vai receber o inicio da lista
        lista->inicio = aRemover->proximo; // o novo inicio agora será o proximo nó depois do removido
        
        if(lista->inicio == NULL){ // caso o novo inicio seja NULL
            lista->fim = NULL; // fim tambem vai receber NULL pois não há mais nó
        }
        else{ // caso o novo inicio nao seja NULL
            lista->inicio->anterior = NULL; // ponteiro anterior vai receber NULL pois se trata do primeiro nó
        }
    }
    else{ // caso o valor não esteja no primeiro nó
        
        while(atual != NULL && atual->proximo != NULL && atual->proximo->valor != valor){ // vai percorrer a lista ate encontra o valor ou nó null
            atual = atual->proximo;
        }
        
        if(atual->proximo){ // caso encontre e o nó a frente não seja null
            
            aRemover = atual->proximo; // ponteiro vai receber o nó respectivo do valor
            atual->proximo = aRemover->proximo; // esse nó vai receber o seu proximo nó
            
            if(atual->proximo == NULL){ // caso o proximo nó seja null
                lista->fim = atual; // ponteiro que indica o final da lista recebe NULL
            }
            else{ // caso o proximo nó nao seja nulo
                atual->proximo->anterior = atual; // o ponteiro do proximo nó que indica o seu nó anterior vai receber seu nó atual
            }
        }
    }
    if(aRemover){

        lista->tam -= 1; // diminui o tamanho da lista em 1
        free(aRemover); // libera a memoria alocada para o nó que foi removido
        return 0; // retorna 0 se tudo ocorreu bem
    }
    return -1; // retorna -1 caso ocorra algum erro
}

int buscar(Lista *lista, int valor){ // vair ealizar a busca por algum valor informado pelo usuario
    
    int i = 1;
    No *atual = lista->inicio; // ponteiro atual vai receber inicio da lista
    
    while(atual != NULL){ // vai percorrer toda a lista
        
        if(atual->valor == valor){ // caso o valor na lista seja igual ao informado pelo usuario
            printf("Valor Encotrada no Indice %d\n",i);
            return 0;
        }
        
        i++; // indice da lista aumenta em 1
        atual = atual->proximo; // atual vai receber proximo nó
    }
    return -1;
}

int imprime(Lista *lista){ // funcao vai imprimir todos os nó da lista e seus valores
    
    No *atual = lista->inicio; // ponteiro atual vai receber inicio da lista

    if(atual == NULL){ // caso a lista esteja vazia será retornado -1
        return -1;
    }
    
    printf("Tamanho atual da Lista:%d\n",lista->tam);
    printf("Valores:");
    
    while(atual != NULL){ // vai percorrer toda a lista
        
        printf("[%d]",atual->valor);
        atual = atual->proximo; // ponteiro atual vai receber proximo nó
    }
    printf("\n\n");
    return 0;
}

int imprimeReverso(Lista *lista){ // vai imprimir todos os nó e valores da lista só que do fim ao inicio

    No *ultimo = lista->inicio; // ponteiro ultima vai receber inicio da lista

    if(ultimo == NULL){ // retorna -1 caso a lista esteja vazia
        return -1;
    }

    while(ultimo->proximo){ // vai percorrer toda a lista
        ultimo = ultimo->proximo; // vai guardar o ultimo nó
    }

    printf("Tamanho atual da Lista:%d\n",lista->tam);
    printf("Valores:");
    
    while(ultimo){ // vai ser executado ate ultimo ser igual a NULL
        
        printf("[%d]",ultimo->valor);
        ultimo = ultimo->anterior; // ultimo nó vai receber nó anterior
    }
    printf("\n\n");
    return 0;
}

void liberarLista(Lista *lista){ // vai liberar todos os espaços de memoria alocado para os nó
    
    No *atual = lista->inicio; // ponteiro atual vai receber inicio da lista
    No *proximo = NULL; // ponteiro proximo será um ponteiro auxiliar
    
    while(atual != NULL){ // vai ser executador enquanto o nó atual nao seja NULL
        
        proximo = atual->proximo; // ponteiro proximo vai receber um nó a frente do atual
        free(atual); // libera a memoria do nó atual
        atual = proximo; // atual recebe o proximo nó
    }
}

void main(){
    
    int op = 1, valor, retorno;
    
    Lista *lista = (Lista*) malloc(sizeof(Lista)); // aloca memoria para a lista de nó
    inicializar(lista); // inicializa essa lista de nó
    
    while(op != 0){
        
        printf("1-Inserir Valor\n");
        printf("2-Buscar Valor\n");
        printf("3-Remover Valor\n");
        printf("4-Imprime Lista\n");
        printf("5-Imprime Reverso\n");
        printf("6-Liberar Lista\n");
        printf("0-Sair\n");
        printf("Opcao:");
        scanf("%d", &op);
        system("cls");
        
        switch(op){
            
            case 1:
            
                printf("Informe Valor para Inserir:");
                scanf("%d", &valor); // leitura do valor a ser inserido
                
                retorno = inserir(lista,valor);
                
                if(retorno == 0){
                    printf("Valor Inserido com Sucesso!\n\n");
                }
                else{
                    printf("Erro ao Inserir Valor!\n\n");
                }
                break;
                
            case 2:
            
                printf("Informe Valor para Buscar:");
                scanf("%d", &valor); // leitura do valor para busca
                
                retorno = buscar(lista,valor);
                
                if(retorno == -1){
                    printf("Valor nao Encontrado!\n\n");
                }
                break;
                
            case 3:
            
                printf("Informe Valor para Remover:");
                scanf("%d", &valor); // leitura do valor para remoçao
                
                retorno = remover(lista,valor);
                
                if(retorno == 0){
                    printf("Valor Removido!\n\n");
                }
                else{
                    printf("Valor nao Encontrado!\n\n");
                }
                break;
                
            case 4:
            
                retorno = imprime(lista);

                if(retorno == -1){
                    printf("Lista Vazia!\n\n");
                }
                break;
                
            case 5:
            
                retorno = imprimeReverso(lista);

                if(retorno == -1){
                    printf("Lista Vazia!\n\n");
                }
                break;
            
            case 6:

                liberarLista(lista);
                inicializar(lista); // apos liberar a memoria a lista e inicializada com inicio e fim NULL
                printf("Espaco de Memoria Liberado!\n\n");
                break;
            
            case 0:
                break;
        }
        
    }
}