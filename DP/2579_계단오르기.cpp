/*
	N번째 일 때 dp[N][0] = 1칸으로 올라왔다.
	            dp[N][1] = 2칸으로 올라왔다.
			1	dp[N-1]이  연속  상황		  dp[N] = dp[N-1][1] + A[N];                                N-1을 1칸으로 왔으면 안됨.
			       
			2   dp[N-1]을 지나친 상황         dp[N] = max(dp[N-2][0] + A[N] , dp[N-2][1] + A[N] ) ;  N-2를 1칸으로/2칸으로 상관 X
*/

#pragma warning(disable:4996)
#include <iostream>
#include <algorithm>
using namespace std;
int N, max_ans;
int dp[301][2];
int A[301];
int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &A[i]);
	}
	dp[1][0] = A[1];
	dp[1][1] = A[1];
	dp[2][0] = max(A[1] + A[2], A[2]);
	dp[2][1] = A[2];
	for (int i = 3; i <= N; i++) {
		dp[i][0] = dp[i - 1][1] + A[i];
		dp[i][1] = max(dp[i - 2][0] + A[i], dp[i - 2][1] + A[i]);
	}
	printf("%d", max(dp[N][0], dp[N][1]));
}