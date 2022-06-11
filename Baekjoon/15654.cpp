#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int ans[8];
int arr[8];
bool check[8];

void dfs(int len)
{
	if (len == M)
	{
		for (int i = 0; i < M; i++)
			cout << ans[i] << ' ';
		cout << '\n';
	}

	for (int i = 0; i < N; i++)
	{
		if (!check[i])
		{
			ans[len] = arr[i];
			check[i] = true;
			dfs(len + 1);
			check[i] = false;
		}
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

	dfs(0);
}