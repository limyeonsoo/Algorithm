/*

  ... ... ...  N  일 때, 
						N-1이 1^2 일 때,  D[ N-(1^2) ] + 1 = D[N]
						N-1이 2^2 일 때,  D[ N-(2^2) ] + 1 = D[N]
						...
						N-1이 k^2 일 때,  D[ N-(k^2) ] + 1 = D[N]
					cond =>  N 번째 k^2 <= N
							 

		D[]의 크기 1^2 * 100,000으로 표현 가능.				
*/

#pragma warning(disable:4996)
#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;
int N;
int D[100001];
int main() {
	scanf("%d", &N);
	D[1] = 1;
	for (int i = 2; i <= N; i++) {
		D[i] = 100000;
		for (int j = 1; j <= sqrt(i); j++) {
			if (D[i] > D[i - (int)pow(j, 2)])
				D[i] = D[i - (int)pow(j, 2)] + 1;
		}
	}
	printf("%d", D[N]);
}