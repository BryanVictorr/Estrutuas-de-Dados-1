#include <stdio.h>

int maiusculas_vogais(char string[], int *maiuscula, int vogal){

    int i;

    for(i = 0; string[i] != '\0' ; i++){ //Vai se inicia um for até encontrar o caractere \0 que indica o final da string

        if(string[i] >= 65 && string[i] <= 90){ // Se o valor da tabela ascii for maior igual a 65 e menor igual a 90 será um caractere referente a letra Maiusculas

            *maiuscula += 1; // Aumenta a quantidade de maiuscula em 1
        }

        if(string[i] == 65 || string[i] == 97){ // Verifica que o caractere é a Letra A seja ela minúscula ou maiuscula

            vogal++; // aumenta a quantidade de vogais em 1
        }

        else if(string[i] == 69 || string[i] == 101){ // Verifica que o caractere é a Letra E seja ela minúscula ou maiuscula

            vogal++; // aumenta a quantidade de vogais em 1
        }

        else if(string[i] == 73 || string[i] == 105){ // Verifica que o caractere é a Letra I seja ela minúscula ou maiuscula

            vogal++; // aumenta a quantidade de vogais em 1
        }

        else if(string[i] == 79 || string[i] == 111){ // Verifica que o caractere é a Letra O seja ela minúscula ou maiuscula

            vogal++; // aumenta a quantidade de vogais em 1
        }

        else if(string[i] == 85 || string[i] == 117){ // Verifica que o caractere é a Letra U seja ela minúscula ou maiuscula

            vogal++; // aumenta a quantidade de vogais em 1
        }
    }

    return vogal; // retorno a quantidade de vogais
}

void main(){

    int maiuscula = 0, vogal = 0;

    char string_01[20],string_02[20];

    printf("Digite uma Palavra:");
    scanf("%s",string_01);

    printf("Digite uma Palavra:");
    scanf("%s",string_02);

    vogal = maiusculas_vogais(string_01, &maiuscula, vogal);
    printf("Quantidade de Maiusculas String 1:%d",maiuscula);

    maiuscula = 0; // Zero a variável maiuscula para receber a quantidade de maiusculas da nova string

    vogal = maiusculas_vogais(string_02, &maiuscula, vogal);
    printf("\nQuantidade de Maiusculas String 2:%d",maiuscula);
    printf("\nQuantidade Total de Vogais:%d",vogal);
}