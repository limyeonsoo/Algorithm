/*
��ܼ� ���ϱ�
 ���̰� N�� ��ܼ��� ���� ��.
  N �ڸ� ��  A ��, N-1�ڸ��� �� �� �ִ� ����  A+1 or A-1
  ��, ù�ڸ��� ���ڸ���  A-1 / A+1 �� �� ����.

  dp[N][A] : N �ڸ��� A��
  dp[N][A] = dp[N-1][A-1] + dp[N-1][A+1]
  dp[1] = 9����  
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
            dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % cond;   // j-1�� ������ j+1�� 10�� �� ó�� �ؾ���.
        }
    }
    for (int i = 0; i <= 9; i++) {
        ans = (ans + dp[N][i]) % cond;
    }
    printf("%d", ans);
}