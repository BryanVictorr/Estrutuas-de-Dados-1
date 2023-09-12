#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct livro {
    
    int codigo;
    int ano;
    int quantidade;
    char titulo[50];
    char autor[50];
    char editora[50];
    
};
typedef struct livro Livro;

void inicializar(Livro** livros,int MAX){
    
    for(int i = 0; i < MAX; i++){
        livros[i] = NULL; // vai colocar NULL em cada posição do vetor
    }
}

void adicionarLivro(Livro** livros, int n){

    system("cls");

    if(livros[n] == NULL){
        livros[n] = malloc(sizeof(Livro)); // caso o indice seja NULL ou seja nao preenchido, vai ser alocada memoria para receber os dados
    }
    
    // Leitura dos dados para o livro
    
    printf("Titulo:");
    scanf(" %[^\n]s", livros[n]->titulo);

    printf("Autor:");
    scanf(" %[^\n]s", livros[n]->autor);

    printf("Editora:");
    scanf(" %[^\n]s", livros[n]->editora);

    printf("Ano:");
    scanf("%d", &livros[n]->ano);

    printf("Quantidade:");
    scanf("%d", &livros[n]->quantidade);

    printf("Codigo:");
    scanf("%d", &livros[n]->codigo);

    system("cls");
}

void imprimeLivro(Livro** livros, int n){

    system("cls");

    int aux = 0;

    // Vai imprimir todos o livros caso o indice não tenha NULL
    
    for(int i = 0; i < n; i++){ // N vai ser a quantidade de Livros

        if(livros[n] != NULL){
            
            printf("Titulo:%s\n", livros[i]->titulo);
            printf("Autor:%s\n", livros[i]->autor);
            printf("Editora:%s\n", livros[i]->editora);
            printf("Ano:%d\n", livros[i]->ano);
            printf("Quantidade:%d\n", livros[i]->quantidade);
            printf("codigo:%d\n\n", livros[i]->codigo);
            aux = 1; // aux recebe 1 caso pelo menos 1 livro seja impresso
        }
    }

    if(aux == 0){ // caso nenhum livro seja impresso
        printf("Nao existe Livros cadastrados!\n\n");
    }

    system("pause");
    system("cls");
}

void buscarAutor(Livro** livros, int n){

    char busca[50];
    int verificar, aux = 0;

    system("cls");
    printf("Informe o Autor(Igual ao Registro):");
    scanf(" %[^\n]s", busca); // leitura da variavel de buscar que recebe o nome do autor
    system("cls");

    for(int i = 0; i < n; i++){

        verificar = strcmp(livros[i]->autor, busca); // caso algum autor seja igual ao de busca o retorno sera 0
        
        if(verificar == 0){ // se retorno de verificar seja 0 será impresso os dados

            printf("Titulo:%s\n", livros[i]->titulo);
            printf("Autor:%s\n", livros[i]->autor);
            printf("Editora:%s\n", livros[i]->editora);
            printf("Ano:%d\n", livros[i]->ano);
            printf("Quantidade:%d\n", livros[i]->quantidade);
            printf("codigo:%d\n\n", livros[i]->codigo);
            aux = 1;
        }
    }
    
    if(aux == 0){
        printf("Nao existe Livros com esse Autor!\n\n");
    }
    system("pause");
    system("cls");
}

void buscarEditora(Livro** livros, int n){

    char busca[50];
    int verificar, aux = 0;

    system("cls");
    printf("Informe a Editora(Igual ao Registro):");
    scanf(" %[^\n]s", busca); // Leitura da variavel de busca o nome da editora
    system("cls");

    for(int i = 0; i < n; i++){

        verificar = strcmp(livros[i]->editora, busca); // caso alguma editora tenha o nome igual ao de busca o retorno sera 0
        
        if(verificar == 0){ // caso o retorno de verificar seja 0 será impresso os dados

            printf("Titulo:%s\n", livros[i]->titulo);
            printf("Autor:%s\n", livros[i]->autor);
            printf("Editora:%s\n", livros[i]->editora);
            printf("Ano:%d\n", livros[i]->ano);
            printf("Quantidade:%d\n", livros[i]->quantidade);
            printf("codigo:%d\n\n", livros[i]->codigo);
            aux = 1; // caso alguma editora seja impressa qux recebe 1
        }
    }

    if(aux == 0){ // caso nenhuma editora seja impressa
        printf("Nao existe Livros com essa Editora!\n\n");
    }
    system("pause");
    system("cls");
}

int removerLivro(Livro** livros, int n){

    int busca;

    system("cls");
    printf("Informe o Codigo do Livro:");
    scanf("%d", &busca); // sera informado o codigo de busca para ser removido

    for(int i = 0; i < n; i++){

        if(livros[i]->codigo == busca){ // caso o codigo seja igual ao de algum livro

            printf("O Livro %s foi removido!\n\n", livros[i]->titulo);

            free(livros[i]); // será liberada a memória alocado para o livro
            livros[i] = NULL; // o indice do livro recebe NULL para informar que está vazio

            system("pause");
            system("cls");

            return 1;
        }
    }
    return 0;
}

void main(){
    
    int MAX,cont = 0;
    
    printf("Informe a Quantidade Maxima do Conjunto:");
    scanf("%d",&MAX); // Leitura da quantidade de livros
    system("cls");
    
    Livro **Livros;
    Livros = malloc((MAX) * sizeof(Livro*)); // alocado memoria para o vetor de livros

    inicializar(Livros, MAX); // inicializa todas as posicoes alocadas
    
    while(1){
        
        int opcao, verificar;
        
        printf("1-Adicionar Livro\n");
        printf("2-Exibir Livros\n");
        printf("3-Buscar por Autor\n");
        printf("4-Buscar por Editora\n");
        printf("5-Remover Livro\n");
        printf("0-sair\n");
        printf("Opcao:");
        scanf("%d",&opcao);

        if(opcao == 0){
            break;
        }
        
        switch(opcao){
            
            case 1:

                if(cont < MAX){

                    adicionarLivro(Livros, cont);
                    cont++;
                }
                else{

                    printf("Conjunto no Limite!\n\n");
                    system("pause");
                    system("cls");
                }
                break;
                
            case 2:

                imprimeLivro(Livros, cont);
                break;

            case 3:

                buscarAutor(Livros, cont);
                break;

            case 4:

                buscarEditora(Livros, cont);
                break;

            case 5:

                verificar = removerLivro(Livros, cont);

                if(verificar == 1){
                    cont--;
                }
                else{

                    printf("Livro nao encontrado!\n\n");
                    system("pause");
                    system("cls");
                }
                break;
        }
    }
}