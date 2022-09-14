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
	int K, S;	// ���νð�, ����
	for (int i = 1; i <= N; i++)
	{
		cin >> K >> S;
		for (int j = 1; j <= T; j++)
		{
			if (K <= j)	// ������ �� �ִ� ��� (�����ϱ� or ���ϱ�)
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - K] + S);
			else // ���� ����
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