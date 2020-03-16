/*
1. 2. 3. 중  3으로 나눌 수록 크기가 작아짐. 우선순위UP -> 2로 나누기 -> 1 빼기  X 
 -> 10의 경우  1을 빼고  3을 나누면 3번 만에 가능함.

 정수 N을 1로 만드는데 연산을 사용하는 횟수의 최소값을  D배열에 저장해놓자. 




 D[N] : N정수를 1로 만드는 데 걸리는 최소 횟수.
 D[N] = D[N/3] + 1 
 D[N] = D[N/2] + 1
 D[N] = D[N-1] + 1
	 =>  D[N] = min(1,2,3)

*/


// Top - down
//#pragma warning (disable:4996)
//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//int N;
//int dp[1000001];
//int make_one(int x) {
//	if (x == 1) return 0;   //1은 1이다.
//	if (dp[x] > 0) return dp[x];  // memorization 활용
//
//	dp[x] = make_one(x-1) + 1;                            // 1을 빼었을 때 최소인가?
//
//	if (x % 3 == 0) {                                     // 3으로 나누어 떨어질 때 최소인가?
//		if (dp[x] > make_one(x / 3) + 1) dp[x] = make_one(x / 3) + 1;
//	}
//
//	if (x % 2 == 0) {                                     //2로 나누어 떨어질 때 최소인가?
//		if (dp[x] > make_one(x / 2) + 1) dp[x] = make_one(x / 2) + 1;
//	}
//
//	return dp[x];
//}
//
//int main() {
//	scanf("%d", &N);
//	printf("%d", make_one(N));
//}


// Bottom - up
#pragma warning (disable:4996)
#include <iostream>
#include <algorithm>
using namespace std;

int N, a,b,c;
int dp[1000001];

int main() {
	scanf("%d", &N);
	
    for (int i = 2; i <= N; i++) {
        a = b = c = 1000001;
        a = dp[i - 1] + 1;
        if (i % 3 == 0) b = dp[i / 3] + 1;
        if (i % 2 == 0) c = dp[i / 2] + 1;
        dp[i] = min({a,b,c});
    }
    printf("%d", dp[N]);
}