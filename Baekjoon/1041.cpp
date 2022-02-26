#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio();
	cin.tie(NULL);

	long long N, total = 0;
	long long dice[6];
	int mv = 1;

	// �Է�
	cin >> N;
	for (int i = 0; i < 6; i++)
	{
		cin >> dice[i];
		mv = max(mv, (int)dice[i]);
		total += dice[i];
	}

	// ���� ���� �� �� �߿� ���� �� ���ϱ�
	vector<long long> vec = { min(dice[0], dice[5]), min(dice[1], dice[4]), min(dice[2], dice[3]) };
	sort(vec.begin(), vec.end());

	// N�� 1�� ���
	if (N == 1)
	{
		cout << total - mv;
		return 0;
	}

	// 3�� -> 4��
	// 2�� -> 4(N-2)+4(N-1)��
	// 1�� -> (N-2)^2+4(N-1)(N-2)��
	long long ans = (vec[0] + vec[1] + vec[2]) * 4 + (vec[0] + vec[1]) * (8 * N - 12) + vec[0] * (5 * N * N - 16 * N + 12);
	cout << ans;
}