#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int T;
	long x, y;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> x >> y;
		int dis = y - x;
		float t = sqrt(dis);
		int s = sqrt(dis);
		if (t == s) cout << 2 * s - 1 << endl;
		else if (dis >= s * s && dis <= s * s + s) cout << 2 * s << endl;
		else cout << 2 * s + 1 << endl;
	}
}