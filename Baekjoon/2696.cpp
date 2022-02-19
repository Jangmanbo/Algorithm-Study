#include <iostream>
#include <queue>
using namespace std;

int main()
{
	ios_base::sync_with_stdio();
	cin.tie(NULL);

	int T, M, num, mid, len;
	priority_queue<int> left;	// ���غ��� ���� �� (�ִ� ��)
	priority_queue<int, vector<int>, greater<int>> right;	// ���غ��� ū �� (�ּ� ��)
	vector<int> ans;

	cin >> T;
	while (T--)
	{
		cin >> M;

		cin >> mid;	// ù��° ���� ����
		ans.push_back(mid);	// ù��° ���� �׻� ����

		for (int i = 1; i < M; i++)
		{
			cin >> num;
			if (num < mid)
				left.push(num);
			else
				right.push(num);

			// Ȧ�� ��° ������ �߾Ӱ� ���ϱ�
			if (!(i % 2))
			{
				if (left.size() < right.size())
				{
					left.push(mid);
					mid = right.top();
					right.pop();
				}
				else if (left.size() > right.size())
				{
					right.push(mid);
					mid = left.top();
					left.pop();
				}
				ans.push_back(mid);
			}
		}

		// ���
		len = M / 2 + 1;
		cout << len;
		for (int i = 0; i < len; i++)
		{
			if (!(i % 10))
				cout << '\n';
			cout << ans[i] << ' ';
		}
		cout << '\n';

		// �ʱ�ȭ
		ans.clear();
		while (!left.empty())
			left.pop();
		while (!right.empty())
			right.pop();
	}
}