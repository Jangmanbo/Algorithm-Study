#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<pair<int, int>> vec;
int dp[501];

void input()
{
	cin >> N;
	
	int left, right;
	for (int i = 0; i < N; i++)
	{
		cin >> left >> right;
		vec.push_back({ right, left });
	}

	sort(vec.begin(), vec.end());
}

void solve()
{
	int ans = 0;
	for (int i = 0; i < N; i++)
	{
		dp[i] = 1;
		for (int j = 0; j < i; j++)
		{
			if (vec[i].second > vec[j].second && dp[j] + 1 > dp[i])
			{
				dp[i] = dp[j] + 1;
				ans = max(ans, dp[i]);
			}
		}
	}

	cout << N - ans;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solve();
}