#include <iostream>
#include <queue>
#define MAX 101
using namespace std;


queue<pair<int, int>> q;
bool map[MAX][MAX];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int N, M;

int bfs(int weight)
{
	int x, y, nx, ny;
	while (!q.empty())
	{
		x = q.front().first;
		y = q.front().second;
		q.pop();

		// 현재 위치의 상하좌우 중 쓰레기가 있으면 큐에 삽입
		for (int i = 0; i < 4; i++)
		{
			nx = x + dx[i];
			ny = y + dy[i];
			if ((1 <= nx && nx <= N) && (1 <= ny && ny <= M)
				&& map[nx][ny])
			{
				map[nx][ny] = false;
				q.push(make_pair(nx, ny));
				weight++;
			}
		}
	}
	return weight;
};

int main() {
	int K, r, c, mv = 0;
	
	// 쓰레기 위치 배열 (1-based)
	cin >> N >> M >> K;
	for (int i = 0; i < K; i++)
	{
		cin >> r >> c;
		map[r][c] = true;
	}


	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			// 쓰레기가 있으면서 아직 체크하지 않은 위치 (새로운 개별요소)
			if (map[i][j])
			{
				map[i][j] = false;
				q.push(make_pair(i, j));
				mv = max(mv, bfs(1));
			}
		}
	}

	cout << mv;
}