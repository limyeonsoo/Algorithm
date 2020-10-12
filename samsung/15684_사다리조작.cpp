#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M, H, answer = 2147483647;
bool visit[11][31];
void input() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M >> H;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		visit[b][a] = true;
	}
}

bool game() {
	for (int i = 1; i <= N; i++) {
		int now = i;
		for (int j = 1; j <= H; j++) {
			if (visit[now][j]) now = now + 1;
			else if (visit[now - 1][j]) now = now - 1;
		}
		if (now != i)return false;
	}
	return true;
}
void solve(int line, int depth) {
	if (depth > 3) return;
	if (game()) {
		answer = (answer > depth ? depth : answer);
		return;
	}

	for (int j = line; j <= H; j++) {
		for (int i=1; i < N; i++) {
			if (visit[i][j]) continue;
			if (visit[i - 1][j]) continue;
			if (visit[i + 1][j]) continue;
			visit[i][j] = true;
			solve(j, depth + 1);
			visit[i][j] = false;
		}
	}
}

int main() {
	input();
	solve(1, 0);
	cout <<  (answer==2147483647 ? -1 : answer);
}
