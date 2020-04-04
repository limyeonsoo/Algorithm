#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
ll n, m, temp;
ll result[2];
int main() {
	cin >> n >> m;
	// n!  m!  n-m !
	for (ll i = 2; i <= n; i *= 2) {
		result[0] += n / i;
	}
	for (ll i = 2; i <= m; i *= 2) {
		result[0] -= m / i;
	}
	for (ll i = 2; i <= n - m; i *= 2) {
		result[0] -= (n - m) / i;
	}
	for (ll i = 5; i <= n; i *= 5) {
		result[1] += n / i;
	}
	for (ll i = 5; i <= m; i *= 5) {
		result[1] -= m / i;
	}
	for (ll i = 5; i <= n - m; i *= 5) {
		result[1] -= (n-m) / i;
	}
	(result[0] < 1 || result[1] < 1) ? cout << '0' : cout << min(result[0], result[1]);
}
