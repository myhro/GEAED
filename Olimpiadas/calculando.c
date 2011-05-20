#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char expressao[101], temp[101], c;
	int n, i, j, k, nums[100], neg, res, t = 1;
	while (1) {
		res = 0;
		scanf("%d", &n);
		if (n == 0) {
			break;
		}
		scanf("%s", expressao);
		i = 0;
		j = 0;
		k = 0;
		c = expressao[0];
		temp[0] = '\0';
		while (c != '\0') {
			temp[0] = '\0';
			neg = 1;
			if (!isdigit(c)) {
				if (c == '-') {
					neg = -1;
				}
				else {
					neg = 1;
				}
				i++;
				c = expressao[i];
			}
			for (j = 0; isdigit(c); j++) {
				temp[j] = c;
				i++;
				c = expressao[i];
				if (expressao[i+1] == '\0') {
					j++;
					temp[j] = c;
					c = '\0';
				}
			}
			temp[j] = '\0';
			if (strlen(temp) > 0) {
				nums[k] = atoi(temp) * neg;
				k++;
			}
		}
		for (i = 0; i < n; i++) {
			res += nums[i];
		}
		printf("Teste %d\n%d\n\n", t, res);
		t++;
	}
	return 0;
}
