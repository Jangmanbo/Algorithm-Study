#include <iostream>
#include <queue>
using namespace std;

int map[100][100][100];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	int M, N, H, tomato = 0;
	queue<pair<int, int>> q[100];

	// ют╥б
	cin >> M >> N >> H;
	for (int k = 0; k < H; k++)
	{
		for (int i = 0; i < M; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cin >> map[i][j][k];
				switch (map[i][j][k])
				{
				case 0:
					tomato++;
				case 1:
					q[k].push({ i, j });
					break;
				default:
					break;
				}
			}
		}
	}


}