#include <iostream>
#include <vector>
using namespace std;

int K, V, E;
vector<pair<int, int>> vertex;
int color[20001];

void check()
{
	int u, v;
	for (int i = 0; i < E; i++)
	{
		u = vertex[i].first;
		v = vertex[i].second;

		// 두 정점 모두 처음 체크
		if (!color[u] && !color[v])
		{
			color[u] = 1;
			color[v] = -1;
		}
		// 두 정점 모두 이미 체크했으며 두 색이 동일
		else if (color[u] && color[v] && color[u] == color[v])
		{
			cout << "NO\n";
			return;
		}
		else
		{
			if (color[u])
				color[v] = -color[u];
			else
				color[u] = -color[v];
		}
	}
	cout << "YES\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int u, v;
	cin >> K;

	while (K--)
	{
		cin >> V >> E;
		for (int i = 0; i < E; i++)
		{
			cin >> u >> v;
			vertex.push_back({ u, v });
		}

		check();

		// 초기화
		vertex.clear();
		for (int i = 1; i <= V; i++)
			color[i] = 0;
	}
}