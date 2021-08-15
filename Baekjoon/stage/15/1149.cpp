#include <iostream>
using namespace std;

int main() {
	int N;
	int house[1000][3];
	int red, green, blue;
	cin >> N;
	cin >> house[0][0] >> house[0][1] >> house[0][2];
	for (int i = 1; i < N; i++)
	{
		cin >> red >> green >> blue;
		house[i][0] = min(house[i - 1][1], house[i - 1][2]) + red;
		house[i][1] = min(house[i - 1][0], house[i - 1][2]) + green;
		house[i][2] = min(house[i - 1][0], house[i - 1][1]) + blue;
	}

	cout << min(min(house[N - 1][0], house[N - 1][1]), house[N - 1][2]);
	return 0;
}