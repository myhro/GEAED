#include <stdio.h>
#include <stdlib.h>

int main() {
	int j, q, t1, t2, t3, d1, d2, i, n = 1, venc, *pontuacao, vez, *pula;
	while (1) {
		vez = 0;
		scanf("%d %d", &j, &q);
		if (j == 0 && q == 0) {
			break;
		}
		scanf("%d %d %d", &t1, &t2, &t3);
		pontuacao = (int *) malloc(j*sizeof(int));
		pula = (int *) malloc(j*sizeof(int));
		for (i = 0; i < j; i++) {
			pontuacao[i] = 0;
			pula[i] = 0;
		}
		while (1) {
			vez = vez % j;
			if (pula[vez] == 1) {
				pula[vez] = 0;
				vez++;
				continue;
			}
			scanf("%d %d", &d1, &d2);
			pontuacao[vez] += (d1 + d2);
			if (pontuacao[vez] == t1 || pontuacao[vez] == t2 || pontuacao[vez] == t3) {
				pula[vez] = 1;
			}
			if (pontuacao[vez] > q) {
				venc = vez + 1;
				break;
			}
			vez++;
		}
		printf("Teste %d\n%d\n\n", n, venc);
		n++;
		free(pontuacao);
		free(pula);
	}
	return 0;
}
