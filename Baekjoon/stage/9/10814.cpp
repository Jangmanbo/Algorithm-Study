#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	int N, age;
	string s;
	vector<pair<int, int>> vec;

	cin >> N;
	string* name = new string[N];

	for (int i = 0; i < N; i++)
	{
		cin >> age >> s;
		vec.push_back(make_pair(age, i));
		name[i] = s;
	}
	sort(vec.begin(), vec.end());

	for (int i = 0; i < N; i++)
	{
		cout << vec[i].first << " " << name[vec[i].second] << "\n";
	}
}