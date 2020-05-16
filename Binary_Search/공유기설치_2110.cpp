#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;
int N, K, ans;

int home[200001];

bool check(ll mid) {
	ll tmp = 1;
	ll pre = home[0];
	for (int i = 0; i < N; i++) {
		if (home[i] - pre >= mid) {
			pre = home[i];
			tmp++;
		}
	}
	if (tmp >= K) {
		return true;
	}
	else return false;
}

void bs(ll start, ll end) {
	while (end - start >= 0) {
		ll mid = (end + start) / 2;
		if (check(mid)) {
			if (ans < mid) ans = mid;
			start = mid + 1;
		}
		else {
			end = mid - 1;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> K;
	for (int i = 0; i < N; i++) cin >> home[i];
	sort(home, home + N);
	bs(1, home[N-1] - home[0]);
	cout << ans;
}