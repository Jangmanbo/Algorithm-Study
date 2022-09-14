#include <iostream>
using namespace std;

int N, T;
int dp[101][10001];

void input()
{
	cin >> N >> T;
}

void solve()
{
	int K, S;	// 공부시간, 배점
	for (int i = 1; i <= N; i++)
	{
		cin >> K >> S;
		for (int j = 1; j <= T; j++)
		{
			if (K <= j)	// 공부할 수 있는 경우 (공부하기 or 안하기)
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - K] + S);
			else // 공부 못함
				dp[i][j] = dp[i - 1][j];
		}
	}
	
	cout << dp[N][T];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solve();
}