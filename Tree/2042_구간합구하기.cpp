#pragma warning(disable:4996)
#include <vector>
#include <iostream>
#include <math.h>
using namespace std;
typedef long long ll;
int N, M, K, q;  //N: ���� ����   M: ���� Ƚ��  K: ������ Ƚ��. q: ���� ����.
vector <long long> A;
vector <long long> tree;
//���׸�Ʈ Ʈ�� �̿�.
ll init(vector <ll>& tree, vector <ll>& arr, int node, int start, int end) {
	if (start == end) //leaf node
		return tree[node] = arr[start];
	int mid = (start + end) / 2;
	return tree[node] = init(tree, arr, node * 2, start, mid) + init(tree, arr, node * 2 + 1, mid + 1, end);
}
void update(vector <ll>& tree, int node, int start, int end, int index, ll diff) {
	if (!(start <= index && index <= end))  //���� Ȯ��.
		return;
	tree[node] += diff;  //�� ����
	if (start != end) {   //leaf node �� �ȹٲٳ�??
		int mid = (start + end) / 2;
		update(tree, node * 2, start, mid, index, diff);
		update(tree, node * 2 + 1, mid + 1, end, index, diff);
	}
}
ll sum(vector <ll> &tree, int node, int start, int end, int left, int right) {
	if (right < start || end < left)  //���� X
		return 0;
	if (left <= start && end <= right) //��� ����.
		return tree[node];
	int mid = (start + end) / 2;
	return sum(tree, node * 2, start, mid, left, right) + sum(tree, node * 2 + 1, mid + 1, end, left, right); //���� ��������.
}

int main() {
	scanf("%d %d %d", &N, &M, &K); A.resize(N); tree.resize(1 << ((int)ceil(log2(N)) + 1));
	for (int i = 0; i < N; i++) scanf("%lld", &A[i]);  //���Է�.
	init(tree, A, 1, 0, N - 1);
	for (int i = 0; i < M + K; i++) {
		scanf("%d", &q);
		if (q == 1) {  //1 -> 2�� ����
			int index;
			ll val, diff;
			scanf("%d %lld", &index, &val);
			diff = val - A[index - 1];  
			A[index - 1] = val;     // arr �� �ٲ��ְ�
			update(tree, 1, 0, N-1, index - 1, diff);
		}
		else{      // 1 ~ 2 ��.
			int left, right;
			scanf("%d %d", &left, &right);
			printf("%lld\n", sum(tree, 1, 0, N-1, left-1, right-1));
		}
	}
}