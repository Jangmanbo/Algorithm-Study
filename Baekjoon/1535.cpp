#include <iostream>
using namespace std;

int N;	// ���
int hp[21], happy[21], dp[21][100];	// ü��, ���, i��° ������� ü�� j�� �Ҹ��Ͽ��� �� �ִ� ���

void input()
{
	cin >> N;

	for (int i = 1; i <= N; i++)
		cin >> hp[i];
	for (int i = 1; i <= N; i++)
		cin >> happy[i];
}

// �賶
void solve()
{
	// �λ縦 �� �� ���� ���
	// 1. �λ� X -> ���� ������� ���� ü�¿����� �ִ� ���
	// 2. �λ� O -> ���� ������� ���� ü��-�̹� �λ翡 �ʿ��� ü�¿����� �ִ� ���
	// �λ縦 �� �� ���� ��� -> ���� ������� ���� ü�¿����� �ִ� ���
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