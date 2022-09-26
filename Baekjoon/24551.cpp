#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	long long num, ans = 0;
	vector<pair<int, long long>> div = { {1,11}, {2,  111}, {4,11111}, {6,1111111}, {10,11111111111}, {12,1111111111111}, {16,11111111111111111} };

	cin >> num;

	for (int i = 0; i < 7; i++)
	{
		if (div[i].second <= num)
		{
			ans += num / div[i].second;
		}
		else
		{
			break;
		}
	}

	for (int i = 0; i < 6; i++)
	{
		for (int j = i + 1; j < 7; j++)
		{
			if (div[i].first + div[j].first < 18 && div[i].second * div[j].second <= num)
			{
				ans -= num / (div[i].second * div[j].second);
			}
		}
	}

	for (int i = 0; i < 5; i++)
	{
		for (int j = i + 1; j < 6; j++)
		{
			for (int k = j + 1; k < 7; k++)
			{
				if (div[i].first + div[j].first + div[k].first < 18 && div[i].second * div[j].second * div[k].second <= num)
				{
					ans += num / (div[i].second * div[j].second * div[k].second);
				}
			}
		}
	}

	for (int i = 0; i < 4; i++)
	{
		for (int j = i + 1; j < 5; j++)
		{
			for (int k = j + 1; k < 6; k++)
			{
				for (int s = k + 1; s < 7; s++)
				{
					if (div[i].first + div[j].first + div[k].first + div[s].first < 18 && div[i].second * div[j].second * div[k].second * div[s].second <= num)
					{
						ans -= num / (div[i].second * div[j].second * div[k].second * div[s].second);
					}
				}

			}
		}
	}

	cout << ans;
}