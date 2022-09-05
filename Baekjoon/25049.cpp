#include <iostream>
#include <algorithm>
#include <limits>
using namespace std;

int N;
long long sum = 0;
long long arr[500001];
long long dp[500001];
long long rdp[500001];	// ���������� ����� dp
long long dp_max[500001];	// dp�� ������� �ִ밪
long long rdp_max[500001];	// rdp�� ������� �ִ밪

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
		dp[i] = max(dp[i - 1] + arr[i], arr[i]);	// ���� �ε����� �������� �� �ִ� �κ���
		dp_max[i] = max(dp_max[i - 1], dp[i]);	// ��������� �ִ� �κ���

		// ������
		rdp[N - 1 - i] = max(rdp[N - i] + arr[N - 1 - i], arr[N - 1 - i]);
		rdp_max[N - 1 - i] = max(rdp_max[N - i], rdp[N - 1 - i]);
	}

	// dp_max[i-1], rdp_max[i] : i�� �������� ����/�������� �ִ� �κ���
	// �ٽ� �ȵ�� or ���� ������ �ٽ� ��� or �� ���� ��� �ٽ� ���
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