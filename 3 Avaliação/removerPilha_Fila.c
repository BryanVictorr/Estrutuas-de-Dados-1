*No *removerPilha(No *pilha){
    
    if(pilha == NULL){
        return NULL;
    }
    
    No *aux;
    
    for(aux = pilha; aux->proximo != NULL; aux = aux->proximo){
        aux->inicio = pilha->proximo;
    }
    
    aux->inicio = pilha->proximo;
    return pilha->proximo;
}

No *removerFila(No *fila){
    
    if(fila == NULL){
        return NULL;
    }
    
    No *aux;
    
    for(aux = fila; aux->proximo != NULL; aux = aux->proximo){
        aux->inicio = fila->proximo;
    }
    
    aux->inicio = fila->proximo;
    return fila->proximo;
}*
