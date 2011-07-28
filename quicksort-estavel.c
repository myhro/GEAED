/*
 Universidade Estadual de Montes Claros - Unimontes
 GEAED - Grupo de Estudos em Algoritmos e Estrutura de Dados

 Descrição: Quicksort estável que, a partir do elemento central, subdivide
            o vetor inicial em dois subvetores onde os elementos de menor
            valor que o pivo sao colocados num vetor e os de maior valor
            em outro, evitando instabilidades no algoritmo, concatenando ao
            final dos processoss ambos os vetores, resultando na ordenação
            do vetor principal.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 10

// Protótipos das Funções do Quicksort
int *Qsort(int *v, int n);
void Concatena(int *v, int n, int *menor,int Nme, int pivo, int *maior,int Nma);
void Imprime(int *v,int n);


int main(){
    int vet[TAM];
    int i;

    printf("\n\t Quicksort Estavel \n\n");

    // Geração de elementos aleatorios para preencher o vetor
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

// Corpo das funções
int *Qsort(int *v, int n){
    int maior[n],menor[n],i,pivo, Me , Ma;
    int passo=0;

    // Se n==0, o vetor está vazio
    if(n == 0){
        return NULL;
    }
    // Se n==1, o vetor possui apenas um elemento
    if (n == 1)
        return v;

    // calculo do pivo
    pivo = v[n-1];

    for(i=0, Ma=0, Me=0; i< n-1 ; i++){
        // se o elemento comparado for menor ou igual ao pivo
        // ele é copiado para o vetor dos elementos menores 'menor[]'
        if( v[i] <= pivo){
            menor[Me]=v[i];
            Me++;
        }
        // se o elemento comparado for maior que o pivo
        // ele é copiado para o vetor dos elementos maiores 'maior[]'
        if( v[i] > pivo){
            maior[Ma]=v[i];
            Ma++;
        }
    }

    // Mostra os passos realizados pelo algoritmo ao separar os elementos
    // nos dois vetores 'maior[]' e 'menor[]'
    printf("\n Passo %d  :  ",passo);
    Imprime(menor,Me);
    Imprime(maior,Ma);
    passo++;
    Concatena (v,n,Qsort(menor,Me),Me,pivo,Qsort(maior,Ma),Ma);
    return v;
}

// Função responsável pela concatenação dos vetores
void Concatena(int *v, int n, int *menor,int Nme, int pivo, int *maior,int Nma){
    int i,j;

    for(i=0; i<Nme && menor != NULL; i++)
        v[i]=menor[i];
    v[i]=pivo;
    i++;
    for(j=0; j<Nma && maior != NULL; j++,i++)
        v[i]=maior[j];

}

// Função que imprime o vetor na tela
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
