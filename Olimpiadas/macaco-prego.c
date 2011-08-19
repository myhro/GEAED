#include <stdio.h>

int main() {
	int n, x, y, u, v, i, a, b, c, d, teste = 1;
	while (1) {
		a = 1000, b = 1000, c = -1000, d = -1000;
		scanf("%d", &n);
		if (n == 0) break;
		for (i = 0; i < n; i++) {
			scanf("%d %d %d %d", &x, &y, &u, &v);
			if (x > d) d = x;
			if (y < a) a = y;
			if (u < b) b = u;
			if (v > c) c = v;
		}
		printf("Teste %d\n", teste);
		if (a > c && d < b) {
			printf("%d %d %d %d\n\n", d, a, b, c);
		}
		else {
			printf("nenhum\n\n");
		}
		teste++;
	}
	return 0;
}
