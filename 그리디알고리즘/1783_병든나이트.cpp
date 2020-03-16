#pragma warning(disable:4996)
#include <iostream>
using namespace std;

int dy[4] = { 2,1,-1,-2 };
int dx[4] = { 1,2,2,1 };
int Y, X;
int main() {
	scanf("%d %d", &Y, &X);
	if (Y == 1) {
		printf("1");
	}
	else if (Y == 2) {
		if (X <= 2) {
			printf("1");
		}
		else if (2 < X && X <= 4) {
			printf("2");
		}
		else if (4 < X && X <= 6) {
			printf("3");
		}
		else printf("4");
	}
	else {
		if (X == 1) {
			printf("1");
		}
		else if (X == 2) {
			printf("2");
		}
		else if (X==3) {
			printf("3");
		}
		else if (4 <= X && X <= 6) {
			printf("4");
		}
		else if (X==7)printf("5");
		else {   //충분히 격자가 클 때 처음 7칸은 7칸안에서 시작 => 5개 // 다음은 전 칸 부터 시작해서 6 cycle 1cycle에 4개
			printf("%d", X - 2);
			
		}
	}
}