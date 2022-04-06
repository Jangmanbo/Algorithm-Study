#include <iostream>
using namespace std;

int main() {
	int N;
    cin >> N;
	int* x = new int[N];
	int* y = new int[N];
	int* more = new int[N]();


	for (int i = 0; i < N; i++)
	{
		cin >> x[i] >> y[i];
	}
	for (int i = 0; i < N - 1; i++)
	{
		for (int j = i + 1; j < N; j++)
		{
			if (x[i] > x[j] && y[i] > y[j]) {
				more[j]++;
			}
			else if (x[i] < x[j] && y[i] < y[j]) {
				more[i]++;
			}
		}
	}
	for (int i = 0; i < N; i++)
	{
		cout << more[i] + 1 << " ";
	}
}