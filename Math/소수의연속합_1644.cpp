//#include <stdio.h>
//#include <math.h>
//using namespace std;
//bool chae[4000001] = { true, true };
//int N, result, breaking;
//void eratho() { 
//	for (int i = 2; i <= N; i++) 
//		if(chae[i] == false)
//			for (int j = i + i; j <= N; j += i) 
//				chae[j] = true; 
//}
//int main() {
//	scanf("%d", &N);
//	eratho();
//	for (int i = N; i >= 2; i--) {
//		if (chae[i]) continue;
//		int sum = 0;
//		for (int j = i; j >= 2; j--) {
//			if (sum >= N) break;
//			if (chae[j]) continue;
//			if (j == 2) breaking = 1;
//			sum += j;
//		}
//		if (sum == N) result++;
//		if (breaking) break;
//	}
//	printf("%d", result);
//}

// 투포인터 연속합

//#include <stdio.h>
//#include <math.h>
//using namespace std;
//bool chae[4000001] = { true, true };
//int N, result, l, r, sum, cnt, prime[4000001];
//void eratho() {
//	for (int i = 2; i <= N; i++)
//		if (chae[i] == false)
//			for (int j = i + i; j <= N; j += i)
//				chae[j] = true;
//}
//int main() {
//	scanf("%d", &N);
//	eratho();
//	for (int i = 2; i <= N; i++) {
//		if (chae[i]) continue;
//		prime[cnt++] = i;
//	}
//	while (1) {
//		if (sum >= N) sum -= prime[l++];
//		else if (r == cnt) break;
//		else sum += prime[r++];
//		if (sum == N) result++;
//	}
//	printf("%d", result);
//}

#include <stdio.h>
#include <math.h>
using namespace std;
bool chae[4000001] = { true, true };
int N, result, l, r, sum, cnt, prime[4000001];
void eratho() {
	for (int i = 2; i <= N; i++)
		if (chae[i] == false)
			for (int j = i + i; j <= N; j += i)
				chae[j] = true;
}
int main() {
	scanf("%d", &N);
	eratho();
	for (int i = 2; i <= N; i++) {
		if (chae[i]) continue;
		prime[cnt++] = i;
	}
	while (r <= cnt) {
		if (sum < N) {
			sum += prime[r++];
			continue;
		}
		if (sum == N) result++;
		sum -= prime[l++];
	}
	printf("%d", result);
}