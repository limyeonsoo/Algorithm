#pragma warning(disable:4996)
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };

int d[9][9];
int d2[9][9];
int check[9][9];
vector <pair<int, int> > zero;

int N, M;
int ans;

void dfs(int x, int y) {
	if (check[y][x] == 1) return;
	check[y][x] = 1;
	d2[y][x] = 2;
	for (int i = 0; i < 4; i++) {
		int next_x = x + dx[i]; int next_y = y + dy[i];
		if (0 <= next_x && next_x < M && 0 <= next_y && next_y < N) {
			if (d2[next_y][next_x] == 0) {
				dfs(next_x, next_y);
			}
		}
	}
	return;
}

int main() {

	scanf("%d%d", &N, &M);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &d[i][j]);
			if (d[i][j] == 0) {
				zero.push_back({ j,i });
			}
		}
	}
	for (int i = 0; i < zero.size(); i++) {
		for (int j = i + 1; j < zero.size(); j++) {
			for (int k = j + 1; k < zero.size(); k++) {
				memcpy(d2, d, sizeof(d2));    // d2 초기화
				memset(check, 0, sizeof(check));
				int max = 0;                 // 정답 초기화
				d2[zero[i].second][zero[i].first] = 1;
				d2[zero[j].second][zero[j].first] = 1;
				d2[zero[k].second][zero[k].first] = 1;
				//   벽 3가지를 세웠다. 
				for (int y = 0; y < N; y++) {
					for (int x = 0; x < M; x++) {
						if (d2[y][x] == 2) {
							dfs(x, y);
						}
					}
				}   // d2에서는 dfs를 다 돌아서 감염 될만큼 됐을 것.
				for (int y = 0; y < N; y++) {
					for (int x = 0; x < M; x++) {
						if (d2[y][x] == 0) {
							max++;
						}
					}
				}
				if (max > ans) {
					ans = max;					
				}
			}
		}
	}

	printf("%d", ans);

}