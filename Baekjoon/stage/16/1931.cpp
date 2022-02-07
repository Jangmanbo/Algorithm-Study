#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	// (����, ����) �������� ����
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
		// ���۽ð��� ������ ȸ�� ���� �ð� ���ĸ� ä��
		if (pq.top().second >= last_end)
		{
			meeting++;
			last_end = pq.top().first;	// ������ ȸ�� ���� �ð� ������Ʈ
		}
		pq.pop();
	}

	cout << meeting;
}