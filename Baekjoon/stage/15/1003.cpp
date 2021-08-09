#include <iostream>
using namespace std;


int main() {
	int T, N;
	cin >> T;
	int one[41] = { 0,1 };
	for (int i = 2; i <= 40; i++)
	{
		one[i] = one[i - 1] + one[i - 2];
	}
	for (int i = 0; i < T; i++)
	{
		cin >> N;
		if (N == 0) cout << 1 << " " << 0 << "\n";
		else if (N == 1) cout << 0 << " " << 1 << "\n";
		else cout << one[N - 1] << " " << one[N - 1] + one[N - 2] << "\n";
	}
}