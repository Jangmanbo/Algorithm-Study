#include <iostream>
#include <string>
#include <stack>
using namespace std;

string str;
stack<char> stk;
stack<pair<char, int>> pass;

void solve()
{
	int last = str.size() - 1;
	int idx = last;

	char c;

	while (!stk.empty())
	{
		c = stk.top();
		stk.pop();

		if (c == str[idx])
		{
			if (idx == 0)
			{
				// 폭발
				for (int i = 0; i < last; i++)
					pass.pop();

				if (!pass.empty() && pass.top().second)
					idx = pass.top().second - 1;
				else
					idx = last;
			}
			else
			{
				pass.push({ c, idx });
				idx--;
			}
		}
		else if (c == str[last])
		{
			idx = last;
			pass.push({ c, idx });
			
			if (idx == 0)
			{
				// 폭발
				for (int i = 0; i < last; i++)
					pass.pop();
				idx = last;
				continue;
			}
			idx--;
		}
		else
			pass.push({ c, 0 });
	}

}

void input()
{
	cin >> str;	// 문자열 입력
	int len = str.size();

	for (int i = 0; i < len; i++)
		stk.push(str[i]);

	cin >> str;	// 폭발 문자열 입력
}

void print()
{
	if (pass.empty())
		cout << "FRULA";
	else
	{
		do {
			cout << pass.top().first;
			pass.pop();
		} while (!pass.empty());
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	input();

	solve();

	print();
}