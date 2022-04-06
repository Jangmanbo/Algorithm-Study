#include <iostream>
#include <math.h>
#include <memory.h>
using namespace std;

int main() {
    unsigned int M, N;
    cin >> M >> N;
    if (M == 1) M++;

    bool* prime = new bool[N + 1];
    memset(prime, 0, sizeof(bool) * (N + 1));

    for (int i = 2; i <= N; i++) {
        if (prime[i] == false) {
            for (int j = i * 2; j <= N; j += i) {
                prime[j] = true;
            }
        }
    }

    for (int i = M; i <= N; i++)
    {
        if (!prime[i]) cout << i << "\n";
    }

    return 0;
}