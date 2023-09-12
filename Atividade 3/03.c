#include <stdio.h>
#include <stdlib.h>

#define NOTAS 3 //Define a quantidade de notas

struct aluno {
    
    char nome[81];
    char matricula[8];
    char turma;
    float notas[NOTAS];
    
};

typedef struct aluno Aluno;

void preencher(Aluno** turmas,int n){
    
    //Preenche um Aluno
    
    for(int i = 0; i < n; i++){
        
        printf("Aluno %d\n\n",i + 1);

        printf("Nome:");
        scanf(" %[^\n]s",turmas[i]->nome);
        
        printf("Matricula:");
        scanf(" %[^\n]s",turmas[i]->matricula);
    
        printf("Turma (A) (B) (C):");
        scanf(" %c",&turmas[i]->turma);

        for(int j = 0; j < NOTAS; j++){ // Preenche as 3 notas do aluno

            printf("Digite a %d nota:",j + 1);
            scanf("%f",&turmas[i]->notas[j]);
        }
        system("cls");
    }
}

float calcularMedia(float *Notas){
    
    float media = 0.0;
    
    for(int i = 0; i < NOTAS; i++){ // i vai percorrer a quantidade de Notas
    
        media += Notas[i]; // media vai receber as 3 notas do referente aluno
    }
    
    media = (media / NOTAS); // media vai receber ela mesmo dividido pela quantidade de notas 

    return media; // retorno a media do aluno
}

void imprime_aprovados(Aluno** turmas,int n){
    
    int cont = 0;
    float media = 0.0;
    
    for(int i = 0; i < n; i++){
        
        media = calcularMedia(turmas[i]->notas); // media vai receber a media de notas do aluno i
        
        if(media >= 7){ // caso sua media seja maior ou igual a 7 ele foi aprovado e seus dados serão impressos
            
            printf("Aluno Aprovado!\n\n");
            printf("Nome:%s\n",turmas[i]->nome);
            printf("Numero da Matricula:%s\n",turmas[i]->matricula);
            printf("Turma:%c\n\n",turmas[i]->turma);
            cont = 1;
        }
    }

    if(cont == 0){
        
        system("cls");
        printf("Nao existe Alunos Aprovados!");
    }
}

float* media_turma(Aluno** turmas, char turma, int n){
    
    int cont = 0;
    
    for(int i = 0; i < n; i++){ // i vai percorrer a quantidade de alunos
        
        if(turmas[i]->turma == turma){ // vai verificar se o aluno possui a turma informada
        
            cont++; // cont vai armazenar a quantidade de aluno da Referente turma
        }
    }
    
    float *medias = (float*) malloc((cont) *sizeof(float));
    // Aloca memoria para armazenar as medias dos alunos daquela turmas
    
    cont = 0;
    
    for(int i = 0; i < n; i++){
        
        if(turmas[i]->turma == turma){// Vai percorrer todos os alunos até encontrar um com a turma referida
            
            medias[cont] = calcularMedia(turmas[i]->notas); // medias na posição i (Aluno ) vai receber sua media final

            cont++; // cont++ para o proximo aluno
        }
    }
    
    return medias; // retorna as media finais
}

void imprime_medias(Aluno** turmas, float* Medias, char turma, int n){
    
    int cont = 0;
    
    for(int i = 0; i < n; i++){ // vai imprimir a media final de cada alubo
        
        if(turmas[i]->turma == turma){ // se turma do curso i é igual a turma informada pelo usuário
            
            printf("Nome:%s\n",turmas[i]->nome);
            printf("Media:%.2f\n\n",Medias[cont]);
            cont++;
        }
    }
}

void main(){
    
    int TAM;
    float *Medias;
    
    Aluno **Alunos;
    Alunos = malloc((TAM) * sizeof(Aluno*));
    
    //Aloco espaço para o vetor de ponteiros

    for(int i = 0; i < TAM; i++){
        Alunos[i] = malloc(sizeof(Aluno)); // aloca memoria para cada posição do vetor
    }
    
    while(1){
        
        int opcao;
        char turma;
        
        printf("1-Criar Classe\n2-Imprime Alunos Aprovados\n3-Media de Alunos de uma Turma\n0-Sair\n");
        scanf("%d",&opcao);
        
        system("cls");
        
        if(opcao == 0){
            break;
        }
        
        switch(opcao){
            
            case 1:
            
                printf("Quantidade de Alunos para Cadastro:");
                scanf("%d",&TAM); // le a quantidade de alunos para ser cadastrado
                
                system("cls");
                
                preencher(Alunos,TAM);
                break;
                
            case 2:
            
                imprime_aprovados(Alunos,TAM);
                break;
                
            case 3:
            
                printf("Escolha a Turma (A) (B) (C):");
                scanf(" %c",&turma);
                
                Medias = media_turma(Alunos,turma,TAM);
                imprime_medias(Alunos,Medias,turma,TAM);
                break;
        }
    }
    
    free(Alunos);
    free(Medias);
}