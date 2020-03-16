/*
	A[]  =>  값
	역순으로 정렬 후
	D[N]  => N까지 증가하는 부분 수열의 길이 중 가장 큰 값
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
	reverse(A+1, A+N+1);
	for (int i = 1; i <= N; i++) { // 기본 반복문 D[i]
		D[i] = 1;
		for (int j = 1; j < i; j++) { // 검색을 위한 반복문 j<i
			if (D[j] + 1 > D[i] && A[j] < A[i]) {
				D[i] = D[j] + 1;
			}
		}
	}
	printf("%d", *max_element(D, D + N + 1));
}