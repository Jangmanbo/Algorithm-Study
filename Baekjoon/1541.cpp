#include <iostream>
#include <string>
using namespace std;

string str;
int ans;
bool offset;

void update(int start, int i)
{
	int num = stoi(str.substr(start, i - start));
	ans = offset ? (ans - num) : (ans + num);
}

void solve()
{
	cin >> str;

	int len = str.length();
	int num, start = 0;

	for (int i = 0; i < len; i++)
	{
		switch (str[i])
		{
		case '+':
			update(start, i);
			start = i + 1;
			break; 
		case '-':
			update(start, i);
			start = i + 1;
			offset = true;
			break;
		default:
			break;
		}
	}
	update(start, len);

	cout << ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
}