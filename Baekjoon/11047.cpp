#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	int N, K, ans = 0;
	int arr[10];
    cin >> N >> K;

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	for (int i = N-1; i >= 0; i--)
	{
		if (K - arr[i] >= 0)
		{
			ans += K / arr[i];
			K -= K / arr[i] * arr[i];
		}
		if (K == 0)
			break;
	}

	cout << ans;
}