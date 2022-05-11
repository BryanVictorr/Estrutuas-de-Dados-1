#include <stdio.h>

void fatoraPotencia(int numero,int *base,int *expoente){
    
    int i,j,soma = 1;
    
    for(i=2; numero != soma && numero != 0 ;i++){ // Vai ser iniciar um lanço de repetição caso o número seja diferente de 0 e soma seja diferente do número digitado,pois se for igual a base e expoente ja foi encontrado
        
        soma = 1; //Soma precisa ser iniciada com 1 pois é o  número netro em multiplicação
        
        for(j=0; soma < numero;j++){ // se soma for menor que o número digitado a chance da base está certa onde j é o expoente, se ela for maior isso diz que a base precisa ser aumentada
            
            soma *= i; //soma vai receber ela mesmo vezes i onde i é a base
            
        }
    }

    if(numero == 0){ // caso o usuário digite o valor 0 tratamos essa condição

        *base = 0;
        *expoente = 1;

    }

    if(numero != 0){ // caso o valor seja inteiro e maior que 0

        *base = i-1; // base vai receber i onde i foi a base encontrado menos 1, pois antes do lanço parar ele aumenta +1
        *expoente = j; // expoente vai receber j onde j foi o expoente encontrado

    }
}

void main(){
    
    int valor,base = 0,expoente = 0;
    
    printf("Digite um Valor: ");
    scanf("%d",&valor); // faço a leitura do valor
    
    fatoraPotencia(valor,&base,&expoente); //chamo a função e passo os parâmetros por referência
    
    printf("Base = %d Expoente = %d",base,expoente); // Imprimo os novos valores alterados por referência

}