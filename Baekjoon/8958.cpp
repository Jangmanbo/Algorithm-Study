#include <stdio.h>

int main() {
	int T, score = 0, buf = 0;
	char s[80];
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		scanf("%s", &s);
		for(int j = 0; true; j++) {
			if (s[j] == 'O') {
				buf++;
				score += buf;
			}
			else if (s[j] == 'X') buf = 0;
			else break;
		}
		printf("%d\n", score);
		score = 0;
		buf = 0;
	}
}