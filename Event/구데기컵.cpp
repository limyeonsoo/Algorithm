//#pragma warning(disable:4996)
//#include <iostream>
//#include <algorithm>
//using namespace std;
//int N;
//long long dp[100001];
//long long A[100001];
//int main() {
//	scanf("%d", &N);
//	for (int i = 1; i <= N; i++) {
//		scanf("%lld", &A[i]);
//	}
//	dp[1] = A[1];
//	for (int i = 2; i <= N; i++) {
//		dp[i] = max(dp[i - 1] + A[i], A[i]);
//	}
//	printf("%lld", *max_element(dp + 1, dp + N + 1));
//}

#pragma warning(disable:4996)
#include <iostream>
#include <string>
using namespace std;
//int T, odd, even;
//string s;
//int main() {
//	cin.tie(NULL);
//	ios_base::sync_with_stdio(false);
//	cin >> T;
//	while (T--) {
//		cin >> s; odd = 0; even = 0;
//		
//		for (int i = 0; i < s.length(); i++) {
//			if ((s[i] - '0') > 9 || (s[i] - '0') < 1) continue;
//			(s[i] - '0') % 2 == 0 ? even++ : odd++;
//			if (even > (s.length() / 2)) break;
//		}
//		if(even!=0 || odd!=0) cout << ((even >= odd) ? "O" : "E") << '\n';
//	}
//}
int T;
long long temp, sum;
int main() {
	scanf("%d", &T);
	while (T--) {
		sum = 0;
		for (int i = 0; i < 28; i++) {
			for (int j = 0; j < 28; j++) {
				scanf("%lld", &temp);
				sum += temp;
			}
		}
		printf("%lld\n", sum);
	}
}