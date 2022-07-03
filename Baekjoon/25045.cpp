#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

long long N, M;
priority_queue<long long> A;
priority_queue<long long, vector<long long>, greater<long long>> B;

void input()
{
	long long num;

	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		cin >> num;
		A.push(num);
	}
	for (int i = 0; i < M; i++)
	{
		cin >> num;
		B.push(num);
	}

}

void solve()
{
	long long answer = 0;
	long long Ai, Bi;
	while (!A.empty() && !B.empty())
	{
		Ai = A.top();
		Bi = B.top();
		B.pop();
		if (Ai - Bi >= 0)
		{
			A.pop();
			answer += Ai - Bi;
		}
	}

	cout << answer;
}


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	input();
	solve();
}