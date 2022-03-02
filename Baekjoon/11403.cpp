#include <iostream>
using namespace std;

int N;
int map[100][100];

void dfs(int i, int j)
{
	for (int k = 0; k < N; k++)
	{
		// i에서 k로 가는 경로가 있으며 처음 체크하는 경우
		if (map[j][k] && !map[i][k])
		{
			map[i][k] = 1;
			dfs(i, k);
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	// 입력
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cin >> map[i][j];
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (map[i][j])
				dfs(i, j);
		}
	}

	// 출력
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cout << map[i][j] << ' ';
		cout << '\n';
	}
}