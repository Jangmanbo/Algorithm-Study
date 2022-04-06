#include <iostream>
#include <string.h>
using namespace std;

#define MAX 6561

char map[MAX][MAX];
int N;

void func(int x, int y, int width)
{
	// 빈칸을 채울 시작점
	int si = x + width;
	int sj = y + width;

	// 빈칸 넣기
	for (int i = si; i < si + width; i++)
		for (int j = sj; j < sj + width; j++)
			map[i][j] = ' ';

	// 3*3이면 return
	if (width == 1)
		return;

	// 8개의 사각형 빈칸 넣기
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (!(i == 1 && j == 1))	// 가운데 사각형 제외
				func(x + width * i, y + width * j, width / 3);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	// *로 배열 초기화
	for (int i = 0; i < MAX; i++)
		memset(map[i], '*', sizeof(char) * MAX);

	cin >> N;
	func(0, 0, N / 3);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cout << map[i][j];
		cout << '\n';
	}
}