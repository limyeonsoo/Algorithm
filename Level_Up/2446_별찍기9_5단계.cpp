#include <cstdio>
int main() {
	int N; scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{ 
		for (int k = 0; k < i; k++) printf(" ");
		for (int k = 0; k < 2 * N - 1 - 2 * i; k++) printf("*");
		printf("\n");
	}
	for (int i = N-2; i >= 0; i--)
	{
		for (int k = 0; k < i; k++) printf(" ");
		for (int k = 0; k < 2 * N - 1 - 2 * i; k++) printf("*");
		if(i!=0)printf("\n"); 
	}
}