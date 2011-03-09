#include<conio.h>
#include<malloc.h>
#include<stdio.h>
#include<stdlib.h>

int main() {
    int **mat, i, j, k, n, l, c;
    printf("Tamanho (linhas): ");
    scanf("%d", &l);
    printf("Tamanho (colunas): ");
    scanf("%d", &c);
    mat = (int **) malloc(l*sizeof(int));
    if (mat == NULL) {
        printf("Erro.");
        return 1;
    }
    else {
        for (i = 0; i < l; i++) {
            mat[i] = (int *) malloc(c*sizeof(int));
            if (mat[i] == NULL) {
                printf("Erro.");
                return 1;
            }
        }
        for (i = 0; i < l; i++) {
            for (j = 0; j < c; j++) {
                printf("Elemento %d: ", i+1);
                scanf("%d", &mat[i][j]);
            }
        }
        printf("\n");
        for (i = 0; i < l; i++) {
            for (j = 0; j < c; j++) {
                printf("%d ", mat[i][j]);
            }
        }
        for (i = 0; i < l; i++) {
            //printf("\n%d ", i);
            printf("\n%u", _msize(mat[i]));
            free(mat[i]);
            printf("\n%u", _msize(mat[i]));
            //mat[i] = NULL;
            printf("\n");
            for (j = 0; j < l; j++) {
                for (k = 0; k < c; k++) {
                    printf("%d ", mat[j][k]);
                }
            }
		}
        free(mat);
    }
    return 0;
}
