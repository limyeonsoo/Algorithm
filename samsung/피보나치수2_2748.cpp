#include <cstdio>
#define ll long long
int main() {
	int N; scanf("%d", &N);
	ll a = 1, b = 1;
	for (int i = 3; i <= N; i++) {
		if (i % 2 == 0) a = a + b;
		else b = a + b;
	}
	printf("%lld", N % 2 == 0 ? a : b);
}