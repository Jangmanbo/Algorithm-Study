#include <stdio.h>

int main() {
	int N, count = 0;
	bool group = true;
	char str[100];
	int alpha[26] = { 0 };
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%s", str);
		for (int j = 0; str[j] != '\0'; j++) {
			if ((alpha[str[j] - 'a']!=0) && (str[j]!=str[j-1])) {
				group = false;
				break;
			}
			else {
				alpha[str[j] - 'a']++;
			}
		}
		if (group) count++;
		group = true;
		for (int i = 0; i < 26; i++) {
			alpha[i] = 0;
		}
	}
	printf("%d", count);
}