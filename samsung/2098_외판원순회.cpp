#pragma warning(disable:4996)
#include <iostream>
#include <cstring>

using namespace std;

int N;
int node[17][17];
int path[17];
bool check[17];
int minimum = 1e9;

void dfs(int start, int city, int pay, int depth) {
	if (depth == N) {
		if (node[city][start] == 0)return;
		pay += node[city][start];
		if (minimum > pay) minimum = pay;
		return;
	}
	
	for (int i = 0; i < N; i++) {
		if (check[i] == true) continue;
		if (node[city][i] == 0) continue;
		if (pay + node[city][i] > minimum) continue;
		check[city] = true;
		path[depth] = i;
		dfs(start, i, pay + node[city][i], depth+1);
		check[city] = false;
		
	}
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) scanf("%d", &node[i][j]); // 도시 입력
	check[0] = true;
	path[0] = 0;
	dfs(0, 0, 0, 1);
	printf("%d", minimum);
}