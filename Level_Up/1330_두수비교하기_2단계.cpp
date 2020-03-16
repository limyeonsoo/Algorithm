#pragma warning(disable:4996)
#include <iostream>
using namespace std;
int main() {
	int A, B; scanf("%d %d", &A, &B);
	if (A != B)	A < B ? printf("<") : printf(">");
	else printf("==");	
}