/*
	A[]  =>  값
	D[N]  => N까지 증가하는 부분 수열 합 중 가장 큰 값
	D[N] = MAX( D[N-1], D[N-2] , ... , )
*/

#pragma warning(disable:4996)
#include <iostream>
#include <algorithm>
#define MAX 1001
using namespace std;
int N;
int A[MAX];
int D[MAX];
int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &A[i]);
	}

	for (int i = 1; i <= N; i++) { // 기본 반복문 D[i]
		D[i] = A[i];
		for (int j = 1; j < i; j++) { // 검색을 위한 반복문 j<i
			if (D[j] + A[i] > D[i] && A[j] < A[i]) {
				D[i] = D[j] + A[i];
			}
		}
	}
	printf("%d", *max_element(D, D + N + 1));
}