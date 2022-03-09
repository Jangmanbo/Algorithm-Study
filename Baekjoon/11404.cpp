#include <iostream>
#include <algorithm>
using namespace std;

int map[101][101];	// 버스 비용
bool visit[101][101];	// 버스 사용 체크
int ans[101][101];
int N, M, a, b, c;

void dfs(int start, int def, int cost)
{
	// 적은 비용만 기록
	if (ans[start][def])
		ans[start][def] = min(ans[start][def], cost);
	else
		ans[start][def] = cost;

	for (int j = 1; j <= N; j++)
	{
		// def를 경유지로 하는 노선 탐색
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
		// 비용이 적은 버스만 사용
		if (map[a][b])
			map[a][b] = ans[a][b] = min(map[a][b], c);
		else
			map[a][b] = ans[a][b] = c;
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			// i->j 버스가 있음
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