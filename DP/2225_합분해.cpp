
/*
	? ? ? ? ? ? ? ? ? = N �� ��,   ?�� K��.
	dp[K][N] // K���� N�� �� ���. = dp[K-1][N-L]   �̶�, L�� 0, 1, 2, ....N����.
	3�� for��  
	1 : ���� ����
	2 : �� 
	3 : ������ �� ��  
*/
// 2����
//#pragma warning(disable:4996)
//#include <iostream>
//#define mod 1000000000
//using namespace std;
//int N, K;
//int dp[201][201];
//int main() {
//	scanf("%d %d", &N, &K);
//	for (int j = 0; j <= N; j++) {
//		dp[1][j] = 1;   // �ϳ��� ���ڷ� j�� ���� �� 1���� ���.
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

//1����

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