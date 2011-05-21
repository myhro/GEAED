#include <math.h>
#include <stdio.h>

int main() {
	int v, r = 0, n = 1;
	while (1) {
		scanf("%d", &v);
		if (v == -1) {
			break;
		}
		r = (pow(2,v)+1)*(pow(2,v)+1);
		printf("Teste %d\n%d\n\n", n, r);
		n++;
	}
	return 0;
}
