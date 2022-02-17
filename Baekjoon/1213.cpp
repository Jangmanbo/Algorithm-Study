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
	int* arr = new int[26]();	// 각 알파벳의 개수
	char* ans = new char[len]();	// 가장 빠른 팰린드롬
	int nt, cur = 0;

	for (int i = 0; i < len; i++)
		arr[name[i] - 'A']++;

	for (int i = 0; i < 26; i++)
	{
		if (!(arr[i] % 2))	// 알파벳이 짝수개
		{
			nt = cur + arr[i] / 2;
			while (cur < nt)
			{
				ans[cur] = i + 'A';
				ans[len - cur - 1] = i + 'A';
				cur++;
			}
		}
		else	// 알파벳이 홀수개
		{
			// 이름 길이가 짝수거나 앞서 홀수개인 알파벳이 있었다면 팰린드롬 불가능
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