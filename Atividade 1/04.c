#include <stdio.h>

void minutosHoras(int totalMinutos,int *horas,int *minutos){

    *horas = totalMinutos/60; // A convenção de minutos para horas se dá por minutos/60 onde para cada hora há 60 minutos
    *minutos = totalMinutos - (*horas * 60); // Os minutos que sobraram se dão pelo cálculo de horas*60 menos os minutos total digitado

}

void main(){

    int total,h,m;

    printf("Digite o total de minutos: ");
    scanf("%d",&total); // Fazendo a leitura do total de minutos

    minutosHoras(total,&h,&m); // chamando a função e passando seus parâmetros por referência

    printf("Horas: %d Minutos: %d",h,m); // imprimindo os novos valores alterados

}