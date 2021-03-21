#include <stdio.h>

int main() {
	int n, i;
	int ans = 0;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) ans = ans + i;
	printf("%d", ans);
}