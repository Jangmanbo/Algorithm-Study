#include <stdio.h>

int main() {
	int A, B, V, day = 1, climb = 0;
	scanf("%d %d %d", &A, &B, &V);
	V -= A;
	A -= B;
	day += V / A;
	if (V % A != 0) day += 1;
	printf("%d", day);
}