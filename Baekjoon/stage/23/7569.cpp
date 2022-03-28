#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int M, N, H, tomato = 0;
int map[100][100][100];
queue<vector<int>> q;

void bfs()
{
	int i, j, k, ni, nj, nk, day = -1, ripe = q.size();
	int di[6] = { -1,1,0,0,0,0 };
	int dj[6] = { 0,0,-1,1,0,0 };
	int dk[6] = { 0,0,0,0,-1,1 };

	q.push({ -1,-1,-1 });	// �Ϸ� ����
	while (!q.empty())
	{
		i = q.front()[0], j = q.front()[1], k = q.front()[2];
		q.pop();

		if (i == -1)
		{
			day++;
			if (!q.empty())
				q.push({ -1,-1,-1 });	// �Ϸ� ����
			continue;
		}

		for (int dir = 0; dir < 6; dir++)
		{
			ni = i + di[dir], nj = j + dj[dir], nk = k + dk[dir];
			// ������ ĭ�� ���� ���� �丶�䰡 ������
			if ((0 <= ni && ni < H) && (0 <= nj && nj < N) && (0 <= nk && nk < M)
				&& !map[ni][nj][nk])
			{
				// �丶�� ����
				map[ni][nj][nk] = 1;
				ripe++;

				q.push({ ni, nj, nk });
			}
		}
	}

	if (tomato == ripe)	// �丶�� �� ����
		cout << day;
	else	// ������ �丶�� ����
		cout << -1;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	// �Է�
	cin >> M >> N >> H;
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < M; k++)
			{
				cin >> map[i][j][k];
				switch (map[i][j][k])
				{
				case 1:
					q.push({ i, j, k });
				case 0:
					tomato++;
					break;
				default:
					break;
				}
			}
		}
	}

	bfs();
}