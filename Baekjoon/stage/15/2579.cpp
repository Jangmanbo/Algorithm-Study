#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int* dp = new int[n + 1]();
	int* score = new int[n + 1]();

	cin >> score[1];
	dp[1] = score[1];
	if (n > 1) {
		cin >> score[2];
		dp[2] = score[1] + score[2];
	}
	for (int i = 3; i <= n; i++)
	{
		cin >> score[i];
		dp[i] = max(dp[i - 3] + score[i - 1] + score[i], dp[i - 2] + score[i]);
	}

	cout << dp[n];
}