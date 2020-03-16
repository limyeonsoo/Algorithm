#pragma warning(disable:4996)
#include <iostream>
using namespace std;
int N;
int main() {
	scanf("%d", &N);
	int End = N, div = 2;
	while (N != 1) {
		if (N % div == 0) {
			N /= div;
			printf("%d\n", div);
		}
		else (div++);
	}
}
