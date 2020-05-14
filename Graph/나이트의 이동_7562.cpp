#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int x[8] = { 1,1,2,2,-1,-1,-2,-2 };
int y[8] = { 2,-2,1,-1,2,-2,1,-1 };

int T, I, sx, sy, dx, dy;
int chess[301][301];
int check[301][301];
bool success;
queue <pair<int, int> > q;
int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &I);
		scanf("%d %d", &sx, &sy);
		q.push({ sx,sy });
		check[sy][sx] = 1;
		scanf("%d %d", &dx, &dy);
		if (dx == sx && dy == sy) {
			printf("%d\n", 0);
			success = true;
		}
		while (!q.empty()) {
			if (success)break;
			pair<int, int> now = q.front(); q.pop();
			for (int i = 0; i < 8; i++) {
				pair<int, int> next = {now.first + x[i], now.second + y[i]};
				if (next.first == dx && next.second == dy) {
					printf("%d\n", check[now.second][now.first]);
					success = true;
					break;
				}
				if (next.first < 0 || next.first >= I || next.second >= I || next.second < 0)continue;
				if (check[next.second][next.first] != 0)continue;
				check[next.second][next.first] = check[now.second][now.first]+1;
				q.push(next);
			}
		}
		success = false;
		while (!q.empty()) q.pop();
		memset(check, 0, sizeof(check));
		memset(chess, 0, sizeof(chess));
	}
}