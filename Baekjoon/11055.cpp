#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio();
	cin.tie(NULL);

	int N, ans = 0;
	cin >> N;

	vector<pair<int, int>> dp(N);
	
	for (int i = 0; i < N; i++)
	{
		cin >> dp[i].first;
		dp[i].second = dp[i].first;

		for (int j = 0; j < i; j++)
		{
			if (dp[j].first < dp[i].first)	// 증가 부분 수열을 이룬다면
				dp[i].second = max(dp[i].second, dp[j].second + dp[i].first);	// 기존값과 비교
		}
		ans = max(dp[i].second, ans);
	}
	cout << ans;
}