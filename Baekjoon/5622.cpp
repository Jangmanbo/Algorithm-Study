#include <stdio.h>

int main() {
	char num[15];
	int sum = 0;
	scanf("%s", num);
	for (int i = 0; num[i] != '\0'; i++) {
		if (num[i]<'S') {
			sum+= (num[i]- 'A') / 3 + 3;
		}
		else if (num[i] >= 'S' && num[i] != 'Z') {
			sum += (num[i] - 'B') / 3 + 3;
		}
		else {
			sum += 10;
		}
	}
	printf("%d", sum);
	return 0;
}