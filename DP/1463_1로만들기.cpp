/*
1. 2. 3. ��  3���� ���� ���� ũ�Ⱑ �۾���. �켱����UP -> 2�� ������ -> 1 ����  X 
 -> 10�� ���  1�� ����  3�� ������ 3�� ���� ������.

 ���� N�� 1�� ����µ� ������ ����ϴ� Ƚ���� �ּҰ���  D�迭�� �����س���. 




 D[N] : N������ 1�� ����� �� �ɸ��� �ּ� Ƚ��.
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
//	if (x == 1) return 0;   //1�� 1�̴�.
//	if (dp[x] > 0) return dp[x];  // memorization Ȱ��
//
//	dp[x] = make_one(x-1) + 1;                            // 1�� ������ �� �ּ��ΰ�?
//
//	if (x % 3 == 0) {                                     // 3���� ������ ������ �� �ּ��ΰ�?
//		if (dp[x] > make_one(x / 3) + 1) dp[x] = make_one(x / 3) + 1;
//	}
//
//	if (x % 2 == 0) {                                     //2�� ������ ������ �� �ּ��ΰ�?
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