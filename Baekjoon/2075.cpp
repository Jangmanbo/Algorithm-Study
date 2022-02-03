#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, num;
	cin >> N;
	priority_queue<int, vector<int>, greater<int>> pq;

	for (int i = 0; i < N; i++)
	{
		cin >> num;
		pq.push(num);
	}
	for (int i = 1; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> num;
			pq.push(num);
		}
		for (int j = 0; j < N; j++)
		{
			pq.pop();
		}
	}
	cout << pq.top();
}