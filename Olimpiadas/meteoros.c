#include <stdio.h>

int main() {
	int x1, y1, x2, y2, q, i, x, y, cont, n = 1;
	while (1) {
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		if (x1 == 0 && y1 == 0 && x2 == 0 && y2 == 0) {
			break;
		}
		scanf("%d", &q);
		cont = 0;
		for (i = 0; i < q; i++) {
			scanf("%d %d", &x, &y);
			if ((x >= x1 && x <= x2) && (y >= y2 && y <= y1)) {
				cont++;
			}
		}
		printf("Teste %d\n%d\n\n", n, cont);
		n++;
	}
	return 0;
}
