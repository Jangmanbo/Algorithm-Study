#include <iostream>
#include <vector>
using namespace std;

#define MAX 50

int arr[MAX + 1];
vector<int> know;
vector<int> party[MAX];

void make_set()
{
	for (int i = 1; i <= MAX; i++)
		arr[i] = i;
}

int find(int x)
{
	if (arr[x] == x)
		return x;

	return arr[x] = find(arr[x]);
}

void Union(int x, int y)
{
	x = find(x);
	y = find(y);
	arr[y] = x;
}

// union-find
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	make_set();

	int N, M, real, n, p, ans = 0;

	cin >> N >> M;
	cin >> real;

	// 진실을 아는 사람들
	while (real--)
	{
		cin >> n;
		know.push_back(n);
		Union(know[0], n);	// 같은 그룹
	}

	// 각 파티에 참여하는 사람들
	for (int i = 0; i < M; i++)
	{
		// 파티의 최소 인원 == 1
		cin >> n >> p;
		party[i].push_back(p);

		// 파티에 2명 이상 참석
		for (int j = 1; j < n; j++)
		{
			cin >> p;
			Union(party[i][0], p);	// 같은 그룹
			party[i].push_back(p);
		}
	}

	for (int i = 0; i < M; i++)
	{
		bool lie = true;	// 거짓말 가능 여부
		for (int person : party[i])
		{
			// 파티 참여 인원 중 진실을 아는 사람이거나 진실을 아는 사람과 언젠가 만날 사람이 있는 경우
			if (!know.empty() && find(person) == find(know[0]))
				lie = false;
		}
		if (lie)
			ans++;
	}

	cout << ans;
}