#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N, x, y;
	cin >> N;
	vector<vector<int>> xy;
	for (int i = 0; i < N; i++)
	{
		cin >> x >> y;
		xy.push_back({ y, x });
	}
	sort(xy.begin(), xy.end());
	for (int i = 0; i < N; i++)
	{
		cout << xy[i][1] << " " << xy[i][0] << "\n";
	}

	return 0;
}