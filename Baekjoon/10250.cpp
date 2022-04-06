#include <stdio.h>

int main() {
	int T, H, W, N, floor, room;
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		scanf("%d %d %d", &H, &W, &N);
		floor = N % H;
		room = N / H + 1;
		if (floor != 0)	room += floor * 100;
		else room += (H * 100 - 1);
		printf("%d\n", room);
	}
}