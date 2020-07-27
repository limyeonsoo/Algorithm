#include <iostream>
#include <vector>
using namespace std;

int sdk[10][10];
vector <pair<int, int>> zero;
vector <bool> check;
vector <int> result;

int row_check(int idx, int k) {
	for (int i = 0; i < 9; i++) {
		if (k == sdk[idx][i]) return true;
	}
	return false;
}
int col_check(int idx, int k) {
	for (int i = 0; i < 9; i++) {
		if (k == sdk[i][idx]) return true;
	}
	return false;
}
int box_check(int x, int y, int k) {
	int row_box = x / 3;   // 0, 1, 2  => 0~2  3~5 6~8
	int col_box = y / 3;   // 0, 1, 2
	for (int i = 3 * row_box; i < 3 * row_box + 3; i++) {
		for (int j = 3 * col_box; j < 3 * col_box + 3; j++) {
			if (k == sdk[i][j]) return true;
		}
	}
	return false;
}
int dfs(int depth) {
	if (depth == zero.size()) {
		int check = 0;
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << sdk[i][j] << ' ';
			}
			cout << '\n';
		}
		exit(0);
	}

	for (int i = 0; i < zero.size(); i++) {
		if (check[i]) continue;
		if (sdk[zero[i].first][zero[i].second] != 0) continue;
		for (int k = 1; k <= 9; k++) {
			if (row_check(zero[i].first, k)) continue;
			if (col_check(zero[i].second, k)) continue;
			if (box_check(zero[i].first, zero[i].second, k)) continue;
			check[i] = true;
			sdk[zero[i].first][zero[i].second] = k;
			dfs(depth + 1);
			sdk[zero[i].first][zero[i].second] = 0;
			check[i] = false;
		}
		if (sdk[zero[i].first][zero[i].second] == 0) return 0;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> sdk[i][j];
			if (sdk[i][j] == 0) zero.push_back({ i,j });
		}
	}
	check.resize(zero.size());
	result.resize(zero.size());
	dfs(0);
	
}