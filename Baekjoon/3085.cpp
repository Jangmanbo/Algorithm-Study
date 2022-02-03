#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
using namespace std;

// 세로줄 최대 개수
int vertical_max(char** arr, int j, int N)
{
	int max_value = 1;
	stack<char> stk;
	stk.push(arr[0][j]);

	for (int i = 1; i < N; i++)
	{
		if (stk.top() == arr[i][j])
			stk.push(arr[i][j]);
		else
		{
			max_value = max((int) stk.size(), max_value);

			while (!stk.empty())
				stk.pop();

			stk.push(arr[i][j]);
		}
	}
	max_value = max((int)stk.size(), max_value);
	return max_value;
}

// 가로줄 최대 개수
int horizontal_max(char** arr, int i, int N)
{
	int max_value = 1;
	stack<char> stk;
	stk.push(arr[i][0]);

	for (int j = 1; j < N; j++)
	{
		if (stk.top() == arr[i][j])
			stk.push(arr[i][j]);
		else
		{
			max_value = max((int)stk.size(), max_value);

			while (!stk.empty())
				stk.pop();

			stk.push(arr[i][j]);
		}
	}
	max_value = max((int)stk.size(), max_value);
	return max_value;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, local_max, total_max = 0;
	cin >> N;
	cin.ignore();

	string str;
	char** arr;
	arr = new char* [N];

	// 2차원 배열
	for (int i = 0; i < N; i++)
	{
		arr[i] = new char[N];
		getline(cin, str);
		for (int j = 0; j < N; j++)
		{
			arr[i][j] = str[j];
		}
	}

	// 좌우 교환
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N - 1; j++)
		{
			swap(arr[i][j], arr[i][j + 1]);
			local_max = max({ vertical_max(arr, j, N), vertical_max(arr, j + 1, N), horizontal_max(arr, i, N) });
			total_max = max(local_max, total_max);
			swap(arr[i][j], arr[i][j + 1]);
		}
	}

	// 상하 교환
	for (int j = 0; j < N; j++)
	{
		for (int i = 0; i < N - 1; i++)
		{
			swap(arr[i][j], arr[i + 1][j]);
			local_max = max({ vertical_max(arr, j, N), horizontal_max(arr, i, N), horizontal_max(arr, i + 1, N) });
			total_max = max(local_max, total_max);
			swap(arr[i][j], arr[i + 1][j]);
		}
	}
	cout << total_max;
}