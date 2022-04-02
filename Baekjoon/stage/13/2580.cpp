#include <iostream>
#include <vector>
using namespace std;

int map[9][9];

bool row[9][10];
bool col[9][10];
bool square[9][10];
vector<pair<int, int>> zero;	// ��ĭ ��ǥ

void input()
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cin >> map[i][j];

			if (map[i][j])
			{
				row[i][map[i][j]] = true;	// i�࿡ map[i][j] ����
				col[j][map[i][j]] = true;	// j���� map[i][j] ����
				square[(i / 3) * 3 + j / 3][map[i][j]] = true;	// n��° ���簢���� map[i][j] ����
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
	// ��� ��ĭ�� ä��
	if (n == zero.size())
		return true;

	int i = zero[n].first;
	int j = zero[n].second;
	for (int num = 1; num <= 9; num++)
	{
		// num�� (i, j)�� �� �� ������
		if (!row[i][num] && !col[j][num] && !square[(i / 3) * 3 + j / 3][num])
		{
			map[i][j] = num;
			row[i][num] = col[j][num] = square[(i / 3) * 3 + j / 3][num] = true;	// üũ
			if (dfs(n + 1))
				return true;
			row[i][num] = col[j][num] = square[(i / 3) * 3 + j / 3][num] = false;	// üũ ����
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