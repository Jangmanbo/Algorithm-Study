#include <iostream>
using namespace std;

void insert(int N, int* num) {
	int key;
	for (int i = 1; i < N; i++)
	{
		key = num[i];
		for (int j = i - 1; j >= 0; j--)
		{
			if (key < num[j]) {
				num[j + 1] = num[j];
				num[j] = key;
			}
			else break;
		}
	}
}

int main() {
	int N;
	cin >> N;
	int* num = new int[N];
	for (int i = 0; i < N; i++)
	{
		cin >> num[i];
	}
	insert(N, num);
	for (int i = 0; i < N; i++)
	{
		cout << num[i] << "\n";
	}
}