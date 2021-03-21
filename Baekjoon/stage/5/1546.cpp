#include <stdio.h>

int main() {
	int N, score, total = 0, max = 0;
	float avg;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &score);
		total += score;
		if (score > max) max = score;
	}
	avg = (float)(total * 100) / (N * max);
	printf("%g", avg);
}