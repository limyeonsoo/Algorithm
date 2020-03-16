/*
	1 ... N ���� ������ index��ŭ ī�尡 ����ְ�, ������ �ް����ִ�. 
	ī�� ���� N, ī�� ������ MAX �� �ǵ���.
	dp[N] : 
			A[N] = dp[N-0] + dp[0] ? or
			dp[N-1] + dp[1]          or 
			dp[N-2] + dp[2]          or
			......
			dp[N-(N-1)] + dp[N-1]

*/
#pragma warning(disable:4996)
#include <iostream>
#include <algorithm>
using namespace std;
int dp[1001];
int A[1001];
int N, temp, maximum;
int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) scanf("%d", &A[i]);  //ī�� ����
	dp[1] = A[1]; dp[0] = 0;
	for (int i = 2; i <= N; i++) {
		temp = 0; maximum = 0;
		for (int k = 1; k <= i; k++) {
			temp = dp[i - k] + A[k];
			maximum < temp ? maximum = temp : maximum = maximum;
		}
		dp[i] = maximum;
	}
	printf("%d", dp[N]);
}