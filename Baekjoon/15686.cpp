#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// ���Ʈ ����
int main() {
	ios_base::sync_with_stdio();
	cin.tie(NULL);

	int N, M, kind, distance, city_distance, ans = 10000;
	bool check;
	vector<pair<int, int>> house;	// �� ��ǥ
	vector<pair<int, int>> store;	// ġŲ�� ��ǥ

	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> kind;
			switch (kind)
			{
			case 1:
				house.push_back(make_pair(i, j));
				break;
			case 2:
				store.push_back(make_pair(i, j));
				break;
			default:
				break;
			}
		}
	}

	//������ �� ġŲ���� (ġŲ �Ÿ�, ġŲ�� ��ǥ)
	vector<vector<pair<int, pair<int, int>>>> dis_vec(house.size());

	for (int i = 0; i < house.size(); i++)
	{
		for (pair<int, int> s : store)
		{
			distance = abs(house[i].first - s.first) + abs(house[i].second - s.second);
			dis_vec[i].push_back(make_pair(distance, s));
		}
		sort(dis_vec[i].begin(), dis_vec[i].end());
	}

	vector<bool> comb;	// ������ ���ϱ� ���� ����

	for (int i = 0; i < store.size() - M; i++)
		comb.push_back(false);

	for (int i = 0; i < M; i++)
		comb.push_back(true);


	do
	{
		city_distance = 0;	// ���� ������ ���� ġŲ �Ÿ�
		// ���� ���տ��� ġŲ �Ÿ� ���ϱ�
		for (vector<pair<int, pair<int, int>>> house : dis_vec)
		{
			check = false;
			// ����� ġŲ������ ���� ���տ� �ִ��� ����
			for (pair<int, pair<int, int>> dis : house)
			{
				for (int i = 0; i < comb.size(); i++)
				{
					// ���տ� �����ϸ�
					if (comb[i] && store[i] == dis.second)
					{
						city_distance += dis.first;
						check = true;
						break;
					}
				}
				if (check)
					break;
			}
		}
		ans = min(ans, city_distance);
	} while (next_permutation(comb.begin(), comb.end()));

	cout << ans;
}