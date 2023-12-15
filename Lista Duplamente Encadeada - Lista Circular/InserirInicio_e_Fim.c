No *inserirInicio(No *lista, char *nome, int idade, int cpf){
    
    No *novo = (No*) malloc(sizeof(No));
    
    strcpy(novo->nome, nome);
    novo->cpf = cpf;
    novo->idade = idade;
    
    if(lista == NULL){
        
        novo->anterior = NULL;
        novo->proximo = NULL;
    }
    else{

        novo->proximo = lista;
        novo->anterior = NULL;
    }
    return novo;
}

No *inserirFim(No *lista, char *nome, int idade, int cpf){

    No *novo = (No*) malloc(sizeof(No));

    strcpy(novo->nome, nome);
    novo->cpf = cpf;
    novo->idade = idade;

    if(lista == NULL){

        novo->proximo = NULL;
        novo->anterior = NULL;
        return novo;
    }
    else{

        No *aux;
        for(aux = lista; aux->proximo != NULL; aux = aux->proximo);

        novo->anterior = aux;
        novo->proximo = NULL;
        aux->proximo = novo;
        return lista;
    }
}
