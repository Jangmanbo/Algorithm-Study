#include <stdio.h>

int main() {
	int first, second;
	scanf("%d %d", &first, &second);
	first= first % 10 * 100 + (first - first / 100 * 100) / 10 * 10 + first / 100;
	second = second % 10 * 100 + (second - second / 100 * 100) / 10 * 10 + second / 100;
	if(first>second) printf("%d", first);
	else printf("%d", second);

	return 0;
}