#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> virus;
vector<pair<int, int>> area;
vector<bool> comb;
int N, M, wall = 0;
int map[8][8];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

int bfs()
{
	bool check[8][8] = { false };	// 감염 체크 여부
	int x, y, nx, ny, danger = virus.size();	// 감염 지역

	queue<pair<int, int>> q;
	for (pair<int, int> v : virus)
		q.push(v);

	while (!q.empty())
	{
		x = q.front().first;
		y = q.front().second;
		q.pop();

		// 감염 지역의 상하좌우가 빈칸이면 감염 지역
		for (int i = 0; i < 4; i++)
		{
			nx = x + dx[i];
			ny = y + dy[i];
			
			// 감염되는 지역인 경우
			if ((0 <= nx && nx < N) && (0 <= ny && ny < M) && !map[nx][ny] && !check[nx][ny])
			{
				q.push({ nx, ny });
				danger++;
				check[nx][ny] = true;
			}
		}
	}

	return N * M - danger - wall - 3;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int ans = 0;
	cin >> N >> M;

	// 입력
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
			switch (map[i][j])
			{
			case 0:
				area.push_back({ i, j });
				break;
			case 1:
				wall++;
				break; 
			case 2:
				virus.push_back({ i, j });
				break;
			default:
				break;
			}
		}
	}

	// 3개의 벽을 세우는 조합을 구하기 위한 벡터
	for (int i = 0; i < (int)area.size() - 3; i++)
		comb.push_back(false);
	for (int i = 0; i < 3; i++)
		comb.push_back(true);

	vector<int> walls;	// 3개의 벽
	do
	{
		// 3개의 벽 세우기
		for (int i = 0; i < (int)comb.size(); i++)
		{
			if (comb[i])
			{
				map[area[i].first][area[i].second] = 1;
				walls.push_back(i);
			}
		}

		// 안전 영역 구하기
		ans = max(ans, bfs());

		// 세웠던 벽 철거
		for (int i : walls)
			map[area[i].first][area[i].second] = 0;

	} while (next_permutation(comb.begin(), comb.end()));

	cout << ans;
}