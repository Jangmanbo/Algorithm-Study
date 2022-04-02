#include <iostream>
using namespace std;

int N, M;
int arr[9];
int visit[9] = { 0, };

void dfs(int cnt) {
	if (cnt > M) {
		for (int i = 1; i <= M; i++)
		{
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = 1; i <= N; i++)
	{
		if (!visit[i])
		{
			visit[i] = 1;
			arr[cnt] = i;
			dfs(cnt + 1);
			visit[i] = 0;
		}
	}
}

int main() {
	cin >> N >> M;
	dfs(1);
	return 0;
}