/*
	작대기, 네모, 기역, 지그재그 는 dfs 
	ㅜ는 bfs
	
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
int N, M, maximum = -2147483648;
vector <vector<int> > base;
vector <vector<bool> > visit;
int woo[3][3] = { {0, 0, 0}, {1, 1, 1}, {0, 1, 0} };

void rotate() {
	int temp[3][3];
	copy(&woo[0][0], &woo[0][0] + 9, &temp[0][0]);
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			woo[i][j] = temp[3 - j - 1][i];
}

bool inner(int x, int y) {
	return (0 <= x && x < M && 0 <= y && y < N);
}

void input() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M;
	base.resize(N); for (int i = 0; i < N; i++) base[i].resize(M);
	visit.resize(N); for (int i = 0; i < N; i++) visit[i].resize(M);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> base[i][j];
}

void dfs(int x, int y, int depth, int sum) {
	if (depth == 4) {
		maximum = (maximum < sum ? sum : maximum);
		return;
	}
	for (int i = 0; i < 4; i++) {
		int next_x = x + dx[i], next_y = y + dy[i];
		if(!inner(next_x, next_y)) continue;
		if (visit[next_y][next_x]) continue;
		visit[next_y][next_x] = true;
		dfs(next_x, next_y, depth + 1, sum + base[next_y][next_x]);
		visit[next_y][next_x] = false;
	}

}
void wooMatching() {
	for (int iter = 0; iter < 4; iter++) {
		for (int i = (-N + 4); i <= N - 4; i++) {
			for (int j = (-M + 4); j <= M - 4; j++) {
				int matchingCnt = 0, matchingSum = 0;
				for (int y = 0; y < 3; y++) {
					for (int x = 0; x < 3; x++) {
						int ny = i + y, nx = j + x;
						if (!inner(nx, ny)) continue;
						if (woo[y][x] == 0) continue;
						matchingCnt++;
						matchingSum += base[ny][nx];
					}
				}
				if (matchingCnt == 4) {
					maximum = (maximum < matchingSum ? matchingSum : maximum);
				}
			}
		}
		rotate();
	}
}

int main() {
	input();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			visit[i][j] = true;
			dfs(j, i, 1, base[i][j]);
			visit[i][j] = false;
		}
	}
	wooMatching();
	cout << maximum;
}