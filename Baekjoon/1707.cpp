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
	
	for (int nxt : graph[key])
	{
		// 두 정점 모두 처음 체크
		if (!color[key] && !color[nxt])
		{
			color[key] = 1;
			color[nxt] = -1;
			return dfs(nxt);
		}
		// 두 정점 모두 이전에 체크
		else if (color[key] && color[nxt])
		{
			if (color[key] == color[nxt])
				return false;
		}// key만 이전에 체크
		else if (color[key])
		{
			color[nxt] = -color[key];
			return dfs(nxt);
		}
		// nxt만 이전에 체크
		else
			color[key] = -color[nxt];
	}
	return true;
}

bool solve() {
	int u, v;
	cin >> V >> E;

	// 입력
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