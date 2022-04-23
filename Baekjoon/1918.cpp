#include <iostream>
#include <stack>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	char c;
	stack<char> stk;

	while (c != '\n')
	{
		c = cin.get();
		if (c >= 'A' && c <= 'Z')
			cout << c;
		else
		{
			switch (c)
			{
				// ������ top�� ���� �����ڿ� �켱������ ���ų� ������ ������ top ���
			case '*':
			case '/':
				while (!stk.empty() && (stk.top() == '*' || stk.top() == '/'))
				{
					cout << stk.top();
					stk.pop();
				}
				stk.push(c);
				break;
			case '+':
			case '-':
				while (!stk.empty() && stk.top() != '(')
				{
					cout << stk.top();
					stk.pop();
				}
				stk.push(c);
				break;
			case '(':
				stk.push(c);
				break;
			case ')':	// '('�� ���� ������ ���
				while (stk.top() != '(')
				{
					cout << stk.top();
					stk.pop();
				}
				stk.pop();
				break;
			default:
				break;
			}
		}
	}
	while (!stk.empty())
	{
		cout << stk.top();
		stk.pop();
	}
}