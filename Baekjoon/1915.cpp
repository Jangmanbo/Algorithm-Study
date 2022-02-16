#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int dp[1001][1001] = { 0 };

int main() {
	ios_base::sync_with_stdio();
	cin.tie(NULL);

	int N, M, ans = 0;
	string str;

	cin >> N >> M;
	cin.ignore();

	for (int i = 1; i <= N; i++)
	{
		getline(cin, str);
		for (int j = 1; j <= M; j++)
			dp[i][j] = str[j-1] - '0';
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			if (dp[i][j])
			{
				dp[i][j] = min({ dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1] }) + 1;
				ans = max(ans, dp[i][j]);
			}
		}
	}
	cout << ans * ans;
}