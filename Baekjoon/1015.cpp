#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio();
	cin.tie(NULL);

	int N, num;
	cin >> N;

	vector<int> A(N), B(N), P(N);
	bool* check = new bool[N]();	// ���� P�� �����ϴ� �� üũ

	for (int i = 0; i < N; i++)
	{
		cin >> num;
		A[i] = B[i] = num;
	}

	sort(B.begin(), B.end());	// ���� B
	
	for (int i = 0; i < N; i++)
	{
		int ext = 0;
		do
		{
			auto index = find(B.begin() + ext, B.end(), A[i]);
			// P������ ���� ����� P������ ����
			if (!check[index - B.begin()])
			{
				P[i] = index - B.begin();
				check[P[i]] = true;	// P������ �ִٰ� üũ
				break;
			}
			else
				ext = index - B.begin() + 1;	// �̹� P������ �����ϴ� ����� B�������� ���� i�� ã����
		} while (true);
	}

	// ���
	for (int i = 0; i < N; i++)
		cout << P[i] << ' ';
}