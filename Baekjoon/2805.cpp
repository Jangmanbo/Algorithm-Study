#include <iostream>
#include <vector>
using namespace std;

long long int N, M;
vector<int> vec;

// ���ܱ� ���̰� mid�� �� �ʿ��� ��ŭ ������ �� �ִ���
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
		right = max(length, right);	// right �ʱⰪ = ���� ���� �ִ밪
	}

	// �̺�Ž��
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (enough(mid))	// ���ܱ� ���̰� �� ũ�ų� ���ƾ� ��
		{
			ans = mid;
			left = mid + 1;
		}
		else	// ���ܱ� ���̰� �� �۰ų� ���ƾ� ��
			right = mid - 1;
	}
	cout << ans;
}