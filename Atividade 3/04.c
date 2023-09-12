#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct disciplina {
    
    char codigo_disciplina[20];
    char codigo_curso[20];
    int periodo;
    int horas;
    char nome[50];
    
};

typedef struct disciplina Disciplina;

struct curso {
    
    char codigo[20];
    int quant_periodo;
    char nome[50];
    Disciplina *disciplinas_curso; // vetor de struct disciplinas
    
};

typedef struct curso Curso;

void criarCurso(Curso *cursos, int cont_curso){
    
    //Vai cadastrar um curso na posição cont_curso que vai funcionar como um contador de cursos
    
    printf("Nome do Curso:");
    scanf(" %[^\n]s",cursos[cont_curso].nome);
    
    printf("Codigo do Curso:");
    scanf(" %[^\n]s",cursos[cont_curso].codigo);
    
    printf("Quantidade de Periodos:");
    scanf("%d",&cursos[cont_curso].quant_periodo);

    system("cls");
}

void criarDisciplina(Curso* cursos,int cont_curso, int cont_disciplina){
    
    //criar uma Disciplina que ja é referenciada dentro da struct Curso como ponteiro

    printf("Nome da Disciplina:");
    scanf(" %[^\n]s",cursos[cont_curso].disciplinas_curso[cont_disciplina].nome);

    printf("Codigo da Disciplina:");
    scanf(" %[^\n]s",cursos[cont_curso].disciplinas_curso[cont_disciplina].codigo_disciplina);

    printf("Periodo:");
    scanf("%d",&cursos[cont_curso].disciplinas_curso[cont_disciplina].periodo);

    printf("Carga Horaria:");
    scanf("%d",&cursos[cont_curso].disciplinas_curso[cont_disciplina].horas);

    system("cls");
}

int verifCurso(Curso *cursos, int cont_curso){
    
    //Vai verificar se um codigo de curso informado pelo usuario existe

    int iguais;
    char string[20];

    printf("Informe o codigo referente ao Curso:");
    scanf(" %[^\n]s",string); // leitura do codigo de busca

    for(int i = 0; i <= cont_curso; i++){ // percorrer a quantidade de cursos

        iguais = strcmp(string, cursos[i].codigo); // se o codigo informado pelo usuario for igual ao codigo de algum curso strcmp vai retornar 0 para a variavel iguaid

        if(iguais == 0){ // se o codigo existe em cursos
        
            return i; // retorna qual curso tem esse codigo
        }
    }
    return -1; // retorna -1 caso nao exista curso com esse codigo
}

void imprimeCursos(Curso *cursos, int cont_curso, int cont_disciplina[]){
    
    //Vai Imprimir todos os cursos e os atributos referentes ao mesmo
    
    printf("Cursos Cadastrados Abaixo\n\n");
    
    for(int i = 0; i <= cont_curso; i++){ // vai percorrer a quantidade de cursos
        
        printf("Nome do Curso:%s\n",cursos[i].nome);
        printf("Codigo do Curso:%s\n",cursos[i].codigo);
        printf("Periodos:%d\n\n",cursos[i].quant_periodo);

        if(cont_disciplina != 0){

            for(int j = 0; j < cont_disciplina[i]; j++){ // vai percorrer a quantidade de disciplinas

                printf("[%s] - ",cursos[i].disciplinas_curso[j].nome);
                printf("Periodo:%d - ",cursos[i].disciplinas_curso[j].periodo);
                printf("Carga Horario:%d:00hs - ",cursos[i].disciplinas_curso[j].horas);
                printf("Codigo:%s\n",cursos[i].disciplinas_curso[j].codigo_disciplina);
            }
            printf("\n");
        }
        else if(cont_disciplina == 0){ // caso não exista disciplinas cadastradas
        
            printf("Nao existe disciplinas cadastradas!");
        }
    }

    system("pause");
    system("cls");
}

void maisPeriodo(Curso* cursos, int cont_curso){

    int maior = 0, aux;
    
    //Vai imprimir o curso com a maior quantidade de periodos

    for(int i = 0; i <= cont_curso; i++){ // vai percorrer todos cursos

        if(cursos[i].quant_periodo > maior){ // se a quantidade daquele curso for maior que a variavel maior
            
            maior = cursos[i].quant_periodo; // a variavel maior vai receber a quantidade de cursos
            
            aux = i; // aux vai gravar o indice do curso que teve a maior quantidade de periodos
        }
    }

    printf("Curso com a maior quantidade de Periodos:%s com %d Periodos\n\n",cursos[aux].nome, cursos[aux].quant_periodo);
}

void quantDisciplina(Curso* cursos,int cont_curso, int cont_disciplina){
    
    //Vai imprimir a quantidade de disciplinas de um determinado curso, que foi informado pelo usuario

    printf("Curso:%s com %d disciplinas\n\n",cursos[cont_curso].nome, cont_disciplina);
}

void disciplinaPeriodo(Curso *cursos, int cont_curso, int cont_disciplina){
    
    //A funcao vai exibir quantas disciplina existem no periodo informado pelo usuario

    int periodo, cont = 0;
    
    printf("Escolha o Periodo:");
    scanf("%d",&periodo); // faz a leitura de qual periodo

    for(int i = 0; i < cont_disciplina; i++){ // vai percorrer todas as disciplinas

        if(periodo == cursos[cont_curso].disciplinas_curso[i].periodo){ // caso alguma disciplina tenha seu periodo igual ao informado pelo usuario
        
            cont++; // vai contar a Quantidade de disciplinas igual ao periodo informado
        }
    }

    printf("Quantidade de Disciplinas no Periodo:%d\n\n",cont);
}

void main(){
    
    int i, opcao,aux_1 = 0, aux_2 = 0, *cont_disciplina, cont_curso = 0;
    
    cont_disciplina = (int*) malloc((1) * sizeof(int));
    cont_disciplina[0] = 0;

    Curso *Cursos;
    Cursos = (Curso*) malloc((1) * sizeof(Curso));
    
    //Aloca uma posicao de memoria que vai ficar pronta esperando o cadastro do primeiro curso

    Cursos->disciplinas_curso = (Disciplina*) malloc((1) * sizeof(Disciplina));
    
    //cria um vetor de ponteiro que vai apontar para uma struct disciplinas

    while(1){
        
        printf("1-Criar Curso\n");
        printf("2-Criar Disciplina\n");
        printf("3-Exibir cursos\n");
        printf("4-Curso com mais Periodos\n");
        printf("5-Quantidade de Disciplinas\n");
        printf("6-Quantidade de Disciplinas de um Periodo\n");
        printf("0-Sair\n");
        scanf("%d",&opcao);
        
        system("cls");
        
        if(opcao == 0){
            break;
        }
        
        switch(opcao){
            
            case 1:
            
                if(aux_1 == 0){
                    
                    criarCurso(Cursos,0);
                    aux_1++;
                }
                else{
                    
                    cont_curso++;
                    
                    Cursos = (Curso*) realloc(Cursos,(cont_curso + 1) * sizeof(Curso));
                    Cursos[cont_curso].disciplinas_curso = (Disciplina*) malloc(sizeof(Disciplina));
                    
                    cont_disciplina = (int*) realloc(cont_disciplina, (cont_curso + 1) * sizeof(int));
                    cont_disciplina[cont_curso] = 0;

                    criarCurso(Cursos,cont_curso);
                }
                
                break;

            case 2:

                i = verifCurso(Cursos, cont_curso);

                if(i != -1){
                    
                    if(aux_2 == 0){
                        
                        criarDisciplina(Cursos, i, 0);
                        cont_disciplina[0] = 1;
                        aux_2++;
                    }
                    else{
                        
                        cont_disciplina[i] += 1;
                        
                        Cursos[i].disciplinas_curso = (Disciplina*) realloc(Cursos[i].disciplinas_curso, ((cont_disciplina[i]) * sizeof(Disciplina)));
                        
                        criarDisciplina(Cursos, i, cont_disciplina[i] - 1);
                    }
                }
                else{

                    printf("Nao existe curso com o referente codigo!\n\n");
                    system("pause");
                    system("cls");
                }

                break;

            case 3:

                imprimeCursos(Cursos,cont_curso,cont_disciplina);
                break;

            case 4:
                
                maisPeriodo(Cursos,cont_curso);
                break;

            case 5:

                i = verifCurso(Cursos, cont_curso);
                quantDisciplina(Cursos, i, cont_disciplina[i]);
                break;

            case 6:

                i = verifCurso(Cursos, cont_curso);
                disciplinaPeriodo(Cursos, i, cont_disciplina[i]);
                break;
        }
    }

    free(cont_disciplina); // libera memoria do contador de disciplinas
    
    free(Cursos); // libera memoria dos cursos
}
