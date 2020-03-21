#pragma warning(disable:4996)
#include <stdio.h>
long long result=1; int N;
int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) result *= i;
	printf("%d", result);
}