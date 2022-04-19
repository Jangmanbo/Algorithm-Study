#include <iostream>
#include <vector>
using namespace std;

#define MAX 50
#define REAL 1
#define LIE -1

int N, M, real, ans;
vector<int> real_people;
int hear[MAX + 1];
vector<int> party[MAX];

void dfs(int p, int lie)
{
	if (p == M)
	{
		ans = max(ans, lie);
	}
	for (int person : party[p])
	{
		auto it = find(real_people.begin(), real_people.end(), person);
		if (it != real_people.end())	// 진실을 아는 사람이 있음
		{

		}
		else	// 진실을 아는 사람이 없음
		{

		}
	}

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
		real_people.push_back(p);
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
	dfs(0, 0);
	cout << ans;
}