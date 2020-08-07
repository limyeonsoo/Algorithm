#include <iostream>
using namespace std;
int T, N;
pair<int, int> dp[41] = { {1,0}, {0, 1}, {1, 1} };
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	for (int i = 3; i <= 40; i++) {
		dp[i].first = dp[i - 1].first + dp[i - 2].first;
		dp[i].second = dp[i - 1].second + dp[i - 2].second;
	}
	cin >> T;
	while (T--) {
		cin >> N;
		cout << dp[N].first << ' ' << dp[N].second << '\n';
	}
}