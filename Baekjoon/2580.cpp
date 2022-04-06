#include <iostream>
#include <vector>
using namespace std;

int map[9][9];

bool row[9][10];
bool col[9][10];
bool square[9][10];
vector<pair<int, int>> zero;	// 빈칸 좌표

void input()
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cin >> map[i][j];

			if (map[i][j])
			{
				row[i][map[i][j]] = true;	// i행에 map[i][j] 존재
				col[j][map[i][j]] = true;	// j열에 map[i][j] 존재
				square[(i / 3) * 3 + j / 3][map[i][j]] = true;	// n번째 정사각형에 map[i][j] 존재
			}
			else
				zero.push_back({ i, j });
		}
	}
}

void output()
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
			cout << map[i][j] << ' ';
		cout << '\n';
	}
}

bool dfs(int n)
{
	// 모든 빈칸을 채움
	if (n == zero.size())
		return true;

	int i = zero[n].first;
	int j = zero[n].second;
	for (int num = 1; num <= 9; num++)
	{
		// num이 (i, j)에 들어갈 수 있으면
		if (!row[i][num] && !col[j][num] && !square[(i / 3) * 3 + j / 3][num])
		{
			map[i][j] = num;
			row[i][num] = col[j][num] = square[(i / 3) * 3 + j / 3][num] = true;	// 체크
			if (dfs(n + 1))
				return true;
			row[i][num] = col[j][num] = square[(i / 3) * 3 + j / 3][num] = false;	// 체크 해제
		}
	}
	return false;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	input();
	dfs(0);
	output();
}