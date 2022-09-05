#include <iostream>
#include <algorithm>
#include <limits>
using namespace std;

int N;
long long sum = 0;
long long arr[500001];
long long dp[500001];
long long rdp[500001];	// 역방향으로 계산한 dp
long long dp_max[500001];	// dp의 현재까지 최대값
long long rdp_max[500001];	// rdp의 현재까지 최대값

void input()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
		sum += arr[i];
	}
}

void solve()
{
	dp[0] = dp_max[0] = arr[0];
	rdp[N - 1] = rdp_max[N - 1] = arr[N - 1];

	for (int i = 1; i < N; i++)
	{
		dp[i] = max(dp[i - 1] + arr[i], arr[i]);	// 현재 인덱스를 포함했을 때 최대 부분합
		dp_max[i] = max(dp_max[i - 1], dp[i]);	// 현재까지의 최대 부분합

		// 역방향
		rdp[N - 1 - i] = max(rdp[N - i] + arr[N - 1 - i], arr[N - 1 - i]);
		rdp_max[N - 1 - i] = max(rdp_max[N - i], rdp[N - 1 - i]);
	}

	// dp_max[i-1], rdp_max[i] : i를 기준으로 왼쪽/오른쪽의 최대 부분합
	// 다시 안듣기 or 한쪽 구간만 다시 듣기 or 두 구간 모두 다시 듣기
	long long plus = 0;
	for (int i = 1; i < N; i++)
		plus = max({ plus, dp_max[i - 1], rdp_max[i], dp_max[i - 1] + rdp_max[i] });

	cout << sum + plus;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solve();
}