#include <stdio.h>

int main() {
	int n, x, num;
	scanf("%d %d", &n, &x);
	for (int i = 0; i < n; i++) {
		scanf("%d", &num);
		if (x > num) {
			printf("%d ", num);
		}
	}
	return 0;
}