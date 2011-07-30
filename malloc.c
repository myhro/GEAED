/*
 Universidade Estadual de Montes Claros - Unimontes
 GEAED - Grupo de Estudos em Algoritmos e Estruturas de Dados
 Descrição: Alocação dinâmica em um vetor estático
*/

#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main() {
    int *vet, i, n;

    printf("\n\t Alocacao dinamica de vetores \n\n");

    // Dados de entrada
    printf(" Tamanho do vetor: ");
    fflush(stdin);
    scanf("%d", &n);

    // Alocando espaco para o vetor
    vet = (int *) malloc(n*sizeof(int));

    if (vet == NULL) {
        printf("Memoria insuficiente.");
        return 1;
    }
    else {
        // Inserindo elementos
        for (i = 0; i < n; i++) {
            printf("Elemento %d: ", i+1);
            fflush(stdin);
            scanf("%d", &vet[i]);
        }
        printf("\n");

        // Imprimindo o vetor obtido
        for (i = 0; i < n; i++) {
            printf("%d ", vet[i]);
        }

        // Testando se o vetor foi desalocado corretamente
        printf("\n%d", &vet);
        free(vet);
        printf("\n%d", &vet);
    }
    return 0;
}
