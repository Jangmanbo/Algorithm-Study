#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

int main() {
	deque<int> dq;
	int N, M, num, repeat = 0, ans = 0;

	cin >> N >> M;
	int* pop = new int[M];

	for (int i = 1; i <= N; i++)
		dq.push_back(i);

	for (int i = 0; i < M; i++)
		cin >> pop[i];

	for (int i = 0; i < M; i++)
	{
		//2번 연산 수행
		while (dq.front() != pop[i]) {
			num = dq.front();
			dq.pop_front();
			dq.push_back(num);
			repeat++;
		}
		//2번 연산, 3번 연산 중 작은 값을 더함
		ans += min(repeat, (int)dq.size() - repeat);
		dq.pop_front();
		repeat = 0;
	}

	cout << ans;
}