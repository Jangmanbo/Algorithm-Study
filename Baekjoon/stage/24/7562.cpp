#include <iostream>
#include <queue>
#define MAX 300
using namespace std;


queue<pair<int, int>> q;
int dx[8] = { -2,-2,-1,-1,1,1,2,2 };
int dy[8] = { -1,1,-2,2,-2,2,-1,1 };
int N, ex, ey;

void bfs()
{
	int x, y, nx, ny;
	int times[MAX][MAX] = { 0 };

	while (!q.empty())
	{
		x = q.front().first;
		y = q.front().second;
		q.pop();

		// 현재 칸이 도착지면 종료
		if (x == ex && y == ey)
		{
			cout << times[ex][ey] << "\n";
			while (!q.empty())
				q.pop();
			return;
		}

		// 8가지 방향 중 현재 칸에서 갈 수 있는 방향 큐에 삽입
		for (int i = 0; i < 8; i++)
		{
			nx = x + dx[i];
			ny = y + dy[i];

			// 방문하지 않은 칸이면
			if ((0 <= nx && nx < N) && (0 <= ny && ny < N)
				&& !times[nx][ny])
			{
				q.push(make_pair(nx, ny));
				times[nx][ny] = times[x][y] + 1;
			}
		}
	}
};

int main() {
	int T, sx, sy;
	cin >> T;
	while (T--)
	{
		// 입력
		cin >> N;
		cin >> sx >> sy;
		cin >> ex >> ey;

		q.push(make_pair(sx, sy));
		bfs();
	}
}