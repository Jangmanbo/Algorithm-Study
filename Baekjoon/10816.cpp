#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



int main() {
	ios_base::sync_with_stdio();
	cin.tie(NULL);
	
	vector<int> cards;	// 카드 숫자
	vector<int> goals;	// 개수가 궁금한 숫자
	int N, M, num;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> num;
		cards.push_back(num);
	}

	sort(cards.begin(), cards.end());	// 오름차순 정렬

	cin >> M;

	for (int i = 0; i < M; i++)
	{
		cin >> num;
		goals.push_back(num);
	}

	for (int i = 0; i < M; i++)
	{
		// (목표값의 마지막 위치 + 1) - 목표값의 첫번째 위치 = 목표값의 개수
		cout << upper_bound(cards.begin(), cards.end(), goals[i]) - lower_bound(cards.begin(), cards.end(), goals[i]) << " ";
	}
}