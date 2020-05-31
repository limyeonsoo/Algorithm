#pragma warning(disable:4996)
#include <vector>
#include <iostream>
#include <math.h>

using namespace std;

typedef long long ll;
typedef struct Tree {
	ll value, lazy;
}Tree;

int N, M, K, q;  //N: 수의 개수   M: 변경 횟수  K: 구간합 횟수. q: 쿼리 종류.

vector <ll> A;
vector <Tree> tree;

//세그먼트 트리 이용.
ll init(vector <ll>& arr, int node, int start, int end) {
	if (start == end) //leaf node
		return tree[node].value = arr[start];
	return tree[node].value = init(arr, node * 2, start, (start + end) / 2) + init(arr, node * 2 + 1, (start + end) / 2 + 1, end);
}
void update(int node, int start, int end, int left, int right, ll diff) {
	//lazy
	if (tree[node].lazy != 0) {
		tree[node].value += (end - start + 1) * tree[node].lazy;  //lazy값은 값 + (diff * 구간 갯수(자식))
		if (start != end) {
			tree[node * 2].lazy += tree[node].lazy;
			tree[node * 2 + 1].lazy += tree[node].lazy;
		}
		tree[node].lazy = 0;
	}

	if (!(start <= right && left <= end))  //구간 확인.
		return;

	if (left <= start && end <= right) {
		tree[node].value += (end - start + 1) * diff;
		if (start != end) {                  //leaf가 아니면 자식에게 lazy남겨둔다.
			tree[node * 2].lazy += diff;
			tree[node * 2 + 1].lazy += diff;
		}
		return;
	}

	update(node * 2, start, (start + end) / 2, left, right, diff);
	update(node * 2 + 1, (start + end) / 2 + 1, end, left, right, diff);
	tree[node].value = tree[node * 2].value + tree[node * 2 + 1].value;  //lazy업데이트 된 value
}
ll sum(int node, int start, int end, int left, int right) {
	if (tree[node].lazy != 0) { //sum에서 구지 lazy를?
		tree[node].value += (end - start + 1) * tree[node].lazy;  //lazy값은 값 + (diff * 구간 갯수(자식))
		if (start != end) {
			tree[node * 2].lazy += tree[node].lazy;
			tree[node * 2 + 1].lazy += tree[node].lazy;
		}
		tree[node].lazy = 0;
	}
	if (right < start || end < left)  //전혀 X
		return 0;
	if (left <= start && end <= right) //모두 포함.
		return tree[node].value;

	return sum(node * 2, start, (start + end) / 2, left, right) + sum(node * 2 + 1, (start + end) / 2 + 1, end, left, right); //다음 구간으로.
}

int main() {
	scanf("%d %d %d", &N, &M, &K); A.resize(N); tree.resize(1 << ((int)ceil(log2(N)) + 1));
	for (int i = 0; i < N; i++) scanf("%lld", &A[i]);  //수입력.
	init(A, 1, 0, N - 1);
	for (int i = 0; i < M + K; i++) {
		scanf("%d", &q);
		int a, b;
		if (q == 1) {  //1 -> 2로 변경
			ll diff;
			scanf("%d %d %lld", &a, &b, &diff);
			update(1, 0, N - 1, a-1,b-1, diff);
		}
		else {      // 1 ~ 2 합.
			scanf("%d %d", &a, &b);
			printf("%lld\n", sum(1,0, N - 1, a - 1, b - 1));
		}
	}
}