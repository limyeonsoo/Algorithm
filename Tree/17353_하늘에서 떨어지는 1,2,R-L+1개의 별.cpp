#include <iostream>
#include <vector>
#include <math.h>
#define ll long long
using namespace std;
typedef struct Tree {
	ll value;
	ll lazy;
};
vector <int> arr;
vector <Tree> tree;
int N, QK, q;

ll init(int node, int start, int end) {
	if (start == end) return tree[node].value = arr[start];
	return tree[node].value = init(node * 2, start, (start + end) / 2) + init(node * 2 + 1, (start + end) / 2 + 1, end);
}

void update(int node, int start, int end, int left, int right) {
	if (tree[node].lazy != 0) { //lazy update
		tree[node].value += tree[node].lazy * (end - start + 1);
		if (start != end) {
			tree[node * 2].lazy += tree[node].lazy;
			tree[node * 2 + 1].lazy += tree[node].lazy;
		}
		tree[node].lazy = 0;
	}
	
	if (left > end || start > right) return;

	if (left <= start && end <= right) {
		tree[node].value += right * (right + 1) / 2 - left * (left - 1) / 2;
		if (start != end) { 
			tree[node*2].lazy += ((right + left) / 2) * (((right + left) / 2) + 1) / 2 - left * (left - 1) / 2;
			tree[node*2+1].lazy += right * (right + 1) / 2 - ((right + left) / 2 + 1) * (((right + left) / 2 + 1) - 1) / 2;
		}
		return;
	}

	update(node, start, (start + end)/2, left, right);
	update(node, (start+end)/2+1, end, left, right);
	tree[node].value = tree[node * 2].value + tree[node * 2 + 1].value;
	
}

ll sum(int node, int start, int end, int index) {
	if (tree[node].lazy != 0) { //lazy update
		tree[node].value += tree[node].lazy * (end - start + 1);
		if (start != end) {
			tree[node * 2].lazy += tree[node].lazy;
			tree[node * 2 + 1].lazy += tree[node].lazy;
		}
		tree[node].lazy = 0;
	}

	if (index < start || end < index)  //전혀 X
		return 0;
	if (index <= start && end <= index) //모두 포함.
		return tree[node].value;

	return sum(node * 2, start, (start + end) / 2, index) + sum(node * 2 + 1, (start + end) / 2 + 1, end, index); //다음 구간으로.
}


int main() {
	cin >> N; arr.resize(N); for (int i = 0; i < N; i++) cin >> arr[i];
	cin >> QK; tree.resize((1 << (int)(ceil(log2(N)) + 1)));
	init(1, 0, N - 1);
	for (int i = 0; i < QK; i++) {
		cin >> q;
		int left, right, index;
		if (q == 1) {
			cin >> left >> right;
			update(1, 0, N - 1, left, right);
		}
		else {
			cin >> index;
			cout << sum(1, 0, N - 1, index) << '\n';
		}
	}
}