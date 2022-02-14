#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
	ios_base::sync_with_stdio();
	cin.tie(NULL);

	int N, P, line, pret, ans = 0;
	cin >> N >> P;
	stack<int> s[7];

	for (int i = 0; i < N; i++)
	{
		cin >> line >> pret;
		
		// 이미 프렛을 누르고 있으면
		while (!s[line].empty())
		{
			// pret보다 더 높은 프렛을 누르고 있다면 손가락 떼기
			if (s[line].top() > pret)
			{
				s[line].pop();
				ans++;
			}
			// 같은 프렛을 누르고 있으므로 손가락 움직임 변화 없음
			else if (s[line].top() == pret)
				break;
			// pret을 눌러 더 높은 음 연주
			else
			{
				s[line].push(pret);
				ans++;
				break;
			}
		}

		// 처음부터 누르고 있던 프렛이 없었음 or pret보다 더 높은 프렛만 누르고 있었음
		if (s[line].empty())
		{
			s[line].push(pret);
			ans++;
		}
	}
	cout << ans;
}