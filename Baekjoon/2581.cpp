#include <iostream>
#include <cmath>
using namespace std;
int main() {
	int M, N, min = -1, sum = 0;
	bool prime = true;
	cin >> M;
	cin >> N;
	if (M == 1) M++;
	for (int i = M; i <= N; i++)
	{
		for (int j = 2; j <= sqrt(i); j++)
		{
			if (i % j == 0) {
				prime = false;
				break;
			}
		}
		if (prime) {
			sum += i;
			if (min == -1) min = i;
		}
		prime = true;
	}
	if (min != -1) cout << sum << '\n';
	cout << min << '\n';
}