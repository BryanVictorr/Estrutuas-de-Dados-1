#include <stdio.h>

void troca(char *string){

    int i;

    for(i = 0; *(string + i) != '\0' ; i++){ // Um for para percorrer a string até encontrar o carecte \0 que indica o fim da string

        if(*(string + i) == 97){ // Usando os valores da tabela ascii casa seja letra A 

            *(string + i) = 'u'; // vai receber na posição a letra U
        }

        else if(*(string + i) == 101){ //Usando os valores da tabela ascii casa seja letra E

            *(string + i) = 'o'; // receber na posição a letra O
        }

        else if(*(string + i) == 105){ //Usando os valores da tabela ascii casa seja letra I 

            *(string + i) = 'u'; //  receber na posição a letra U
        }

        else if(*(string + i) == 111){ // Usando os valores da tabela ascii casa seja letra O

            *(string + i) = 'a'; //  receber na posição a letra A
        }

        else if(*(string + i) == 117){ // Usando os valores da tabela ascii casa seja letra U

            *(string + i) = 'e'; //  receber na posição a letra E
        }
    }
}

void main(){

    char string[100];

    printf("Digite ate 100 letras:");
    scanf("%[^\n]",string);

    troca(string);

    printf("String Alterada:%s",string);

}