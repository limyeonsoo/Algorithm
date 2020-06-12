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

void init(int node, int start, int end) {
	if (start == end) tree[node].value = arr[start];
	else {
		init(node * 2, start, (start + end) / 2);
		init(node * 2 + 1, (start + end) / 2 + 1, end);
	}
}

void update(int node, int start, int end, int left, int right) {
		
	if (left > end || start > right) return;

	if (left <= start && end <= right) {
		tree[node].value += (start - left + 1);
		tree[node].lazy++;
	}
	else {
		update(node * 2, start, (start + end) / 2, left, right);
		update(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
	}
	
	
}

ll sum(int node, int start, int end, int index) {

	if (index < start || end < index)  //전혀 X
		return 0;
	if (start == end) 
		return tree[node].value;
	else {
		return sum(node * 2, start, (start + end) / 2, index) +
				sum(node * 2 + 1, (start + end) / 2 + 1, end, index) +
				tree[node].value + tree[node].lazy * (index - start); //다음 구간으로.
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N; arr.resize(N); for (int i = 0; i < N; i++) cin >> arr[i];
	cin >> QK; tree.resize((1 << (int)(ceil(log2(N)) + 1)));
	init(1, 0, N - 1);
	
	for (int i = 0; i < QK; i++) {
		cin >> q;
		int left, right, index;
		if (q == 1) {
			cin >> left >> right;
			update(1, 0, N - 1, left-1, right-1);


		}
		else {
			cin >> index;
			cout << sum(1, 0, N - 1, index-1) << '\n';
		}
	}
}