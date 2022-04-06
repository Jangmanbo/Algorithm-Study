#include <iostream>
#include <stack>
using namespace std;

int main()
{
	ios_base::sync_with_stdio();
	cin.tie(NULL);

	int A, num, idx;
	stack<int> stk;	// ����, ����

	// �Է�
	cin >> A;
	int* arr = new int[A];	// ����
	int* ans = new int[A];	// ��ū�� �迭
	for (int i = 0; i < A; i++)
		cin >> arr[i];

	// �������� ��ū�� ���ϱ�
	for (int i = A - 1; i >= 0; i--)
	{
		while (!stk.empty() && stk.top() <= arr[i])
			stk.pop();
		if (stk.empty())
			ans[i] = -1;
		else
			ans[i] = stk.top();

		stk.push(arr[i]);
	}

	// ���
	for (int i = 0; i < A; i++)
		cout << ans[i] << ' ';
}