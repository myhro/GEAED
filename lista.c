#include <conio.h>
#include <stdlib.h>
#include <stdio.h>


// Criando a estrutura pessoa, correspondente ao conteudo da celula
typedef struct{
    int Idade;
    char Nome[50];
}pessoa;

// Criando o tipo Apontador, que � um ponteiro que aponta para o tipo celula
typedef struct celula *Apontador;

//Redefine celula e define a estrutura , criando o tipo Celula
typedef struct celula{
    pessoa Item;
    Apontador Prox;
    Apontador Ant;
}Celula;

//Cria a estrutura TipoLista, que ter� dois apontadores para ter
// a refer�ncia do inicio e fim da lista
typedef struct{
    Apontador Primeiro;
    Apontador Ultimo;
}TipoLista;


//Fun��o que inicializa a lista (deve ser utilizada no inicio do main)
void IniciarLista(TipoLista *Lista){
	//Aloca(cria) a celula cabe�a
    Lista->Primeiro = (Apontador) malloc(sizeof(Celula));
    // O ponteiro Prox do Primeiro ainda nao aponta a lugar algum
    Lista->Primeiro->Prox = NULL;
    // O ponteiro Ant do Primeiro ainda nao aponta a lugar algum
    Lista->Primeiro->Ant = NULL;
    // Ultimo aponta para o mesmo lugar que o Primeiro
    Lista->Ultimo = Lista->Primeiro;
}

//Fun��o que testa se a lista possui celulas al�m da cabe�a
int TesteListaVazia(TipoLista Lista){
	//Caso a lista esteja "vazia" retorna 1, caso contr�rio, 0
	return(Lista.Primeiro == Lista.Ultimo);
}

//Fun��o que insere uma celula � lista
//Como a lista ser� alterada � necess�rio um ponteiro
//O segundo par�metro ter� o conte�do (Item) da nova c�lula
void Insere(TipoLista *Lista, pessoa X){
    //cria um ponteiro auxiliar para trocas
    Apontador aux;
    //aux apontar� para a �ltima posi��o da lista
    aux=Lista->Ultimo;

    //Aloca uma nova c�lula onde o Prox do Ultimo aponta
    Lista->Ultimo->Prox = (Apontador) malloc(sizeof(Celula));
    //O novo Ultimo ser� a nova c�lula alocada
    Lista->Ultimo = Lista->Ultimo->Prox;
    //O ponteiro Ant apontar� para o antigo �ltimo
    Lista->Ultimo->Ant = aux;
    //O conte�do da c�lula(Item) recebe X
    Lista->Ultimo->Item = X;
    //O ponteiro Prox do Ultimo apontar� para NULL
    Lista->Ultimo->Prox= NULL;

}

//Fun��o que imprime a lista do Primeiro ao Ultimo
void Imprime(TipoLista Lista){
    Apontador aux;
    // o "i" ser� utilizado para mostrar a posi��o da c�lula
    int i=1;
    // aux aponta para o pr�ximo da lista cabe�a
    aux = Lista.Primeiro->Prox;

    //loop que percorre a lista enquanto aux n�o apontar para NULL(fim da lista)
    while(aux !=NULL){
        printf("\n\n Celula %d \n Idade: %d\n Nome : %s ",i,aux->Item.Idade,aux->Item.Nome);
        i++;
        //aux apontar� para a c�lula seguinte
        aux = aux->Prox;
    }
}

void Retira(TipoLista *Lista, char *nome){
    Apontador aux,tmp;
    int op,parar=0;

    tmp = Lista->Primeiro;
    aux = tmp->prox;
    while(aux!=NULL){
        if(strcmpi(aux->Item.nome,nome) == 0){
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
