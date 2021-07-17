#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(int dot1[2], int dot2[2]) {
	if (dot1[0]==dot2[0]) return dot1[1] < dot2[1];
	return dot1[0] < dot2[0];
}

int main() {
	int N, x, y;
	cin >> N;
	vector<pair<int, int>> vec;
	for (int i = 0; i < N; i++)
	{
		cin >> x >> y;
		vec.push_back(make_pair(x, y));
	}
	sort(vec.begin(), vec.end());
	for (int i = 0; i < N; i++)
	{
		cout << vec[i].first << " " << vec[i].second << "\n";
	}
	return 0;
}