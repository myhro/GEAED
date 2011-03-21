#include <conio.h>
#include <stdlib.h>
#include <stdio.h>


// Criando a estrutura pessoa, correspondente ao conteudo da celula
typedef struct{
    int Idade;
    char Nome[50];
}pessoa;

// Criando o tipo Apontador, que é um ponteiro que aponta para o tipo celula
typedef struct celula *Apontador;

//Redefine celula e define a estrutura , criando o tipo Celula
typedef struct celula{
    pessoa Item;
    Apontador Prox;
    Apontador Ant;
}Celula;

//Cria a estrutura TipoLista, que terá dois apontadores para ter
// a referência do inicio e fim da lista
typedef struct{
    Apontador Primeiro;
    Apontador Ultimo;
}TipoLista;


//Função que inicializa a lista (deve ser utilizada no inicio do main)
void IniciarLista(TipoLista *Lista){
	//Aloca(cria) a celula cabeça
    Lista->Primeiro = (Apontador) malloc(sizeof(Celula));
    // O ponteiro Prox do Primeiro ainda nao aponta a lugar algum
    Lista->Primeiro->Prox = NULL;
    // O ponteiro Ant do Primeiro ainda nao aponta a lugar algum
    Lista->Primeiro->Ant = NULL;
    // Ultimo aponta para o mesmo lugar que o Primeiro
    Lista->Ultimo = Lista->Primeiro;
}

//Função que testa se a lista possui celulas além da cabeça
int TesteListaVazia(TipoLista Lista){
	//Caso a lista esteja "vazia" retorna 1, caso contrário, 0
	return(Lista.Primeiro == Lista.Ultimo);
}

//Função que insere uma celula à lista
//Como a lista será alterada é necessário um ponteiro
//O segundo parâmetro terá o conteúdo (Item) da nova célula
void Insere(TipoLista *Lista, pessoa X){
    //cria um ponteiro auxiliar para trocas
    Apontador aux;
    //aux apontará para a última posição da lista
    aux=Lista->Ultimo;

    //Aloca uma nova célula onde o Prox do Ultimo aponta
    Lista->Ultimo->Prox = (Apontador) malloc(sizeof(Celula));
    //O novo Ultimo será a nova célula alocada
    Lista->Ultimo = Lista->Ultimo->Prox;
    //O ponteiro Ant apontará para o antigo último
    Lista->Ultimo->Ant = aux;
    //O conteúdo da célula(Item) recebe X
    Lista->Ultimo->Item = X;
    //O ponteiro Prox do Ultimo apontará para NULL
    Lista->Ultimo->Prox= NULL;

}

//Função que imprime a lista do Primeiro ao Ultimo
void Imprime(TipoLista Lista){
    Apontador aux;
    // o "i" será utilizado para mostrar a posição da célula
    int i=1;
    // aux aponta para o próximo da lista cabeça
    aux = Lista.Primeiro->Prox;

    //loop que percorre a lista enquanto aux não apontar para NULL(fim da lista)
    while(aux !=NULL){
        printf("\n\n Celula %d \n Idade: %d\n Nome : %s ",i,aux->Item.Idade,aux->Item.Nome);
        i++;
        //aux apontará para a célula seguinte
        aux = aux->Prox;
    }
}

void Retira(TipoLista *Lista, char *nome){
    Apontador aux,tmp;
    int op,parar=0;

    tmp = Lista->Primeiro;
    aux = tmp->Prox;
    while(aux!=NULL){
        if(strcmpi(aux->Item.Nome,nome) == 0){
            printf("\n Nome: %s \n Idade: %d\n Deseja retirar? \n [1] Sim \t [2] Nao",nome,aux->Item.Idade);
            while(1){
                if( scanf("%d",&op) == 0 ){
                    printf("\n Digite novamente: ");
                    continue;
                }
                if(op == 1){


                    parar=1;
                }
                else if(op == 2){

                    break;
                }
                else{
                    printf("\n Digite novamente");
                }
            }
            if(parar==1) break;
        }
    }
}

int main() {
	return(0);
}
