#include <iostream>
using namespace std;

int N, ans;
int arr[1000], dp[1000], rdp[1000];

void solve()
{
	cin >> N;

	// 가장 긴 증가 수열
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
		dp[i] = 1;
		for (int j = 0; j < i; j++)
		{
			if (arr[i] > arr[j] && dp[j] + 1 > dp[i])
				dp[i] = dp[j] + 1;
		}
	}

	// 가장 긴 감소 수열
	for (int i = N - 1; i >= 0; i--)
	{
		rdp[i] = 1;
		for (int j = N - 1; j > i; j--)
			if (arr[i] > arr[j] && rdp[j] + 1 > rdp[i])
				rdp[i] = rdp[j] + 1;

		ans = max(ans, dp[i] + rdp[i]);
	}

	cout << ans - 1;	// 자기 자신 중복 제거(-1)
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
}