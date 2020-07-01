#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int node[1001][1001];
int pay_dp[1001];
bool check[1001];
int N, M, A, B, x, y, pay, result = 987654321;


void dfs(int now, int pay) {
	if (now == B) {
		if (result > pay) result = pay;
	}
	for (int i = 1; i <= N; i++) {
		if (check[i]) continue;
		if (node[now][i] == -1)continue;
		if ((pay + node[now][i]) >= result) continue;
		check[i] = true;
		dfs(i, pay + node[now][i]);
		check[i] = false;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M;
	memset(node, -1, sizeof(node));
	while (M--) {
		cin >> x >> y >> pay;
		node[x][y] = pay;
	}
	cin >> A >> B;
	check[A] = true;
	dfs(A, 0);
	cout << result;
}