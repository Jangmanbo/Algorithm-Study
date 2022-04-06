#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	// (종료, 시작) 오름차순 정렬
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	int N, start, end, last_end = 0, meeting = 0;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> start >> end;
		pq.push({ end, start });
	}

	while (!pq.empty())
	{
		// 시작시간이 마지막 회의 종료 시간 이후면 채택
		if (pq.top().second >= last_end)
		{
			meeting++;
			last_end = pq.top().first;	// 마지막 회의 종료 시간 업데이트
		}
		pq.pop();
	}

	cout << meeting;
}