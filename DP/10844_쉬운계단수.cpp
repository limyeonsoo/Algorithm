/*
계단수 구하기
 길이가 N인 계단수가 있을 때.
  N 자리 수  A 앞, N-1자리에 올 수 있는 수는  A+1 or A-1
  단, 첫자리와 끝자리는  A-1 / A+1 올 수 없음.

  dp[N][A] : N 자리에 A수
  dp[N][A] = dp[N-1][A-1] + dp[N-1][A+1]
  dp[1] = 9가지  
*/
#pragma warning(disable:4996)
#include <iostream>
#define MAX 101
#define cond 1000000000
using namespace std;
int dp[MAX][11];
int N, ans;
int main() {
    scanf("%d", &N);
    for (int i = 1; i <= 9; i++) dp[1][i] = 1;
    for (int i = 2; i <= N; i++) {
        dp[i][0] = dp[i - 1][1] % cond;
        dp[i][9] = dp[i - 1][8] % cond;
        for (int j = 1; j <= 8; j++) {
            dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % cond;   // j-1이 음수와 j+1이 10일 때 처리 해야함.
        }
    }
    for (int i = 0; i <= 9; i++) {
        ans = (ans + dp[N][i]) % cond;
    }
    printf("%d", ans);
}