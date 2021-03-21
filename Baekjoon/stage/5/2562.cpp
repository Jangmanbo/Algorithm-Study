#include <stdio.h>

int main() {
	int num, index;
	int max = 0;
	for (int i = 0; i < 9; i++) {
		scanf("%d", &num);
		if (num > max) {
			max = num;
			index = i+1;
		}
	}
	printf("%d\n%d", max, index);
	return 0;
}