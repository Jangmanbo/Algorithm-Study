#include <iostream>
#include <set>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	string name, el;
	set<string, greater<string>> s;	// 역순으로 정렬
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> name >> el;
		if (el == "enter")	//출근
			s.insert(name);
		else	// 퇴근
			s.erase(name);
	}
	for (string n : s)
		cout << n << "\n";
}