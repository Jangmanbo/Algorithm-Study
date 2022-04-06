#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int a[3];
	int max, result;
	cin >> a[0] >> a[1] >> a[2];
	while (a[0] && a[1] && a[2]) {
		max = *max_element(a, a + 3);
		if (max == a[0]) result = (a[0] * a[0] == a[1] * a[1] + a[2] * a[2]);
		else if (max == a[1]) result = (a[1] * a[1] == a[0] * a[0] + a[2] * a[2]);
		else result = (a[0] * a[0] + a[1] * a[1] == +a[2] * a[2]);
		if (result) cout << "right" << "\n";
		else cout << "wrong" << "\n";
		cin >> a[0] >> a[1] >> a[2];
	}
}