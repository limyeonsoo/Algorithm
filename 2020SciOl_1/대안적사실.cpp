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
	for (int i = 0; i < N; i++) // �⺻ ���� A �Է�. index �� 0~N-1
	{
		scanf("%d", &A[i]);
		pq.push(A[i]);
	}
	int count = -1;
	if (L == 0) {  //L �� 0�̸� �ٷ� ��������.
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
				else if (i < L && abs(A[i] - pq.top()) <= K && B[i] == 0)   // index�� L���� �۰�, ���ݵ� K���� �۴�. 
				{
					B[i] = pq.top(); pq.pop();
					count++;
					break;
				}
				else if (i == N - 1) {	//���� ���� �尥 �� ���� ��.


					for (int j = 0; j < N; j++) {
						if (B[j] == 0) { // ������ ���� ä��.
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