#include <iostream>
#include <vector>

using namespace std;

int dx[3] = { 1,0,1 };
int dy[3] = { 0,1,1 };
int N, cnt;
vector <vector<int> > bottom;

void dfs(int x, int y, int dic) { // 0; 가로 1: 세로 2:대각
	if (x == N && y == N) {
		cnt++;
		return;
	}

	for (int i = 0; i < 3; i++) {  //3가지의 방향.
		if (i == 0 && dic == 1) continue; //가로에선 세로로 못감.
		if (i == 1 && dic == 0) continue; //세로에선 가로로 못감.
		pair<int, int> next = { x + dx[i], y + dy[i] };
		if (next.first > N || next.second > N) continue;  //배열 밖 범위 초과
		if (bottom[next.second][next.first] != 0) continue; // 다음칸이 1인지
		if (i == 2) { if (bottom[next.second][x] != 0 || bottom[y][next.first] != 0) continue; } //대각선으로 갈 땐 주변도 봐야함.
		bottom[next.second][next.first] = 1;
		dfs(next.first, next.second, i);
		bottom[next.second][next.first] = 0;
	}
}

int main() {
	scanf("%d", &N);
	bottom.resize(N+1);
	for (int i = 1; i <= N; i++) bottom[i].resize(N+1);
	for (int i = 1; i <= N; i++) for (int j = 1; j <= N; j++) scanf("%d", &bottom[i][j]);
	bottom[1][1] = 1; bottom[1][2] = 1;   // 1,1  1,2를 가진 채.

	dfs(2, 1, 0);
	printf("%d", cnt);
}