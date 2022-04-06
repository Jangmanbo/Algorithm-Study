#include <iostream>
using namespace std;

int main() {
	int x, y, w, h, first, second;
	cin >> x >> y >> w >> h;
	first = min(w - x, h - y);
	second = min(x, y);
	cout << min(first, second) << "\n";
}