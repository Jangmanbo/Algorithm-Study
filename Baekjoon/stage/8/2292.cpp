#include <stdio.h>

int main() {
	int N, sum = 1, repeat = 1, mul = 1;
	scanf("%d", &N);
	while (N > sum) {
		sum += 6 * mul;
		mul += 1;
		repeat += 1;
	}
	printf("%d", repeat);
}