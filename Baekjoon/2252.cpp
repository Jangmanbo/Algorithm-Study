#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define MAX 100001

int N, M;
int in_degree[MAX];
bool visit[MAX];
vector<int> graph[MAX];

vector<int> answer;

void input()
{
	cin >> N >> M;

	int A, B;
	for (int i = 0; i < M; i++)
	{
		cin >> A >> B;
		graph[A].push_back(B);
		in_degree[B]++;
	}
}

void solve()
{
	queue<int> q;
	for (int i = 1; i <= N; i++)
		if (in_degree[i] == 0) q.push(i);

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		visit[cur] = true;
		answer.push_back(cur);
		
		for (int node : graph[cur])
		{
			if (!visit[node])
			{
				in_degree[node]--;
				if (in_degree[node] == 0)
					q.push(node);
			}
		}
	}

	for (int node : answer)
		cout << node << ' ';
}

// 위상 정렬
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solve();
}