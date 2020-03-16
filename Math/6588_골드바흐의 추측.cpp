#pragma warning(disable:4996)
#include <iostream>
using namespace std;
int n;
bool eratos[1000001] = { true,true };
void Eratosthenes_chae() {
	for (int i = 2; i <= 1000000; i++) if (eratos[i] == false)	for (int j = i + i; j <= 1000000; j += i) eratos[j] = true;
}
int main() {
	Eratosthenes_chae();
	while (1) {
		scanf("%d", &n);
		if (n == 0)break;
		for (int i = 3; i <= 1000000; i++) {
			if (eratos[i] == false && eratos[n - i] == false) {
				printf("%d = %d + %d\n", n, i, n - i);
				break;
			}
		}
	}
}