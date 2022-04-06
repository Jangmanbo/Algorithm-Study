#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
	int N;
	string str;
	stack<char> stk;
	bool VPS = true;
	cin >> N;
	for (int i = 0; i < N && cin >> str; i++)
	{
		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] == '(') stk.push(str[i]);
			else {
				if (!stk.empty() && stk.top() == '(') stk.pop();
				else {
					VPS = false;
					break;
				}
			}
		}
		if (VPS && stk.empty()) cout << "YES" << "\n";
		else cout << "NO" << "\n";
		VPS = true;
		while (!stk.empty()) {
			stk.pop();
		}
	}
}