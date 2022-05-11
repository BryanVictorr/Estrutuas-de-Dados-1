#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define INFINITO 10000000

int rec;

void guloso(int troco,int valores[],int tam){
    
    int i,cont = 0;
    int *aux = (int*) malloc(sizeof(int) * (troco + 1));
    
    for(i = 0; i < tam; i++){
        
        while(valores[i] <= troco){
            
            aux[cont] = valores[i];
            troco = troco - valores[i];
            cont++;
        }
    }
    
    aux[cont] = 0;
    printf("Quantidade minima de Moedas:%d - ",cont);
    
    for(i=0; aux[i] != 0; i++){
        
        printf("[%d] ",aux[i]);
        
    }
    
    printf("\n\n");
}


int recursivo(int valores[],int troco,int tam){
    
    if(troco == 0 || troco < 0){
        
        return 0;
        
    }
    
    int min_moedas = INFINITO,i,cont;
    
    for(i=0; i < tam; i++){
        
        if(troco >= valores[i]){
            
            rec++;
            cont = 1 + recursivo(valores,troco - valores[i],tam);
            
            if(min_moedas > cont){
                
                min_moedas = cont;
            }
        }
    }
    
    return min_moedas;
}


void dinamico(int valores[],int troco,int tam){
    
    int i,j,contador,qual_pegar,aux;
    int cont[troco+1],local[troco+1];
    
    for(i = 0;i < troco + 1;i++){
        
        cont[i] = 0;
        local[i] = 0;
    }
    
    for(i = 1;i < troco + 1; i++){
        
        contador = i; 
        qual_pegar = 1;
        
        for(j = 0;j < tam;j++){
            
            if(valores[j] <= i){
                
                rec++;
                
                aux = valores[j];
                
                if(cont[i-aux] + 1 < contador){
                    
                    contador = cont[i-aux] + 1;
                    qual_pegar = aux;
                }
                
            }
            
            cont[i] = contador;
            local[i] = qual_pegar;
        }
    }
    
    printf("Minimo Moedas:%d - ",cont[troco]);
    
    int *moedas = (int*) malloc(sizeof(int) * (troco + 1));
    aux = 0;
    
    while(troco > 0){
        
        moedas[aux] = local[troco];
        aux++;
        troco = troco - local[troco];
    }
    
    for(i = 0;i < aux; i++){
        
        printf("[%d] ",moedas[i]);
    }
}


void main(){
    
    int troco,tam,i,retorno;
    float tempo;
    
    time_t t_inicial,t_final;
    
    printf("Digite a quantidade de valores validos:");
    scanf("%d",&tam);
    printf("\n");
    
    int valores[tam];
    
    for(i = 0; i < tam; i++){
        
        printf("Informe o %d Valor:",i+1);
        scanf("%d",&valores[i]);
    }
    
    system("cls");
    int opcao = 1;
    
    while(opcao != 0){
        
        printf("1-Metodo Guloso(Quantidade e Moedas)");
        printf("\n2-Metodo Recursivo(Quantidade)");
        printf("\n3-Metodo Dinamico(Quantidade e Moedas)");
        printf("\n0-Encerrar Programa!\n");
        scanf("%d",&opcao);
        system("cls");
        
        printf("Informe o Troco:");
        scanf("%d",&troco);
        
        switch(opcao){
            
            case 1:
            
                guloso(troco,valores,tam);
                break;
                
            case 2:
            
                t_inicial = time(NULL);
                retorno = recursivo(valores,troco,tam);
                t_final = time(NULL);
                
                tempo = difftime(t_final,t_inicial);
                
                printf("Quantidade minima de moedas:%d\n",retorno);
                
                if(tempo == 0){
                    
                    printf("Numero de Recursividades:%d\n",rec);
                    
                    printf("Tempo de execucao menor que 1 segundo!\n\n");
                }else{
                    
                    printf("Numero de Recursividades:%d\n",rec);
                    
                    printf("Tempo:%.2fs\n\n",tempo);
                }
                
                rec = 0;
                break;
                
            case 3:
            
                dinamico(valores,troco,tam);
                
                printf("\nNumero de Interacoes:%d\n\n",rec);
                
                rec = 0;
                break;
        }
    }
}