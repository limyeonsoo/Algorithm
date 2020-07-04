//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <math.h>
//#define INF 1000000001
//using namespace std;
//
//int N, temp, qn, q, pos;
//vector <pair<int, int> > value; //value & index
//vector <pair<int, int> > tree;
//
//pair<int,int> init(int node, int start, int end) {
//	if (start == end) {//leaf node
//		tree[node] = value[start];
//		return tree[node];
//	}
//	else {
//		int mid = (start + end) / 2;
//		if (init(node * 2, start, mid).first == init(node * 2 + 1, mid + 1, end).first) {
//			return tree[node] = tree[node*2];
//		}
//		else {
//			if (init(node * 2, start, mid).first < init(node * 2 + 1, mid + 1, end).first) {
//				return tree[node] = tree[node * 2];
//			}
//			else {
//				return tree[node] =tree[node * 2 + 1];
//			}
//		}
//	}
//}
//
//pair<int, int> update(int node, int start, int end, int idx, int value) {
//	if (start > idx || idx > end) {
//		return tree[node];
//	}
//	if (start == end) {
//		tree[node].first = value;
//		return tree[node];
//	}
//	else {
//		int mid = (start + end) / 2;
//		int l = update(node * 2, start, mid, idx, value).first;
//		int r = update(node * 2 + 1, mid + 1, end, idx, value).first;
//		if (l == r) {
//			return tree[node] = tree[node * 2];
//		}
//		else {
//			if (l < r) {
//				return tree[node] = tree[node * 2];
//			}
//			else {
//				return tree[node] = tree[node * 2+1];
//			}
//		}
//	}
//
//}
//pair<int, int> print(int node, int start, int end, int left, int right) {
//	if (left > end || right < start) {
//		return { INF, INF };
//	}
//	if (left <= start && end <= right) { //모두 포함
//		return tree[node];
//	}
//	else {
//		int mid = (start + end) / 2;
//		pair<int, int> l = print(node * 2, start, mid, left, right);
//		pair<int, int> r = print(node * 2+1, mid+1, end, left, right);
//		if (l.first == r.first) {
//			if (l.second < r.second) return l;
//			else return r;
//		}
//		else {
//			if (l.first < r.first) {
//				return l;
//			}
//			else {
//				return r;
//			}
//		}
//	}
//}
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cin >> N; value.resize(N);
//	tree.resize(1 << ((int)ceil(log2(N)) + 1));
//	for (int i = 0; i < N; i++) {
//		cin >> temp;
//		value[i] = { temp, i+1 }; // 배열의 index를 1부터 매김.
//	}
//	init(1, 0, N - 1);
//	
//	cin >> qn;
//	while (qn--) {
//		cin >> q;
//		if (q == 1) {
//			int idx, value;
//			cin >> idx >> value;
//			update(1, 0, N - 1, idx - 1, value);
//		}
//		else if (q == 2) {
//			int left, right;
//			cin >> left >> right;
//			cout << print(1, 0, N - 1, left - 1, right - 1).second << '\n';
//		}
//	}
//}

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
vector <int> v;
int N, M, temp;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N; v.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> temp; v[i] = temp;
    }
    sort(v.begin(), v.end());
    cin >> M;
    while (M--) {
        cin >> temp;
        cout << (binary_search(v.begin(), v.end(), temp) ? "1" : "0") << " ";
    }
}