#pragma warning(disable:4996)
#include <iostream>
#include <cstring>
#define xors(a) (a^1)
using namespace std;
int r, c, N;
int x, y, z;
int A[51][51];
int B[51][51];
string temp;
int swaap;
bool result = true;
int main() {
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		cin >> temp;
		for (int j = 0; j < temp.length(); j++) {
			A[i][j] = temp[j] - '0';
		}
	}
	for (int i = 0; i < r; i++) {
		cin >> temp;
		for (int j = 0; j < temp.length(); j++) {
			B[i][j] = temp[j] - '0';
		}
	}//입력 완료

	for (int i = 0; i < r - 2; i++) {
		for (int j = 0; j < c - 2; j++) {  //필터 시작점.
			if (A[i][j] != B[i][j]) {  // 하나라도 다른게 있으면 안됨.
				swaap++;
				for (int a = 0; a < 3; a++) {
					for (int b = 0; b < 3; b++) {
						A[i + a][j + b] = xors(A[i + a][j + b]);
					}
				}
			}
		}
	}
	for (int i = 0; i < r; i++) {
		if (result == false) break;
		for (int j = 0; j < c; j++) {
			if (A[i][j] != B[i][j])
			{
				result = false;
				break;
			}
		}
	}
	result == false ? printf("-1") : printf("%d", swaap);
}
// if문 break; 실수;;