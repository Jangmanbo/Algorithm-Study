#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// å ������ �������� ����, ������ å ������ ���������� ����
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

	// map�� vector�� ��ȯ�Ͽ� å ������ �������� ����
	vector<pair<string, int>> vec(m.begin(), m.end());
	sort(vec.begin(), vec.end(), compare);
	cout << vec[0].first;
}