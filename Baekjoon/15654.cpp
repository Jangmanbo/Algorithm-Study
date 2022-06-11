#include <iostream>
#include <algorithm>
using namespace std;

int ans[8];
int arr[8];
bool check[8];

void dfs(int idx)
{

}


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	int N, M;

	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	sort(arr, arr + N);

	dfs(0);
}