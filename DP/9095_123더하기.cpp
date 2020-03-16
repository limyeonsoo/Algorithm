/*
	정수 N을 만들기 위해서   o + o + o + o + ? = N
	           => ? 에는 1, 2, 3
			   1: 앞에 sum(o) = N-1;
			   2: 앞에 sum(o) = N-2;
			   3: 앞에 sum(o) = N-3;
*/
#pragma warning(disable: 4996)
#include <iostream>
using namespace std;

int dp[12];
int N, T;
int main() {
	scanf("%d", &T); 
	while (T--) {
		scanf("%d", &N);
		dp[1] = 1; dp[2] = 2; dp[3] = 4;
		for (int i = 4; i <= N; i++) dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
		printf("%d\n", dp[N]);
	}
}