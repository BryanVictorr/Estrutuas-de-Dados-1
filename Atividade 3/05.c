#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* repete(char *s, int n){
    
    int tam_palavra = strlen(s); // palavra vai receber o tamanho da string
    
    char *nova_string = (char*) malloc((tam_palavra * n) + (n - 1) * sizeof(char));
    
    // alocar memoria suficiente para o tamanho da palavra * quantidade de repetição + quantidade de espaços
    
    strcpy(nova_string, s); // nova_string vai receber a string com a palavra informada pelo usuário
    
    for(int i = 0; i < n; i++){ // for vai se repetir a quantidade de repeticoes informadas pelo usuário
        
        if(i < n - 1){ // enquanto não for a última repetição
            
            strcat(nova_string," "); // strcat vai juntar " " no final da nova_string
            
            strcat(nova_string,s); // junta mais uma vez a palavra a nova_string
        }
    }
    
    return nova_string; // retorna a nova_string
}


void main(){
    
    int n;
    char *string = (char*) malloc((20) * sizeof(char));
    char *nova_string;
    
    printf("Informe a palavra:");
    scanf(" %[^\n]s",string); // faz a leitura da palavra
    
    printf("Quantas repeticoes:");
    scanf("%d",&n); // faz a leitura da quantidade de repetições
    
    nova_string = repete(string,n);
    
    printf("Nova String:%s",nova_string);
    
    free(string); // libera memoria da palavra
    free(nova_string); // libera memoria da nova_stringn
}
