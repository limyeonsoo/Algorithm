#pragma warning(disable:4996)
#include <vector>
#include <iostream>
#include <math.h>
using namespace std;
typedef long long ll;
int N, Q, q;  //N: ���� ����   Q: ���� Ƚ��  K: ������ Ƚ��. q: ���� ����.
vector <ll> A;
vector <ll> tree;
vector <ll> lazy;
//���׸�Ʈ Ʈ�� �̿�.
ll init(vector <ll>& tree, vector <ll>& arr, int node, int start, int end) {
	if (start == end) //leaf node
		return tree[node] = arr[start];
	int mid = (start + end) / 2;
	return tree[node] = init(tree, arr, node * 2, start, mid) + init(tree, arr, node * 2 + 1, mid + 1, end);
}
void update_lazy(vector <ll>& tree, vector <ll>& lazy, int node, int start, int end) {
	if (lazy[node] != 0) { //tree�� update�Ѵ�.
		tree[node] += (end - start + 1) * lazy[node];
		//leaf�� �ƴѰ��� �����ش�. 
		if (start != end) {
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}
		lazy[node] = 0;  //update�� ���� 0;
	}
}
void update_range(vector <ll>& tree, vector <ll>& lazy, int node, int start, int end, int left, int right, ll diff) {
	update_lazy(tree, lazy, node, start, end);
	if (end < left || right < start)  //���� Ȯ��.
		return;

	if (left >= start && end <= right) {
		tree[node] += (end - start + 1) * diff;
		if (start != end) {
			lazy[node * 2] += diff;
			lazy[node * 2 + 1] += diff;
		}
		return;
	}
	int mid = (start + end) / 2;
	update_range(tree, lazy, node * 2, start, mid, left, right, diff);
	update_range(tree, lazy, node * 2 + 1, mid + 1, end, left, right, diff);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];   // �ؿ� ������Ʈ �Ǵ� ���� �����´�.
}
ll sum(vector <ll>& tree, int node, int start, int end, int left, int right) {   //lazy�� ����ؾ���.
	update_lazy(tree, lazy, node, start, end);
	if (end < left || right < start)  //���� X
		return 0;
	if (left <= start && right >= end) //��� ����.
		return tree[node];
	int mid = (start + end) / 2;
	return sum(tree, node * 2, start, mid, start, end) + sum(tree, node * 2 + 1, mid + 1, end, start, end); //���� ��������.
}

int main() {
	scanf("%d", &N); A.resize(N); tree.resize(1 << ((int)ceil(log2(N)) + 1)); lazy.resize(1 << ((int)ceil(log2(N)) + 1));
	for (int i = 0; i < N; i++) scanf("%lld", &A[i]);
	init(tree, A, 1, 0, N - 1);
	scanf("%d", &Q);  //���� ����
	while (Q--) {
		scanf("%d", &q);
		if (q == 1) {   // L, R   L->R���� �� ������.
			int left, right;
			scanf("%d %d", &left, &right);
			update_range(tree, lazy, 1, 0, N - 1, left - 1, right - 1, 1);

		}
		else {  // X   X�� ������ ���� ���� ��.
			int X;
			scanf("%d", &X);
			printf("%lld\n", sum(tree, 1, 0, N - 1, X - 1));
		}
	}
}