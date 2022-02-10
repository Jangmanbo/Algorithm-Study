#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include  <algorithm>
using namespace std;

int R, C, ans = 0, cnt = 0;
int dir_i[4] = { 0,0,-1,1 };
int dir_j[4] = { -1,1,0,0 };
char map[20][20];
bool visit[26];

void dfs(int i, int j)
{
	cnt++;
	visit[map[i][j] - 'A'] = true;
	for (int dir = 0; dir < 4; dir++)
	{
		int new_i = i + dir_i[dir];
		int new_j = j + dir_j[dir];
		if ((0 <= new_i && new_i < R) && (0 <= new_j && new_j < C) && !visit[map[new_i][new_j] - 'A'])
		{
			dfs(new_i, new_j);
		}
	}
	ans = max(ans, cnt);
	cnt--;
	visit[map[i][j] - 'A'] = false;
}

int main() {
	string str;

	cin >> R >> C;
	cin.ignore();

	for (int i = 0; i < R; i++)
	{
		getline(cin, str);
		for (int j = 0; j < C; j++)
		{
			map[i][j] = str[j];
		}
	}

	dfs(0, 0);
	cout << ans;
}