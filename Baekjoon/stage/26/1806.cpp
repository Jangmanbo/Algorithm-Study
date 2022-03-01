#include <iostream>
using namespace std;

int arr[100000];

// 투포인터
int main()
{
	int N, start = 0, end = 0, ans = 100000;
	long long S;

	cin >> N >> S;

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	int sum = arr[0];
	while (start <= end && end < N)
	{
		if (sum >= S)
		{
			ans = min(ans, end - start + 1);
			sum -= arr[start];
			start++;
		}
		else
		{
			end++;
			sum += arr[end];
		}
	}

	if (ans == 100000)
		cout << 0;
	else
		cout << ans;
}