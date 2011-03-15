#include <conio.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct{
    int Idade;
    char Nome[50];
}pessoa;

typedef struct celula *Apontador;

typedef struct celula{
    pessoa Item;
    Apontador Prox;
    Apontador Ant;
}Celula;


typedef struct{
    Apontador Primeiro;
    Apontador Ultimo;
}TipoLista;

void IniciarLista(TipoLista *Lista){
    Lista->Primeiro = (Apontador) malloc(sizeof(Celula));
    Lista->Primeiro->Prox = NULL;
    Lista->Primeiro->Ant = NULL;
    Lista->Ultimo = Lista->Primeiro;
}

int TesteListaVazia(TipoLista Lista){
   return(Lista.Primeiro == Lista.Ultimo);
}

void Insere(TipoLista *Lista,pessoa X){
    Apontador aux;

    aux=Lista->Ultimo;

    Lista->Ultimo->Prox = (Apontador) malloc(sizeof(Celula));
    Lista->Ultimo = Lista->Ultimo->Prox;
    Lista->Ultimo->Ant = aux;
    Lista->Ultimo->Item = X;
    Lista->Ultimo->Prox= NULL;

}

void Imprime(TipoLista Lista){
    Apontador aux;
    int i=1;

    aux = Lista.Primeiro->Prox;
    while(aux !=NULL){
        printf("\n\n Celula %d \n Idade: %d\n Nome : %s ",i,aux->Item.Idade,aux->Item.Nome);
        i++;
        aux = aux->Prox;
    }
}

int main() {
	return(0);
}
