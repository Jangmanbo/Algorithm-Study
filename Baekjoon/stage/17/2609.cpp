#include <iostream>
using namespace std;

int divisor(int a, int b) {
	int small = min(a, b);
	int maximum = 1;
	for (int i = 2; i <= small; i++)
	{
		if (a % i == 0 && b % i == 0) maximum = i;
	}
	return maximum;
}

int multiple(int a, int b) {
	return a * (b / divisor(a, b));
}

int main() {
	int a, b;
	cin >> a >> b;
	cout << divisor(a, b) << "\n" << multiple(a, b);

	return 0;
}