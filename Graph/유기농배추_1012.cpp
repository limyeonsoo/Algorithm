#pragma warning(disable:4996)
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int T, X, Y, K, x, y, cnt;

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

int base[51][51];
int check[51][51];
queue <pair<int, int> > q;
int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d%d", &X, &Y, &K);
		for (int i = 0; i < K; i++) {
			scanf("%d%d", &x, &y);
			base[y][x] = 1;
		}
		for (int i = 0; i < Y; i++) {
			for (int j = 0; j < X; j++) {
				if (check[i][j] == 0 && base[i][j] == 1) {
					check[i][j] = 1;
					q.push({ j,i });
					while (!q.empty()) {
						pair<int, int> now = q.front();q.pop();
						for (int i = 0; i < 4; i++) {
							pair<int, int> next = { now.first + dx[i], now.second + dy[i] };
							if (0 > next.first || X <= next.first || 0 > next.second || Y <= next.second) continue;
							if (check[next.second][next.first] == 1) continue;
							if (base[next.second][next.first] != 1)continue;
							printf("%d,%d\n", next.first, next.second);
							check[next.second][next.first] = 1;
							q.push(next);
						}
					}
					cnt++;
				}
			}
		}
		printf("%d\n", cnt);
		cnt = 0;
		memset(check, 0, sizeof(check));
		memset(base, 0, sizeof(base));
	}
}