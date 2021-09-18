#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int Euclid(int a, int b) {
	return a % b ? Euclid(b, a % b) : b;
}

int main() {
	//����� �ӵ� ���̱�
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	//sub:���� ���ҿ� ���� ������ ��
	int* arr = new int[N];
	int* sub = new int[N - 1];

	cin >> arr[0];
	for (int i = 1; i < N; i++) {
		cin >> arr[i];
		sub[i - 1] = abs(arr[i] - arr[i - 1]);
	}

	N -= 1;
	sort(sub, sub + N);

	//��Ŭ���� ȣ������ �̿��� �ִ����� ���ϱ�
	for (int i = 1; i < N; i++)
		sub[i] = Euclid(sub[i], sub[i - 1]);

	int gcd = sub[N - 1];
	vector<int> vec;
	for (int i = 2; i * i <= gcd; i++) {
		if (gcd % i == 0) {
			vec.push_back(i);
			vec.push_back(gcd / i);
		}
	}
	vec.push_back(gcd);
	sort(vec.begin(), vec.end());
	vec.erase(unique(vec.begin(), vec.end()), vec.end());//�ߺ��� ���� ����

	for (int elem : vec)
		cout << elem << " ";

	return 0;
}