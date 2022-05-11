#include <stdio.h>
#include <string.h>

void nova_string(char string_01[], char string_02[], char *string_03, int maior){

    int i,cont = 0;

    for(i = 0; i < maior; i++){ // vai executar enquanto i for menor que o tamanho da maior string

        if(string_01[i] == 97 || string_01[i] == 101 || string_01[i] == 105 || string_01[i] == 111 || string_01[i] == 117){ // caso a letra armazenada em string_01 no indice i seja uma vogal com base na tabela ascii
            
            *(string_03 + cont) = string_01[i]; // a string_03 vai receber a vogal contida em string_01
            
            cont++; // cont vai ser responsável por armazenar o indice que ja foi preenchido em string_03
        }
        
        if(string_02[i] == 97 || string_02[i] == 101 || string_02[i] == 105 || string_02[i] == 111 || string_02[i] == 117){ // caso a letra armazenada em string_02 no indice i seja uma vogal com base na tabela ascii

            *(string_03 + cont) = string_02[i]; // a string_03 vai receber a vogal contida em string_02
            
            cont++; // cont vai ser responsável por armazenar o indice que ja foi preenchido em string_03
        }
    }

    *(string_03 + cont) = '\0'; // string_03 na sua última posição preenchida + 1 vai receber \0 para indicar o final da string
}

void main(){

    int i, cont_01 = 0, cont_02 = 0, maior;
    char string_01[20], string_02[20], string_03[20];

    printf("Digite uma Palavra:");
    scanf("%s", string_01);

    printf("Digite outra Palavra:");
    scanf("%s", string_02);

    cont_01 = strlen(string_01); // recebe em cont_01 o tamanho da string_01
    
    cont_02 = strlen(string_02); // recebe em cont_02 o tamanho da string_02
    
    if(cont_01 > cont_02){ // caso a string_01 seja maior que a string_02

        maior = cont_01; // maior vai receber tamanho da string_01
    }
    else if(cont_02 > cont_01){ // caso a string_02 seja maior que a string_01

        maior = cont_02; // maior vai receber string_02
    }else{
        maior = cont_01; // caso sejam iguais maior vai receber string_01 já que não importa qual tamanho
    }

    nova_string(string_01, string_02, string_03, maior);
    printf("string intercalada:%s",string_03);
}