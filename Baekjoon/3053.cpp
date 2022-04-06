#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
	int R;
	double scope1, scope2, pi = 2 * acos(0.0);
	cin >> R;
	scope1 = R * R * pi;
	scope2 = 2 * R * R;
	cout<< setprecision(16);
	cout << scope1 << "\n" << scope2;
}