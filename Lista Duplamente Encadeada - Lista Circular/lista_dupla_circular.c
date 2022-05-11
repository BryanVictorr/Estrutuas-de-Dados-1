#include <stdio.h>
#include <stdlib.h>

struct no{
    
	int valor;
	struct no *proximo; // ponteiro para o próximo nó
	struct no *anterior; // ponteiro pra o nó anterior
	
};

typedef struct no NO;

NO *inicializarLista(){ // retorno NULL na função para inicializar
    
	return NULL;
}

NO *inserirInicio(NO *lista, int valor){ // vai inserir valores e sempre adicionar ao inicio da lista
	
	NO *novo = (NO*) malloc(sizeof(NO));// aloca memoria para o novo nó que será adicionado
	novo->valor = valor; // valor adicionado ao novo nó

	if(lista == NULL){ // caso a lista esteja vazia
	    
		novo->proximo = novo; // ponteiro próximo recebe novo nó
		novo->anterior = novo; // ponteiro anterior recebe no nó
	}
	else{ // caso lista não esteja vazia
	
	    NO *aux;
	    
		novo->proximo = lista; // ponteiro próximo do novo nó vai recebe lista
		lista->anterior = novo; // lista anterior vai receber recebe novo nó
		
		for(aux = lista; lista != aux->proximo; aux = aux->proximo); // sera executado ate o início ser igual ao fim e armazenar em aux o fim
		    
		aux->proximo = novo; // o próximo nó depois do último será o novo nó
		    
		novo->anterior = aux; // o nó anterior ao novo adicionado será o último que existia na lista
		
	}
	return novo;
}

NO *inserirFinal(NO *lista, int valor){ // vai inserir valores e sempre adicionar ai final da lista	
    
	NO *novo = (NO*) malloc(sizeof(NO)); // aloca memoria para o novo nó
	novo->valor = valor; // valor adicionado ao novo nó

	if(lista == NULL){ // caso a lista esteja vazia
	    
		novo->proximo = novo; // ponteiro proximo do novo nó vai receber novo nó, pois é o único nó da lista
		novo->anterior = novo; // ponteiro anterior vai receber novo nó, pois é o único nó da lista
		
		return novo;
	}
	else{ // caso a lista não seja vazia
	    
		NO *aux; // variável nó auxiliar que vai ajudar encontrar último nó
		aux = lista; // variável nó auxiliar vai receber inicio da lista
		
		lista->anterior = novo; // o anterior ao início vai apontar para o novo nó adicionado que no caso é o último 
		
		novo->proximo = lista; // o próximo nó depois do último sera o início da lista
		
		for(aux = lista; lista != aux->proximo; aux = aux->proximo);// vai pecorrer todos os nó
		
		aux->proximo = novo; // proximo nó do ponteiro auxiliar vai receber novo nó
		novo->anterior = aux; // nó anterior do novo nó vai receber ponteiro auxiliar
		return lista;
	}
}

void mostrarLista(NO *lista){ // vai exibir todos os nó da lista
    
    NO *aux = lista; // ponteiro auxiliar recebe inicio da lista
    
	if(lista == NULL){ // caso lista esteja vazia
		printf("Lista Vazia!\n\n");
	}
	else{
	    
		printf("LISTA:");
		
		do{ // vai garantir que o primeiro nó seja executado
		
			printf("[%d]",aux->valor);
			aux = aux->proximo;
			
		}while(aux != lista); // verifica se o próximo nó é o nó inicial
		printf("\n\n");
	}
}

void mostrarInverso(NO *lista){ // vai exibir todos os nó da lista só que inversamente
    
    NO *aux = lista->anterior; // ponteiro auxiliar recebe nó anterior ao início da lista
    
	if(lista == NULL){ // caso lista esteja vazia
		printf("Lista Vazia!\n\n");
	}
	else{
	    
		printf("LISTA INVERTIDA:");
		
		while(lista != aux){ // vai ser executado até o primeiro nó ser igual ao último
		    
		    printf("[%d]",aux->valor);
		    aux = aux->anterior; // aux vai receber seu nó anterior
		}
		printf("[%d]",aux->valor); // print do último elemento, caso inicio seja igual ao fim o fim não será executado, por isso um print exclusivo do último nó
		printf("\n\n");
	}
}

int buscar(NO *lista, int valor){ // vai fazer uma busca na lista a partir de um valor do usuário
    
    NO *aux = lista; // aux vai receber inicio da lista
    
	if(lista == NULL){ // caso a lista esteja vazia
		printf("Lista Vazia!\n\n");
	}
	else if(lista->valor == valor){ // caso o valor informado esteja no primeiro nó
	    printf("Valor encontrado!\n\n");
	    return 1;
	}
	else{ // caso a lista não esteja vazia
	    
		while(lista != aux->proximo){ // vai pecorrer todos os nó da lista ate que o primeiro seja igual ao último
		    
			if(aux->valor == valor){ // caso o valor de algum nó seja igual ao do usuário
				printf("Valor encontrado!\n\n");
				return 1;
			}
			aux = aux->proximo; // aux vai receber o proximo nó
		}
		if(aux->valor == valor){ // verificaçao para o último nó
		    printf("Valor encontrado!\n\n");
		    return 1;
		}
		return 0;
	}
}

NO* remover(NO *lista, int valor){ // vai remover um nó da lista a partir de um valor do usuário
    
	if(lista == NULL){ // caso lista esteja vazia
	    
		printf("Lista Vazia!\n\n");
		return lista;
	}
	else{ // caso lista não seja vazia
	
	    if(lista->proximo == lista){ //caso exista apenas um nó na lista
	    
	        if(lista->valor == valor){ // se valor do nó seja igual ao do usuário
	            
	            return NULL; // retorna null pois não existe mais nó na lista
	        }
	        else{
	            printf("Valor nao encontrado!\n\n");
	            return lista;
	        }
	        
	    }
	    
	    NO *aux;
		
		if(lista->valor == valor){ // caso o primeiro nó seja o informado pelo usuário
		    
			printf("Valor Removido!\n\n", valor);
			
			for(aux = lista; lista != aux->proximo; aux = aux->proximo);// vai ser executado ate o nó aux ser igual ao nó inicial
			
			lista = lista->proximo; // o início da lista agora será um nó a frente
			lista->anterior = aux; // e o nó anterior do novo início vai apontar para o último nó
			
			return lista; // retorna a lista alterada
		}
		
		for(aux = lista; lista != aux->proximo; aux = aux->proximo){ // vai pecorrer todos os nó até que o início seja igual ao fim
		    
			if(aux->proximo->valor == valor){ // caso o próximo nó tenha o valor igual ao do usuário 
			    
				NO *local; // vai armazenar qual nó será removido
				local = aux->proximo->proximo; // local vai receber o que o nó removido apontava
				aux->proximo = local; // próximo nó depois do atual vai receber local
				local->anterior = aux; // no local tem como seu anterior o último nó
				
				printf("Valor Removido!\n\n", valor);
				return lista;
			}
		}
		printf("Valor:%d nao encontrado!\n\n", valor);
		return lista;
	}
}

void liberarMemoria(NO *lista){ // libera toda a memória alocada para os nó
    
    if(lista == NULL){
		free(lista);
	}

	else{

		NO *aux = lista;

		void liberando(NO *lista){

			if(lista->proximo != aux){
				liberando(lista->proximo);
			}
			free(lista);
		}
		liberando(lista);
		free(lista);
		free(aux);
	}
}

void main(){
    
    NO *lista;
    int valor, busca;
    
    lista = inicializarLista();

    while(1){
        
        int op_menu;
        
        printf("************ MENU **************\n");
        printf(" 1 - Inserir no Inicio\n");
        printf(" 2 - Inserir no Fim\n");
        printf(" 3 - Exibir\n");
        printf(" 4 - Exibir Invertida\n");
        printf(" 5 - Buscar Elemento\n");
        printf(" 6 - Remover Elemento\n");
        printf(" 7 - Liberar Memoria \n");
        printf(" 0 - SAIR\n");
        printf("*********************************\n");
        printf("opcao:");
        scanf("%d", &op_menu);
        system("cls");
        
        switch(op_menu){
            
            case 1:
            
                printf("Numero a inserir:");
                scanf("%d",&valor);
                
                lista = inserirInicio(lista, valor);
                
                if(lista != NULL){
                    printf("Valor Inserido!\n\n");
                }
                break;
    
            case 2:
            
                printf("Numero a inserir:");
                scanf("%d", &valor);
                
                lista = inserirFinal(lista, valor);
                
                if(lista != NULL){
                    printf("Valor Inserido!\n\n");
                }
                break;
    
            case 3:
            
                mostrarLista(lista);
                break;
    
            case 4:
                
                mostrarInverso(lista);
                break;
                
            case 5:
            
                printf("Numero para Busca:");
                scanf("%d", &valor);
                
                busca = buscar(lista, valor);
                
                if(busca == 0){
                    printf("Valor nao encontrado!\n\n");
                }
                break;
                
            case 6:
            
                printf("Numero para remover:");
                scanf("%d", &valor);
                
                lista = remover(lista,valor);
                break;
                
            case 7:
            
                liberarMemoria(lista);
                lista = inicializarLista();
                printf("Memoria Liberada!\n\n");
                break;
                
            case 0:
                break;
        }
    }
}