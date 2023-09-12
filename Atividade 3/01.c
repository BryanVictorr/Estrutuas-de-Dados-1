#include <stdio.h>
#include <stdlib.h>

struct jogador {
    
    int idade, camisa;
    float altura;
    char nome[20],posicao[20];
    
};

typedef struct jogador Jogador;

void preencher(Jogador* J,int quantidade){
    
    // Função cadastrar os jogadores
    
    int i;
    
    for(i = 0; i < quantidade; i++){
        
        printf("Jogador %d\n\n",i + 1);
        
        printf("Nome:");
        scanf(" %[^\n]s",J[i].nome);
        
        printf("Idade:");
        scanf("%d",&J[i].idade);
        
        printf("Altura:");
        scanf("%f",&J[i].altura);
        
        printf("Numero da Camisa:");
        scanf("%d",&J[i].camisa);
        
        printf("Posicao:");
        scanf(" %[^\n]s",J[i].posicao);
        
        system("cls");
    }
}

void maisAlto(Jogador* J,float *Maior,int quantidade){
    
    //Função Responsável por devolver por referência a altura do jogador mais alto
    
    int i;
    
    for(i = 0; i < quantidade; i++){ // i vai de 0 até a quantidade de jogadores
        
        if(J[i].altura > *Maior){ // caso a idade do jogador i seja maior que a última maior altura alocada
        
            *Maior = J[i].altura; // Maior vai receber a altura do jogador i
        }
    }
}

int menorIdade(Jogador* J,int quantidade){
    
    int i,cont = 0;
    float menor;
    
    menor = J[0].altura; // A variável que vai guardar a menor altura vai receber a altura do primeiro jogador
    
    for(i = 1; i < quantidade; i++){ // i vai de 1 ate a quantidade de jogadores
        
        if(J[i].altura < menor){ // caso a altura do jogador  seja menor que a do último jogador
            
            menor = J[i].altura; // menor vai receber a altura do jogador atual
            
            cont = i; // cont vai receber o indice do último jogador que teve a menor altura
        }
    }
    
    return J[cont].idade; // retorno para o main a idade do jogar na posicao cont que é a posicao do menor jogador
}

float mediaAltura(Jogador* J,int quantidade){
    
    int i;
    float media = 0.0;
    
    for(i = 0; i < quantidade; i++){ // i vai de 0 ate a quantidade de jogadores
    
        media += J[i].altura; // media vai somar a altura de todos os jogadores
    }
    
    media = media/quantidade; // media vai receber ela mesmo dividido pela quantidade de jogadores assim obtendo uma media das Alturas
    
    return media; // retorno para o main essa media
}

float *medianaAltura(Jogador* J,int quantidade){
    
	float *VetAux = (float*) malloc((quantidade) *sizeof(float)); // alocando memória para receber as alturas dos jogadores para ordenar
	
	float *jogadores = (float*) malloc((quantidade) * sizeof(float)); // alocando memoria para adicionar os jogadores que tem sua idade igual a mediana

	int i, j, cont = 0;
	float aux, mediana;
	
	for(i = 0; i < quantidade; i++){ // i vai percorrer todos os jogadores 
	
	    VetAux[i] = J[i].altura; // vetor auxiliar vai receber a altura de todos os jogadores
	}
	
	for (i = 0; i < quantidade; i++){ // i vai ser executado a quantidade existente de jogadores
	    
	    for (j = i + 1; j < quantidade; j++){ // j vai ser sempre um jogador a frente de i
	        
	        if (VetAux[i] > VetAux[j]){ // caso o jogador i tenha sua altura maior que o jogador a sua frente será trocado as suas posicoes 
	         
	            aux = VetAux[i];
	            VetAux[i] = VetAux[j];
	            VetAux[j] = aux;
	        }
	    }
	}

    if(quantidade % 2 != 0){ // caso a quantidade de jogadores seja impar

        for(i = 0; i < quantidade; i++){ // i vai percorrer todos os jogadores;

            if(J[i].altura == VetAux[quantidade / 2]){ // cado algum jogador tenha sua altura igual a altura mediana

                jogadores[cont] = i; // o vetor jogadores vai armazenar os indices dos jogadores com altura mediana;
                
                cont++; // cont vai encremetar 1 para adicionar espaço para caso tenha outro jogador
            }
        }

        jogadores[cont] = -1; // vetor jogadores na última posição vai receber -1 para marcar o fim do vetor

    }else{

        mediana = VetAux[quantidade / 2 - 1] + VetAux[quantidade / 2]; // caso a quantidade de jogadores nao seja impar, mediana vai ser a soma das duas alturas centrais
        
        for(i = 0; i < quantidade; i++){ // i vai percorrer todos os jogadores
            
            if(J[i].altura == mediana){ // caso algum jogador tenha sua altura igual a mediana
            
                jogadores[cont] = i; // vetor jogadores vai receber o indice do jogador com altura mediana
                
                cont++; // cont vai encremetar 1 para adicionar espaço caso tenha outro jogador
            }
        }
        jogadores[cont] = -1; // vetor jogadores na ultima Posicao vai receber -1 para marcar o fim do vetor
    }
    
    free(VetAux); // libero a menoria do VeTAux que guardava as alturas ordenadas
    
    return jogadores; // retorno o vetor com os indice dos jogadores com idade mediana
}

void imprime_jogadores(Jogador* J,int quantidade){
    
    // Funçãovai imprimir todos os jogadores
    
    printf("Jogadores Cadastrados\n\n");
    
    for(int i = 0; i < quantidade; i++){
        
        printf("Nome:%s\n",J[i].nome);
        printf("Idade:%d\n",J[i].idade);
        printf("Altura:%.2f\n",J[i].altura);
        printf("Camisa:%d\n",J[i].camisa);
        printf("Posicao:%s\n\n",J[i].posicao);
    }
}

void main(){
    
    int quant_jogador, menor_idade, cont;
    float mais_alto = 0.0,media_altura, *nome_jogadores;
    
    printf("Informe a quantidade de Jogadores:");
    scanf("%d",&quant_jogador); // Faço a leitura da quantidade de Jogador que vão ser cadastradas 

    system("cls");
    
    Jogador *J;
    
    J = (Jogador*) malloc((quant_jogador) * sizeof(Jogador));
    nome_jogadores = (float*) malloc((quant_jogador) * sizeof(float));
    
    // Aloco memoria para a quantidade de jogadores e para receber as alturas dos jogadores com altura mediana
    
    preencher(J,quant_jogador);
    maisAlto(J,&mais_alto,quant_jogador);
    menor_idade = menorIdade(J,quant_jogador);
    media_altura = mediaAltura(J,quant_jogador);
    nome_jogadores = medianaAltura(J,quant_jogador);
    imprime_jogadores(J,quant_jogador);
    
    printf("Jogador Mais Alto tem:%.2f\n",mais_alto);
    printf("Idade do Jogador Mais Baixo:%d\n",menor_idade);
    printf("Media das Alturas:%.2f\n",media_altura);
    
    if(nome_jogadores[0] == -1){ // se o vetor na posição 0 for =-1 não existe jogador com altura mediana
    
        printf("Nao ha jogadores com a Altura mediana!");
        
    }
    else{
        
        for(int i = 0; nome_jogadores[i] != -1; i++){ // i vai percorrer os indice dos jogadores com altura mediana ate encontrar-1 que indica o fim desse vetor
            
            cont = nome_jogadores[i]; // cont vai receber essa altura
            
            printf("Jogador com Altura mediana:%s\n",J[cont].nome); // vai exibir na posição do indice do jogador com altura mediana o seu nome
        }
    }
    
    free(J); // libera a memória que alocou os jogadors
    free(nome_jogadores); // libera o vetor que guardava os índices dos jogadores com altura mediana
}
