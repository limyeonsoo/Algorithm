//#include <iostream>
//#include <algorithm>
//#define ll long long
//using namespace std;
//int N, K, M, result;
//
//int tree[1000001];
//
//int check(ll mid) {
//	ll tmp = 0;
//	for (int i = 0; i < N; i++)	if(tree[i] >= mid) tmp += (tree[i] - mid);
//	if (tmp == K) return 0;
//	else if (tmp > K) return 1;
//	else return -1;	
//}
//
//void bs(ll start, ll end) {
//	while (end - start >= 0) {
//		ll mid = (end + start) / 2;
//		if (check(mid) < 0)	end = mid - 1;
//		else {
//			start = mid + 1;
//			if (result < mid) result = mid;
//		}
//	}
//}
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	cin >> N >> K;
//	for (int i = 0; i < N; i++) cin >> tree[i];
//	M = *max_element(tree, tree + N);
//	bs(0, M);
//	cout << result;
//}

#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long

using namespace std;
int H, N, M, temp, maxi;
vector <int> trees;

void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		maxi = (maxi < temp ? temp : maxi);
		trees.push_back(temp);
	}
}

bool check(int mid){
	ll sum = 0;
	for (auto& tree : trees) {
		sum += (tree - mid > 0 ? tree - mid : 0);
	}
	return sum >= M;
}

void search() {
	int left = 0;
	int right = maxi;

	while (left <= right) {
		int mid = (right - left)/2 + left;
		bool res = check(mid);
		if (res) {
			H = mid;
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
}

int main() {
	input();
	search();
	cout << H;
}