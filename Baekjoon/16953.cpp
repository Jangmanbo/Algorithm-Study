#include <iostream>
#include <queue>
using namespace std;

#define MAX 1000000000

long long A, B;

bool bfs()
{
	int ans = 2;
	long long op1, op2;
	queue<long long> q;

	q.push(A);

	while (!q.empty())
	{
		int s = q.size();
		while (s--)
		{
			op1 = q.front() * 2;
			op2 = q.front() * 10 + 1;
			q.pop();

			if (op1 == B || op2 == B)
			{
				cout << ans;
				return true;
			}
			if (op1 <= B)
				q.push(op1);
			if (op2 <= B)
				q.push(op2);
		}
		ans++;
	}
	return false;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> A >> B;
	if (!bfs())
		cout << -1;
}