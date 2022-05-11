#include <stdio.h>

float media (double vet[],int N, int *i){ 
    
    int j;
    float media, soma = 0.0, menor = 100.0, aux[N];
    
    for(j=1; j<=N; j++){    
        
        soma += vet[j-1]; //Faz a soma de todos os valores do vetor e guarda na variavel soma
        
    }
    
    media = soma/N; //A soma total dos valores dividido pela quantidade de valores que é N
    
    for(j=1; j<=N; j++){    

        float maiorBase,menorBase;
        
        if(media > vet[j-1]){ //Verificando o maior número, se é a media dos valores ou o valor armazenado na posição do vetor
            
            maiorBase = media; // maiorBase recebe media pois ela foi o maior valor
            menorBase = vet[j-1]; // menorBase Recebe o valor do vetor pois foi a menor posição
           
        }else{
            
            maiorBase = vet[j-1]; // maiorBase recebe o valor do vetor pois foi o maior valor
            menorBase = media; // menorBase recebe a media pois ela foi o menor valor
        }
        
        aux[j-1] = maiorBase - menorBase; // Vetor aux vai receber o maior valor menos o valor
        
        if(aux[j-1] < menor){ // Caso o valor da posição do vetor aux seja menor do que o da variavel
            
            menor = aux[j-1]; // A varia vai receber o valor que está no vetor aux, que é menor que ela mesma
        }
    }
    
    for(j=1; j<=N; j++){
        
        if(menor == aux[j-1]){ // Verifico onde está o indice da menor diferença guardada no vetor aux
            
            *i = j-1; // Armazena por referência qual foi o indice da menor diferença, ou seja o valor do vetor que se encontra mais próximo da média
            break;
        }
    }
    
    return media; // Retorno a media dos valores do vetor
}

int main(){
    
    int N,i,j;

    printf("Tamanho do Vetor: ");   
    scanf("%d", &N); // Faço a Leitura do tamanho do vetor
    
    double vet[N];
    
    for(j=1; j<=N; j++){    
        
        int x;
        
        printf("Digite um numero para adicionar ao indice %d: ",j-1);
        scanf("%d", &x); // Faço a leitra de todos os valores que quero adicionar ao vetor
        
        vet[j-1] = x;
        
    }
    
    printf("Media = %.2f\n",media(vet,N,&i)); // Imprimo o retorno da chamada da função media
    printf("Indice mais proximo %d",i); // Imprimo o indice que já foi alterado por referência na função
    
    return 0;
}