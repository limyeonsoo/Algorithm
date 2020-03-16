#pragma warning(disable:4996)
#include <iostream>

using namespace std;

int main() {
	int A, B, ans;
	scanf("%d %d", &A, &B);
	ans = A * B;
	int a, b, c;
	a = B % 10;
	B /= 10;
	b = B % 10;
	B /= 10;
	c = B % 10;
	printf("%d\n%d\n%d\n%d", a * A, b * A, c * A, ans);
}