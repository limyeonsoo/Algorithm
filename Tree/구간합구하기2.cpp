#pragma warning(disable:4996)
#include <vector>
#include <iostream>
#include <math.h>

using namespace std;

typedef long long ll;
typedef struct Tree {
	ll value, lazy;
}Tree;

int N, M, K, q;  //N: ���� ����   M: ���� Ƚ��  K: ������ Ƚ��. q: ���� ����.

vector <ll> A;
vector <Tree> tree;

//���׸�Ʈ Ʈ�� �̿�.
ll init(vector <ll>& arr, int node, int start, int end) {
	if (start == end) //leaf node
		return tree[node].value = arr[start];
	return tree[node].value = init(arr, node * 2, start, (start + end) / 2) + init(arr, node * 2 + 1, (start + end) / 2 + 1, end);
}
void update(int node, int start, int end, int left, int right, ll diff) {
	//lazy
	if (tree[node].lazy != 0) {
		tree[node].value += (end - start + 1) * tree[node].lazy;  //lazy���� �� + (diff * ���� ����(�ڽ�))
		if (start != end) {
			tree[node * 2].lazy += tree[node].lazy;
			tree[node * 2 + 1].lazy += tree[node].lazy;
		}
		tree[node].lazy = 0;
	}

	if (!(start <= right && left <= end))  //���� Ȯ��.
		return;

	if (left <= start && end <= right) {
		tree[node].value += (end - start + 1) * diff;
		if (start != end) {                  //leaf�� �ƴϸ� �ڽĿ��� lazy���ܵд�.
			tree[node * 2].lazy += diff;
			tree[node * 2 + 1].lazy += diff;
		}
		return;
	}

	update(node * 2, start, (start + end) / 2, left, right, diff);
	update(node * 2 + 1, (start + end) / 2 + 1, end, left, right, diff);
	tree[node].value = tree[node * 2].value + tree[node * 2 + 1].value;  //lazy������Ʈ �� value
}
ll sum(int node, int start, int end, int left, int right) {
	if (tree[node].lazy != 0) { //sum���� ���� lazy��?
		tree[node].value += (end - start + 1) * tree[node].lazy;  //lazy���� �� + (diff * ���� ����(�ڽ�))
		if (start != end) {
			tree[node * 2].lazy += tree[node].lazy;
			tree[node * 2 + 1].lazy += tree[node].lazy;
		}
		tree[node].lazy = 0;
	}
	if (right < start || end < left)  //���� X
		return 0;
	if (left <= start && end <= right) //��� ����.
		return tree[node].value;

	return sum(node * 2, start, (start + end) / 2, left, right) + sum(node * 2 + 1, (start + end) / 2 + 1, end, left, right); //���� ��������.
}

int main() {
	scanf("%d %d %d", &N, &M, &K); A.resize(N); tree.resize(1 << ((int)ceil(log2(N)) + 1));
	for (int i = 0; i < N; i++) scanf("%lld", &A[i]);  //���Է�.
	init(A, 1, 0, N - 1);
	for (int i = 0; i < M + K; i++) {
		scanf("%d", &q);
		int a, b;
		if (q == 1) {  //1 -> 2�� ����
			ll diff;
			scanf("%d %d %lld", &a, &b, &diff);
			update(1, 0, N - 1, a-1,b-1, diff);
		}
		else {      // 1 ~ 2 ��.
			scanf("%d %d", &a, &b);
			printf("%lld\n", sum(1,0, N - 1, a - 1, b - 1));
		}
	}
}