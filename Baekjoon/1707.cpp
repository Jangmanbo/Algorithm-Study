#include <iostream>
#include <vector>
using namespace std;

int K, V, E;
int color[20001];
vector<int> graph[20001];

void dfs(int key)
{
	if (!color[key])
		color[key] = 1;

	for (int nxt : graph[key])
	{
		if (!color[nxt])
		{
			color[nxt] = -color[key];
			dfs(nxt);
		}
	}
}

bool check()
{
	for (int i = 1; i <= V; i++)
	{
		for (int near : graph[i])
		{
			if (color[i] == color[near])
				return false;
		}
	}
	return true;
}

bool solve() {
	int u, v;
	cin >> V >> E;

	// ют╥б
	for (int i = 0; i < E; i++)
	{
		cin >> u >> v;

		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	for (int i = 1; i <= V; i++)
		dfs(i);

	if (check())
		return true;
	else
		return false;

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