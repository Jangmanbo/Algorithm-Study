#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int N;
int map[25][25];
bool check[25][25];

int dx[4] = { 0,0,1,-1 };
int dy[4] = { -1,1,0,0 };

void input()
{
	cin >> N;

	string s;
	for (int i = 0; i < N; i++)
	{
		cin >> s;
		for (int j = 0; j < N; j++)
			map[i][j] = s[j] - '0';
	}
}

void solve()
{
	int x, y, nx, ny, house;
	queue<pair<int, int>> q;
	vector<int> vec;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (map[i][j] && !check[i][j])
			{
				check[i][j] = true;
				q.push({ i, j });
				house = 1;

				while (!q.empty())
				{
					x = q.front().first, y = q.front().second;
					q.pop();

					for (int k = 0; k < 4; k++)
					{
						nx = x + dx[k], ny = y + dy[k];
						if ((nx >= 0 && nx < N) && (ny >= 0 && ny < N)
							&& map[nx][ny] && !check[nx][ny])
						{
							q.push({ nx, ny });
							check[nx][ny] = true;
							house++;
						}
					}
				}

				vec.push_back(house);
			}
		}
	}

	sort(vec.begin(), vec.end());
	int len = vec.size();

	cout << len << '\n';
	for (int i = 0; i < len; i++)
		cout << vec[i] << '\n';
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solve();
}