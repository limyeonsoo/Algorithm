#pragma warning(disable:4996)
/* N은 100이하다. */
#include <cstdio>
int N, count;
int A[101];
bool eratos[1001] = { true,true };
void Eratosthenes_chae() {
	for (int i = 2; i <= 1000; i++) if (eratos[i] == false)	for (int j = i + i; j <= 1000; j += i) eratos[j] = true;
}
int main() {
	scanf("%d", &N);
	Eratosthenes_chae();
	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
		if(!eratos[A[i]]) count++;
	}
	printf("%d", count);	
}