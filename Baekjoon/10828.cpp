#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
	int N, num;
	string str;
	stack<int> stk;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> str;
		if (str == "push") {
			cin >> num;
			stk.push(num);
		}
		else if (str == "pop") {
			if (stk.empty()) cout << -1 << "\n";
			else {
				cout << stk.top() << "\n";
				stk.pop();
			}
		}
		else if (str == "size") {
			cout << stk.size() << "\n";
		}
		else if (str == "empty") {
			cout << stk.empty() << "\n";
		}
		else if (str == "top") {
			if (stk.empty()) cout << -1 << "\n";
			else cout << stk.top() << "\n";
		}
	}
}