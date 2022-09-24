#include <iostream>
using namespace std;

int N, M, x, y, d;
int clean;	// û�� Ƚ��
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
int map[50][50];
bool check[50][50];	// û�� ����

int new_direction(int d, int turn)
{
	int nd = d + turn;
	return nd < 0 ? nd + 4 : nd;
}

void input()
{
	cin >> N >> M;
	cin >> x >> y >> d;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
		}
	}
}

void solve()
{
	int nd, nx, ny, check_dir;
	while (true)
	{
		if (!check[x][y])	// 1. ���� ��ġ û��
		{
			check[x][y] = true;
			clean++;
		}

		check_dir = 0;	// 2������ �� ���� üũ�ߴ���
		do
		{
			nd = new_direction(d, -1);
			nx = x + dx[nd], ny = y + dy[nd];

			// 2-1. ���� ���⿡ ���� û������ ���� ���� ����
			if (!check[nx][ny] && map[nx][ny] == 0)
			{
				x = nx, y = ny, d = nd;
				break;
			}
			// 2-2. ���� ���⿡ û���� ���� X
			else
				d = nd;

			check_dir++;
			if (check_dir == 4)		// 2-3 or 2-4
			{
				nd = new_direction(d, -2);
				nx = x + dx[nd], ny = y + dy[nd];	// ���� ����

				// 2-3. ��ĭ ����
				if (map[nx][ny] == 0)
				{
					check_dir = 0;
					x = nx, y = ny;
				}
				// 2-4. �۵� ����
				else
					return;
			}
		} while (true);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solve();

	cout << clean;
}