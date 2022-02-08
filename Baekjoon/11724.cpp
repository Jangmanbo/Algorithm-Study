#include <iostream>
using namespace std;

int N, M;

void dfs(int i, bool** arr, bool* visit)
{
	for (int j = 1; j <= N; j++)
	{
		if (arr[i][j] && !visit[j])
		{
			visit[j] = true;
			dfs(j, arr, visit);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int u, v, ans = 0;
	cin >> N >> M;

	// ���� �迭 �ʱ�ȭ (1-based)
	N++;
	bool* visit = new bool[N]();	// ��� �湮 ����
	bool** arr = new bool* [N]();	// ���� �迭
	for (int i = 0; i < N; i++)
	{
		arr[i] = new bool[N]();
	}
	N--;

	// ���� �迭
	for (int i = 0; i < M; i++)
	{
		cin >> u >> v;
		arr[u][v] = true;
		arr[v][u] = true;
	}

	for (int i = 1; i <= N; i++)
	{
		if (!visit[i])
		{
			ans++;
			visit[i] = true;
			dfs(i, arr, visit);
		}
	}
	cout << ans;
}