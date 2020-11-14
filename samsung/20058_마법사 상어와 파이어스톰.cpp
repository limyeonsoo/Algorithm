#include <iostream>
#include <math.h>
#include <vector>
#include <queue>
using namespace std;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, -1, 0, 1 };
int N, Q, SZ;
vector <vector<int> > ice;
vector <int> queries;
bool inner(int x, int y) {
	return (0 <= x && x < SZ && 0 <= y && y < SZ);
}
void input() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> Q;
	SZ = pow(2, N); 
	ice.resize(SZ); for (int i = 0; i < SZ; i++) ice[i].resize(SZ);
	queries.resize(Q);
	for (int i = 0; i < SZ; i++)
		for (int j = 0; j < SZ; j++)
			cin >> ice[i][j];
	for (int q = 0; q < Q; q++)
		cin >> queries[q];
}
void print() {
	for (int i = 0; i < SZ; i++) {
		for (int j = 0; j < SZ; j++) {
			cout << ice[i][j] << ' ';
		}cout << '\n';
	}cout << '\n';
}
void melting() {
	vector <vector <bool> > beMelting;
	beMelting.resize(SZ); for (int i = 0; i < SZ; i++) beMelting[i].resize(SZ);
	for (int i = 0; i < SZ; i++) {
		for (int j = 0; j < SZ; j++) {
			int cnt = 0;
			for (int d = 0; d < 4; d++) {
				if (!inner(j + dx[d], i + dy[d])) continue;
				if (ice[i + dy[d]][j + dx[d]] < 1) continue;
				cnt++;
			}
			beMelting[i][j] = (cnt >= 3 ? false : true);
		}
	}
	for (int i = 0; i < SZ; i++) {
		for (int j = 0; j < SZ; j++) {
			ice[i][j] = (beMelting[i][j]==true ? ice[i][j] - 1 : ice[i][j]);
		}
	}
}
 
void level(int lev) {
	int size = pow(2, lev);
	vector <vector<int> > temp;
	temp.resize(SZ); for (int i = 0; i < SZ; i++) temp[i].resize(SZ);
	for (int c = 0; c < SZ; c += size) {
		for (int r = 0; r < SZ; r += size) {
			//상자의 범위 r, c  ~~  r+size, c+size
			int tmp_x = r, tmp_y = c;
			for (int j = r; j < r + size; j++) {
				for (int i = c + size - 1; i >= c; i--) {
					temp[tmp_y][tmp_x] = ice[i][j];
					tmp_x++;
				}tmp_y++; tmp_x = r;
			}
		}
	}

	for (int i = 0; i < SZ; i++) {
		for (int j = 0; j < SZ; j++) {
			ice[i][j] = temp[i][j];
		}
	}
}
int sumIce() {
	int sum = 0;
	for (int i = 0; i < SZ; i++) {
		for (int j = 0; j < SZ; j++) {
			sum = (ice[i][j] > 0 ? sum + ice[i][j] : sum);
		}
	}
	return sum;
}
int dummy() {
	int sum = 0;
	vector <vector<bool> > visit;
	visit.resize(SZ); for (int i = 0; i < SZ; i++) visit[i].resize(SZ);
	queue <pair<int, int> > q;
	for (int i = 0; i < SZ; i++) {
		for (int j = 0; j < SZ; j++) {
			if (visit[i][j]) continue;
			if (ice[i][j] < 1) continue;
			int cnt = 0;
			q.push({ j,i });
			visit[i][j] = true;
			while (!q.empty()) {
				int x = q.front().first;
				int y = q.front().second;
				q.pop();
				cnt++;
				for (int d = 0; d < 4; d++) {
					int next_x = x + dx[d];
					int next_y = y + dy[d];
					if (!inner(next_x, next_y)) continue;
					if (visit[next_y][next_x]) continue;
					if (ice[next_y][next_x] < 1) continue;
					visit[next_y][next_x] = true;
					q.push({ next_x, next_y });
				}
			}
			sum = (sum < cnt ? cnt : sum);
		}
	}
	return sum;
}
int main() {
	input();
	for (auto q : queries) {
		if (q == 0) melting();
		else {
			level(q);
			melting();
		}
	}
	cout << sumIce() << '\n' << dummy();
}