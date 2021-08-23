#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n, num;
	int buf[2];
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
		buf[0] = triangle[0] + line[0];
		for (int j = 1; j < i; j++)
		{
			buf[1] = line[j] + max(triangle[j - 1], triangle[j]);
			triangle[j - 1] = buf[0];
			buf[0] = buf[1];
		}
		triangle[i] = line[i] + triangle[i - 1];
		triangle[i - 1] = buf[0];
	}

	cout << *max_element(triangle, triangle + n);
	return 0;
}