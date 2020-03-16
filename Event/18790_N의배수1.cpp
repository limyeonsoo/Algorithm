//#pragma warning(disable:4996)
//#include <algorithm>
//#include <iostream>
//#include <vector>
//#include <numeric>
//#define MAX 1000
//using namespace std;
//int N;
//int A[MAX];
//bool check[MAX];
//vector <int> ans;
//
//void dfs(int depth) {
//
//	int sum = accumulate(ans.begin(), ans.end(), 0);
//	if (sum != 0 && sum % N == 0 && depth == N) {
//		for (auto& k : ans) {
//			printf("%d ", k);
//		}
//		exit(0);
//	}
//	if (depth == N) {
//		return;
//	}
//	
//	for (int i = 0; i < 2 * N - 1; i++) {
//		if (check[i]) continue;
//		if (check[i] == false) {
//			check[i] = true;
//			ans[depth] = A[i];
//			dfs(depth + 1);
//			check[i] = false;
//		}
//	}
//}
//
//#include <malloc.h>
//int main() {
//	scanf("%d", &N); 
//	for (int i = 0; i < 2 * N - 1; ++i) {
//		scanf("%d", &A[i]);
//	}
//	ans.resize(N);
//	sort(A, A + N + 1);
//	for (int i = 0; i < 2*N-1; i++) {
//		check[i] = true;
//		ans[0] = A[i];
//		dfs(1);
//		check[i] = false;
//	}
//	printf("-1");
//}

//#pragma warning(disable:4996)
//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <numeric>
//using namespace std;
//int N;
//int A[1001];
//vector <int> odd;
//vector <int> sum;
//int dist[1001];
//int dp[1001][1001];
//vector <vector<int>> v;
//int main() {
//	scanf("%d", &N);
//	v.resize(N+1);
//	for (int i = 0; i < 2 * N - 1; ++i) {
//		scanf("%d", &A[i]);
//		if (A[i] % 2 == 1) odd.push_back(A[i]);
//		dist[A[i]]++;   //수의 종류를 담아놓는 배열.
//	}
//	if (odd.size() >= N)
//	{
//		for (int i = 0; i < N; i++) {
//			printf("%d ", odd[i]);
//		}
//	}
//	else if (odd.size() < N) {  //홀수가 N개 없으면
//		for (int i = 0; i < N; i++) {
//			if (dist[i] > 0) {
//				dp[1][i] = i;
//				dist[i]--;
//			}
//		}  // dp 기본값.
//		for (int i = 2; i <= N; i++) {    // dp의 변수
//			for (int j = 0; j < N; j++) {  // 해당 수의 변수
//				if (j == 0 && dist[0] > 0) {
//					dp[i][j] = dp[i - 1][0] % 0;
//					v[i].push_back(j);
//					dist[0]--;
//				}
//				else if (dist[j] > 0) {
//					dp[i][j] = dp[i - 1][N - j] % j;
//					v[i].push_back(j);
//					dist[j]--;
//				}
//				 
//			}
//		}
//	}
//	for (int i = 1; i < v[N].size(); i++) {
//		printf("%d ", v[N][i]);
//	}
//
//
//}

/*
	N*0 이 되는 조합을 찾고,  없으면 ->
	N*1 이 되는 조합...
	N^(2N-1)이 되는 조합 까지.
	  x => 이러면 너무 많이 봐야함. 
	N각각 나머지를 더해서 0이되도록?
	
	
*/


#pragma warning(disable:4996)
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
int N;
int A[1001];
vector <pair<long long int, int>> v;

int check[1001];

void dfs(int index, int depth) {
	if (depth == N) {
		return;
	}
	for (int i = 0; i <= N; i++) { //A[]의 index가 될 것.
		if (check[i] != 0) continue;

	}
	
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < 2 * N - 1; ++i) {
		scanf("%d", &A[i]);
	}
	// 가능한 배수를 구하자.
	sort(A, A + N + 1); //가장 뒤에 N개 숫자의 합을 구해본다. 
	int MAX_total = 0;
	for (int i = 2 * N - 2; i >= N - 1; i--) {
		MAX_total += A[i];
	} // 이 수 안에서 N의 배수를 만들면 된다. 

	for (int sum = N; sum <= MAX_total; sum*=2) { //합이 sum이 되는 것을 구하면 종료.
		
		for (int i = 0; i <= N; i++) {
			check[i] = 1;
			dfs(i,1);
			check[i] = 0;
		}

	}
	printf("-1");


}