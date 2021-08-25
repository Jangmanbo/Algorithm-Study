#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int* stairs = new int[n + 1]();
	int** score = new int*[n + 1];
	for (int i = 0; i <= n; i++)
		score[i] = new int[2]();
	cin >> stairs[1];
	score[1][0] = stairs[1];
	score[1][1] = stairs[1];

	for (int i = 2; i <= n; i++)
	{
		cin >> stairs[i];
		score[i][0] = score[i - 1][1] + stairs[i];
		score[i][1] = max(score[i - 2][0], score[i - 2][1]) + stairs[i];
	}
	cout << max(score[n][0], score[n][1]);
}