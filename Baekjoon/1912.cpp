#include <iostream>
using namespace std;

int dp[100000];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	int n;
	cin >> n;
	cin >> dp[0];
	int ans = dp[0];

	for (int i = 1; i < n; i++)
	{
		cin >> dp[i];
		if (dp[i] + dp[i - 1] > dp[i])
			dp[i] += dp[i - 1];
		ans = max(ans, dp[i]);
	}

	cout << ans;
}