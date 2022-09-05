#include <iostream>
#include <string>
using namespace std;

string str;

void convert(int minute)
{
	int h = minute / 60;
	int m = minute % 60;

	if (h < 10)
		str += "0";
	str += to_string(h) + ":";

	if (m < 10)
		str += "0";
	str += to_string(m) + "\n";
}

void func(int N, int K)
{
	int day = 0;
	int stop = 0;
	int minute = 900;

	while (day < N)
	{
		stop++;

		if (stop % 3 == 0)
		{
			minute += (1080 + K);
			stop -= 3;
		}
		else
			minute += 180;

		if (minute >= 1440)
		{
			minute -= 1440;
			day++;
		}
	}

	int ans = 0;
	do
	{
		convert(minute);
		stop++;

		if (stop % 3 == 0)
		{
			minute += (1080 + K);
			stop -= 3;
		}
		else
			minute += 180;

		if (minute >= 1440)
		{
			minute -= 1440;
			day++;
		}

		ans++;

	} while (day == N);

	cout << ans << '\n';
	cout << str;
}

int main()
{
	int N, K;
	cin >> N >> K;

	func(N, K);

	return 0;
}