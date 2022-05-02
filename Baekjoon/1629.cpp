#include <iostream>
#include <cmath>
using namespace std;

long long int A, C;

long long int func(long long int B)
{
	if (B == 1)
		return A;
	else
	{
		long long int n = func(B / 2);
		if (B % 2)
			return (((n * n) % C) * A) % C;
		else
			return (n * n) % C;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	long long int B;
	cin >> A >> B >> C;
	A %= C;

	cout << func(B);
}