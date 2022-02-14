#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio();
	cin.tie(NULL);

	int L, P, V, use, i = 0;
	while (true)
	{
		cin >> L >> P >> V;
		if (!L && !P && !V)	// 마지막 줄
			break;
		
		use = 0, i++;

		use += V / P * L;
		use += min(V % P, L);
		cout << "Case " << i << ": " << use << "\n";
	}
}