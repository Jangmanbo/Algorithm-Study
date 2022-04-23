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
				// 스택의 top이 현재 연산자와 우선순위가 같거나 높으면 스택의 top 출력
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
			case ')':	// '('가 나올 때까지 출력
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