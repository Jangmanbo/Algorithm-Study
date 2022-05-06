#include <iostream>
using namespace std;

#define MAX 10000

int n, arr[MAX], dp[MAX][3];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;
	cin >> arr[0];
	dp[0][1] = arr[0];

	for (int i = 1; i < n; i++)
	{
		cin >> arr[i];
		dp[i][0] = max(max(dp[i - 1][0], dp[i - 1][1]), dp[i - 1][2] );
		dp[i][1] = dp[i - 1][0] + arr[i];
		dp[i][2] = dp[i - 1][1] + arr[i];
	}

	cout << max(max( dp[n - 1][0], dp[n - 1][1]), dp[n - 1][2] );
}