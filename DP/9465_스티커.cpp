/*
	스티커는 2열에 N행으로 이루어져있다. 
	N행에 올 수 있는 3가지의 경우의 수 

	dp[N][0] : X    
	           X
			     => max( dp[N-1][0] + dp[N-1][1] + dp[N-1][2] )    +  N에서 선택 X
	dp[N][1] : O
	           X
			     => max( dp[N-1][0] + dp[N-1][2] )   + N 에서  A[0] 선택.
	dp[N][2] : X
	           O
			     => max( dp[N-1][0] + dp[N-1][1] )   + N 에서  A[1] 선택.

	* 인덱스 조심.
*/
#pragma warning(disable:4996)
#include <iostream>
#include <algorithm>
using namespace std;
long long dp[100001][3];
int A[2][100001];
int N, T;
int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &N);
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < N; j++) {
				scanf("%d", &A[i][j]);
			}
		}
		dp[0][0] = dp[0][1] = dp[0][2] = 0; 
		for (int i = 1; i <= N; i++) {
			dp[i][0] = max({ dp[i - 1][0], dp[i - 1][1], dp[i - 1][2] });
			dp[i][1] = max(dp[i - 1][0], dp[i - 1][2]) + A[0][i-1];
			dp[i][2] = max(dp[i - 1][0], dp[i - 1][1]) + A[1][i-1];
		}
		printf("%lld\n", max({dp[N][0], dp[N][1], dp[N][2]}));
	}
}

/*
#include<iostream>
#define max(a,b) (a>b ? a:b)
using namespace std;
long long D[100001][3];
long long a[100001][2];

int main() {
	int T, N;
	cin >> T;
	while (T--) {
		scanf("%d", &N);
		for (int i = 1; i <= N; i++) {
			scanf("%lld", &a[i][0]);
		}
		for (int i = 1; i <= N; i++) {
			scanf("%lld", &a[i][1]);
		}
		D[0][0] = D[0][1] = D[0][2] = 0;

		for (int i = 1; i <= N; i++)
		{
			D[i][0] = max(D[i - 1][0], max(D[i - 1][1], D[i - 1][2]));
			D[i][1] = max(D[i - 1][0], D[i - 1][2]) + a[i][0];
			D[i][2] = max(D[i - 1][0], D[i - 1][1]) + a[i][1];
		}
		long long ans = 0;
		for (int i = 1; i <= N; i++)
			ans = max(max(ans, D[i][0]), max(D[i][1], D[i][2]));
		printf("%lld\n", ans);
	}
}
*/