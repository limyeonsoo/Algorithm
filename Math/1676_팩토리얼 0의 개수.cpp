#pragma warning(disable:4996)
//#include <iostream>
//#include <algorithm>
//using namespace std;
//int N, s=1;  //a=2의 개수b=5의 개수
//int result[2];
//int main() {
//	scanf("%d", &N);
//	if (N < 5) printf("0");
//	else {
//		for (int i = 2; i <= N; i++) {
//			s = i;
//			while (s != 1) {
//				for (int i = 2; i <= s; i++)
//					if (s % i == 0) {
//						s = s / i;
//						if (i == 2) result[0]++;
//						else if (i == 5) result[1]++;
//						break;
//					}
//			}
//		}
//		printf("%d", min(result[0], result[1]));
//	}
//}

#include <iostream>
using namespace std;
int main() {
    int ans = 0;
    int n;
    cin >> n;
    for (int i = 5; i <= n; i *= 5) {
        ans += n / i;
    }
    cout << ans << '\n';
    return 0;
}