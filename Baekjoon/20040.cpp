#include <iostream>
using namespace std;

int N, M;
int node[500000];

void set()
{
	for (int i = 0; i < N; i++)
		node[i] = i;
}

int find(int x)
{
	if (node[x] == x)
		return x;

	int parent = find(node[x]);
	node[x] = parent;
	return parent;
}

void join(int x, int y)
{
	x = find(x);
	y = find(y);
	node[x] = y;
}

bool equal(int x, int y)
{
	return find(x) == find(y);
}

void solve()
{
	cin >> N >> M;
	set();

	int x, y;
	for (int i = 1; i <= M; i++)
	{
		cin >> x >> y;
		if (equal(x, y))	// 이미 같은 집합인데 연결  -> 사이클 생성
		{
			cout << i;
			return;
		}
		else
			join(x, y);
	}
	cout << 0;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
}