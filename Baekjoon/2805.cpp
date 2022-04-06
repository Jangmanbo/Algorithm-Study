#include <iostream>
#include <vector>
using namespace std;

long long int N, M;
vector<int> vec;

// 절단기 높이가 mid일 때 필요한 만큼 가져갈 수 있는지
bool enough(long long int mid)
{
	long long int sum = 0;

	for (long long int length : vec)
	{
		if (length > mid)
			sum += length - mid;
	}

	if (sum >= M)
		return true;

	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	long long int length, mid, ans;
	long long int left = 0, right = 0;

	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		cin >> length;
		vec.push_back(length);
		right = max(length, right);	// right 초기값 = 나무 길이 최대값
	}

	// 이분탐색
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (enough(mid))	// 절단기 높이가 더 크거나 같아야 함
		{
			ans = mid;
			left = mid + 1;
		}
		else	// 절단기 높이가 더 작거나 같아야 함
			right = mid - 1;
	}
	cout << ans;
}