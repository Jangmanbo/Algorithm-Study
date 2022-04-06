#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	long long ans = 0;
	long long arr[100][10];

	cin >> N;

	for (int i = 0; i < 10; i++)
		arr[0][i] = 1;

	for (int i = 1; i < N; i++)
	{
		arr[i][0] = arr[i - 1][1];
		for (int j = 1; j < 9; j++)
			arr[i][j] = (arr[i - 1][j - 1] + arr[i - 1][j + 1]) % 1000000000;
		arr[i][9] = arr[i - 1][8];
	}

	for (int j = 1; j < 10; j++)
		ans = (ans + arr[N - 1][j]) % 1000000000;

	cout << ans;
}