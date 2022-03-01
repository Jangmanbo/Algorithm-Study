#include <iostream>
using namespace std;


int main()
{
	int T, n;
	long long arr[65][10];

	for (int i = 0; i < 65; i++)
		arr[i][0] = 1;
	for (int i = 0; i < 10; i++)
		arr[0][i] = 1;
	for (int i = 1; i < 65; i++)
	{
		for (int j = 1; j < 10; j++)
			arr[i][j] = arr[i - 1][j] + arr[i][j - 1];
	}


	cin >> T;
	while (T--)
	{
		cin >> n;
		cout << arr[n][9] << '\n';
	}
}