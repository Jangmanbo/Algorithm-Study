#include <stdio.h>

int main() {
	int arr[42] = { 0 };
	int input;
	int total = 0;
	for (int i = 0; i < 10; i++) {
		scanf("%d", &input);
		arr[input % 42]++;
	}
	for (int i = 0; i < 42; i++) {
		if (arr[i] != 0) {
			total++;
		}
	}
	printf("%d", total);
}