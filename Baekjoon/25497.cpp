#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
	int N;
	cin >> N;

	string skills;
	cin >> skills;

	int S = 0, L = 0, success = 0;
	bool next = true;

	for (int i = 0; i < N; i++)
	{
		if (!next)
			break;

		switch (skills[i])
		{
		case 'S':
			S++;
			break;

		case 'L':
			L++;
			break;

		case 'K':
			if (S > 0)
			{
				S--;
				success++;
			}
			else
				next = false;
			break;

		case 'R':
			if (L > 0)
			{
				L--;
				success++;
			}
			else
				next = false;
			break;

		default:
			success++;
			break;
		}
	}

	cout << success;
}