#include <iostream>
using namespace std;
int main() {
	int N;
	cin >> N;
	for (int i = 2; i*i <= N; i++)
	{
		if (N % i == 0) {
			N /= i;
			cout << i << '\n';
			i -= 1;
		}
	}
	if (N > 1) cout << N;
}