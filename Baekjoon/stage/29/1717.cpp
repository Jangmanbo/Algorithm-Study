#include <iostream>
using namespace std;

#define MAX 1000001

int arr[MAX];

void make_set(int m)
{
	for (int i = 1; i <= m; i++)
		arr[i] = i;
}

int find(int x)
{
	if (arr[x] == x)
		return x;
	else
	{
		int parent = find(arr[x]);
		arr[x] = parent;
		return parent;
	}
}

void sum_set(int a, int b)
{
	a = find(a);
	b = find(b);
	arr[b] = a;
}

// union-find
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	int n, m, op, a, b;
	cin >> n >> m;
	make_set(n);

	while (m--)
	{
		cin >> op >> a >> b;
		switch (op)
		{
		case 0:
			sum_set(a, b);
			break;
		case 1:
			if (find(a) == find(b))
				cout << "YES\n";
			else
				cout << "NO\n";
			break;
		default:
			break;
		}
	}
}