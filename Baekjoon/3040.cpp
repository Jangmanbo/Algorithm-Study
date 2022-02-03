#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int arr[9];
	int sum;

	for (int i = 0; i < 9; i++)
		cin >> arr[i];

	do
	{
		sum = 0;
		for (int i = 0; i < 7; i++)
			sum += arr[i];

		if (sum == 100)
			break;
	} while (next_permutation(arr, arr+9));

	for (int i = 0; i < 7; i++)
		cout << arr[i] << "\n";
}