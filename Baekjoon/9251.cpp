#include <iostream>
#include <string>
using namespace std;

int len1, len2;
int arr[1001][1001];

string str1, str2;


int LCS()
{
	for (int i = 1; i <= len1; i++)
	{
		for (int j = 1; j <= len2; j++)
		{
			if (str1[i] == str2[j])
				arr[i][j] = arr[i - 1][j - 1] + 1;
			else
				arr[i][j] = max(arr[i - 1][j], arr[i][j - 1]);
		}
	}

	return arr[len1][len2];
}

void input()
{
	getline(cin, str1);
	getline(cin, str2);
	len1 = str1.size(), len2 = str2.size();

	str1 = ' ' + str1;
	str2 = ' ' + str2;

}

// LCS
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	input();

	cout << LCS();
}