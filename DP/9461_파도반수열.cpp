#pragma warning(disable:4996)
#include <iostream>
using namespace std;
int T, N;
long long int dp[101];
int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &N);
		for (int i = 1; i <= 3; i++) dp[i] = 1;
		for (int i = 4; i <= 5; i++) dp[i] = 2;
		for (int i = 6; i <= N; i++) dp[i] = dp[i - 1] + dp[i - 5];
		printf("%lld\n", dp[N]);
	}
}
