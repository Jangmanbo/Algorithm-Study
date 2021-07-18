#include <iostream>
#include <vector>
using namespace std;

int N, total = 0;
vector<pair<int, int>> vec;

bool attack(pair<int, int> p) {
	int size = vec.size();
	for (int i = 0; i < size; i++)
	{
		if (vec[i].second == p.second || abs(vec[i].first - p.first) == abs(vec[i].second - p.second)) return 1;
	}
	return 0;
}

void dfs(int cnt) {
	if (cnt == N) total++;
	for (int i = 0; i < N; i++)
	{
		if (!attack(make_pair(cnt, i))) {
			vec.push_back(make_pair(cnt, i));
			dfs(cnt + 1);
			vec.pop_back();
		}
	}
}

int main() {
	cin >> N;
	dfs(0);
	cout << total;
	return 0;
}