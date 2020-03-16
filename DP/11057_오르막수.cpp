/*

������ �� 
 dp[N][A] : N���� �ڸ��� A��� ��
  * N-1�ڸ����� ?   dp[N-1][A], dp[N-1][A-1] ,,, 0����

*/

#pragma warning(disable:4996)
#include <stdio.h>
#define MAX 1001
#define cond 10007

int dp[MAX][10];
int N, ans;
int main() {
    scanf("%d", &N);
    for (int i = 0; i <= 9; i++) dp[1][i] = 1;
    for (int i = 2; i <= N; i++) {
        for (int j = 0; j <= 9; j++) {
            for (int k = 0; k <= j; k++) {
                dp[i][j] += dp[i - 1][k] % cond;
            }
        }
    }
    for (int i = 0; i <= 9; i++) ans += dp[N][i] % cond;
    printf("%d", ans%cond);
}
