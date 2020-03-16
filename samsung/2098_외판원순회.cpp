#pragma warning(disable:4996)
#include <iostream>
#include <cstring>

using namespace std;

int N;
int node[17][17];
bool check[17];
int minimum = 1e9;

void dfs(int start, int city, int pay, int depth) {
	printf("%d %d %d %d\n", start, city, pay, depth);
	if (depth == N) {
		if (minimum > pay+node[city][start]) minimum = pay + node[city][start];
		return;
	}
	
	for (int i = 0; i < N; i++) {
		if (check[i] == false && node[city][i] != 0) {
			if (minimum < pay + node[city][i])continue;
			check[city] = true;
			pay += node[city][i];
			dfs(start, i, pay, depth + 1);
			check[city] = false;
		}
	}
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) scanf("%d", &node[i][j]); // 도시 입력
	for (int i = 0; i < N; i++) {
		check[i] = true;
		dfs(i, i, 0, 1);
		memset(check, false, sizeof(check));
	}
	printf("%d", minimum);
}