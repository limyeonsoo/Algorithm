/*
	N번째 일 때 dp[N] = max(dp[N-1] + A[N] , A[N])
*/

#pragma warning(disable:4996)
#include <iostream>
#include <algorithm>
using namespace std;
int N, max_ans;
int dp[100001];
int A[100001];
int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &A[i]);
	}
	dp[1] = A[1];
	for (int i = 2; i <= N; i++) {
		dp[i] = max(dp[i - 1] + A[i], A[i]);
	}
	printf("%d", *max_element(dp + 1, dp + N + 1));
}