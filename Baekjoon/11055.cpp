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
			if (dp[j].first < dp[i].first)	// ���� �κ� ������ �̷�ٸ�
				dp[i].second = max(dp[i].second, dp[j].second + dp[i].first);	// �������� ��
		}
		ans = max(dp[i].second, ans);
	}
	cout << ans;
}