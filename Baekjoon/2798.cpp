#include <iostream>
using namespace std;

int main() {
	int N, M, sum, max = 0;
	int num[100];
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> num[i];
	}
	for (int i = 0; i < N - 2; i++)
	{
		for (int j = i + 1; j < N - 1; j++)
		{
			for (int k = j + 1; k < N; k++)
			{
				sum = num[i] + num[j] + num[k];
				if (sum <= M && sum > max) max = sum;
			}
		}
	}
	cout << max;
}