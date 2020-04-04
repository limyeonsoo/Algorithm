/*
		0 45 => 0 0
		0 44 юлго => 23 xx

*/

#include <cstdio>
int main() {
	int A, B; scanf("%d %d", &A, &B);
	A >= 1 ? (B >= 45 ? printf("%d %d", A, B - 45) : printf("%d %d", A - 1, B + 15)) : (B >= 45 ? printf("0 %d", B-45):printf("23 %d", (B + 15) % 60));
}