#include <stdio.h>

int main() {
	int N, buf, min, por;
	bool div = false;
	scanf("%d", &N);
	por = N / 3;
	for (int i = 0; i < por; i++)
	{
		buf = N - 3 * i;
		if (buf % 5 == 0) {
			min = i;
			div = true;
            break;
		}
	}
	if (div)	printf("%d", min + (N - min * 3) / 5);
	else
	{
		if	(N % 3 == 0)printf("%d", N / 3);
		else	printf("%d", -1);
		
	}
}