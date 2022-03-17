#include <iostream>
#include <map>
#include <vector>
using namespace std;

int K, V, E;
int color[20001];
vector<int> graph[20001];

bool dfs(int key)
{
	// ������ ������ ����
	if (graph[key].size() == 0)
		return true;
	
	for (int nxt : graph[key])
	{
		// �� ���� ��� ó�� üũ
		if (!color[key] && !color[nxt])
		{
			color[key] = 1;
			color[nxt] = -1;
			return dfs(nxt);
		}
		// �� ���� ��� ������ üũ
		else if (color[key] && color[nxt])
		{
			if (color[key] == color[nxt])
				return false;
		}// key�� ������ üũ
		else if (color[key])
		{
			color[nxt] = -color[key];
			return dfs(nxt);
		}
		// nxt�� ������ üũ
		else
			color[key] = -color[nxt];
	}
	return true;
}

bool solve() {
	int u, v;
	cin >> V >> E;

	// �Է�
	for (int i = 0; i < E; i++)
	{
		cin >> u >> v;

		graph[u].push_back(v);
		graph[v].push_back(u);
	}


	for (int i = 1; i <= V; i++)
	{
		if (!dfs(i))
		{
			return false;
		}
	}

	return true;
}

void init() {
	for (int i = 1; i <= V; i++)
	{
		graph[i].clear();
		color[i] = 0;
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> K;

	while (K--)
	{
		if (solve())
			cout << "YES\n";
		else
			cout << "NO\n";
		init();
	}
}