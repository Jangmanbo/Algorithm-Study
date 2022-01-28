#include <iostream>
#include <set>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	string name, el;
	set<string, greater<string>> s;	// �������� ����
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> name >> el;
		if (el == "enter")	//���
			s.insert(name);
		else	// ���
			s.erase(name);
	}
	for (string n : s)
		cout << n << "\n";
}