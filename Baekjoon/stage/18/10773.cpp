#include <iostream>
#include <stack>
using namespace std;

int main() {
	int N, num;
	stack<int> stk;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		if (!num) stk.pop();
		else stk.push(num);
	}
	num = 0;
	while (!stk.empty())
	{
		num += stk.top();
		stk.pop();
	}
	cout << num;
}