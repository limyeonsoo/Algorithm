#pragma warning(disable:4996)
#include <iostream>
using namespace std;
int main() {
	int A; scanf("%d", &A);
	A >= 90 ? printf("A") : A >= 80 ? printf("B") : A >= 70 ? printf("C") : A >= 60 ? printf("D") : printf("F");
}