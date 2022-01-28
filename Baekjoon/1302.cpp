#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// 책 개수를 기준으로 정렬, 같으면 책 제목을 사전순으로 정렬
bool compare(pair<string, int> a, pair<string, int> b)
{
	if (a.second == b.second)
		return a.first < b.first;
	else
		return a.second > b.second;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	map<string, int> m;
	int N;
	string str;

	cin >> N;
	cin.ignore();
	for (int i = 0; i < N; i++)
	{
		getline(cin, str);
		if (m.find(str) != m.end())
			m[str]++;

		else
			m.insert({ str, 1 });
	}

	// map을 vector로 변환하여 책 개수를 기준으로 정렬
	vector<pair<string, int>> vec(m.begin(), m.end());
	sort(vec.begin(), vec.end(), compare);
	cout << vec[0].first;
}