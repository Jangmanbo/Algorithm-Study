#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



int main() {
	ios_base::sync_with_stdio();
	cin.tie(NULL);
	
	vector<int> cards;	// ī�� ����
	vector<int> goals;	// ������ �ñ��� ����
	int N, M, num;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> num;
		cards.push_back(num);
	}

	sort(cards.begin(), cards.end());	// �������� ����

	cin >> M;

	for (int i = 0; i < M; i++)
	{
		cin >> num;
		goals.push_back(num);
	}

	for (int i = 0; i < M; i++)
	{
		// (��ǥ���� ������ ��ġ + 1) - ��ǥ���� ù��° ��ġ = ��ǥ���� ����
		cout << upper_bound(cards.begin(), cards.end(), goals[i]) - lower_bound(cards.begin(), cards.end(), goals[i]) << " ";
	}
}