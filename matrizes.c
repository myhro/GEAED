/*
 Universidade Estadual de Montes Claros - Unimontes
 GEAED - Grupo de Estudos em Algoritmos e Estruturas de Dados

 Descrição: Estudo de alocação dinâmica em matrizes

*/

#include<conio.h>
#include<malloc.h>
#include<stdio.h>
#include<stdlib.h>

int main() {
    int **mat, i, j, k, n, l, c;

    printf("\n\t Estudo de Alocacao Dinamica em Matrizes \n\n");

    // Dados de Entrada
    printf(" Tamanho (linhas): ");
    scanf("%d", &l); fflush(stdin);
    printf("\n Tamanho (colunas): ");
    scanf("%d", &c); fflush(stdin);

    // Alocacao  das linhas da matriz
    mat = (int **) malloc(l*sizeof(int));

    // Caso a matriz seja nula, houve um erro: encerra o programa
    if (mat == NULL) {
        printf("Erro.");
        return 1;
    }
    else {
        // do contrario, sao alocadas as colunas
        for (i = 0; i < l; i++) {
            mat[i] = (int *) malloc(c*sizeof(int));
            if (mat[i] == NULL) {
                printf("Erro.");
                return 1;
            }
        }

        // Armazenando os elementos
        for (i = 0; i < l; i++) {
            for (j = 0; j < c; j++) {
                printf("Elemento %d: ", i+1);
                scanf("%d", &mat[i][j]);
            }
        }
        printf("\n");

        // Imprimindo a matriz obtida
        for (i = 0; i < l; i++) {
            for (j = 0; j < c; j++) {
                printf("%d ", mat[i][j]);
            }
        }

        // Testando se a matriz foi desalocada corretamente
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


/* OBS: é interessante notar que, ao testar se todas as posicoes da matriz
    foram corretamente desalocadas, vimos que os valores alocados nas posicoes
    de memoria NAO sao literalmente 'deletados', mas sim, sua referencia é perdida,
    como se o sistema fosse 'autorizado' a reutilizar aquele espaço para gravar outros
    dados.
*/
