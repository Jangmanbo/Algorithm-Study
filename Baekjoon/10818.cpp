#include <stdio.h>
#include <algorithm>
using namespace std;

int main() {
	int N, num;
	scanf("%d", &N);
	int* array = new int[N];
	for (int i = 0; i < N; i++) {
		scanf("%d", &num);
		array[i] = num;
	}
	printf("%d %d", *min_element(array, array + N), *max_element(array, array + N));
	return 0;
}