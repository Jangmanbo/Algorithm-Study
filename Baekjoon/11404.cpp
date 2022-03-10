#include <iostream>
#include <algorithm>
using namespace std;

#define INF 9999999

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int map[101][101];
	int N, M, a, b, c;

	cin >> N;
	cin >> M;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (i != j)
				map[i][j] = INF;
			else
				map[i][j] = 0;
		}
	}

	while (M--)
	{
		cin >> a >> b >> c;
		map[a][b] = min(map[a][b], c);	// 비용이 적은 버스만 사용
	}

	for (int k = 1; k <= N; k++)
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				map[i][j] = min(map[i][j], map[i][k] + map[k][j]);

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (map[i][j] != INF)
				cout << map[i][j] << ' ';
			else
				cout << 0 << ' ';
		}
		cout << '\n';
	}
}