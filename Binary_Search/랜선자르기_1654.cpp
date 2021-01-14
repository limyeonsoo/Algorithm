//#include <iostream>
//#include <algorithm>
//using  namespace std;
//long long N, K, M, m;
//long long tmp;
//int lan[10001];
//
//
//int check(long long mid) {
//	long long cnt = 0;
//	for (int i = 0; i < N; i++) cnt += lan[i] / mid;
//	return cnt == K ? 0 : (cnt<K?-1:1);
//}
//
//void bs(long long start, long long end) {
//	while (end - start >= 0) {
//		long long mid = (end + start) / 2;
//		if (mid == 0) { tmp = 1; return; }
//		if (check(mid) < 0) end = mid - 1;
//		else {
//			start = mid + 1;
//			if (tmp < mid) tmp = mid;
//		}
//	}
//}
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	cin >> N >> K;
//	for (int i = 0; i < N; i++) cin >> lan[i];
//	M = *max_element(lan, lan + N);
//	//m = *min_element(lan, lan + N);
//
//	bs(1, M);
//	cout << tmp;
//}

#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long

using namespace std;
int N, M, temp;
vector <int> v;

void input() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> temp; v.push_back(temp);
	}
}

bool check(int mid) {
	ll sum = 0;
	for (auto& each : v) {
		sum += each / mid;
	}
	if (sum >= M) return true;
	else return false;
}

int search() {
	ll H = 0;
	ll left = 1;
	ll right = (ll)*max_element(v.begin(), v.end());
	while (left <= right) {
		ll mid = (right - left) / 2 + left;
		bool res = check(mid);
		if (res) {
			H = (H < mid ? mid : H);
			left = (ll)mid + 1;
		}
		else {
			right = (ll)mid - 1;
		}
	}
	return H;
}
int main() {
	input();
	cout << search();
}