#include <stdio.h>

void update(int& i, int& count) {
	i += 2;
	count++;
}

int main() {
	int count = 0, i = 0, dz = 0;
	char str[101];
	scanf("%s", str);
	while (str[i]!='\0') {
		if (str[i + 1] == '\0') {
			i++;
			break;
		}
		if (str[i] == 'c') {
			if (str[i + 1] == '=' || str[i + 1] == '-') {
				update(i, count);
				continue;
			}
		}
		if (str[i] == 'd') {
			if (str[i + 1] == '-') {
				update(i, count);
				continue;
			}
			if (str[i + 1] == 'z' && str[i + 2] == '=') {
				update(i, count);
				dz++;
				i++;
				continue;
			}
		}
		if (str[i+1] == 'j') {
			if (str[i] == 'l' || str[i] == 'n') {
				update(i, count);
				continue;
			}
		}
		if (str[i + 1] == '=') {
			if (str[i] == 's' || str[i] == 'z') {
				update(i, count);
				continue;
			}
		}
		i++;
	}
	printf("%d",i-count-dz);
	return 0;
}