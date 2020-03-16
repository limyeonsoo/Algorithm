/*
	���� N�� ����� ���ؼ�   o + o + o + o + ? = N
	           => ? ���� 1, 2, 3
			   1: �տ� sum(o) = N-1;
			   2: �տ� sum(o) = N-2;
			   3: �տ� sum(o) = N-3;
*/
#pragma warning(disable: 4996)
#include <iostream>
using namespace std;

int dp[12];
int N, T;
int main() {
	scanf("%d", &T); 
	while (T--) {
		scanf("%d", &N);
		dp[1] = 1; dp[2] = 2; dp[3] = 4;
		for (int i = 4; i <= N; i++) dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
		printf("%d\n", dp[N]);
	}
}