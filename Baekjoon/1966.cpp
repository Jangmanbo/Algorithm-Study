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
			q.pop(); //queue에서 문서를 pop

			if (document.second != pq.top()) {//가장 높은 중요도가 아닌 경우
				q.push(document);//문서를 다시 push
			}
			else {//가장 높은 중요도인 경우
				pq.pop();
				ans++;
				if (document.first == M) {//현재 문서가 M번째 문서인 경우
					cout << ans << "\n";
					break;
				}
			}
		}
		//초기화
		q = queue<pair<int, int>>();
		pq = priority_queue<int>();
		ans = 0;
	}
	return 0;
}