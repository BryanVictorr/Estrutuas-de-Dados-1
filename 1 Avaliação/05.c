#include <stdio.h>

char *cont_letra(char *string, int *Quantidade){

    int i,j,aux = 0,cont = 0;
    char *Letras = (char*) malloc((27) * sizeof(char)); // Declaro vetor de letras dinamicamente com 27 posições, as 26 do alfabeto + 1 que é '\0' do final da string 

    for(i = 0; *(string + i) != '\0'; i++){ // Vai percorrer toda a string
        
        for(j = 0; Letras[j] != '\0'; j++){ // Vai percorrer todo o meu vetor de letras
            
            if( *(string + i) == Letras[j]){ // Caso a Letra da string já exista no meu vetor letras
                
                *(Quantidade + j) += 1; // Meu Vetor de quantidade vai receber na mesma posição onde foi adicionada a letra no Vetor Letras o valor + 1
                
                aux = 1; // Aux vai receber 1 caso a letra já exista no vetor Letras
            }
        }
        
        if(aux == 0){ // Caso Aux seja igual a 0 a letra ainda não existe no meu Vetor Letras
        
            Letras[cont] = *(string + i); // Vetor Letras vai receber a letra
            
            *(Quantidade + cont) = 1; // Meu Vetor de quantidade vai adicionar o valor 1
            
            cont++; // cont vai ser responsável por armazenar a quantidade de Letras que foram adicionada no vetor Letras
        }
        
        aux = 0; // Zero meu aux, pois sempre preciso verificar se a letra existe no vetor Letras ou não
    }
    
    Letras[cont] = '\0'; // A última posição do meu Vetor Letras vai receber \0 para sabemos onde ele terminou
    
    return Letras; // Vou retornar o endereço de memória do meu Vetor Letras
}

void main(){

    int i,Quantidade[26]; // Declaro o vetor que vai armazenar a quantidade de letras, ele tem 26 posições pois são a quantidade de letras do alfabeto 
    
    char string[100],*P;

    for(i = 0; i < 26; i++){
        
        Quantidade[i] = 0; // Zera todas as posições do meu vetor de quantidade
    }

    printf("Digite:");
    scanf("%[^\n]",string);
    
    P = cont_letra(string,Quantidade); // Ponteiro P vai receber o endereço de memória do Vetor Letras retornado ao final da função
    
    for(i = 0; *(P + i) != '\0'; i++){
        
        printf("%c:[%d] ",*(P + i), Quantidade[i]); // Imprimo na tela qual a letra e depois a sua quantidade de vezes que foi repetida
    }
}