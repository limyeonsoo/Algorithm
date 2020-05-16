#include <iostream>
#include <algorithm>
using  namespace std;
long long N, K, M, m;
long long tmp;
int lan[10001];


int check(long long mid) {
	long long cnt = 0;
	for (int i = 0; i < N; i++) cnt += lan[i] / mid;
	return cnt == K ? 0 : (cnt<K?-1:1);
}

void bs(long long start, long long end) {
	while (end - start >= 0) {
		long long mid = (end + start) / 2;
		if (mid == 0) { tmp = 1; return; }
		if (check(mid) < 0) end = mid - 1;
		else {
			start = mid + 1;
			if (tmp < mid) tmp = mid;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> K;
	for (int i = 0; i < N; i++) cin >> lan[i];
	M = *max_element(lan, lan + N);
	//m = *min_element(lan, lan + N);

	bs(1, M);
	cout << tmp;
}