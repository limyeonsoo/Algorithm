#pragma warning(disable:4996)
#include <iostream>
#include <queue>
using namespace std;
int N, M; 
int tomato[1001][1001];
int cnt[1001][1001];
queue <pair<int, int>> q;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
int main() {
	scanf("%d %d", &M, &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &tomato[i][j]);
			cnt[i][j] = tomato[i][j];
			if (tomato[i][j] == 1) q.push(make_pair(i, j));
		}
	}
	while (!q.empty()) {
		pair<int, int> curr = q.front(); q.pop();
		for (int d = 0; d < 4; d++) {
			pair<int, int> next = make_pair(curr.first + dy[d], curr.second + dx[d]);
			if (0 <= next.first && next.first < N && 0 <= next.second && next.second < M) {
				if (tomato[next.first][next.second] == 0 & cnt[next.first][next.second] == 0) {
					cnt[next.first][next.second] = cnt[curr.first][curr.second] + 1;
					q.push(next);
				}
			}
		}
	}
	int max = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (cnt[i][j] == 0) {
				printf("-1\n");
				exit(0);
			}
			if (max < cnt[i][j])max = cnt[i][j];
		}
	}
	printf("%d", max-1);
}

