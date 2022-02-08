#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main() {
	queue<pair<int, int>> q;
	int N, M;
	string str;
	cin >> N >> M;
	cin.ignore();

	
	int** map = new int* [N];	// ���� �迭
	int** distance = new int* [N];	// ������κ����� �Ÿ� �迭
	bool** visit = new bool* [N];	// �湮 �迭

	for (int i = 0; i < N; i++)
	{
		map[i] = new int[M];
		distance[i] = new int[M]();
		visit[i] = new bool[M]();
		getline(cin, str);
		for (int j = 0; j < M; j++)
		{
			map[i][j] = str[j] - '0';
		}
	}

	int new_x, new_y, x, y;

	// �ʱ�ȭ
	q.push({ 0, 0 });
	distance[0][0] = 1;
	visit[0][0] = true;

	// ���� (�����¿�)
	int dir_x[4] = { 0,0,-1,1 };
	int dir_y[4] = { -1,1,0,0 };

	while (!q.empty())
	{
		x = q.front().first;
		y = q.front().second;
		q.pop();

		// �湮���� ����+�̵��� �� �ִ� ��ġ�� ť�� ����
		for (int i = 0; i < 4; i++)
		{
			new_x = x + dir_x[i];
			new_y = y + dir_y[i];
			if ((0 <= new_x && new_x < M) && (0 <= new_y && new_y < N)
				&& !visit[new_y][new_x] && map[new_y][new_x] == 1)
			{
				q.push({ new_x, new_y });
				visit[new_y][new_x] = true;
				distance[new_y][new_x] = distance[y][x] + 1;
			}
		}
	}

	cout << distance[N - 1][M - 1];
}