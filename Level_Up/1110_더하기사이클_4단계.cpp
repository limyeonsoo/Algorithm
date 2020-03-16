#pragma warning(disable:4996)
#include <stdio.h>
int main() {
	int N, ans = 100, count = 0;
	scanf("%d", &N);
	int now = N;
	
	while (N != ans) {
		count++;
		ans = now % 10 * 10 + (now / 10 + now % 10) % 10;
		now = ans;
	}
	printf("%d", count);
}