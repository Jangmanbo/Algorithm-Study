#include <iostream>
#include <vector>
using namespace std;

#define MAX 50

int N, M, real, ans;
bool real_people[MAX + 1];
vector<int> party[MAX];

void dfs()
{

}

void input()
{
	int n, p;
	cin >> N >> M;

	// 진실을 아는 사람
	cin >> real;
	for (int i = 0; i < real; i++)
	{
		cin >> p;
		real_people[p] = true;
	}

	// 각 파티에 오는 사람
	for (int i = 0; i < M; i++)
	{
		cin >> n;
		for (int j = 0; j < n; j++)
		{
			cin >> p;
			party[i].push_back(p);
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	input();
	dfs();
	cout << ans;
}