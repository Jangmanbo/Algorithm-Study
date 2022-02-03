#include <iostream>
#include <stack>
#include <map>
#include <string>
using namespace std;

void find_operand(stack<double>& stk, double& op1, double& op2)
{
	op2 = stk.top();
	stk.pop();
	op1 = stk.top();
	stk.pop();
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, len;
	double num, op1, op2;
	stack<double> stk;
	map<char, double> m;
	string str;

	cin >> N;
	cin.ignore();

	getline(cin, str);
	len = str.size();

	for (int i = 0; i < N; i++)
	{
		cin >> num;
		m.insert({ 65 + i, num });
	}

	// �����ڸ� ������ 2���� �ǿ����ڸ� pop�ϰ� �����Ͽ� �ٽ� push
	for (int i = 0; i < len; i++)
	{
		switch (str[i])
		{
		case '+':
			find_operand(stk, op1, op2);
			stk.push(op1 + op2);
			break;
		case '-':
			find_operand(stk, op1, op2);
			stk.push(op1 - op2);
			break;
		case '*':
			find_operand(stk, op1, op2);
			stk.push(op1 * op2);
			break;
		case '/':
			find_operand(stk, op1, op2);
			stk.push(op1 / op2);
			break;
		default:
			stk.push(m[str[i]]);
			break;
		}
	}

	// �Ҽ��� ��� ���� ����
	cout << fixed;
	cout.precision(2);

	cout << stk.top();
}