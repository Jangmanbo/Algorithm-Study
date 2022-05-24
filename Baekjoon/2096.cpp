#include <iostream>
using namespace std;

int N;
int max_dp[3], min_dp[3];

void solve()
{
	int input[3];
	int temp[3];
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < 3; j++)
			cin >> input[j];

		// 최대
		temp[0] = max(max_dp[0], max_dp[1]) + input[0];
		temp[1] = max(max(max_dp[0], max_dp[1]), max_dp[2]) + input[1];
		temp[2] = max(max_dp[1], max_dp[2]) + input[2];
		max_dp[0] = temp[0], max_dp[1] = temp[1], max_dp[2] = temp[2];

		// 최소
		temp[0] = min(min_dp[0], min_dp[1]) + input[0];
		temp[1] = min(min(min_dp[0], min_dp[1]), min_dp[2]) + input[1];
		temp[2] = min(min_dp[1], min_dp[2]) + input[2];
		min_dp[0] = temp[0], min_dp[1] = temp[1], min_dp[2] = temp[2];
	}
}

void print()
{
	cout << max(max(max_dp[0], max_dp[1]), max_dp[2]) << ' ';
	cout << min(min(min_dp[0], min_dp[1]), min_dp[2]);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	solve();
	print();
}