#pragma warning(disable:4996)
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

priority_queue<int> pq;
vector <int> A;
vector <int> B;
int N, K, L;
int main() {
	scanf("%d %d %d", &N, &K, &L);
	A.resize(N); B.resize(N);
	for (int i = 0; i < N; i++) // 기본 수열 A 입력. index 는 0~N-1
	{
		scanf("%d", &A[i]);
		pq.push(A[i]);
	}
	int count = -1;
	if (L == 0) {  //L 이 0이면 바로 내림차순.
		for (int i = 0; i < N; i++) {
			printf("%d ", pq.top());
			pq.pop();
		}
	}
	else {
		while (!pq.empty()) {
			
			for (int i = 0; i < N; i++) {
				if (i >= L) {
					B[i] = pq.top(); pq.pop();
					count++;
					continue;
				}
				else if (i < L && abs(A[i] - pq.top()) <= K && B[i] == 0)   // index는 L보다 작고, 간격도 K보다 작다. 
				{
					B[i] = pq.top(); pq.pop();
					count++;
					break;
				}
				else if (i == N - 1) {	//여기 오면 드갈 곳 없는 것.


					for (int j = 0; j < N; j++) {
						if (B[j] == 0) { // 전에꺼 까지 채움.
							int temp = B[j - 1];
							B[j - 1] = pq.top();
							pq.push(temp);
						}
					}
				}
				
			}
		}
		for (int i = 0; i < N; i++) {
			printf("%d ", B[i]);
		}
	}
}