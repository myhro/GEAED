#include <stdio.h>
#include <stdlib.h>

int main() {
	int a, i, v, *vet, x, y, cong, n = 1;
	while (1) {
		scanf("%d %d", &a, &v);
		/* if (a < 0 || a > 100) {
			return 1;
		}
		if (v < 0 || v > 10000) {
			return 1;
		} */
		if (a == 0 && v == 0) {
			break;
		}
		vet = (int *) malloc(a*sizeof(int));
		for (i = 0; i < a; i++) {
			vet[i] = 0;
		}
		for (i = 0; i < v; i++) {
			scanf("%d %d", &x, &y);
			/* if (x < 1 || x > a || y < 1 || y > a || x == y) {
				return 1;
			} */
			vet[x-1]++;
			vet[y-1]++;
		}
		cong = vet[0];
		for (i = 0; i < a; i++) {
			if (vet[i] > cong) {
				cong = vet[i];
			}
		}
		printf("Teste %d\n", n);
		for (i = 0; i < a; i++) {
			if (vet[i] == cong) {
				printf("%d ", i+1);
			}
		}
		n++;
		printf("\n\n");
		free(vet);
	}
	return 0;
}
