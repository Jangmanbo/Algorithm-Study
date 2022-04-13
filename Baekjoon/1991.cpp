#include <iostream>
using namespace std;

int N;
pair<int, int> node[26];

void input()
{
	char parent, son1, son2;

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> parent >> son1 >> son2;
		node[parent - 'A'] = { son1, son2 };
	}
}

void func1(char cur)
{
	if (cur != '.')
	{
		cout << cur;
		func1(node[cur - 'A'].first);
		func1(node[cur - 'A'].second);
	}
}

void func2(char cur)
{
	if (cur != '.')
	{
		func2(node[cur - 'A'].first);
		cout << cur;
		func2(node[cur - 'A'].second);
	}
}

void func3(char cur)
{
	if (cur != '.')
	{
		func3(node[cur - 'A'].first);
		func3(node[cur - 'A'].second);
		cout << cur;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	input();

	func1('A');
	cout << '\n';
	func2('A');
	cout << '\n';
	func3('A');
}