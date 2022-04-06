#include <iostream>
#include <algorithm>
using namespace std;

int Euclid(int a, int b) {
	int small = min(a, b);
	int big = max(a, b);
	int remain;

	do
	{
		remain = big % small;
		big = small;
		small = remain;
	} while (remain);
	return big;
}

int main() {
	int T, a, b;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> a >> b;
		cout << a * (b / Euclid(a, b)) << "\n";
	}
}