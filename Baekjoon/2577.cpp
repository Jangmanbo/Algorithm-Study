#include <stdio.h>

int main() {
	int input;
	int mul = 1;
	for (int i = 0; i < 3; i++) {
		scanf("%d", &input);
		mul *= input;
	}
	int arr[10] = { 0 };
	for (int i = 0; mul!=0; i++) {
		arr[mul % 10] += 1;
		mul /= 10;
	}
	for (int i = 0; i < 10; i++) {
		printf("%d\n", arr[i]);
	}
}