#include <iostream>
#include <string>
#include <deque>
using namespace std;

void AC(deque<int>& dq, string p)
{
	bool reverse = false;
	int len = p.size();

	for (int i = 0; i < len; i++)
	{
		switch (p[i])
		{
		case 'R':
			reverse = !reverse;
			break;
		case 'D':
			if (dq.empty())
			{
				cout << "error\n";
				return;
			}
			if (reverse)
				dq.pop_back();
			else
				dq.pop_front();
			break;
		}
	}
	cout << "[";
	if (!dq.empty())
	{
		if (reverse)
		{
			cout << dq.back();
			dq.pop_back();
			while (!dq.empty())
			{
				cout << "," << dq.back();
				dq.pop_back();
			}
		}
		else
		{
			cout << dq.front();
			dq.pop_front();
			while (!dq.empty())
			{
				cout << "," << dq.front();
				dq.pop_front();
			}
		}
	}
	cout << "]\n";
}


int main() {
	ios_base::sync_with_stdio();
	cin.tie(NULL);

	int T, n, len;
	string p, arr, num = "";
	deque<int> dq;
	cin >> T;
	cin.ignore();

	while (T--)
	{
		getline(cin, p);

		cin >> n;
		cin.ignore();

		getline(cin, arr);
		len = arr.size();

		for (int i = 1; i < len; i++)
		{
			if (isdigit(arr[i]))
				num += arr[i];
			else
			{
				// 배열의 길이가 0일 경우 고려
				if (!num.empty())
				{
					dq.push_back(stoi(num));
					num = "";
				}
			}
		}

		AC(dq, p);
	}
}