#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define INF 999999999

int V, E, K;	// 정점, 간선, 시작점
int dist[20001];	// 시작점에서 정점까지의 최소거리
vector<pair<int, int>> graph[20001];	// (도착점, 비용)

void input()
{
	fill_n(dist, 20001, INF);	// 무한으로 초기화
	cin >> V >> E >> K;

	int u, v, w;
	while (E--)
	{
		cin >> u >> v >> w;
		graph[u].push_back({ v, w });
	}
}

void solve()
{
	// 비용, 노드 (오름차순)
	priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0, K });
	dist[K] = 0;

	while (!pq.empty())
	{
		int cost = pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		if (dist[cur] < cost)	// 지금까지 구한 최소비용이 이미 더 작은 경우
			continue;

		for (int i = 0; i < graph[cur].size(); i++)
		{
			int next_node = graph[cur][i].first;
			int next_cost = cost + graph[cur][i].second;

			if (next_cost < dist[next_node])
			{
				dist[next_node] = next_cost;
				pq.push({ next_cost, next_node });
			}
		}
	}

	for (int i = 1; i <= V; i++)
	{
		switch (dist[i])
		{
		case INF:
			cout << "INF\n";
			break;
		default:
			cout << dist[i] << '\n';
			break;
		}
	}

}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solve();
}