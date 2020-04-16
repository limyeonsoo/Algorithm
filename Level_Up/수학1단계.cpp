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

#include <cstdio>
int main() {
	int H,W,N,T; scanf("%d", &T);
	while (T--) {
		scanf("%d%d%d", &H, &W, &N); 
		if (N % H >= 10) printf("%d\n", N % H == 0 ? H * 100 + ((int)N / H) : N % H * 100 + ((int)N / H + 1));
		else printf("%d\n", N % H == 0 ? H * 100 + ((int)N / H) : N % H*100 + ((int)N / H + 1));
	}
}