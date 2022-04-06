#include <stdio.h>

int main() {
	int N;
	int cycle = 0;
	scanf("%d", &N);
	int change = N;
	do {
		if (change > 9) {
			change = (change % 10) * 10 + (change / 10 + change % 10) % 10;
		}
		else {
			change = change * 11;
		}
		cycle = cycle + 1;
	} while (change != N);
	printf("%d", cycle);
	return 0;
}