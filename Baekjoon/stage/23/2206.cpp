#include <iostream>
#include <queue>
#include <string>
using namespace std;

#define INF 1000000

int N, M, ans = INF;
int map[1000][1000];
int _distance[1000][1000];
bool visit[1000][1000][2];

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1,};

typedef struct{
	int x;
	int y;
	int wall;
} pos;

int bfs()
{
	int x, y, wall, nx, ny;

	queue<pos> q;

	q.push({ 0, 0 , 0});
	visit[0][0][0] = visit[0][0][1] = true;
	_distance[0][0] = 1;
	
	while (!q.empty())
	{
		x = q.front().x;
		y = q.front().y;
		wall = q.front().wall;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			nx = x + dx[i], ny = y + dy[i];
			if ((nx >= 0 && nx < N) && (ny >= 0 && ny < M))
			{
				// 벽을 부순 적 X -> 벽 부수고 이동
				if (!wall && map[nx][ny] && !visit[nx][ny][wall + 1])
				{
					q.push({ nx, ny, 1 });
					visit[nx][ny][wall + 1] = true;
				}
				// 벽 부시지 않고 이동
				else if (!map[nx][ny] && !visit[nx][ny][wall])
				{
					q.push({ nx, ny, wall});
					visit[nx][ny][wall] = true;
				}
				_distance[nx][ny] = _distance[x][y] + 1;

				// 도착
				if (nx == N - 1 && ny == M - 1)
					return _distance[nx][ny];
			}
		}
	}

	return INF;
}



int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;

	string str;
	cin.ignore();

	for (int i = 0; i < N; i++)
	{
		getline(cin, str);
		for (int j = 0; j < M; j++)
		{
			map[i][j] = str[j] - '0';
		}
	}

	if (N == 1 && M == 1)
	{
		cout << 1;
		return 0;
	}
	else {
		ans = bfs();

		if (ans != INF)
			cout << ans;
		else
			cout << -1;
	}
	
}