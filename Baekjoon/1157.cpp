#include <stdio.h>
#include <string.h>

int main() {
	char str[1000000];
	int i, index, count = -2, max = 0, alp[26] = { 0 };
	scanf("%s", str);
	int len = strlen(str);
	for (i = 0; i < len; i++) {
		if (str[i] >= 'a') {
			alp[str[i] - 'a']++;
		}
		else {
			alp[str[i] - 'A']++;
		}
	}
	for (i = 0; i < 26; i++) {
		if (alp[i] > max) max = alp[i];
	}
	for (i = 0; i < 26; i++) {
		if (alp[i] == max) {
			count++;
			if (!count) {
				printf("?");
				return 0;
			}
			index = i;
		}
	}
	printf("%c", index + 'A');
	return 0;
}