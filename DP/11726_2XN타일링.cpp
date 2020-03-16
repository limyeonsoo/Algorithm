/*
	n번째 타일을 채우는 방법 :
	  1. n번째에  2X1  => dp[n-1] 에 붙이기;
	  2. n번째에  1X2 2 => dp[n-2] 에 붙이기;
	  즉, dp[n-1] + dp[n-2] => dp[n]

	
	* 함정이 있음.
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