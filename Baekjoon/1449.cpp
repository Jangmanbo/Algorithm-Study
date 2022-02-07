#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	// 물이 새는 위치 오름차순 정렬
	priority_queue<int, vector<int>, greater<int>> pq;
	// 새는 위치 개수, 테이프 길이, 새는 위치, 마지막 테이프가 커버할 수 있는 최대 위치, 테이프 개수
	int N, L, point, end_point = 0, tape = 0;
	cin >> N >> L;
	L--;	// L : 테이브가 커버할 수 있는 최대 길이

	for (int i = 0; i < N; i++)
	{
		cin >> point;
		pq.push(point);
	}

	while (!pq.empty())
	{
		if (pq.top() > end_point)
		{
			end_point = pq.top() + L;
			tape++;
		}
		pq.pop();
	}
	cout << tape;
}