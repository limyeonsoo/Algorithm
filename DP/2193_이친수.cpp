/*
dp[N][0]  : N �ڸ��� 0�� �� ���.
dp[N][1]  : N �ڸ��� 1�� �� ���.
dp[N][0] �� ���  dp[N][0] = dp[N-1][0] + dp[N-1][1]   // 0�� �������� �� �� �ֱ� ����.
dp[N][1] �� ���  dp[N][1] = dp[N-1][0]                // 1�� �������� �� �� ���� ����.
dp[0] = 1  // 0�� ���ڸ��� �� �� ����.
*/

#pragma warning(disable:4996)
//#include <stdio.h>
//
//long long int dp[91][2];
//int N;
//int main() {
//	scanf("%d", &N);
//	dp[1][0] = 0;
//	dp[1][1] = 1;
//	for (int i = 2; i <= N; i++) {
//		dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
//		dp[i][1] = dp[i - 1][0];
//	}
//	printf("%lld", dp[N][0] + dp[N][1]);
//}

#include <stdio.h>

long long int dp[91];
int N;
int main() {
	scanf("%d", &N);
	dp[1] = 1;
	dp[2] = 1;
	for (int i = 3; i <= N; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	printf("%lld", dp[N]);
}