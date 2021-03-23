#include <stdio.h>

int main() {
	char S[100];
	int find = false;
	scanf("%s", S);
	for (int i = 97; i < 123; i++) {
		for (int j = 0; S[j] != '\0'; j++) {
			if ((char)i == S[j]) {
				printf("%d ", j);
				find = true;
				break;
			}
		}
		if (!find) printf("%d " , -1);
		find = false;
	}
	return 0;
}