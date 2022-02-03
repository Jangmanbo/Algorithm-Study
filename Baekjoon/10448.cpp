#include <iostream>
#include <algorithm>
using namespace std;

int T[46];

bool Eureka() {
	int K;
	cin >> K;
	for (int i : T)
	{
		for (int j : T)
		{
			for (int k : T)
			{
				if ((i + j + k) == K)
					return true;
			}
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	for (int i = 0; i < 46; i++)
	{
		T[i] = (((i + 2) * (i + 1)) / 2);
	}

	for (int i = 0; i < N; i++)
	{
		if (Eureka())
			cout << "1\n";
		else
			cout << "0\n";
	}
	
}