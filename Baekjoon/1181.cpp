#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	int N;
	string s;
	cin >> N;
	vector<pair<int, string>> vec;

	for (int i = 0; i < N; i++)
	{
		cin >> s;
		vec.push_back(make_pair(s.size(), s));
	}
	sort(vec.begin(), vec.end());

	s = vec[0].second;
	cout << s << "\n";
	for (int i = 1; i < N; i++)
	{
		if (s == vec[i].second) continue;
		s = vec[i].second; 
		cout << s << "\n";
	}
}