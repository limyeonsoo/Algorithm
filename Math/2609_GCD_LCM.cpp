#pragma warning(disable:4996)
#include <cstdio>
int A, B, temp, AB;
int main() {
	scanf("%d %d", &A,&B);
	AB = A * B;
	while (B != 0) {
		temp = B;
		B = A % B;
		A = temp;
	}
	printf("%d\n%d", A, AB/A);
}