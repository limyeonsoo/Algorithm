//////#pragma warning(disable:4996)
//////#include <iostream>
//////#include <algorithm>
//////using namespace std;
//////int N, K, M;
//////int A[250001];
//////int q, l, r, x;   // l�� ���� ���� , r�� �� ����, x�� OR�� ��.
//////int main() {
//////	scanf("%d %d", &N, &K);  // ���� N �� �񱳰� K.
//////	for (int i = 1; i <= N; i++) scanf("%d", &A[i]);    //���� �Է� �޴´�. N��ŭ.
//////	scanf("%d", &M);  // ������ ���� M.
//////	for (int i = 0; i < M; i++) {
//////		scanf("%d", &q);
//////		if (q == 1) { //1�� ����
//////			scanf("%d %d %d", &l, &r, &x);
//////			for (int i = l; i <= r; i++) A[i] = A[i] | x;
//////		}
//////		else {  //2�� ����.
//////			scanf("%d %d", &l, &r);			
//////			printf("%d\n", count(A+l, A+r+1, K));
//////		}
//////	}	
//////}
////
////// ���س����� ���ϴ°Ŵ� �� �ð��ʰ�
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
////int q, l, r;   // l�� ���� ���� , r�� �� ����, x�� OR�� ��.
////unsigned int temp, x;
////
////
////int main() {
////	scanf("%d %u", &N, &K);  // ���� N �� �񱳰� K.
////	v.resize(N + 1);
////	for (int i = 1; i <= N; i++) {
////		scanf("%u", &temp);
////		v[i] |= temp;
////		v[i] == K ? A[i] = K : A[i] = 0;
////		if (i == 1) sum[i] = A[i];
////		else sum[i] = sum[i - 1] + A[i];
////	}
////
////	scanf("%d", &M);  // ������ ���� M.
////	for (int i = 0; i < M; i++) {
////		scanf("%d", &q);
////		if (q == 1) { //1�� ����
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
////		else {  //2�� ����.
////			scanf("%d %d", &l, &r);
////			printf("%d\n", (sum[r] - sum[l-1])/K);
////		}
////	}
////}
//
//////// https://www.crocus.co.kr/648 ���׸�Ʈ Ʈ�� �̿�.
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
////long long A[250001];  //A ���� ������ 2^30  int�� �ᵵ �ɱ�?
//vector <ui> A;
//vector <ll> tree;
//vector <ll> lazy;
//ll init(vector <ll> &tree, vector <ui> &arr, int node, int start, int end){
//	if (start == end) //  leaf  node �ϳ��� ���Ҵ�. ����� ������ 1�� �������
//	{
//		arr[start] == K ? tree[node] = K : tree[node] = 0;
//		return tree[node];
//	}
//	int mid = (start + end) / 2;
//	return tree[node] = init(tree, arr, node * 2, start, mid) + init(tree, arr, node * 2 + 1, mid + 1, end);
//}
//void update_lazy(vector <ll>& tree, vector <ll>& lazy, int node, int start, int end, int index) {
//	if (lazy[node] != 0) { //tree�� update�Ѵ�.
//		tree[node] += lazy[node];
//		//leaf�� �ƴѰ��� �����ش�. 
//		lazy[index] += lazy[node];
//		/*if (start != end) {
//			lazy[node * 2] += lazy[node];
//			lazy[node * 2 + 1] += lazy[node];
//		}*/
//		lazy[node] = 0;  //update�� ���� 0;
//	}
//}
//void update(vector <ll>& tree, vector <ll> &lazy, int node, int start, int end, int index, int diff) {
//	update_lazy(tree, lazy, node, start, end, index);
//	if (!(start <= index && index <= end))   // ������ �ƴ� ���� ����.
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
//	tree[node] = tree[node * 2] + tree[node * 2 + 1];   // �ؿ� ������Ʈ �Ǵ� ���� �����´�.
//}
//
//ll K_count(vector <ll>& tree, vector <ll> &lazy, int node, int start, int end, int left, int right) { //���� �� 4���� ���.
//	update_lazy(tree, lazy, node, start, end, start);
//	if (left > end || start > right) // ���Ϸ��� ������ ���� ��.
//		return 0;
//	if (left <= start && end <= right) //���Ϸ��� ������ �� ū ���.
//		return tree[node];    //���� ����.
//
//	int mid = (start + end) / 2;
//	return K_count(tree, lazy, node * 2, start, mid, left, right) + K_count(tree, lazy, node * 2 + 1, mid + 1, end, left, right); //���� ��� Ž��.
//}
//
//int main() {
//	scanf("%d %u", &N, &K); //N�� ������ ũ��, K�� �����ؾ��� ��.
//	A.resize(N); tree.resize(1 << (int)ceil(log2(N)) + 1); lazy.resize(1 << (int)ceil(log2(N)) + 1);
//	for (int i = 0; i < N; i++) scanf("%u", &A[i]); //���� �Է�.
//	init(tree, A, 1, 0, N - 1);
//	scanf("%d", &M); // ������ ����
//	while (M--) {
//		int left, right;
//		scanf("%d", &q); //������ ����.
//		//for (int i = 0; i < A.size(); i++) printf("%d ", A[i]); printf("\n");
//		//for (int i = 0; i < tree.size(); i++) printf("%d ", tree[i]); printf("\n");
//		if (q == 1) {  // 1~2���� 3�� OR.
//			unsigned int x;
//			scanf("%d %d %u", &left, &right, &x);
//			for (int i = left - 1; i < right; i++) {
//				if (A[i] > K) continue;
//				if (A[i] != (ui)K && (A[i] | x) == (ui)K) {
//					update(tree, lazy, 1, 0, N - 1, i, K);  // ���� �ƴѵ� K�� ���� �����.
//					//printf("== %u %u %u ==\n", A[i], A[i] | x, (A[i]|x)==K);
//				}
//				else if (A[i] == (ui)K && (A[i] | x) != K){
//					update(tree, lazy, 1, 0, N - 1, i, -K);  //���� K  �ٲ� �� �ƴ�.                        
//					//printf("===%u %u %u===\n", A[i], A[i] | x, (A[i] | x) == K);
//				}	
//				A[i] |= x;
//			}
//			//for (int i = 0; i < A.size(); i++) printf("%d ", A[i]); printf("\n");
//			//for (int i = 0; i < tree.size(); i++) printf("%d ", tree[i]); printf("\n");
//		}
//		else if (q == 2) { // 1~2���� K�� ����.
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