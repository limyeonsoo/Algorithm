#include <cstdio>
int main() {
	int min=2000, s, res;
	for (int i = 0; i < 3; i++) {
		scanf("%d", &s); 
		if (min > s) min = s;
	}
	res = min; min = 2000;
	for (int i = 0; i < 2; i++) {
		scanf("%d", &s);
		if (min > s) min = s;
	}
	printf("%d", res + min - 50);
}