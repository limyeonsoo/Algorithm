#pragma warning(disable:4996)
#include <iostream>
#include <cstring>
using namespace std;

int height, weight;
int dx[8] = {-1,0,1,-1,1,-1,0,1};
int dy[8] = {-1,-1,-1,0,0,1,1,1};

int LS[51][51];  //섬과 바다를 저장할 공간.
int cnt[51][51];

void dfs(int x, int y) {
	int next_x, next_y;
	if (cnt[y][x] != 0) return;
	cnt[y][x] = 1;
	for (int i = 0; i < 8; i++) {
		next_x = x + dx[i]; next_y = y + dy[i];
		if (LS[next_y][next_x] == 1 && cnt[next_y][next_x] == 0) {
			if (0 <= next_x && next_x < weight && 0 <= next_y && next_y < height)
				dfs(next_x, next_y);
		}
	}
}

int main() {
	while (1) {
		memset(LS, 0, sizeof(LS));
		memset(cnt, 0, sizeof(cnt));
		int ans = 0;
		scanf("%d %d", &weight, &height);
		if (weight == 0 && height == 0) break;
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < weight; j++) {
				scanf("%d", &LS[i][j]);   //한 줄씩 받는다. 
			}
		}
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < weight; j++) {
				if (LS[i][j] == 1 && cnt[i][j] == 0) {
					dfs(j, i);
					ans++;
				}
			}
		}
		printf("%d\n", ans);
	}
}