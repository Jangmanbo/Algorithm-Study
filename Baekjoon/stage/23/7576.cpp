#include <iostream>
#include <queue>
using namespace std;

int M, N, ripen, tomato = 0, day = 0;
int map[1000][1000];
queue<pair<int, int>> q;

void bfs()
{
	int x, y, nx, ny;
	int dx[4] = { -1,1,0,0 };
	int dy[4] = { 0,0 ,-1,1 };

	while (!q.empty())
	{
		x = q.front().first;
		y = q.front().second;
		q.pop();

		if (x == -1)	// �Ϸ� ��
		{
			if (q.empty())
				break;
			day++;
			q.push({ -1, -1 });
			continue;
		}

		for (int i = 0; i < 4; i++)
		{
			nx = x + dx[i], ny = y + dy[i];
			// ���� �丶���� �����¿쿡�� ������ �丶�� �߰�
			if ((nx >= 0 && nx < N)
				&& (ny >= 0 && ny < M)
				&& !map[nx][ny])
			{
				map[nx][ny] = 1;
				q.push({ nx, ny });
				ripen++;
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> M >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
			switch (map[i][j])
			{
			case 0:
				tomato++;
				break;
			case 1:
				tomato++;
				q.push({ i, j });
				break;
			default:
				break;
			}
		}
	}

	ripen = q.size();
	q.push({ -1,-1 });	// ������
	bfs();

	if (tomato == ripen)	// ��� �丶�䰡 �� ����
		cout << day;
	else
		cout << -1;
}