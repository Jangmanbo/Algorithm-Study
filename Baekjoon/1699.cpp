#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio();
	cin.tie(NULL);

	int N;
	cin >> N;
	
	vector<int> dp(N + 1);

	for (int i = 1; i <= N; i++)
	{
		dp[i] = i;	// 최대 개수

		for (int j = 1; j * j <= i; j++)
			dp[i] = min(dp[i], dp[i - j * j] + 1);
	}
	cout << dp[N];
}