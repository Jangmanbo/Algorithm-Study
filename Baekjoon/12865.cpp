#include <iostream>
using namespace std;

int dp[101][100001];	// i��° ���Ǳ��� ����� �� ���԰� j�� ��� �ִ� ��ġ

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
			// ������ ���� �� �ִ� ��� ������ ������ ���� �Ǵ�
			if (W <= j) dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - W] + V);
			// ������ ���� �� ���� ���
			else dp[i][j] = dp[i - 1][j];
		}
	}

	cout << dp[N][K];
}