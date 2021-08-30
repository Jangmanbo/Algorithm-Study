#include <iostream>
using namespace std;


int main() {
	int T, N, M, priority, last = -1, ans = 0;
	int document[100];
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> N >> M;
		for (int i = 0; i < N; i++)
		{
			cin >> document[i];
		}
		priority = document[M];


		for (int i = 9; i > priority; i--)
		{
			for (int j = 0; j < N; j++)
			{
				if (document[j] == i) {
					last = j;
					ans++;
				}
			}
		}
		

		if (M > last) {
			for (int i = last + 1; i < M; i++)
			{
				if (document[i] == priority) ans++;
			}
		}
		else {
			for (int i = last + 1; i < N; i++)
			{
				if (document[i] == priority) ans++;
			}
			for (int i = 0; i < M; i++)
			{
				if (document[i] == priority) ans++;
			}
		}
		cout << ans + 1 << "\n";
		ans = 0;
		last = -1;
	}
	return 0;
}