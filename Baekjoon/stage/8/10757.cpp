#include <iostream>
#include <string>
using namespace std;

int main() {
	string A, B, R;
	cin>>A>>B;
	int a = A.size();
	int b = B.size();
	int s = min(a, b);
	int num, plus = 0;
	for (int i = 1; i <= s; i++)
	{
		num = ((A[a-i] - '0') + (B[b-i] - '0')) + plus;
		R = to_string(num % 10) + R;
		plus = num / 10;
	}
	string big;
	if (a>b)
	{
		big = A;
	}
	else
	{
		big = B;
	}
	int l = max(a, b) - min(a, b);
	for (int i = 1; i <= l; i++)
	{
		num = (big[l-i]-'0') + plus;
		R = to_string(num % 10) + R;
		plus = num / 10;
	}
	if (plus)
	{
		R = to_string(plus) + R;
	}
	cout << R << endl;
}