#include <iostream>
#include <queue>
using namespace std;

struct compare {
	bool operator()(int a, int b)
	{
		if (abs(a) == abs(b))
			return a > b;
		else
			return abs(a) > abs(b);
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	priority_queue<int, vector<int>, compare> q;
	int N, num;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		if (num)
			q.push(num);
		else
		{
			if (q.empty())
				cout << "0\n";
			else
			{
				cout << q.top() << "\n";
				q.pop();
			}
		}
	}
}