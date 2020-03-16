/*
	3*2 의 경우의 수 => 3

	3*4 의 경우의 수 => 2 + 3*3 = 11

	3*N 의 경우의 수 => D[N] 
							 끝이 3*2 : 3 * D[N-2]
							 끝이 3*4 : 2 * D[N-4]
							 끝이 3*6 : ?  2와 4로 표현 가능?  2와 4만

	■■  가로
	□    세로
	□
	
	■■	□□    ■■
	□□    □□    ■■
	□□    ■■    ■■
	
	
	■■■■
	□■■□
	□■■□


	■■■■■■
	□■■■■□
	□■■■■□
	

	2 로 이루어진 것.
	2와 4로 이루어진 것
	새롭게 4처럼 구성 된 것.

*/


#pragma warning(disable:4996)
#include <iostream>
#define MAX 31
using namespace std;
int N;
int dp[MAX];
int main() {
	scanf("%d", &N);
	bool odd = N % 2 ? true : false;
	if (odd == true) { printf("0"); return 0; }
	dp[0] = 1; dp[2] = 3; dp[4] = 11;
	for (int i = 6; i <= N; i+=2) {
		for (int j = 0; j <= i; j += 2) {
			j == 2 ? dp[i] += dp[i - j] * 3 : dp[i] += dp[i - j] * 2;
		}
	}
	printf("%d", dp[N]);
}

