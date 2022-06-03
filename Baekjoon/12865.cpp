#include <iostream>
using namespace std;

int dp[101][100001];	// i번째 물건까지 담았을 때 무게가 j일 경우 최대 가치

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	int N, K, W, V;
	cin >> N >> K;

	for (int i = 1; i <= N; i++)
	{
		cin >> W >> V;
		for (int j = 1; j <= K; j++)
		{
			// 물건을 담을 수 있는 경우 물건을 담을지 말지 판단
			if (W <= j) dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - W] + V);
			// 물건을 담을 수 없는 경우
			else dp[i][j] = dp[i - 1][j];
		}
	}

	cout << dp[N][K];
}