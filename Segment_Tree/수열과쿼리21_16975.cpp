#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#define INF 1000000001
using namespace std;

int N, temp, qn, q, pos;
vector <int> value;
vector <int> tree;

int init(int node, int start, int end) {
	if (start == end) return tree[node] = value[start];
	else {
		return tree[node] = min(init(node * 2, start, (start + end) / 2),
			init(node * 2 + 1, (start + end) / 2 + 1, end));
	}
}
int update(int node, int start, int end, int index, int value) {
	if (!(start <= index && index <= end))  //구간 확인.
		return tree[node];
	if (start == end) {
		//cout << "st == end node : " << node << '\n';
		return tree[node] = value;
	}
	return tree[node] = min(update(node * 2, start, (start + end) / 2, index, value), update(node * 2 + 1, (start + end) / 2 + 1, end, index, value));

}

int print(int node, int start, int end, int left, int right) {
	if (right < start || end < left)  //전혀 X
		return INF;
	if (left <= start && end <= right) { //모두 포함.
		return tree[node];
	}
	int mid = (start + end) / 2;
	return min(print(node * 2, start, mid, left, right),
		print(node * 2 + 1, mid + 1, end, left, right)); //다음 구간으로.
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N; value.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> temp;
		value[i] = temp;
	}
	pos = pow(2, (int)ceil(log2(N)) - 1);
	tree.resize(1 << ((int)ceil(log2(N)) + 1));
	init(1, 0, N - 1);

	cin >> qn;
	while (qn--) {
		cin >> q;
		if (q == 1) {
			int idx, value;
			cin >> idx >> value;
			update(1, 0, N - 1, idx - 1, value);

		}
		else if (q == 2) {
			int left, right;
			cin >> left >> right;
			cout << print(1, 0, N - 1, left - 1, right - 1) << '\n';
		}
	}

}