#pragma warning(disable:4996)
//#include <iostream>
//using namespace std;
//int main() {
//	int A; scanf("%d", &A);
//	(A % 4 == 0 && A % 100 != 0) || (A%4 == 0 && A % 400 == 0) ? printf("1") : printf("0");
//}

#include <cstdio>
int main() {
	int A; scanf("%d", &A);
	(A % 4 == 0 && A % 100 != 0) || (A % 4 == 0 && A % 400 == 0) ? printf("1") : printf("0");
}