#include <iostream>
#include <string>
using namespace std;

int ans;
string A, B;
int dp[4001][4001];

void input()
{
	cin >> A;
	cin >> B;

	A = " " + A;
	B = " " + B;
}

void solve()
{
	int lenA = A.length(), lenB = B.length();
	for (int i = 1; i < lenA; i++)
	{
		for (int j = 1; j < lenB; j++)
		{
			if (A[i] == B[j])
			{
				dp[i][j] = dp[i - 1][j - 1] + 1;
				ans = max(ans, dp[i][j]);
			}
			else
				dp[i][j] = 0;
		}
	}

	cout << ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solve();
}