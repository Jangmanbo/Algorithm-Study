#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

bool compare(pair<int, int> u, pair<int, int> v) {
	if (u.first == v.first) return u.second < v.second;
	return u.first > v.first;
}

int main() {
	int N, num;
	double sum = 0;
	vector<int> vec;
	vector<int> frequency(8001);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		vec.push_back(num);
		sum += num;
		frequency[num + 4000]++;
	}
	sort(vec.begin(), vec.end());
	cout << round(sum / N) << endl;
	cout << vec[(N - 1) / 2] << endl;

	if (N == 1) cout << vec[0] << endl;
	else {
		vector<pair<int, int>> frequency2;
		for (int i = 0; i < 8001; i++)
			if (frequency[i]) frequency2.push_back(make_pair(frequency[i], i - 4000));
		sort(frequency2.begin(), frequency2.end(), compare);
		if (frequency2[0].first == frequency2[1].first) cout << frequency2[1].second << endl;
		else cout << frequency2[0].second << endl;
	}
	cout << vec[N - 1] - vec[0] << endl;
	
}