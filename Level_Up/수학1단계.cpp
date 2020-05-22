//#include <cstdio>
//int N, cnt=1;
//int main() { 
//	scanf("%d", &N);
//	for (int i = 1; i < N; i = i + cnt++ * 6);
//	printf("%d", cnt);
//}

////2869 달팽이는 올라가고 싶다
//#include <cstdio>
//#include <math.h>
//int A, B, V, day;
//int main() {
//	scanf("%d%d%d", &A, &B, &V);
//	day = (int)ceil((double)(V - A) / (A - B));
//	printf("%d", A==V?1:(day == 0?2 : day+1));
//}


//  10250 ACM 호텔
// 층수는 나머지   호수는 몫 + 1 나눠떨어지면 +1X

//#include <cstdio>
//int main() {
//	int H,W,N,T; scanf("%d", &T);
//	while (T--) {
//		scanf("%d%d%d", &H, &W, &N); 
//		if (N % H >= 10) printf("%d\n", N % H == 0 ? H * 100 + ((int)N / H) : N % H * 100 + ((int)N / H + 1));
//		else printf("%d\n", N % H == 0 ? H * 100 + ((int)N / H) : N % H*100 + ((int)N / H + 1));
//	}
//}

//#include <cstdio>
//int floor[15][15];
//int T, k, n;
//int main() {
//	scanf("%d", &T);
//	while (T--) {
//		scanf("%d%d", &k, &n);
//		for (int i = 1; i < 15; i++) { floor[0][i] = i; } //0층의 i호수는 i
//		for (int i = 0; i < 15; i++) { floor[i][1] = 1; } // 각 층의 1호는 1;
//		for (int i = 1; i < 15; i++) {
//			for (int j = 2; j < 15; j++) {
//				floor[i][j] = floor[i - 1][j] + floor[i][j - 1];
//			}
//		}
//		printf("%d\n", floor[k][n]);	
//	}
//}

/*
	규칙 찾기

	1   1
	4   3
	9   5
	16  7
	25
	
	1	1
	2   1 1            2
	3   1 1 1
	4   1 2 1          3
	5	1 1 2 1
	6   1 2 2 1        4
	7	1 2 2 1 1
	8   1 2 2 2 1
	9   1 2 3 2 1      5
	10	1 2 3 2 1 1
	11  1 2 3 2 2 1
	12  1 2 3 3 2 1    6
	13  1 2 3 3 2 1 1
	14  1 2 3 3 2 2 1
	15  1 2 3 3 3 2 1
	16  1 2 3 4 3 2 1  7
	 y-x가  (pow(((int)sqrt(y-x)+1),2) - pow((int)sqrt(y-x),2)) /2 <= (y-x) ? (int)sqrt(y-x)*2 : (int)sqrt(y-x)*2-1; 
	((int)sqrt(y-x)+1)-(int)sqrt(y-x) >= (int)((int)sqrt(y-x)+1)/2 ?


*/

#include <cstdio>
#include <math.h>
#define ll long long

int main() {
	int N;
	ll x, y;
	scanf("%d", &N);
	while (N--) {
		scanf("%lld%lld", &x, &y);
		ll answer, stride = 1, diff = y-x;
		for (ll i = 1; ; i++) {
			ll now = i * i, pre = (i - 1) * (i - 1);
			if ((i * i >= diff) && (diff > (i - 1) * (i - 1))) {
				ceil((double)(now + pre) / 2) <= diff ? answer = stride : answer = stride -1;
				printf("%lld\n", answer);
				break;
			}
			stride += 2;
		}
	}
}