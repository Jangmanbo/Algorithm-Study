#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int x1, y1, r1, x2, y2, r2, T;
	float dis;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		dis = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
		if (!dis && r1 == r2) {
			cout << -1 << "\n";
			continue;
		}
		if (abs(r1 - r2) < dis && dis < r1 + r2) cout << 2 << "\n";
		else if (abs(r1 - r2) == dis || dis == r1 + r2) cout << 1 << "\n";
		else cout << 0 << "\n";
	}
}