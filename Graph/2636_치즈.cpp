#include <iostream>
#include <vector>


int N, M, base, result, pre;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
std::vector <std::vector<int> > v;
std::vector <std::vector<int> > temp;
std::vector <std::vector<int> > visit;

void input() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	std::cin >> N >> M;
	v.resize(N); for (int i = 0; i < N; i++) v[i].resize(M);
	temp.resize(N); for (int i = 0; i < N; i++) temp[i].resize(M);
	visit.resize(N); for (int i = 0; i < N; i++) visit[i].resize(M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			std::cin >> v[i][j];
			if (v[i][j] == 1) result++;
		}
	}
	
}


void dfs(std::pair<int, int> now) {
	
	for (int d = 0; d < 4; d++) {
		std::pair<int, int> next = { now.first + dx[d] , now.second + dy[d] };
		if (next.first < 0 || next.first >= M) continue;
		if (next.second < 0 || next.second >= N) continue;
		if (v[next.second][next.first] == 0)continue;
		temp[next.second][next.first] = 1;
	}
	
	for (int d = 0; d < 4; d++) {
		std::pair<int, int> next = { now.first + dx[d] , now.second + dy[d] };
		if (next.first < 0 || next.first >= M) continue;
		if (next.second < 0 || next.second >= N) continue;
		if (visit[next.second][next.first] != 0) continue;
		if (v[next.second][next.first] == 1) continue;
		visit[next.second][next.first] = 1;
		dfs(next);
	}
	
}

void solve() {
	do {
		pre = result;
		result = 0;
		std::pair <int, int> now = { base, base };
		dfs(now);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (temp[i][j] == 1) v[i][j] = 0;
				if (v[i][j] == 1) result++;
			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				temp[i][j] = 0;
				visit[i][j] = 0;
			}
		}
		base++;
	} while (result != 0);
	std::cout << base << '\n' << pre;
}
int main() {
	input();
	solve();
}
