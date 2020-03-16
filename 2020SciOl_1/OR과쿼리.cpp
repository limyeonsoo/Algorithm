//#pragma warning(disable:4996)
//#include <iostream>
//#include <algorithm>
//using namespace std;
//int N, K, M;
//int A[250001];
//int q, l, r, x;   // l은 시작 범위 , r은 끝 범위, x는 OR할 값.
//int main() {
//	scanf("%d %d", &N, &K);  // 길이 N 과 비교값 K.
//	for (int i = 1; i <= N; i++) scanf("%d", &A[i]);    //수열 입력 받는다. N만큼.
//	scanf("%d", &M);  // 쿼리의 개수 M.
//	for (int i = 0; i < M; i++) {
//		scanf("%d", &q);
//		if (q == 1) { //1번 쿼리
//			scanf("%d %d %d", &l, &r, &x);
//			for (int i = l; i <= r; i++) A[i] = A[i] | x;
//		}
//		else {  //2번 쿼리.
//			scanf("%d %d", &l, &r);			
//			printf("%d\n", count(A+l, A+r+1, K));
//		}
//	}	
//}

// 합해놓은거 구하는거는 더 시간초과
#pragma warning(disable:4996)
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int N, M;
unsigned int K;
unsigned int sum[250001];
unsigned int A[250001];
vector <unsigned int> v;
int q, l, r;   // l은 시작 범위 , r은 끝 범위, x는 OR할 값.
unsigned int temp, x;


int main() {
	scanf("%d %u", &N, &K);  // 길이 N 과 비교값 K.
	v.resize(N + 1);
	for (int i = 1; i <= N; i++) {
		scanf("%u", &temp);
		v[i] |= temp;
		v[i] == K ? A[i] = K : A[i] = 0;
		if (i == 1) sum[i] = A[i];
		else sum[i] = sum[i - 1] + A[i];
	}

	scanf("%d", &M);  // 쿼리의 개수 M.
	for (int i = 0; i < M; i++) {
		scanf("%d", &q);
		if (q == 1) { //1번 쿼리
			scanf("%d %d %u", &l, &r, &x);
			for (int i = l; i <= r; i++) {
				temp = v[i] | x;
				v[i] |= x;
				temp == K ? A[i] = K : A[i] = 0;
			}
			for (int i = 1; i <= N; i++) {
				if (i == 1) sum[i] = A[i];
				else sum[i] = sum[i - 1] + A[i];
			}
		}
		else {  //2번 쿼리.
			scanf("%d %d", &l, &r);
			printf("%d\n", (sum[r] - sum[l-1])/K);
		}
	}
}
