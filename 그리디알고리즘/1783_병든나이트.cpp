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
		else {   //����� ���ڰ� Ŭ �� ó�� 7ĭ�� 7ĭ�ȿ��� ���� => 5�� // ������ �� ĭ ���� �����ؼ� 6 cycle 1cycle�� 4��
			printf("%d", X - 2);
			
		}
	}
}