#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long
using namespace std;
ll result, N, K;
vector <ll> v;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> K;
	ll start = 1; ll end = K;
	while (end - start >= 0) {
		ll mid = (start + end) / 2;
		ll sum = 0;
		for (int i = 1; i <= N; i++) sum += min((ll)N, mid / i);   //sum
		if (sum >= K) {
			result = mid;
			end = mid - 1;
		}
		else start = mid + 1;
	}
	cout << result;
}
