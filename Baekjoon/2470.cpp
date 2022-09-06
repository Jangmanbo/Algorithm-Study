#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
pair<int, int> ans;
vector<int> vec;

void input()
{
	int num;

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		vec.push_back(num);
	}

	sort(vec.begin(), vec.end());
}

// 투포인터
void solve()
{
	int start = 0, end = N - 1;
	long long sum, minimum = 2000000000;

	while (start < end)
	{
		sum = vec[start] + vec[end];

		// 0에 더 가까운지
		if (abs(sum) < minimum)
		{
			minimum = abs(sum);
			ans = { vec[start], vec[end] };
		}

		if (abs(sum) == sum)	// 양수
			end--;
		else	// 음수
			start++;
	}

	cout << ans.first << ' ' << ans.second;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solve();
}