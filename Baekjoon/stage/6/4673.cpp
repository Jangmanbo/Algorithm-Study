#include <stdio.h>

int d(int n) {
	if (n == 0) return 0;
	return n % 10 + d(n / 10);
}

int main() {
	int sum = 0;
	int nums[10000] = { false };
	for (int n = 1; n <= 10000; n++) {
		sum += d(n) + n;
		if (n != sum && sum<=10000) nums[sum - 1] = true;
		sum = 0;
	}
	for (int i = 0; i < 10000; i++) {
		if(nums[i]==false) printf("%d\n", i + 1);
	}
	return 0;
}