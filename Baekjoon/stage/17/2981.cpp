#include <iostream>
#include <algorithm>
using namespace std;

int Euclid(int a, int b) {
	return a % b ? Euclid(b, a % b) : b;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	//sub:앞의 원소와 현재 원소의 차
	int* arr = new int[N];
	int* sub = new int[N - 1];

	cin >> arr[0];
	for (int i = 1; i < N; i++) {
		cin >> arr[i];
		sub[i - 1] = abs(arr[i] - arr[i - 1]);
	}

	N -= 1;
	sort(sub, sub + N);

	//유클리드 호제법을 이용해 최대공약수 구하기
	for (int i = 1; i < N; i++)
		sub[i] = Euclid(sub[i], sub[i - 1]);

	int gcd = sub[N - 1];
	for (int i = 2; i <= gcd; i++)
		if (gcd % i == 0) cout << i << " ";
}