#include <iostream>
#include <math.h>
#include <memory.h>
using namespace std;

int main() {
    bool* prime = new bool[10001];
    memset(prime, 0, sizeof(bool) * (10001));

    for (int i = 2; i <= 10000; i++) {
        if (prime[i] == false) {
            for (int j = i * 2; j <= 10000; j += i) {
                prime[j] = true;
            }
        }
    }
    prime[1] = true;
    int T, N, p1, p2, find = 0;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cin >> N;
        for (int i = 2; i <= N / 2; i++)
        {
            if (!prime[i] && !prime[N - i]) p1 = i, p2 = N - i, find = 1;
        }
        if (find) cout << p1 << " " << p2 << "\n";
        find = 0;
    }
}