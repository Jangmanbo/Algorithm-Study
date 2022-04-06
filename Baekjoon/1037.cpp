#include <iostream>
using namespace std;

int main() {
	int N, num, min = 1000000, max = 2;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		if (num < min) min = num;
		if (num > max) max = num;
	}
	cout << min * max;
	return 0;
}