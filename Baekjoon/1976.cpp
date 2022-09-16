#include <iostream>
using namespace std;

int N, M;	// 도시의 수, 여행 갈 도시의 수
int city[200];

void set()
{
	for (int i = 0; i < 200; i++)
		city[i] = i;
}

int find(int x)
{
	if (city[x] == x)
		return x;

	int parent = find(city[x]);
	city[x] = parent;
	return parent;
}

void join(int x, int y)
{
	x = find(x);
	y = find(y);
	city[x] = y;
}

void input()
{
	cin >> N >> M;

	int connect;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> connect;

			if (connect)
				join(i, j);
		}
	}
}

// 유니온 파인드
void solve()
{
	int parent, num;

	cin >> parent;
	parent = find(parent - 1);

	for (int i = 1; i < M; i++)
	{
		cin >> num;

		if (parent != find(num - 1))
		{
			cout << "NO";
			return;
		}
	}

	cout << "YES";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	set();
	input();
	solve();
}