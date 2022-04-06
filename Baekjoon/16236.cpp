#include <iostream>
#include <queue>
using namespace std;

int N, sz = 2, remain = 2;
int map[20][20];
int dx[4] = { -1,0,0,1 };
int dy[4] = { 0,-1,1,0 };
pair<int, int> shark;

int bfs()
{
	int x, y, nx, ny, second = 1;
	bool check[20][20]{};

	queue<pair<int, int>> q;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;	// ��Ƹ��� ����� �ĺ� (��������)

	q.push(shark);
	q.push({ -1,-1 });	// 1��
	check[shark.first][shark.second] = true;

	while (!q.empty())
	{
		x = q.front().first;
		y = q.front().second;
		q.pop();

		// 1�� ����
		if (x == -1)
		{
			// ��Ƹ��� �� �ִ� ����Ⱑ �ִ��� Ȯ��
			if (!pq.empty())
			{
				shark = pq.top();	// ��ġ �̵�

				// ��ƸԱ�
				remain--;
				map[shark.first][shark.second] = 0;

				return second;
			}

			second++;
			if (!q.empty())
				q.push({ -1,-1 });
			continue;
		}

		for (int i = 0; i < 4; i++)
		{
			nx = x + dx[i], ny = y + dy[i];

			// ���� ���� ���� ĭ�̸鼭 �̵� ����
			if ((0 <= nx && nx < N) && (0 <= ny && ny < N) && !check[nx][ny] &&
			(!map[nx][ny] || sz >= map[nx][ny]))
			{
				// ���� �� �ִ� ����Ⱑ �ִ� ĭ
				if (map[nx][ny] && sz > map[nx][ny])
					pq.push({ nx, ny });	// ��Ƹ��� ����� �ĺ��� ����

				// �湮 ���
				q.push({ nx, ny });
				check[nx][ny] = true;
			}
		}
	}

	// ���� �� �ִ� ����Ⱑ ���� ���
	return 0;
}

void solve()
{
	int sec, ans = 0;
	while (true)
	{
		sec = bfs();
		if (sec)
		{
			ans += sec;
			if (!remain)
			{
				sz++;	// ��� ũ�� +1
				remain = sz;	// �Ծ�� �� ����� �� ����
			}
		}
		else 
		{
			cout << ans;
			break;
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 9)
			{
				shark = { i, j };
				map[i][j] = 0;
			}
		}
	}

	solve();
}