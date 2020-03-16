//#pragma warning(disable:4996)
//#include <iostream>
//using namespace std;
//int dp[3001];
//int N, X;
//int main() {
//	scanf("%d %d", &N, &X);
//	
//	for (int i = 1; i <= 3; i++) dp[i] = 1;
//	for (int i = 4; i <= N; i++) {
//		dp[i] = (dp[i - 1] + dp[i - 2]) % X;
//	}
//	printf("%d", dp[N]%X);
//}

#pragma warning(disable:4996)
#include <iostream>
using namespace std;
int dp[3001][5];
int N, X;
int main() {
	scanf("%d %d", &N, &X);

	for (int i = 1; i <= 3; i++) dp[i] = 1;

	for (int i = 4; i <= N; i++) {
		for (int k = 1; k <= 4; k++) {
			if (i - k < 4) continue;
			for (int j = 1; j <= 4; j++) {
				dp[i][k] += dp[i - k][j];
			}
			
		}
		
		dp[i] = (dp[i - 1] + dp[i - 2]) % X;
	}
	printf("%d", dp[N] % X);
}
