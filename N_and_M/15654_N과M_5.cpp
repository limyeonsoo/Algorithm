#pragma warning(disable:4996)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int S[10];
int N, M, P;
bool check[10001];
vector <int> v;

void dfs(int depth) {
	if (depth == M) {
		for (int i = 0; i < M; i++) {
			printf("%d ", S[i]);
		}
		printf("\n");
		return;
	}
	for (int& i:v) {
		if (check[i]) continue;
		check[i] = true;
		S[depth] = i;
		dfs(depth + 1);
		check[i] = false;
	}
}

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		scanf("%d", & P);
		v.push_back(P);
	}
	sort(v.begin(), v.end());

	for (int& i:v) {
		check[i] = true;
		S[0] = i;
		dfs(1);
		check[i] = false;
	}
}