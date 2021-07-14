#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int N;
	cin >> N;
	int num, produce;
	for (int i = 1; i < N; i++)
	{
		produce = i;
		num = i;
		for (int j = 0; num; j++)
		{
			produce += num % 10;
			num /= 10;
		}
		if (produce == N)
		{
			cout << i;
			return 0;
		}
		num = N;
	}
	cout << 0;
	return 0;
}