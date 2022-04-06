#include <stdio.h>

int main() {
	int h, m;
	scanf("%d\n%d", &h, &m);
	if (m < 45) {
		m = m + 15;
		if (h != 0) h = h - 1;
		else h = h + 23;
	}
	else m = m - 45;
	printf("%d %d", h, m);
	return 0;
}