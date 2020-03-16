/*
	n��° Ÿ���� ä��� ��� :
	  1. n��°��  2X1  => dp[n-1] �� ���̱�;
	  2. n��°��  1X2 2 => dp[n-2] �� ���̱�;
	  ��, dp[n-1] + dp[n-2] => dp[n]

	
	* ������ ����.
*/
#pragma warning(disable: 4996)
#include <iostream>
using namespace std;

int dp[1001];
int N;
int main() {
	scanf("%d", &N);
	dp[0] = dp[1] = 1;
	for (int i = 2; i <= N; i++) dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;
	printf("%d", dp[N]);
}