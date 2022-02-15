#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int N, M;
bool user[101][101] = { false };
int bacon[101][101] = { 0 };
queue<pair<int, int>> q;

void bfs()
{
	int other, num;
	// �� �������� �ٸ� �������� ������ ���ϱ�
	for (int i = 1; i <= N; i++)
	{
		// 1�ܰ�
		for (int j = 1; j <= N; j++)
		{
			if (user[i][j])
			{
				q.push(make_pair(j, 1));
				bacon[i][j] = 1;
			}				
		}
		// 2�ܰ� �̻�
		while (!q.empty())
		{
			other = q.front().first;
			num = q.front().second;
			q.pop();

			// ���� �������� ������ ���� ���
			for (int j = 1; j <= N; j++)
			{
				if (user[other][j] && !bacon[i][j] && i != j)
				{
					q.push(make_pair(j, num + 1));
					bacon[i][j] = num + 1;
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio();
	cin.tie(NULL);

	int user1, user2, cur;
	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		cin >> user1 >> user2;
		user[user1][user2] = true;
		user[user2][user1] = true;
	}

	bfs();

	stack<pair<int, int>> s;	// �׻� �ϳ��� ���Ҹ� ����, (����, �ɺ� ������)
	s.push(make_pair(0, 500000));
	// �������� �ɺ� �������� ���� ���ؼ� �ּҰ� ã��
	for (int i = 1; i <= N; i++)
	{
		cur = 0;
		for (int j = 1; j <= N; j++)
			cur += bacon[i][j];

		if (cur < s.top().second)
		{
			s.pop();
			s.push(make_pair(i, cur));
		}
	}
	cout << s.top().first;
}