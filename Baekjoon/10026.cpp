#include <iostream>
#include <string>
#include <queue>
using namespace std;

char map[100][100];
bool visit[100][100];

int N;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };

int bfs()
{
	queue<pair<int, int>> q;
	char color;
	int x, y, nx, ny, section = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (visit[i][j])
				continue;

			section++;
			visit[i][j] = true;
			q.push({ i, j });
			color = map[i][j];

			while (!q.empty())
			{
				x = q.front().first, y = q.front().second;
				q.pop();
				for (int k = 0; k < 4; k++)
				{
					nx = x + dx[k], ny = y + dy[k];
					if ((0 <= nx && nx < N) && (0 <= ny && ny < N) 
						&& !visit[nx][ny] && map[nx][ny] == color)
					{
						q.push({ nx, ny });
						visit[nx][ny] = true;
					}
				}
			}
		}
	}
	return section;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	string str;
	cin >> N;

	cin.ignore();
	for (int i = 0; i < N; i++)
	{
		getline(cin, str);
		for (int j = 0; j < N; j++)
			map[i][j] = str[j];
	}

	int normal = bfs();

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			visit[i][j] = false;
			if (map[i][j] == 'G')
				map[i][j] = 'R';
		}
	}

	int weak = bfs();

	cout << normal << ' ' << weak;
}