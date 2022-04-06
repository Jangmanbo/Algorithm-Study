#include <iostream>
using namespace std;

// LIS
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	int N, ans = 1;
	int arr[1000];
	int dp[1000];

	// ют╥б
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	for (int i = 0; i < N; i++)
	{
		dp[i] = 1;
		for (int j = 0; j < i; j++)
		{
			if (arr[i] > arr[j])
			{
				if (dp[i] < dp[j] + 1)
				{
					dp[i] = dp[j] + 1;
					ans = max(dp[i], ans);
				}
			}
		}
	}

	cout << ans;
}