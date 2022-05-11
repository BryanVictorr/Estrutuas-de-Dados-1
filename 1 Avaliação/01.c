#include <stdio.h>

int soma_recursiva(int soma, int i){

    if(i == 0){ // caso meu numero seja igual a 0 não preciso mais fazer somas 

        return 0;
    }

    soma += soma_recursiva(soma, i - 1); // soma vai receber a mesma mais o retorno (passo a nova soma, passo meu numero - 1)
    
    soma += i; // somo o número atual a soma fin

    return soma; // retorno soma ao qual vai ser somada na recursao
}

void main(){

    int k,soma;

    printf("Dgite o valor de k:");
    scanf("%d",&k);
    
    soma = soma_recursiva(0, k);

    printf("Soma = %d",soma);
}