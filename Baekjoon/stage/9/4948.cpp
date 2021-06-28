#include <iostream>
#include <math.h>
#include <memory.h>
using namespace std;

int main() {
    int max = 123456 * 2;
    bool* prime = new bool[max + 1];
    memset(prime, 0, sizeof(bool) * (max + 1));

    for (int i = 2; i <= max; i++) {
        if (prime[i] == false) {
            for (int j = i * 2; j <= max; j += i) {
                prime[j] = true;
            }
        }
    }

    prime[1] = true;
    int N, total;
    cin >> N;
    while (N != 0) {
        total = 0;
        for (int i = N + 1; i <= 2 * N; i++)
        {
            if (!prime[i]) total++;
        }
        cout << total << "\n";
        cin >> N;
    }
}