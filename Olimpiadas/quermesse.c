#include <stdio.h>

int main() {
	int n, teste = 1, i, convidado, vencedor;
	while (1) {
		scanf("%d", &n);
		if (n == 0) break;
		for (i = 0; i < n; i++) {
			scanf("%d", &convidado);
			if (convidado == i+1) {
				vencedor = convidado;
			}
		}
		printf("Teste %d\n%d\n\n", teste, vencedor);
		teste++;
	}
	return 0;
}
