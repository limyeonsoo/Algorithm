#pragma warning(disable:4996)
/* N은 100이하다. */
#include <cstdio>
#define MAX 1000000
int A, B;
bool eratos[1000001] = { true,true };
void Eratosthenes_chae() {
	for (int i = 2; i <= MAX; i++) if (eratos[i] == false)	for (int j = i + i; j <= MAX; j += i) eratos[j] = true;
}
int main() {
	scanf("%d %d", &A, &B);
	Eratosthenes_chae();
	for (int i = A; i <= B; i++) {
		if (!eratos[i]) printf("%d\n", i);
	}
}