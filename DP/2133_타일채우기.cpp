/*
	3*2 �� ����� �� => 3

	3*4 �� ����� �� => 2 + 3*3 = 11

	3*N �� ����� �� => D[N] 
							 ���� 3*2 : 3 * D[N-2]
							 ���� 3*4 : 2 * D[N-4]
							 ���� 3*6 : ?  2�� 4�� ǥ�� ����?  2�� 4��

	���  ����
	��    ����
	��
	
	���	���    ���
	���    ���    ���
	���    ���    ���
	
	
	�����
	�����
	�����


	�������
	�������
	�������
	

	2 �� �̷���� ��.
	2�� 4�� �̷���� ��
	���Ӱ� 4ó�� ���� �� ��.

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

