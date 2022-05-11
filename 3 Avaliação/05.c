#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct elemento{
    
    char nome[50];
    char cpf[11];
    int idade;
    struct elemento *proximo; // Ponteiro que vai indicar o proximo nó
    struct elemento *anterior; // Ponteiro que vai indicar o nó anterior

}No;

No *inicializar(){ // inicializa a lista de pessoas
    return NULL;
}

No *inserirOrdenado(No *lista, char *nome, int idade, char*cpf){ // vai adicionar pessoas a lista em ordem crescente pelo CPF
    
    int retorno;
    No *novo = (No*) malloc(sizeof(No));
    No *aux;
    
    // copiadado os dados para o novo nó
    strcpy(novo->nome, nome);
    strcpy(novo->cpf, cpf);
    novo->idade = idade;
    
    if(lista == NULL){ // caso a lista esteja vazia
        // elemento anterior e próximo recebe NULL pois é o único nó da lista
        novo->anterior = NULL;
        novo->proximo = NULL;
        return novo;
    }else{
        
        //funcao vai retornar se o primeiro CPF é maior que o novo CPF
        retorno = verificarMaior(lista->cpf, novo->cpf);
        
        if(retorno == 1){ // caso o CPF inicial seja maior
            
            novo->proximo = lista; // o próximo nó depois do novo vai ser o resto da lista
            novo->anterior = NULL; // o anterior vai ser NULL pois o nó foi adicionado ao inicio
            return novo;
        }
        
        for(aux = lista; aux->proximo != NULL; aux = aux->proximo){ // vai pecorrer a lista e guardar no aux o último nó
            
            retorno = verificarMaior(aux->proximo->cpf, novo->cpf); // vai verificar se o proximo CPF e maior que o novo
            
            if(retorno == 1){ // caso seja maior
                
                novo->proximo = aux->proximo; // o próximo nó depois do novo inserido será o próximo nó depois do último
                aux->proximo = novo; // o próximo nó depois do último vai ser o novo nó
                novo->anterior = aux; // o nó anterior ao novo vai ser o último
                return lista;
            }
        }
        
        aux->proximo = novo; //o próximo nó depois ro último vai ser o novo nó
        novo->anterior = aux; // o nó anterior ao novo vai ser o último
        return lista;
    }
}

int imprimeLista(No *lista){ // imprime todos os elementos da lista

    No *atual = lista; // ponteiro atual vai receber inicio da lista

    if(atual == NULL){ // caso a lista esteja vazia
        return -1;
    }

    printf("Pessoas\n\n");
    
    while(atual != NULL){ // vai percorrer toda a lista
        
        printf("Nome:%s - idade:%d - CPF:%s",atual->nome, atual->idade, atual->cpf);
        atual = atual->proximo; // ponteiro atual vai receber proximo nó
        printf("\n");
    }
    printf("\n");
}

int verificarMaior(char *cpf_lista, char *cpf_novo){
    
    int tamanho = strlen(cpf_lista); // tamanho vai receber a quantidade de digitos do CPF
    
    for(int i = 0; i < tamanho; i++){
        
        if(cpf_lista[i] > cpf_novo[i]){ // caso o digito do CPF da lista seja maior que o do novo CPF
            
            return 1; // vai ser retornado 1 para informado que o CPf da lista é maior
        }
    }
    return 0; // retorna 0 para informar que o novo é maior
}

No *listaPorIdade(No *lista, int idade){ // vai retornar uma lista com as pessoas com idade inferior a informada pelo usuario
    
    No *inicioNovaLista = (No*) malloc(sizeof(No));
    No *novaLista = NULL;
    No *aux;
    
    for(aux = lista; aux != NULL; aux = aux->proximo){ // vai pecorrer todos os elementos da lista
        
        if(aux->idade < idade){ // caso a idade da pessoa na lista seja menor que a informada pelo usuario
            
            if(novaLista == NULL){ // caso nova lista esteja vazia
                
                //atribuindo dados a nova lista 
                strcpy(inicioNovaLista->nome,aux->nome);
                strcpy(inicioNovaLista->cpf,aux->cpf);
                inicioNovaLista->idade = aux->idade;
                
                // elemento anterior e próximo recebe NULL pois é o único nó da lista
                inicioNovaLista->anterior = NULL;
                inicioNovaLista->proximo = NULL; 
                
                novaLista = inicioNovaLista; // nova lista vai receber nó do inicio
            }
            else{ // caso lista nao esteja vazia
                
                No *copia = (No*) malloc(sizeof(No)); // aloca memoria para o nó que será copiado da lista
                
                //atribuindo dados ao nó de copia
                strcpy(copia->nome, aux->nome);
                strcpy(copia->cpf, aux->cpf);
                copia->idade = aux->idade;
                

                copia->anterior = novaLista; // nó anterior ao copiado vai recebe o resto da lista
                copia->proximo = NULL; // proximo nó ao copiado será NULL
                novaLista->proximo = copia; // proximo elemento apos o fim da nova lista vai reccebe nó copiado
                novaLista = novaLista->proximo; // fim da nnova lista vai receber o elemento seguinte ao fim
            }
        }
    }
    return inicioNovaLista; //retorna inicio da nova lista
}

No *buscarVizinho(No *lista, char *cpf, int *maisVelho){ // vai devolver o nó que contem o vizinho mais velho
    
    int retorno, maiorAnterior = 0, maiorProximo = 0;
    No *aux;
    
    for(aux = lista; aux != NULL; aux = aux->proximo){ // vai pecorrer todos os nó da lista
        
        retorno = strcmp(aux->cpf, cpf);
        
        if(retorno == 0){ // caso o CPF seja igual ao informado pelo usuario
            
            if(aux->anterior != NULL){ // se a pessoa anterior for diferente de NULL
                maiorAnterior = aux->anterior->idade; // maiorAnterior vai receber idade da pessoa anterior
            }
            
            if(aux->proximo != NULL){ // se a pessoa proxima for diferente de NULL
                maiorProximo = aux->proximo->idade; // maiorProximo vai receber idade da proxima pessoa
            }
            
            if(maiorAnterior > maiorProximo){ // caso a idade da pessoa anterior seja maior que da proxima pessoa
                
                if(aux->anterior->idade > aux->idade){ // caso a idade do vizinho mais velho seja maior que da pessoa informado
                    *maisVelho = 1;
                }
                return aux->anterior; // retorna nó que contem pessoa anterior
            }
            else if(maiorProximo > maiorAnterior){ // caso a idade da proxima pessoa seja maior que da pessoa anterior;
                
                if(aux->proximo->idade > aux->idade){ // caso a idade do vizinho mis velho seja maior que da pessoa informada
                    *maisVelho = 1;
                }
                return aux->proximo; // retorna o nó que contem a proxima pessoa
            }
            else{ // caso a idade dos vizinhos sejam iguais
                
                if(aux->proximo->idade > aux->idade){ // caso a idade de um dos vizinho seja maior que da pessoa informada
                    *maisVelho = 1;
                }
                return aux->proximo; // retorna nó que contem um dos vizinho
            }
        }
    }
    return NULL; // retorna NULL caso nao seja encotrado CPF
}

void main(){
    
    int op = 1, idade, retorno;
    char cpf[11];
    char *nome = (char*) malloc((50) * sizeof(char));
    
    No *lista;
    No *novaLista;
    No *vizinho = NULL; // ponterio que vai guardar o nó que contem o vizinho mais velho
    
    lista = inicializar(); // inicializa essa lista de Pessoas
    novaLista = inicializar(); // inicializa nova lista de Pessoas
    
    while(op != 0){
        
        printf(" 1-Inserir Pessoa\n");
        printf(" 2-Imprime Lista de Pessoas\n");
        printf(" 3-Imprime Lista Pela Idade\n");
        printf(" 4-Mostrar Vizinho mais Velho\n");
        printf(" 0-Sair\n");
        printf(" Opcao:");
        scanf("%d", &op);
        system("cls");
        
        switch(op){

            case 1:

                printf("Informe o Nome:");
                scanf(" %[^\n]s", nome);

                printf("Informe CPF:");
                scanf(" %s", cpf);

                printf("Informe a idade:");
                scanf("%d", &idade);

                lista = inserirOrdenado(lista, nome, idade, cpf);
                printf("Pessoa Inserida com Sucesso!\n\n");
                break;

            case 2:

                retorno = imprimeLista(lista);

                if(retorno == -1){
                    printf("Lista Vazia!\n\n");
                }
                break;
                
            case 3:
            
                printf("Informe a Idade:");
                scanf("%d", &idade);
                
                novaLista = listaPorIdade(lista, idade);
                
                if(novaLista == NULL){
                    
                    printf("Não existe pessoas Menores que essa idade!\n\n");
                    break;
                }
        
                imprimeLista(novaLista);
                break;
                
            case 4:
            
                printf("Informe o CPF:");
                scanf(" %s", cpf);
                
                retorno = 0;
                vizinho = buscarVizinho(lista, cpf, &retorno);
                
                if(vizinho == NULL){
                    
                    printf("CPF não encontrado!\n\n");
                }
                else{
                    
                    printf("Vizinho mais velho tem %d anos\n",vizinho->idade);
                    
                    if(retorno == 1){
                        printf("Vizinho é mais velho!\n\n");
                    }
                    else{
                        printf("Vizinho é mais Novo!\n\n");
                    }
                }
                break;
        }
    }
}