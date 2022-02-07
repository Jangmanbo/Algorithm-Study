#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	// ���� ���� ��ġ �������� ����
	priority_queue<int, vector<int>, greater<int>> pq;
	// ���� ��ġ ����, ������ ����, ���� ��ġ, ������ �������� Ŀ���� �� �ִ� �ִ� ��ġ, ������ ����
	int N, L, point, end_point = 0, tape = 0;
	cin >> N >> L;
	L--;	// L : ���̺갡 Ŀ���� �� �ִ� �ִ� ����

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