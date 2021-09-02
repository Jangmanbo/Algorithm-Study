#include <iostream>
#include <queue>
using namespace std;

int main() {
	int T, N, M, priority, ans = 0;
	pair<int, int> document;
	queue<pair<int, int>> q;
	priority_queue<int> pq;

	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> N >> M;
		for (int j = 0; j < N; j++)
		{
			cin >> priority;
			q.push(make_pair(j, priority));
			pq.push(priority);
		}
		while (!q.empty())
		{
			document = q.front();
			q.pop(); //queue���� ������ pop

			if (document.second != pq.top()) {//���� ���� �߿䵵�� �ƴ� ���
				q.push(document);//������ �ٽ� push
			}
			else {//���� ���� �߿䵵�� ���
				pq.pop();
				ans++;
				if (document.first == M) {//���� ������ M��° ������ ���
					cout << ans << "\n";
					break;
				}
			}
		}
		//�ʱ�ȭ
		q = queue<pair<int, int>>();
		pq = priority_queue<int>();
		ans = 0;
	}
	return 0;
}