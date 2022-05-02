#include <iostream>
#include <cmath>
using namespace std;

long long A, C;

long long func(long long B)
{
	long long temp;
	if (B % 2)
	{
		temp = pow(func(B / 2), 2);
		return (temp * A) % C;
	}
	else
	{
		if (B / 2)
		{
			temp = pow(func(B / 2), 2);
			return temp % C;
		}
		else
			return A;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	long long B;
	cin >> A >> B >> C;
	A %= C;

	cout << func(B);
}