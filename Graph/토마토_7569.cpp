#include <iostream>
#include <queue>
#include <vector>

using namespace std;
struct coord {
	int x, y, z;
};

// 위 아래 왼쪽 오른쪽 앞 뒤
int dx[6] = {0, 0, -1, 1, 0, 0};
int dy[6] = {0, 0, 0, 0, -1, 1};
int dz[6] = {1, -1, 0, 0, 0, 0};

int N, M, H, maxi = 0;
int box[101][101][101];
int visit[101][101][101];
queue <coord> q;
void input() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> M >> N >> H;
	for (int k = 0; k < H; k++) {
		for (int j = 0; j < N; j++) {
			for (int i = 0; i < M; i++) {
				cin >> box[k][j][i];
				
				if (box[k][j][i] == 1) {
					q.push({ i,j,k });
					visit[k][j][i] = 1;
				}
				else if (box[k][j][i] == -1) visit[k][j][i] = -1;
			}
		}
	}	
}
int lastCheck() {
	int maxi = 0;
	for (int k = 0; k < H; k++) {
		for (int j = 0; j < N; j++) {
			for (int i = 0; i < M; i++) {
				if (visit[k][j][i] == 0) return -1;
				if (maxi < visit[k][j][i]) maxi = visit[k][j][i];
			}
		}
	}
	return maxi-1; // 0일 시작.
}
int main() {
	input(); // queue push & input
	while (!q.empty()) {
		coord now = q.front(); q.pop();
		for (int d = 0; d < 6; d++) {
			coord next = { now.x + dx[d], now.y + dy[d], now.z + dz[d] };
			if (0 > next.z || H <= next.z) continue;
			if (0 > next.y || N <= next.y) continue;
			if (0 > next.x || M <= next.x) continue;
			if (box[next.z][next.y][next.x] == -1) continue;
			if (visit[next.z][next.y][next.x] != 0) continue;
			if (box[next.z][next.y][next.x] != 0) continue;
			q.push(next);
			visit[next.z][next.y][next.x] = visit[now.z][now.y][now.x] + 1;
		}
	}
	cout << lastCheck();
}