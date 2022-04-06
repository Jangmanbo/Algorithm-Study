#include <stdio.h>

bool AP(int n) {
	int a, b, c;
	a = n % 10;
	n /= 10;
	b = n % 10;
	c = n / 10;
	return ((a - b) == (b - c));
}

int main() {
	int n, count = 0;
	scanf("%d", &n);
	if (n < 100) {
		printf("%d", n);
		return 0;
	}
	else {
		for (int i = 100; i <= n; i++) {
			if (AP(i)) count++;
		}
		printf("%d", count+99);
	}
	return 0;
}