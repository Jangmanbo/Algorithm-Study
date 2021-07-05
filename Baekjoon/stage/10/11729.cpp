#include <iostream>
#include <cmath>
using namespace std;

void hanoi(int N, int start, int by, int end) {
    if (N == 1) {
        cout << start << " " << end << "\n";
    }
    else {
        hanoi(N - 1, start, end, by);
        cout << start << " " << end << "\n";
        hanoi(N - 1, by, start, end);
    }
}

int main() {
    int N;
    cin >> N;
    cout << (int)pow(2, N) - 1 << endl;
    hanoi(N, 1, 2, 3);
}