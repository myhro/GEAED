#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main() {
    int *vet, i, n;
    printf("Tamanho do vetor: ");
    fflush(stdin);
    scanf("%d", &n);
    vet = (int *) malloc(n*sizeof(int));
    if (vet == NULL) {
        printf("Memoria insuficiente.");
        return 1;
    }
    else {
        for (i = 0; i < n; i++) {
            printf("Valor de %d: ", i+1);
            fflush(stdin);
            scanf("%d", &vet[i]);
        }
        for (i = 0; i < n; i++) {
            printf("%d ", vet[i]);
        }
        printf("\n%d", &vet);
        free(vet);
        printf("\n%d", &vet);
    }
    return 0;
}
