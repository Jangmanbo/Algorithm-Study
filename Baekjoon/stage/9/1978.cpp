#include <iostream>
#include <string>
#include <sstream>
using namespace std;

bool prime(int num) {
	for (int i = 2; i < num; i++)
	{
		if (num % i == 0) return false;
	}
	if (num == 1) return false;
	return true;
}

int main() {
	int N, num, total = 0;
	string s;
	cin >> N;
	string buf;
	for (int i = 0; i < N; i++)
	{
		cin >> buf;
		num = stoi(buf);
		if (prime(num)) total++;
	}
	cout << total << endl;
}