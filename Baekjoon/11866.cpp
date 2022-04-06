#include <iostream>
#include <queue>
using namespace std;


int main() {
	queue<int> q, ans;
	int N, K, num;
	cin >> N >> K;

	K--;
	for (int i = 1; i <= N; i++)
		q.push(i);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < K; j++)
		{
			num = q.front();
			q.pop();
			q.push(num);
		}
		num = q.front();
		q.pop();
		ans.push(num);
	}

	N--;
	cout << "<";
	for (int i = 0; i < N; i++) {
		cout << ans.front() << ", ";
		ans.pop();
	}
	cout << ans.front() << ">";
	return 0;
}