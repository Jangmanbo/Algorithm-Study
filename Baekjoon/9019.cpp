#include <iostream>
#include <string>
#include <queue>
using namespace std;

bool visit[10000];

void bfs(int A, int B)
{
	int DSLR[4];
	char func[4] = { 'D', 'S', 'L', 'R' };

	int num;
	string inst;
	queue<pair<string, int>> q;

	q.push({ "", A });
	visit[A] = true;
	while (true)
	{
		inst = q.front().first, num = q.front().second;
		q.pop();

		if (B == num)
		{
			cout << inst << '\n';
			break;
		}

		// DSLR 연산 수행
		DSLR[0] = (num * 2) % 10000;
		DSLR[1] = (num == 0) ? 9999 : num - 1;
		DSLR[2] = num / 1000 + (num % 1000) * 10;
		DSLR[3] = num / 10 + (num % 10) * 1000;

		for (int i = 0; i < 4; i++)
		{
			if (!visit[DSLR[i]])
			{
				visit[DSLR[i]] = true;
				q.push({ inst + func[i], DSLR[i] });
			}
		}
	}
}

void init()
{
	for (int i = 0; i < 10000; i++)
		visit[i] = false;
}

void solve()
{
	int A, B;
	cin >> A >> B;
	bfs(A, B);
	init();
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	int T;
	cin >> T;

	while (T--)
		solve();
}