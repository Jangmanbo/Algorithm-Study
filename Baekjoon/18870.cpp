#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N, num;
	vector<pair<int, int>> vec;

	cin >> N;
	int* aws = new int[N]();

	for (int i = 0; i < N; i++)
	{
		cin >> num;
		vec.push_back(make_pair(num, i));
	}
	sort(vec.begin(), vec.end());

	for (int i = 1; i < N; i++)
	{
		if (vec[i - 1].first != vec[i].first) {
			aws[vec[i].second] = aws[vec[i - 1].second] + 1;
		}
		else {
			aws[vec[i].second] = aws[vec[i - 1].second];
		}
	}
	for (int i = 0; i < N; i++)
	{
		cout << aws[i] << " ";
	}
}