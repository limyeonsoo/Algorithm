/*
  연속으로 3번 마실 수 없다는 점. 
  dp[N] : 
         0번 연속 : dp[N-1][0], dp[N-1][1], dp[N-1][2]
         1번 연속 : dp[N-1][0]                        + A[N]
         2번 연속 :             dp[N-1][1]            + A[N]
*/
#pragma warning(disable:4996)
#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 10001
int dp[MAX][3];
int A[MAX];
int N, ans;
int main() {
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) scanf("%d", &A[i]);
    dp[1][0] = 0; dp[1][1] = A[1]; dp[1][2] = A[1];   // 초기 설정.

    for (int i = 2; i <= N; i++) {
        dp[i][0] = max({ dp[i - 1][0], dp[i - 1][1], dp[i - 1][2] });
        dp[i][1] = dp[i - 1][0] + A[i];
        dp[i][2] = dp[i - 1][1] + A[i];
    }
    
    printf("%d", max({ dp[N][0], dp[N][1], dp[N][2] }));
}