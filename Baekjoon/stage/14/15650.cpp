#include <iostream>
using namespace std;

int N, M;
int arr[9];
int visit[9] = { 0, };

void dfs(int cnt, int before) {
	if (cnt > M) {
		for (int i = 1; i <= M; i++)
		{
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = before + 1; i <= N; i++)
	{
		if (!visit[i])
		{
			visit[i] = 1;
			arr[cnt] = i;
			dfs(cnt + 1, i);
			visit[i] = 0;
		}
	}
}

int main() {
	cin >> N >> M;
	dfs(1, 0);
	return 0;
}