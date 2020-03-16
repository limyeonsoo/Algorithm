#pragma warning(disable:4996)
#include <cstdio>
int A, B, temp, T, N;
int V[101];
int main() {
	scanf("%d", &T);
	while (T--) {
		long long int sum = 0;
		scanf("%d", &N);
		for(int i=0; i<N; i++){
			scanf("%d", &V[i]);
		}
		for (int i = 0; i < N - 1; i++) {
			for (int j = i + 1; j < N; j++) {
				A = V[i]; B = V[j];
				while (B != 0) {
					temp = B;
					B = A % B;
					A = temp;
				}
				sum += A;
			}
		}
		printf("%lld\n", sum);
	}
}