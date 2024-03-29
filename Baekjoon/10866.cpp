#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main() {
	//입출력 속도 높이기
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	deque<int> dq;
	string str;
	int N, num;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> str;
		if (str == "push_front") {
			cin >> num;
			dq.push_front(num);
		}
		else if (str == "push_back") {
			cin >> num;
			dq.push_back(num);
		}
		else if (str == "pop_front") {
			if (dq.empty()) cout << -1 << "\n";
			else {
				cout << dq.front() << "\n";
				dq.pop_front();
			}
		}
		else if (str == "pop_back") {
			if (dq.empty()) cout << -1 << "\n";
			else {
				cout << dq.back() << "\n";
				dq.pop_back();
			}
		}
		else if (str == "size") cout << dq.size() << "\n";
		else if (str == "empty") cout << dq.empty() << "\n";
		else if (str == "front") {
			if (dq.empty()) cout << -1 << "\n";
			else cout << dq.front() << "\n";
		}
		else if (str == "back") {
			if (dq.empty()) cout << -1 << "\n";
			else cout << dq.back() << "\n";
		}
	}
}