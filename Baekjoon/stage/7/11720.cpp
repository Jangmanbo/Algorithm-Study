#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	char num[100];
	scanf("%s", &num);
	int sum = 0;
	for (int i = 0; num[i] != '\0'; i++) {
		sum += (int)(num[i] - '0');
	}
	printf("%d", sum);
	return 0;
}