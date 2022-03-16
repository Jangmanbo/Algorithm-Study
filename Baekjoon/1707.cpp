#include <iostream>
#include <map>
#include <vector>
using namespace std;

int K, V, E;
int color[20001];
vector<int> graph[20001];

bool dfs(int key)
{
	// 인접한 정점이 없음
	if (graph[key].size() == 0)
		return true;

	for (int i = 0; i < graph[key].size(); i++)
	{
		// 두 정점 모두 처음 체크
		if (!color[key] && !color[graph[key][i]])
		{
			color[key] = 1;
			color[graph[key][i]] = -1;
			return dfs(graph[key][i]);
		}
		// 두 정점 모두 이전에 체크
		else if (color[key] && color[graph[key][i]])
		{
			if (color[key] == color[graph[key][i]])
				return false;
		}
		else
		{
			// key만 이전에 체크
			if (color[key])
			{
				color[graph[key][i]] = -color[key];
				return dfs(graph[key][i]);
			}
			// vertex[i]만 이전에 체크
			else
				color[key] = -color[graph[key][i]];
		}
	}
	return true;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int u, v;
	bool ans = true;
	cin >> K;

	while (K--)
	{
		cin >> V >> E;

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
				ans = false;
				cout << "NO\n";
				break;
			}
		}
		if (ans)
			cout << "YES\n";

		// 초기화
		for (int i = 1; i <= V; i++)
		{
			graph[i].clear();
			color[i] = 0;
		}
		ans = true;
	}
}