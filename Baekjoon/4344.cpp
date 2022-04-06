#include <stdio.h>

int main() {
	int C, N, score, total = 0;
	float per = 0;
	int arr[1000];
	scanf("%d", &C);
	for (int i = 0; i < C; i++) {
		scanf("%d", &N);
		for (int j = 0; j < N; j++) {
			scanf("%d", &score);
			arr[j] = score;
			total += score;
		}
		score = total / N;
		for (int j = 0; j < N; j++) {
			if (arr[j] > score) {
				per++;
			}
		}
		per = (per * 100) / N;
		printf("%.3f%%\n", per);
		total = 0;
		score = 0;
		per = 0;
	}
}