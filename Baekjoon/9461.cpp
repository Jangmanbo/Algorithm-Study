#include <iostream>
using namespace std;

long long p[101] = { 0,1,1,1,2,2,3,4,5,7,9 };


int main() {
	int T, N;
	cin >> T;
	for (int i = 11; i <= 100; i++)
		p[i] = p[i - 1] + p[i - 5];
	for (int i = 0; i < T; i++)
	{
		cin >> N;
		cout << p[N] << "\n";
	}
	return 0;
}