#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
	ios_base::sync_with_stdio();
	cin.tie(NULL);

	int N, P, line, pret, ans = 0;
	cin >> N >> P;
	stack<int> s[7];

	for (int i = 0; i < N; i++)
	{
		cin >> line >> pret;
		
		// �̹� ������ ������ ������
		while (!s[line].empty())
		{
			// pret���� �� ���� ������ ������ �ִٸ� �հ��� ����
			if (s[line].top() > pret)
			{
				s[line].pop();
				ans++;
			}
			// ���� ������ ������ �����Ƿ� �հ��� ������ ��ȭ ����
			else if (s[line].top() == pret)
				break;
			// pret�� ���� �� ���� �� ����
			else
			{
				s[line].push(pret);
				ans++;
				break;
			}
		}

		// ó������ ������ �ִ� ������ ������ or pret���� �� ���� ������ ������ �־���
		if (s[line].empty())
		{
			s[line].push(pret);
			ans++;
		}
	}
	cout << ans;
}