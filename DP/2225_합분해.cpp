
/*
	? ? ? ? ? ? ? ? ? = N 일 때,   ?는 K개.
	dp[K][N] // K개로 N이 될 경우. = dp[K-1][N-L]   이때, L은 0, 1, 2, ....N까지.
	3중 for문  
	1 : 수의 개수
	2 : 합 
	3 : 마지막 올 수  
*/
// 2차원
//#pragma warning(disable:4996)
//#include <iostream>
//#define mod 1000000000
//using namespace std;
//int N, K;
//int dp[201][201];
//int main() {
//	scanf("%d %d", &N, &K);
//	for (int j = 0; j <= N; j++) {
//		dp[1][j] = 1;   // 하나의 숫자로 j를 만들 때 1가지 방법.
//	}
//
//	for (int i = 2; i <= K; i++) {
//		for (int j = 0; j <= N; j++) {
//			for (int l = 0; l <= j; l++) {
//				dp[i][j] += dp[i - 1][j - l];
//				dp[i][j] %= mod;
//			}
//		}
//	}
//	printf("%d", dp[K][N]);
//}

//1차원

#pragma warning(disable:4996)
#include <iostream>
#define mod 1000000000
using namespace std;
int N, K;
int dp[201];
int main() {
	scanf("%d %d", &N, &K);
	
	dp[0] = 1;
	for (int i = 1; i <= K; i++) {
		for (int j = N; j >= 0; j--) {
			for (int l = 1; l <= j; l++) {
				dp[j] += dp[j - l];
				dp[j] %= mod;
			}
		}
	}
	printf("%d", dp[N]);
}