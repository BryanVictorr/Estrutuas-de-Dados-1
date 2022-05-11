#include <stdio.h>

int primo(int m){

    int i,aux = 0;

    for(i = 1; i <= m; i++){ // contador sera iniciado em 1 e vai até ser igual o número informado

        if(m % i == 0){ // caso o resto da divisão do número informado por i tenha resto 0, significado que o número i é divisível pelo numero informado
        
            aux++; // contador responsável por armazenar quantos números são divisíveis pelo número informado
        }
    }

    if(aux == 2){ // caso aux seja igual a 2, ou seja quando o número tenha apenas 2 divisores comum
    
        return 1; // retorno 1 pois o número é primo
    }else{
        return 0; // retorna 0 pois o número não é primo
    }
}

void maior_menor(int m, int *p1, int *p2){

    int i;

    for(i = 1; i < m; i++){ // contador se inicia em 1 e vai até número informado - 1
        
        if(primo(i) == 1){ // vou passar esse número para a minha função primo, caso ele seja primo
        
            *p1 = i; // ponteiro *p1 vai receber esse número (que foi maior primo menor que número informado)
        }
    }

    i = 1;

    while(1){

        if (primo(m+i) == 1){ // vou chamar a minha função primo, mas desta vez vou passar o número informado + 1, caso ele seja primo 
            
            *p2 = m+i; // ponteiro *p2 vai receber esse número(que foi o primeiro primo depois do numero informado)
            
            break; // Quebra o lanço de repetição após a primeiro condição valida
        }
        else{ // enquanto não for condição valida
        
            i++; // contador receber + 1
        }
    }
}

void main(){

    int m, p1 = 0, p2 = 0;

    printf("Digite um numero m:");
    scanf("%d",&m);

    maior_menor(m, &p1, &p2);

    printf("Maior Primo menor que M:[%d]",p1);
    printf("\nMenor Primo maior que M:[%d]",p2);
}