#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool compare(char c1, char c2) {
	return c1 > c2;
}

int main() {
	string s;
	cin >> s;
	sort(s.begin(), s.end(), compare);
	cout << s;
	return 0;
}