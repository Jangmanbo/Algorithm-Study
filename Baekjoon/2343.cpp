#include <iostream>
using namespace std;

int N;
int lectures[100000];

bool enough(int blueray, long long int capacity)
{
	long long int remain = 0;
	for (int i = 0; i < N; i++)
	{
		if (remain - lectures[i] >= 0)	// ���� ���� �ִ� ��緹�̷� ����� ���
			remain -= lectures[i];
		else	// �� ��緹�̸� ��� �ϴ� ���
		{
			blueray--;
			remain = capacity - lectures[i];

			if (blueray < 0 || remain < 0)	// ���� ��緹�̰� ���ų� �� ��緹�̷ε� ���Ǹ� ���� �� ����
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

	// ���� �ð� �迭
	for (int i = 0; i < N; i++)
	{
		cin >> lectures[i];
		right += lectures[i];
	}


	// �̺� Ž��
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