//#pragma warning(disable: 4996)
//#include <iostream>
//#include <algorithm>
//using namespace std;
//int N, M, K;  // N���� ���л�, M���� ���л�, K�� ���Ͻ����� ���� ����
//int TeamMaker(int N, int M, int K) {
//	if (K == 0) return min(N/2, M);
//	if (N / 2 >= M) return TeamMaker(N - 1, M, K-1);
//	else return TeamMaker(N, M - 1, K-1);
//}
//int main() {	
//	scanf("%d %d %d", &N, &M, &K); 
//	printf("%d", TeamMaker(N, M, K));
//}

//#pragma warning(disable: 4996)
//#include <iostream>
//#include <algorithm>
//using namespace std;
//int N, M, K;  // N���� ���л�, M���� ���л�, K�� ���Ͻ����� ���� ����
//int TeamMaker() {
//	if (K == 0) return min(N / 2, M);
//	if (N / 2 >= M) {
//		--N; --K;
//	}
//	else {
//		--M; --K;
//	}
//	return TeamMaker();
//}
//int main() {
//	scanf("%d %d %d", &N, &M, &K);
//	printf("%d", TeamMaker());
//}

#pragma warning(disable: 4996)
#include <iostream>
#include <algorithm>
using namespace std;
int TeamMaker(const int &N, const int &M, const int &K) {
	if (K == 0) return min(N/2, M);
	if (N / 2 >= M) return TeamMaker(N - 1, M, K-1);
	else return TeamMaker(N, M - 1, K-1);
}
int main() {	
	int N, M, K;  // N���� ���л�, M���� ���л�, K�� ���Ͻ����� ���� ����
	scanf("%d %d %d", &N, &M, &K); 
	printf("%d", TeamMaker(N, M, K));
}