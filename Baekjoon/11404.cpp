#include <iostream>
#include <algorithm>
using namespace std;

int map[101][101];	// ���� ���
bool visit[101][101];	// ���� ��� üũ
int ans[101][101];
int N, M, a, b, c;

void dfs(int start, int def, int cost)
{
	// ���� ��븸 ���
	if (ans[start][def])
		ans[start][def] = min(ans[start][def], cost);
	else
		ans[start][def] = cost;

	for (int j = 1; j <= N; j++)
	{
		// def�� �������� �ϴ� �뼱 Ž��
		if (start != j && map[def][j] && !visit[def][j])
		{
			visit[def][j] = true;
			dfs(start, j, cost + map[def][j]);
			visit[def][j] = false;
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	
	cin >> N;
	cin >> M;

	while (M--)
	{
		cin >> a >> b >> c;
		// ����� ���� ������ ���
		if (map[a][b])
			map[a][b] = ans[a][b] = min(map[a][b], c);
		else
			map[a][b] = ans[a][b] = c;
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			// i->j ������ ����
			if (i != j && map[i][j])
			{
				visit[i][j] = true;
				dfs(i, j, map[i][j]);
				visit[i][j] = false;
			}
		}
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
			cout << ans[i][j] << ' ';
		cout << '\n';
	}
}