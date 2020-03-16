#pragma warning(disable:4996)
#include <iostream>
#include <queue>

using namespace std;
int N, M;
char maze[101][101];
int cnt[101][101];
int check[101][101];

int dx[4] = { 0,0,1,-1 };
int dy[4] = { -1,1,0,0 };
queue <pair<int, int>> q;
int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		scanf("%s", maze[i]);
	}
	int step = 0;
	int start_x = 0; int start_y = 0;
	q.push({ start_x, start_y });
	cnt[start_y][start_x] = 1;
	check[start_y][start_x] = 1;
	while (!q.empty()) {
		pair<int, int> curr = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			int next_x = curr.first + dx[i];
			int next_y = curr.second + dy[i];
			if (0 <= next_x && next_x < M && 0 <= next_y && next_y < N) {
				if (maze[next_y][next_x] == '1' && cnt[next_y][next_x] == 0) {
					q.push({ next_x, next_y });
					check[next_y][next_x] = check[curr.second][curr.first]+1;
				}
				cnt[next_y][next_x] = 1;

			}
		}
	}
	printf("%d", check[N - 1][M - 1]);
}
