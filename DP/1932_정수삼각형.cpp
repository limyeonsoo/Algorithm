/*
	Ʈ�� ���·� ���� ��, 
	���� ����(idx : 1)�� ���� ������(idx : j)���� �� �� �ִ� ��δ� ���� �ϳ�,
	else �� �� ĭ �� �������� ����, ������ �� MAX�� ����ش�.

	��� ������ 500 * 500���� ǥ���� ���� ������, 
	���� ������ ���� ������ �־ ǥ���� �� �� �����Ƿ�,
	�޸𸮸� ���� �� �ִ�.
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
//			scanf("%d", &tree[i][j]);  //  ��, �� �ε��� 1���� Ʈ�� ���·�
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


// ������ �ѹ� ��
#include <cstdio>

int pre[501];
int now[501];
int N, input, result;
int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {      //����
		for (int j = 1; j <= i; j++) {
			pre[j] = now[j];  
		} // ���� �ٲٱ� ���� pre�迭�� ����.

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