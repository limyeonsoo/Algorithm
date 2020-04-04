#include <cstdio>
int main() {
	int N; scanf("%d", &N);
	for (int i = 1; i <= N - 1; i++) {
		for (int j = 1; j <= i; j++) {
			printf("*");
		}
		printf("\n");
	}
	for (int j = 1; j <= N; j++) {
		printf("*");
	}
		printf("\n");
	for (int i = N-1; i >= 1; i--) {
		for (int j = i; j > 0; j--) {
			printf("*");
		}
		printf("\n");
	}
}