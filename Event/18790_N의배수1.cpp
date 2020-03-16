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
//		dist[A[i]]++;   //���� ������ ��Ƴ��� �迭.
//	}
//	if (odd.size() >= N)
//	{
//		for (int i = 0; i < N; i++) {
//			printf("%d ", odd[i]);
//		}
//	}
//	else if (odd.size() < N) {  //Ȧ���� N�� ������
//		for (int i = 0; i < N; i++) {
//			if (dist[i] > 0) {
//				dp[1][i] = i;
//				dist[i]--;
//			}
//		}  // dp �⺻��.
//		for (int i = 2; i <= N; i++) {    // dp�� ����
//			for (int j = 0; j < N; j++) {  // �ش� ���� ����
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
	N*0 �� �Ǵ� ������ ã��,  ������ ->
	N*1 �� �Ǵ� ����...
	N^(2N-1)�� �Ǵ� ���� ����.
	  x => �̷��� �ʹ� ���� ������. 
	N���� �������� ���ؼ� 0�̵ǵ���?
	
	
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
	for (int i = 0; i <= N; i++) { //A[]�� index�� �� ��.
		if (check[i] != 0) continue;

	}
	
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < 2 * N - 1; ++i) {
		scanf("%d", &A[i]);
	}
	// ������ ����� ������.
	sort(A, A + N + 1); //���� �ڿ� N�� ������ ���� ���غ���. 
	int MAX_total = 0;
	for (int i = 2 * N - 2; i >= N - 1; i--) {
		MAX_total += A[i];
	} // �� �� �ȿ��� N�� ����� ����� �ȴ�. 

	for (int sum = N; sum <= MAX_total; sum*=2) { //���� sum�� �Ǵ� ���� ���ϸ� ����.
		
		for (int i = 0; i <= N; i++) {
			check[i] = 1;
			dfs(i,1);
			check[i] = 0;
		}

	}
	printf("-1");


}