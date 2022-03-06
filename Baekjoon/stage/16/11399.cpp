#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, ans = 0;

	cin >> N;
	vector<int> vec(N);

	for (int i = 0; i < N; i++)
		cin >> vec[i];

	sort(vec.begin(), vec.end());

	for (int i = 0; i < N; i++)
		ans += vec[i] * (N - i);

	cout << ans;
}