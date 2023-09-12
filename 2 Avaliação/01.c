#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int codigo;

struct disciplina {
    
    int codigo_disciplina; 
    int codigo_curso;
    int periodo;
    int carga_horaria_disciplina;
    char nome[50];
};
typedef struct disciplina Disciplina;

struct curso {
    
    int codigo;
    int quant_periodo;
    int carga_horaria;
    char turno[10];
    char nome[50];
    Disciplina **disciplinas_curso;
};
typedef struct curso Curso;

void inicializar_cursos(Curso** cursos, int MAX){
    
    for(int i = 0; i < MAX; i++){
        cursos[i] = NULL;
    }
}


void inicializar_disciplinas(Disciplina** disciplinas, int MAX){
    
    for(int i = 0; i < MAX; i++){
        disciplinas[i] = NULL;
    }
}


int criarCurso(Curso** cursos, int cont_curso, int *MAX_disciplinas){

    int turma, retorno, MAX;

    if(cursos[cont_curso] != NULL){
        return 0;
    }

    if(cursos[cont_curso] == NULL){
        cursos[cont_curso] = malloc(sizeof(Curso));
    }

    printf("Nome do Curso:");
    scanf(" %[^\n]s",cursos[cont_curso]->nome);

    retorno = verificar_curso(cursos, cont_curso);

    if(retorno == -1){

        cursos[cont_curso]->codigo = codigo;

        printf("Informe a Quantidade de Disciplinas:");
        scanf("%d",&MAX);

        *MAX_disciplinas = MAX;

        printf("Quantidade de Periodos:");
        scanf("%d",&cursos[cont_curso]->quant_periodo);

        printf("Carga Horaria(Hrs):");
        scanf("%d",&cursos[cont_curso]->carga_horaria);

        printf("\nTurno\n1-Manha\n2-Tarde\n3-Noite\nOpcao:");

        while(1){

            scanf("%d",&turma);
            
            if(turma == 1){
                strcpy(cursos[cont_curso]->turno,"Manha");
                break;
            }
            else if(turma == 2){
                strcpy(cursos[cont_curso]->turno,"Tarde");
                break;
            }
            else if(turma == 3){
                strcpy(cursos[cont_curso]->turno,"Noite");
                break;
            }
            else{
                system("cls");
                printf("Turno Invalido!\n");
                printf("1-Manha\n2-Tarde\n3-Noite\nOpcao:");
            }
        }
        system("cls");
        return 1;
    }
    else{

        printf("Codigo ja associado a outro Curso!\n\n");
        system("pause");
        system("cls");
        return 0;
    }
}


int criarDisciplina(Curso** cursos, int cont_curso, int cont_disciplina){
    
    int retorno;

    if(cursos[cont_curso]->disciplinas_curso[cont_disciplina] != NULL){
        return 0;
    }

    if(cursos[cont_curso]->disciplinas_curso[cont_disciplina] == NULL){
        cursos[cont_curso]->disciplinas_curso = malloc(sizeof(Disciplina));
    }

    printf("Nome da Disciplina:");
    scanf(" %[^\n]s",cursos[cont_curso]->disciplinas_curso[cont_disciplina]->nome);

    retorno = verificar_disciplina(cursos, cont_curso, cont_disciplina);

    if(retorno == -1){

        cursos[cont_curso]->disciplinas_curso[cont_disciplina]->codigo_disciplina = codigo;

        printf("Periodo:");

        while(1){

            scanf("%d",&cursos[cont_curso]->disciplinas_curso[cont_disciplina]->periodo);

            if(cursos[cont_curso]->disciplinas_curso[cont_disciplina]->periodo > cursos[cont_curso]->quant_periodo){
                printf("Periodo invalido!\nDigite novamente:");
            }
            else{
                break;
            }
        }
        printf("Carga Horaria(Hrs):");
        scanf("%d",&cursos[cont_curso]->disciplinas_curso[cont_disciplina]->carga_horaria_disciplina);

        system("cls");
        return 1;
    }
    else{

        printf("Codigo ja associado a outra disciplina!\n");
        system("pause");
        system("cls");
        return 0;
    }
}


int verificar_curso(Curso** cursos, int cont_curso){

    printf("Informe o codigo referente ao Curso:");
    scanf("%d",&codigo);

    for(int i = 0; i <= cont_curso; i++){

        if(cursos[i]->codigo == codigo){
            return i;
        }
    }
    return -1;
}

int verificar_disciplina(Curso** cursos, int cont_curso, int cont_disciplina){

    printf("Informe o codigo referente a Disciplina:");
    scanf("%d",&codigo);

    for(int i = 0; i <= cont_disciplina; i++){

        if(cursos[cont_curso]->disciplinas_curso[i]->codigo_disciplina == codigo){
            return i;
        }
    }
    return -1;
}

void imprimeCurso(Curso** cursos, int cont_curso, int cont_disciplina){

    printf("Curso Abaixo\n\n");

    printf("Nome do Curso:%s\n",cursos[cont_curso]->nome);
    printf("Codigo do Curso:%d\n",cursos[cont_curso]->codigo);        
    printf("Periodos:%d\n",cursos[cont_curso]->quant_periodo);
    printf("carga Horaria:%d00hrs\n",cursos[cont_curso]->carga_horaria);
    printf("Turno:%s\n\n",cursos[cont_curso]->turno);

    if(cont_disciplina != 0){

        for(int j = 0; j < cont_disciplina; j++){

            printf("[%s] - ",cursos[cont_curso]->disciplinas_curso[j]->nome);
            printf("Periodo:%d - ",cursos[cont_curso]->disciplinas_curso[j]->periodo);
            printf("Carga Horario:%dhs - ",cursos[cont_curso]->disciplinas_curso[j]->carga_horaria_disciplina);
            printf("Codigo:%d\n",cursos[cont_curso]->disciplinas_curso[j]->codigo_disciplina);
        }
        printf("\n");
    }

    else{
        printf("Nao existe disciplinas cadastradas!\n\n");
    }

    system("pause");
    system("cls");
}

void imprimeDisciplina(Curso** cursos, int cont_curso, int cont_disciplina){

    printf("Disciplina Abaixo\n\n");
    printf("Curso:%s - ",cursos[cont_curso]->nome);
    printf("[%s] - ",cursos[cont_curso]->disciplinas_curso[cont_disciplina]->nome);
    printf("Periodo:%d - ",cursos[cont_curso]->disciplinas_curso[cont_disciplina]->periodo);
    printf("Carga Horario:%dhs - ",cursos[cont_curso]->disciplinas_curso[cont_disciplina]->carga_horaria_disciplina);
    printf("Codigo:%d\n",cursos[cont_curso]->disciplinas_curso[cont_disciplina]->codigo_disciplina);

    system("pause");
    system("cls");
}

void ordenarCursos(Curso** cursos, int cont_curso, int *cont_disciplina){

    int i, j;

    for(i = 0; i < cont_curso; i++){

        for(j = 0; j < cont_curso; j++){

            if(cursos[i]->codigo < cursos[j]->codigo){

                int aux_codigo = cursos[i]->codigo;
                cursos[i]->codigo = cursos[j]->codigo;
                cursos[j]->codigo = aux_codigo;

                int aux_periodo = cursos[i]->quant_periodo;
                cursos[i]->quant_periodo = cursos[j]->quant_periodo;
                cursos[j]->quant_periodo = aux_periodo;

                int aux_carga_horaria = cursos[i]->carga_horaria;
                cursos[i]->carga_horaria = cursos[j]->carga_horaria;
                cursos[j]->carga_horaria = aux_carga_horaria;

                char aux_turno[10];
                char aux_nome[20];

                strcpy(aux_turno,cursos[i]->turno);
                strcpy(cursos[i]->turno,cursos[j]->turno);
                strcpy(cursos[j]->turno,aux_turno);

                strcpy(aux_nome,cursos[i]->nome);
                strcpy(cursos[i]->nome,cursos[j]->nome);
                strcpy(cursos[j]->nome,aux_nome);

                int aux_cont_disciplina = cont_disciplina[i];
                cont_disciplina[i] = cont_disciplina[j];
                cont_disciplina[j] = aux_cont_disciplina;
            }
        }
    }

    for(i = 0; i < cont_curso; i++){

        for(j = 0; j < cont_disciplina[i]; j++){

            for(int k = 0; k < cont_disciplina[i]; k++){

                if(cursos[i]->disciplinas_curso[j]->codigo_disciplina < cursos[i]->disciplinas_curso[k]->codigo_disciplina){

                    int aux_codigo_disciplina = cursos[i]->disciplinas_curso[j]->codigo_disciplina;
                    cursos[i]->disciplinas_curso[j]->codigo_disciplina = cursos[i]->disciplinas_curso[k]->codigo_disciplina;
                    cursos[i]->disciplinas_curso[k]->codigo_disciplina = aux_codigo_disciplina;

                    int aux_periodo = cursos[i]->disciplinas_curso[j]->periodo;
                    cursos[i]->disciplinas_curso[j]->periodo = cursos[i]->disciplinas_curso[k]->periodo;
                    cursos[i]->disciplinas_curso[k]->periodo = aux_periodo;

                    int aux_carga_horaria_disciplina = cursos[i]->disciplinas_curso[j]->carga_horaria_disciplina;
                    cursos[i]->disciplinas_curso[j]->carga_horaria_disciplina = cursos[i]->disciplinas_curso[k]->carga_horaria_disciplina;
                    cursos[i]->disciplinas_curso[k]->carga_horaria_disciplina = aux_carga_horaria_disciplina;

                    char aux_nome[50];

                    strcpy(aux_nome,cursos[i]->disciplinas_curso[j]->nome);
                    strcpy(cursos[i]->disciplinas_curso[j]->nome,cursos[i]->disciplinas_curso[k]->nome);
                    strcpy(cursos[i]->disciplinas_curso[k]->nome,aux_nome);
                }
            }
        }
    }
}

/*void cursosTurno(Curso** cursos,int cont_curso){

    int turno, iguais, aux = 0;

    printf("Informe o Turno\n1-Manha\n2-Tarde\n3-Noite\nOpcao:");
    scanf("%d",&turno);
    system("cls");

    for(int i = 0; i < cont_curso; i++){

        if(turno == 1){

            iguais = strcmp(cursos[i]->turno,"Manha");

            if(iguais == 0){

                printf("Curso:%s\n",cursos[i]->nome);
                aux++;
            }
        }
        else if(turno == 2){

            iguais = strcmp(cursos[i]->turno,"Tarde");

            if(iguais == 0){

                printf("Curso:%s\n",cursos[i]->nome);
                aux++;
            }
        }
        else if(turno == 3){

            iguais = strcmp(cursos[i]->turno,"Noite");

            if(iguais == 0){

                printf("Curso:%s\n",cursos[i]->nome);
                aux++;
            }
        }
        else{

            printf("Turno Invalido!\n\n");
            aux++;
        }
    }

    if(aux == 0){
        printf("Nao existe curso com o referente turno!\n\n");
    }

    system("pause");
    system("cls");
}*/

void main(){

    int MAX_curso, MAX_disciplina = 0, retorno_curso, retorno_disciplina;
    int cont_curso = 0;

    printf("Informe a Quantidade Maxima de Cursos:");
    scanf("%d", &MAX_curso);

    int cont_disciplina[MAX_curso];

    Curso **Cursos;
    Cursos = malloc((MAX_curso) * sizeof(Curso*));
    inicializar_cursos(Cursos, MAX_curso);

    system("cls");

    while(1){

        int opcao;

        printf("1-Criar Curso\n");
        printf("2-Criar Disciplina\n");
        printf("3-Exibir Curso\n");
        printf("4-Exibir Disciplina\n");
        printf("5-Cursos(Turno)\n");
        printf("6-Exibir Disciplina de um Curso\n");
        printf("7-Disciplinas de um Periodo\n");
        printf("9-remover Curso\n");
        printf("0-Sair\n");
        scanf("%d",&opcao);

        system("cls");
        
        if(opcao == 0){
            break;
        }

        switch(opcao){

            case 1:

                retorno_curso = criarCurso(Cursos, cont_curso, &MAX_disciplina);

                if(retorno_curso == 1){

                    Cursos[cont_curso]->disciplinas_curso = malloc((MAX_disciplina) * sizeof(Disciplina*));
                    inicializar_disciplinas(Cursos[cont_curso]->disciplinas_curso, MAX_disciplina);

                    cont_disciplina[cont_curso] = 0;
                    cont_curso++;

                    ordenarCursos(Cursos, cont_curso, cont_disciplina);
                }
                break;

            case 2:

                retorno_curso = verificar_curso(Cursos, cont_curso);

                if(retorno_curso != -1){

                    retorno_disciplina = criarDisciplina(Cursos, retorno_curso, cont_disciplina[retorno_curso]);

                    if(retorno_disciplina == 1){

                        cont_disciplina[retorno_curso] += 1;
                        ordenarCursos(Cursos, cont_curso, cont_disciplina);
                    }
                }

                else{
                    printf("Curso nao existe!\n\n");
                    system("pause");
                    system("cls");
                }
                break;

            case 3:

                retorno_curso = verificar_curso(Cursos, cont_curso);

                if(retorno_curso != -1){

                    imprimeCurso(Cursos, retorno_curso, cont_disciplina[retorno_curso]);
                    break;
                }

            case 4:

                retorno_curso = verificar_curso(Cursos, cont_curso);

                if(retorno_curso != -1){

                    retorno_disciplina = verificar_disciplina(Cursos, retorno_curso, cont_disciplina[retorno_curso]);

                    if(retorno_disciplina != -1){

                        imprimeDisciplina(Cursos, retorno_curso, retorno_disciplina);
                        break;
                    }
                }
        }
    }    
}