#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	stack<char> front, back;
	int N, len;
	cin >> N;
	cin.ignore();
	string str;
	char c;
	for (int i = 0; i < N; i++)
	{
		getline(cin, str);
		len = str.size();
		for (int j = 0; j < len; j++)
		{
			switch (str[j])
			{
			case '<':
				if (!front.empty())
				{
					back.push(front.top());
					front.pop();
				}
				break;
			case '>':
				if (!back.empty())
				{
					front.push(back.top());
					back.pop();
				}
				break;
			case'-':
				if (!front.empty())
					front.pop();
				break;
			default:
				front.push(str[j]);
				break;
			}
		}
		while (!front.empty())
		{
			back.push(front.top());
			front.pop();
		}
		while (!back.empty())
		{
			cout << back.top();
			back.pop();
		}
		cout<<"\n";
	}
}