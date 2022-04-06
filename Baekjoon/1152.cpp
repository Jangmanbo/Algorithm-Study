#include <stdio.h>
#include <string.h>

int main() {
	char str[1000000];
	int final, start = 0, count = 1;
	scanf("%[^\n]", str);
	final = strlen(str);
	if (str[0] == ' ') {
		if (final == 1) {
			printf("%d", 0);
			return 0;
		}
		start++;
	}
	if (str[final - 1] == ' ') final--;
	for (int i = start; i < final; i++) {
		if (str[i] == ' ') count++;
	}
	printf("%d", count);
	return 0;
}