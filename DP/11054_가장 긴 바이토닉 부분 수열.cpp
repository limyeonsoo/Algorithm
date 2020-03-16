#pragma warning(disable:4996)
#include <iostream>
#include <algorithm>
#define MAX 1001
using namespace std;

int N, maxi=0; 
int A[MAX];
int Rising[MAX];
int Falling[MAX];

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &A[i]);
	}

	for (int i = 1; i <= N; i++) {
		Rising[i] = 1;
		for (int j = 0; j < i; j++) {
			if (Rising[i] < Rising[j] + 1 && A[j] < A[i]) {
				Rising[i] = Rising[j] + 1;
			}
		}
	}
	reverse(A+1, A + N + 1);
	for (int i = 1; i <= N; i++) {
		Falling[i] = 1;
		for (int j = 0; j < i; j++) {
			if (Falling[i] < Falling[j] + 1 && A[j] < A[i]) {
				Falling[i] = Falling[j] + 1;
			}
		}
	}
	reverse(Falling+1, Falling + N + 1);

	for (int i = 1; i <= N; i++) {
		if (maxi < Rising[i] + Falling[i] - 1) {
			maxi = Rising[i] + Falling[i] - 1;
		}
	}
	printf("%d", maxi);
}