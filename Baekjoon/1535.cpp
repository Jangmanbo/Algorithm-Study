#include <iostream>
using namespace std;

int N;	// 사람
int hp[21], happy[21], dp[21][100];	// 체력, 기쁨, i번째 사람까지 체력 j를 소모하였을 때 최대 기쁨

void input()
{
	cin >> N;

	for (int i = 1; i <= N; i++)
		cin >> hp[i];
	for (int i = 1; i <= N; i++)
		cin >> happy[i];
}

// 배낭
void solve()
{
	// 인사를 할 수 있을 경우
	// 1. 인사 X -> 이전 사람까지 현재 체력에서의 최대 기쁨
	// 2. 인사 O -> 이전 사람까지 현재 체력-이번 인사에 필요한 체력에서의 최대 기쁨
	// 인사를 할 수 없는 경우 -> 이전 사람까지 현재 체력에서의 최대 기쁨
	for (int i = 1; i <= N; i++)
		for (int j = 0; j < 100; j++)
			dp[i][j] = (j >= hp[i]) ? dp[i][j] = max(dp[i - 1][j - hp[i]] + happy[i], dp[i - 1][j]) : dp[i - 1][j];

	cout << dp[N][99];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solve();
}