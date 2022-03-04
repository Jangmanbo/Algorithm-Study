#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int L, C;
	cin >> L >> C;

	vector<char> vec(C);
	for (int i = 0; i < C; i++)
		cin >> vec[i];
	sort(vec.begin(), vec.end());

	vector<bool> comb(C);
	for (int i = 0; i < L; i++)
		comb[i] = false;
	for (int i = L; i < C; i++)
		comb[i] = true;

	int vowel, consonant;
	string pw;
	do
	{
		vowel = 0, consonant = 0, pw = "";
		for (int i = 0; i < C; i++)
			if (!comb[i])
			{
				pw += vec[i];
				if (vec[i] == 97 || vec[i] == 101 || vec[i] == 105 || vec[i] == 111 || vec[i] == 117)
					vowel++;
				else
					consonant++;
			}
		if (vowel && consonant >= 2)
			cout << pw << '\n';
	} while (next_permutation(comb.begin(), comb.end()));
}