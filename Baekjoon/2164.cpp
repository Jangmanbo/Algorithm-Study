#include <iostream>
#include <queue>
using namespace std;


int main() {
	queue<int> q;
	int N, num;
	cin >> N;
	for (int i = 1; i <= N; i++)
		q.push(i);
	N--;
	for (int i = 0; i < N; i++)
	{
		q.pop();
		num = q.front();
		q.pop();
		q.push(num);
	}
	cout << q.front();
	return 0;
}