#pragma warning(disable:4996)
#include <iostream>
#include <string>
using namespace std;
string s;
int dp[5001];
int main() {
	cin >> s;
	dp[0] = 1;
	for (int i = 1; i <= s.size(); i++) {
		if (1 <= s[i-1] - '0' && s[i-1] - '0' <= 9) {
			dp[i] += dp[i - 1];
			dp[i] %= 1000000;
		}
		if (i == 1) continue;
		if (10 <= (s[i - 2] - '0') * 10 + (s[i - 1] - '0') && (s[i - 2] - '0') * 10 + (s[i - 1] - '0') <= 26) {
			dp[i] += dp[i - 2];
			dp[i] %= 1000000;
		}
	}
	cout << dp[s.size()];
}