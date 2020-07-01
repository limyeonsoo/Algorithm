#pragma warning(disable:4996)
#include <iostream>
#include <algorithm>
#include <cstring>
#define INF 987654321

using namespace std;

int N, candidate;
int node[17][17];
int dp[17][1 << 17];

int dfs(int now, int depth) {
	if (depth == ((1<<N)-1)) {
		if (node[now][0] != 0) return node[now][0];
		return INF;
	}
	if (dp[now][depth] != -1) return dp[now][depth];
	dp[now][depth] = INF;
	for (int i = 0; i < N; i++) {
		if (depth & (1 << i)) continue; //방문했으면 안감.
		if (node[now][i] == 0) continue;  //길이 없어도 안감.
		dp[now][depth] = min(dp[now][depth],node[now][i] + dfs(i, depth | (1 << i))); // 방문 할 때 checking
	}
	return dp[now][depth];
}
//
//int dfs(int now, int depth) {
//	if (depth == (1 << N) - 1) {
//		if (node[now][0] != 0) return node[now][0];
//		return INF;
//	}
//	int &result = dp[now][depth];
//	if (result != -1) return result;
//	result = INF;
//	for (int i = 0; i < N; i++) {
//		if (depth & (1 << i)) continue; //방문했으면 안감.
//		if (node[now][i] == 0) continue;  //길이 없어도 안감.
//		candidate = node[now][i] + dfs(i, depth | (1 << i));
//		result = min(result, candidate); // 방문 할 때 checking
//	}
//	return result;
//}


int main() {
	scanf("%d", &N);
	memset(dp, -1, sizeof(dp));
	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) scanf("%d", &node[i][j]); // 도시 입력
	//printf("%d", dfs(0,1));
	int test = 12;
	for (int i = 0; i < (1 << test); i++) {
		printf("%d ", i);
	}
	printf("\n");
	for (int i = 0; i <test; i++) {
		printf("%d ", i);
	}
}