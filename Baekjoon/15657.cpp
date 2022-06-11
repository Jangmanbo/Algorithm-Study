#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int ans[8];
int arr[8];

void dfs(int idx, int len)
{
	if (len == M)
	{
		for (int i = 0; i < M; i++)
			cout << ans[i] << ' ';
		cout << '\n';
		return;
	}

	for (int i = idx; i < N; i++)
	{
		ans[len] = arr[i];
		dfs(i, len + 1);
	}
}


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL);


	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	sort(arr, arr + N);

	dfs(0, 0);
}