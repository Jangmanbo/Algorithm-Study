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

	// ������ �ƴ� �����
	while (real--)
	{
		cin >> n;
		know.push_back(n);
		Union(know[0], n);	// ���� �׷�
	}

	// �� ��Ƽ�� �����ϴ� �����
	for (int i = 0; i < M; i++)
	{
		// ��Ƽ�� �ּ� �ο� == 1
		cin >> n >> p;
		party[i].push_back(p);

		// ��Ƽ�� 2�� �̻� ����
		for (int j = 1; j < n; j++)
		{
			cin >> p;
			Union(party[i][0], p);	// ���� �׷�
			party[i].push_back(p);
		}
	}

	for (int i = 0; i < M; i++)
	{
		bool lie = true;	// ������ ���� ����
		for (int person : party[i])
		{
			// ��Ƽ ���� �ο� �� ������ �ƴ� ����̰ų� ������ �ƴ� ����� ������ ���� ����� �ִ� ���
			if (!know.empty() && find(person) == find(know[0]))
				lie = false;
		}
		if (lie)
			ans++;
	}

	cout << ans;
}