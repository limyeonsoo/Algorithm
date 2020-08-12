/*
	트리 형태로 있을 때, 
	제일 왼쪽(idx : 1)과 제일 오른쪽(idx : j)으로 갈 수 있는 경로는 오직 하나,
	else 를 한 칸 전 계층에서 왼쪽, 오른쪽 중 MAX로 골라준다.

	모든 계층을 500 * 500으로 표현할 수도 있으나, 
	현재 계층과 이전 계층만 있어도 표현을 할 수 있으므로,
	메모리를 줄일 수 있다.
*/


//#include <cstdio>
//#define MAX(a,b) ((a)>(b)?(a):(b))
//
//int tree[501][501];
//int dp[501][501];
//int N, result;
//int main() {
//	scanf("%d", &N);
//	for (int i = 1; i <= N; i++) {
//		for (int j = 1; j <= i; j++) {
//			scanf("%d", &tree[i][j]);  //  행, 열 인덱스 1부터 트리 형태로
//		}
//	}
//	for (int i = 1; i <= N; i++) {
//		for (int j = 1; j <= i; j++) {
//			if (j == 1) {
//				dp[i][j] = tree[i][j] + dp[i - 1][1];
//			}
//			else if (j == i) {
//				dp[i][j] = tree[i][j] + dp[i - 1][j - 1];
//			}
//			else {
//				dp[i][j] = tree[i][j] + MAX(dp[i - 1][j - 1], dp[i - 1][j]);
//			}
//		}
//	}
//	for (int j = 1; j <= N; j++) {
//		result = (dp[N][j] > result ? dp[N][j] : result);
//	}
//
//	printf("%d", result);
//}


// 층별로 한번 씩
#include <cstdio>

int pre[501];
int now[501];
int N, input, result;
int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {      //층별
		for (int j = 1; j <= i; j++) {
			pre[j] = now[j];  
		} // 층을 바꾸기 위해 pre배열에 저장.

		for (int j = 1; j <= i; j++) {
			scanf("%d", &input);
			if (j == 1) {
				now[j] = pre[1] + input;
			}
			else if (j == i) {
				now[j] = pre[j-1] + input;
			}
			else {
				now[j] = input + (pre[j - 1] > pre[j] ? pre[j - 1] : pre[j]);
			} 
		}

	}
	for (int i = 1; i <= N; i++) {
		result = (now[i] > result ? now[i] : result);
	}

	printf("%d", result);
}