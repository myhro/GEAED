#include <stdio.h>

int main() {
	int v, b50, b10, b5, b1, n = 1;
	while (1) {
		b50 = 0;
		b10 = 0;
		b5 = 0;
		b1 = 0;
		scanf("%d", &v);
		if (v < 1) {
			break;
		}
		b50 = v / 50;
		b10 = (v % 50) / 10;
		b5 = (v % 10) / 5;
		b1 = v % 5;
		printf("Teste %d\n%d %d %d %d\n\n", n, b50, b10, b5, b1);
		n++;
	}
	return 0;
}
