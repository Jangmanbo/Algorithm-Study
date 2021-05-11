#include <stdio.h>

int main() {
	int T, k, n;
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		scanf("%d", &k);
		scanf("%d", &n);
		int** room;
		room = new int* [k];
		for (int i = 0; i < k; i++)
		{
			room[i] = new int[n];
		}
		for (int i = 0; i < n; i++)
		{
			room[0][i] = (i + 1) * (i + 2) / 2;
		}
		for (int i = 1; i < k; i++)
		{
			room[i][0] = 1;
			for (int j = 1; j < n; j++)
			{
				room[i][j] = room[i][j - 1] + room[i - 1][j];
			}
		}
		printf("%d\n", room[k-1][n-1]);
	}
}