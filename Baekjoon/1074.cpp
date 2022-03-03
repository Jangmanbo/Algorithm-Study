#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	// ÀÔ·Â
	int N, r, c, ans = 0;
	cin >> N >> r >> c;

	pair<long long, long long> cur = { 0, 0 };
	long long size = pow(2, N);
	while (size != 1)
	{
		if (r < cur.first + size / 2)
		{
			if (c < cur.second + size / 2)	// ÁÂ»ó
			{
			}
			else	//¿ì»ó
			{
				cur.second += size / 2;
				ans += size * size / 4;
			}
		}
		else
		{
			cur.first += size / 2;
			if (c < cur.second + size / 2)	// ÁÂÇÏ
			{
				ans += size * size / 4 * 2;
			}
			else	// ¿ìÇÏ
			{
				cur.second += size / 2;
				ans += size * size / 4 * 3;
			}
		}
		size /= 2;
	}

	cout << ans;
}