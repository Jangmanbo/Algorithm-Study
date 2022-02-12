#include <iostream>
#include <algorithm>
using namespace std;


void dynamic_programming(int n)
{
	// 스티커 점수 배열
	int dp[2][100001] = { 0 };
	for (int i = 0; i < 2; i++)
		for (int j = 1; j <= n; j++)
			cin >> dp[i][j];

	// 현재까지의 최대 점수
	for (int j = 2; j <= n; j++)
	{
		dp[0][j] += max(dp[1][j - 2], dp[1][j - 1]);
		dp[1][j] += max(dp[0][j - 1], dp[0][j - 2]);
	}
	// 마지막 2칸 중에 최대 점수 존재
	cout << max(dp[0][n], dp[1][n]) << "\n";
}

int main() {
	ios_base::sync_with_stdio();
	cin.tie(NULL);

	int T, n;
	cin >> T;
	while (T--)
	{
		cin >> n;
		dynamic_programming(n);
	}
}