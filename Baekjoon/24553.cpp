#include <iostream>
using namespace std;


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	int T;
	long long N;

	cin >> T;

	while (T--)
	{
		cin >> N;
		if (N % 10)
			cout << 0 << '\n';
		else
			cout << 1 << '\n';
	}
}