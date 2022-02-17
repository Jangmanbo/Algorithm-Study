#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio();
	cin.tie(NULL);

	string name;
	cin >> name;

	int len = (int)name.length();
	int* arr = new int[26]();	// �� ���ĺ��� ����
	char* ans = new char[len]();	// ���� ���� �Ӹ����
	int nt, cur = 0;

	for (int i = 0; i < len; i++)
		arr[name[i] - 'A']++;

	for (int i = 0; i < 26; i++)
	{
		if (!(arr[i] % 2))	// ���ĺ��� ¦����
		{
			nt = cur + arr[i] / 2;
			while (cur < nt)
			{
				ans[cur] = i + 'A';
				ans[len - cur - 1] = i + 'A';
				cur++;
			}
		}
		else	// ���ĺ��� Ȧ����
		{
			// �̸� ���̰� ¦���ų� �ռ� Ȧ������ ���ĺ��� �־��ٸ� �Ӹ���� �Ұ���
			if (len % 2 == 0 || ans[len / 2] != '\0')
			{
				cout << "I'm Sorry Hansoo";
				return 0;
			}
			else
			{
				nt = cur + arr[i] / 2;
				while (cur < nt)
				{
					ans[cur] = i + 'A';
					ans[len - cur - 1] = i + 'A';
					cur++;
				}
				ans[len / 2] = i + 'A';
			}
		}
	}

	for (int i = 0; i < len; i++)
		cout << ans[i];
}