#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX 100001

int N;
int ans[MAX];
vector<int> vec[MAX];

void bfs()
{
	int node;
	queue<int> q;
	q.push(1);

	while (!q.empty())
	{
		node = q.front();
		q.pop();

		for (int elem : vec[node])
		{
			if (!ans[elem])
			{
				ans[elem] = node;
				q.push(elem);
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> N;

	// 입력
	int num1, num2;
	for (int i = 1; i < N; i++)
	{
		cin >> num1 >> num2;
		vec[num1].push_back(num2);
		vec[num2].push_back(num1);
	}
	
	bfs();

	// 출력
	for (int i = 2; i <= N; i++)
	{
		cout << ans[i] << '\n';
	}
}