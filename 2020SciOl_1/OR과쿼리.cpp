//////#pragma warning(disable:4996)
//////#include <iostream>
//////#include <algorithm>
//////using namespace std;
//////int N, K, M;
//////int A[250001];
//////int q, l, r, x;   // l은 시작 범위 , r은 끝 범위, x는 OR할 값.
//////int main() {
//////	scanf("%d %d", &N, &K);  // 길이 N 과 비교값 K.
//////	for (int i = 1; i <= N; i++) scanf("%d", &A[i]);    //수열 입력 받는다. N만큼.
//////	scanf("%d", &M);  // 쿼리의 개수 M.
//////	for (int i = 0; i < M; i++) {
//////		scanf("%d", &q);
//////		if (q == 1) { //1번 쿼리
//////			scanf("%d %d %d", &l, &r, &x);
//////			for (int i = l; i <= r; i++) A[i] = A[i] | x;
//////		}
//////		else {  //2번 쿼리.
//////			scanf("%d %d", &l, &r);			
//////			printf("%d\n", count(A+l, A+r+1, K));
//////		}
//////	}	
//////}
////
////// 합해놓은거 구하는거는 더 시간초과
////#pragma warning(disable:4996)
////#include <iostream>
////#include <algorithm>
////#include <vector>
////
////using namespace std;
////int N, M;
////unsigned int K;
////unsigned int sum[250001];
////unsigned int A[250001];
////vector <unsigned int> v;
////int q, l, r;   // l은 시작 범위 , r은 끝 범위, x는 OR할 값.
////unsigned int temp, x;
////
////
////int main() {
////	scanf("%d %u", &N, &K);  // 길이 N 과 비교값 K.
////	v.resize(N + 1);
////	for (int i = 1; i <= N; i++) {
////		scanf("%u", &temp);
////		v[i] |= temp;
////		v[i] == K ? A[i] = K : A[i] = 0;
////		if (i == 1) sum[i] = A[i];
////		else sum[i] = sum[i - 1] + A[i];
////	}
////
////	scanf("%d", &M);  // 쿼리의 개수 M.
////	for (int i = 0; i < M; i++) {
////		scanf("%d", &q);
////		if (q == 1) { //1번 쿼리
////			scanf("%d %d %u", &l, &r, &x);
////			for (int i = l; i <= r; i++) {
////				temp = v[i] | x;
////				v[i] |= x;
////				temp == K ? A[i] = K : A[i] = 0;
////			}
////			for (int i = 1; i <= N; i++) {
////				if (i == 1) sum[i] = A[i];
////				else sum[i] = sum[i - 1] + A[i];
////			}
////		}
////		else {  //2번 쿼리.
////			scanf("%d %d", &l, &r);
////			printf("%d\n", (sum[r] - sum[l-1])/K);
////		}
////	}
////}
//
//////// https://www.crocus.co.kr/648 세그먼트 트리 이용.
//
//#pragma warning(disable:4996)
//#include <vector>
//#include <iostream>
//#include <algorithm>
//#include <math.h>
//typedef long long ll;
//typedef unsigned int ui;
//using namespace std;
//int N, K, M, q;
////long long A[250001];  //A 값의 범위는 2^30  int를 써도 될까?
//vector <ui> A;
//vector <ll> tree;
//vector <ll> lazy;
//ll init(vector <ll> &tree, vector <ui> &arr, int node, int start, int end){
//	if (start == end) //  leaf  node 하나만 남았다. 노드의 범위가 1인 리프노드
//	{
//		arr[start] == K ? tree[node] = K : tree[node] = 0;
//		return tree[node];
//	}
//	int mid = (start + end) / 2;
//	return tree[node] = init(tree, arr, node * 2, start, mid) + init(tree, arr, node * 2 + 1, mid + 1, end);
//}
//void update_lazy(vector <ll>& tree, vector <ll>& lazy, int node, int start, int end, int index) {
//	if (lazy[node] != 0) { //tree를 update한다.
//		tree[node] += lazy[node];
//		//leaf가 아닌곳에 물려준다. 
//		lazy[index] += lazy[node];
//		/*if (start != end) {
//			lazy[node * 2] += lazy[node];
//			lazy[node * 2 + 1] += lazy[node];
//		}*/
//		lazy[node] = 0;  //update한 곳은 0;
//	}
//}
//void update(vector <ll>& tree, vector <ll> &lazy, int node, int start, int end, int index, int diff) {
//	update_lazy(tree, lazy, node, start, end, index);
//	if (!(start <= index && index <= end))   // 구간이 아닌 노드는 제외.
//		return;
//	if (start <= index&& index <= end) {
//		//tree[node] += diff;
//		if (start != end) {
//			lazy[node] += diff;
//		}
//		return;
//	}
//	int mid = (start + end) / 2;
//	update(tree, lazy, node * 2, start, mid, index, diff);
//	update(tree, lazy, node * 2 + 1, mid + 1, end, index, diff);
//	tree[node] = tree[node * 2] + tree[node * 2 + 1];   // 밑에 업데이트 되는 것을 가져온다.
//}
//
//ll K_count(vector <ll>& tree, vector <ll> &lazy, int node, int start, int end, int left, int right) { //합은 총 4가지 경우.
//	update_lazy(tree, lazy, node, start, end, start);
//	if (left > end || start > right) // 구하려는 구간이 범위 밖.
//		return 0;
//	if (left <= start && end <= right) //구하려는 구간이 더 큰 경우.
//		return tree[node];    //합을 리턴.
//
//	int mid = (start + end) / 2;
//	return K_count(tree, lazy, node * 2, start, mid, left, right) + K_count(tree, lazy, node * 2 + 1, mid + 1, end, left, right); //다음 노드 탐색.
//}
//
//int main() {
//	scanf("%d %u", &N, &K); //N은 수열의 크기, K는 만족해야할 값.
//	A.resize(N); tree.resize(1 << (int)ceil(log2(N)) + 1); lazy.resize(1 << (int)ceil(log2(N)) + 1);
//	for (int i = 0; i < N; i++) scanf("%u", &A[i]); //수열 입력.
//	init(tree, A, 1, 0, N - 1);
//	scanf("%d", &M); // 쿼리의 개수
//	while (M--) {
//		int left, right;
//		scanf("%d", &q); //쿼리의 종류.
//		//for (int i = 0; i < A.size(); i++) printf("%d ", A[i]); printf("\n");
//		//for (int i = 0; i < tree.size(); i++) printf("%d ", tree[i]); printf("\n");
//		if (q == 1) {  // 1~2까지 3과 OR.
//			unsigned int x;
//			scanf("%d %d %u", &left, &right, &x);
//			for (int i = left - 1; i < right; i++) {
//				if (A[i] > K) continue;
//				if (A[i] != (ui)K && (A[i] | x) == (ui)K) {
//					update(tree, lazy, 1, 0, N - 1, i, K);  // 원래 아닌데 K가 새로 생겼다.
//					//printf("== %u %u %u ==\n", A[i], A[i] | x, (A[i]|x)==K);
//				}
//				else if (A[i] == (ui)K && (A[i] | x) != K){
//					update(tree, lazy, 1, 0, N - 1, i, -K);  //원래 K  바꾼 후 아님.                        
//					//printf("===%u %u %u===\n", A[i], A[i] | x, (A[i] | x) == K);
//				}	
//				A[i] |= x;
//			}
//			//for (int i = 0; i < A.size(); i++) printf("%d ", A[i]); printf("\n");
//			//for (int i = 0; i < tree.size(); i++) printf("%d ", tree[i]); printf("\n");
//		}
//		else if (q == 2) { // 1~2까지 K인 개수.
//			scanf("%d %d", &left, &right);
//			printf("%lld\n", (long long)K_count(tree, lazy, 1, 0, N - 1, left-1, right-1)/K);
//		}
//	}
//}

#pragma warning(disable:4996)
#include <iostream>
using namespace std;
int main() {
	int N;
	scanf("%d", &N);
	printf("%d %d %d %d %d %d", N /= 10000, N /= 1000, N /= 500, N /= 100, N /= 50, N /= 10);
}