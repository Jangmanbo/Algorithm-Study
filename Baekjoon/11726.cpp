#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio();
	cin.tie(NULL);

	int dp[1001] = { 0,1,2 };
	int n;
	cin >> n;

	for (int i = 3; i <= n; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2];
		dp[i] %= 10007;
	}

	cout << dp[n];
}