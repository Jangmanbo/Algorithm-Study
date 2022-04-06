#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio();
	cin.tie(NULL);

	int N, M;
	string str;
	// (0, 0)이 black/white일 때 다시 색칠해야 하는지
	bool black[50][50] = { false };
	bool white[50][50] = { false };

	cin >> N >> M;
	cin.ignore();

	for (int i = 0; i < N; i++)
	{
		getline(cin, str);
		// (0, 0)부터
		for (int j = i % 2; j < M; j += 2)
		{
			switch (str[j])
			{
			case 'B':
				white[i][j] = true;
				break;
			case 'W':
				black[i][j] = true;
				break;
			default:
				break;
			}
		}
		// (0, 1)부터
		for (int j = (i + 1) % 2; j < M; j += 2)
		{
			switch (str[j])
			{
			case 'B':
				black[i][j] = true;
				break;
			case 'W':
				white[i][j] = true;
				break;
			default:
				break;
			}
		}
	}

	N -= 8;
	M -= 8;
	int ans = 64;
	int bc = 0, wc = 0;
	for (int i = 0; i <= N; i++)
	{
		for (int j = 0; j <= M; j++)
		{
			// (0, 0)이 black/white일 때 최소값 구하기
			for (int row = i; row < i + 8; row++)
			{
				for (int col = j; col < j + 8; col++)
				{
					if (black[row][col]) bc++;
					if (white[row][col]) wc++;
				}
			}
			ans = min({ ans, bc, wc });
			bc = 0, wc = 0;
		}
	}
	cout << ans;
}