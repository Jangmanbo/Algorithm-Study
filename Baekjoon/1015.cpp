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
	bool* check = new bool[N]();	// 수열 P에 존재하는 수 체크

	for (int i = 0; i < N; i++)
	{
		cin >> num;
		A[i] = B[i] = num;
	}

	sort(B.begin(), B.end());	// 수열 B
	
	for (int i = 0; i < N; i++)
	{
		int ext = 0;
		do
		{
			auto index = find(B.begin() + ext, B.end(), A[i]);
			// P수열에 없는 수라면 P수열에 삽입
			if (!check[index - B.begin()])
			{
				P[i] = index - B.begin();
				check[P[i]] = true;	// P수열에 있다고 체크
				break;
			}
			else
				ext = index - B.begin() + 1;	// 이미 P수열에 존재하는 수라면 B수열에서 다음 i를 찾도록
		} while (true);
	}

	// 출력
	for (int i = 0; i < N; i++)
		cout << P[i] << ' ';
}