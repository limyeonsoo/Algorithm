/*
 배열 rotate쯤 은 알고 있어야 함.
*/

#include <iostream>
#include <algorithm>
using namespace std;
int base_x, base_y, stick, stk_x, stk_y;
int base[41][41];
int stk[11][11];
int temp[11][11];
bool check = false;

void rotate() {
	for (int i = 0; i < stk_y; i++)
		for (int j = 0; j < stk_x; j++)
			temp[i][j] = stk[i][j];
	for (int i = 0; i < stk_x; i++)
		for (int j = 0; j < stk_y; j++)
			stk[i][j] = temp[stk_y-j-1][i];
	swap(stk_x, stk_y);
}

void trying() {
	check = false;
	for (int i = 0; i < base_y - stk_y + 1; i++) {
		for (int j = 0; j < base_x - stk_x + 1; j++) {
			check = true;
			for (int a = 0; a < stk_y; a++) {
				if (check == false) break;
				for (int b = 0; b < stk_x; b++) {
					if (stk[a][b] == 1 && base[i+a][j+b] == 1) {
						check = false;
						break;
					}
				}
			}
			if (check == true) {
				for (int a = 0; a < stk_y; a++) {
					for (int b = 0; b < stk_x; b++) {
						if (base[i + a][j + b] == 1) continue;
						base[i + a][j + b] = stk[a][b];
					}
				}
				return;
			}

		}
	}
}

int main() {
	scanf("%d %d %d", &base_y, &base_x, &stick);
	for (int i = 0; i < base_y; i++)
		for (int j = 0; j < base_x; j++)
			base[base_y][base_x] = 0;
	while (stick--) {
		scanf("%d %d", &stk_y, &stk_x);
		for (int i = 0; i < stk_y; i++)
			for (int j = 0; j < stk_x; j++)
				scanf("%d", &stk[i][j]);
		
		trying();
		for (int a = 0; a < 3; a++) { //4번의 rotate 및 검사.
			if (check == true) break;
			rotate();
			trying();
		}
	}
	int cnt = 0;
	for (int i = 0; i < base_y; i++)
		for (int j = 0; j < base_x; j++)
			if (base[i][j] == 1) cnt++;
	printf("%d", cnt);

}