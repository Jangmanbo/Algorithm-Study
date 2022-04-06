#include <iostream>
#include <stack>
using namespace std;

int main()
{
	ios_base::sync_with_stdio();
	cin.tie(NULL);

	int A, num, idx;
	stack<int> stk;	// 수열, 정답

	// 입력
	cin >> A;
	int* arr = new int[A];	// 수열
	int* ans = new int[A];	// 오큰수 배열
	for (int i = 0; i < A; i++)
		cin >> arr[i];

	// 역순으로 오큰수 구하기
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

	// 출력
	for (int i = 0; i < A; i++)
		cout << ans[i] << ' ';
}