#include <stdio.h>

int soma_recursiva(int A, int soma, int B){

    if(A == B || A - 1 == B){ // caso meu número atual seja igual ao maior número informado pelo usuário não preciso fazer mais somas, ou caso não existe intervalos entre A e B;

        return 0;
    }

    soma += soma_recursiva(A + 1, soma, B); // soma vai receber ela mesmo mais o retorno da função (passo meu menor numero + 1, passo o maior numero)
    
    soma +=A; // somo o número atual a soma total

    return soma; // retorno soma ao qual vai ser somada na recursão
}

void main(){

    int A,B,soma,aux;

    printf("Digite o valor de A:");
    scanf("%d",&A);

    printf("Digite o valor de B:");
    scanf("%d",&B);

    if (B < A){ // vai verificar se o segundo número informado pelo usuário é menor que o primeiro (A)

        aux = B;;
        B = A;
        A = aux; // Caso seja menor o primeiro valor (A) vai receber o segundo (B)
    }
    
    soma = soma_recursiva(A + 1, 0, B);

    printf("Soma = %d",soma);
}