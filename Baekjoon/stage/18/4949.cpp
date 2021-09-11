#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
	int size;
	string str;
	bool VPS = true;
	stack<char> stk;
	while (getline(cin, str)) {
		if (str == ".") break;//프로그램 종료
		size = str.size();
		for (int i = 0; i < size; i++)
		{
			if (str[i] == '(' || str[i] == '[') stk.push(str[i]);
			else if (str[i] == ')') {
				if (!stk.empty() && stk.top() == '(') {
					stk.pop();
				}
				else {//VPS가 아님
					VPS = false;
					break;
				}
			}
			else if (str[i] == ']') {
				if (!stk.empty() && stk.top() == '[') {
					stk.pop();
				}
				else {//VPS가 아님
					VPS = false;
					break;
				}
			}
		}
		//결과 출력
		if (stk.empty() && VPS) cout << "yes" << "\n";
		else cout << "no" << "\n";

		//초기화
		VPS = true;
		stk = stack<char>();
	}
	return 0;
}

