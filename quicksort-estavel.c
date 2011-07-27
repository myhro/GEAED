/*
 Universidade Estadual de Montes Claros - Unimontes
 GEAED - Grupo de Estudos em Algoritmos e Estrutura de Dados
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 10

// Protótipos de Funções
int *Qsort(int *v, int n);
void Concatena(int *v, int n, int *menor,int Nme, int pivo, int *maior,int Nma);
void Imprime(int *v,int n);

int passo=0;

int main(){
    int vet[TAM];
    int i;


    srand(time(NULL));
    for(i=0; i<TAM; i++){
        printf("\n Elemento %d: ",i+1);
        //scanf("%d",&vet[i]);
        vet[i] = rand()%TAM;
        printf("%d",vet[i]);
    }

    printf("\n\n Vetor : ");
    Imprime(vet,TAM);

    printf("\n\n PASSOS \n ");
    Qsort(vet,TAM);

    printf("\n\n Ordenado : ");
    Imprime(vet,TAM);
    printf("\n\n");

    return 0;
}

int *Qsort(int *v, int n){
    int maior[n],menor[n],i,pivo, Me , Ma;

    if(n == 0){
        return NULL;
    }
    if (n == 1)
        return v;

    pivo = v[n-1];

    for(i=0, Ma=0, Me=0; i< n-1 ; i++){

        if( v[i] <= pivo){
            menor[Me]=v[i];
            Me++;
        }
        if( v[i] > pivo){
            maior[Ma]=v[i];
            Ma++;
        }

    }

    printf("\n Passo %d  :  ",passo);
    Imprime(menor,Me);
    Imprime(maior,Ma);
    passo++;
    Concatena (v,n,Qsort(menor,Me),Me,pivo,Qsort(maior,Ma),Ma);
    return v;
}

void Concatena(int *v, int n, int *menor,int Nme, int pivo, int *maior,int Nma){
    int i,j;

    for(i=0; i<Nme && menor != NULL; i++)
        v[i]=menor[i];
    v[i]=pivo;
    i++;
    for(j=0; j<Nma && maior != NULL; j++,i++)
        v[i]=maior[j];

}

void Imprime(int *v,int n){
    int i;
    printf("[");
    if(v == NULL){
        printf("]");
        return;
    }
    for(i=0; i<n; i++){
        if(i != n-1)
            printf("%d, ",v[i]);
        else
            printf("%d",v[i]);
    }
    printf("]  ");

}
