#include <iostream>
#include <queue>
using namespace std;

int main()
{
	ios_base::sync_with_stdio();
	cin.tie(NULL);

	int T, M, num, mid, len;
	priority_queue<int> left;
	priority_queue<int, vector<int>, greater<int>> right;
	vector<int> ans;

	cin >> T;
	while (T--)
	{
		cin >> M;

		// 첫번째 수가 기준
		cin >> mid;
		ans.push_back(mid);

		for (int i = 1; i < M; i++)
		{
			cin >> num;
			if (num < mid)
				left.push(num);
			else
				right.push(num);

			// 홀수 번째
			if (!(i % 2))
			{
				if (left.size() < right.size())
				{
					left.push(mid);
					mid = right.top();
					right.pop();
				}
				else if (left.size() > right.size())
				{
					right.push(mid);
					mid = left.top();
					left.pop();
				}
				ans.push_back(mid);
			}
		}

		// 출력
		len = M / 2 + 1;
		cout << len;
		for (int i = 0; i < len; i++)
		{
			if (!(i % 10))
				cout << '\n';
			cout << ans[i] << ' ';
		}
		cout << '\n';

		// 초기화
		ans.clear();
		while (!left.empty())
			left.pop();
		while (!right.empty())
			right.pop();
	}
}