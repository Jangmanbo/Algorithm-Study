#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n, num;
	cin >> n;
	int* triangle = new int[n];
	int* line = new int[n];
	cin >> triangle[0];
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			cin >> line[j];
		}
		triangle[0] += line[0];
		for (int j = 1; j < i; j++)
		{
			triangle[j] += max(line[j - 1], line[j]);
		}
		triangle[i] = line[i] + triangle[i - 1];
	}

	cout << *max_element(triangle, triangle + n);
}