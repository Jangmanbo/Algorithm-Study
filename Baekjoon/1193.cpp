#include <stdio.h>

int main() {
	int N, sub, sum = 0, line = 0;
	scanf("%d", &N);
	for (int i = 1; N > sum; i++) {
		sum += i;
		line += 1;
	}
	sub = sum - N;
	if (line % 2 == 0) {
		printf("%d/%d", line - sub, sub + 1);
	}
	else {
		printf("%d/%d", sub + 1, line - sub);
	}
}