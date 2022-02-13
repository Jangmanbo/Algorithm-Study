#include <iostream>
using namespace std;

int N;
int lectures[100000];

bool enough(int blueray, long long int capacity)
{
	long long int remain = 0;
	for (int i = 0; i < N; i++)
	{
		if (remain - lectures[i] >= 0)	// 현재 쓰고 있는 블루레이로 충분한 경우
			remain -= lectures[i];
		else	// 새 블루레이를 써야 하는 경우
		{
			blueray--;
			remain = capacity - lectures[i];

			if (blueray < 0 || remain < 0)	// 남은 블루레이가 없거나 새 블루레이로도 강의를 담을 수 없음
				return false;
		}
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio();
	cin.tie(NULL);

	int M;
	long long int ans, mid, right = 0, left = 1;
	cin >> N >> M;

	// 강의 시간 배열
	for (int i = 0; i < N; i++)
	{
		cin >> lectures[i];
		right += lectures[i];
	}


	// 이분 탐색
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (enough(M, mid))
		{
			ans = mid;
			right = mid - 1;
		}
		else
			left = mid + 1;
	}
	cout << ans;
}