#pragma warning(disable:4996)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int S[10];
int N, M, P;
vector <int> v;

void dfs(int depth) {
	if (depth == M) {
		for (int i = 0; i < M; i++) {
			printf("%d ", S[i]);
		}
		printf("\n");
		return;
	}
	for (int& i : v) {	
		if (i >= S[depth - 1]) {
			S[depth] = i;
			dfs(depth + 1);
		}
			
	}
}

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		scanf("%d", &P);
		v.push_back(P);
	}
	sort(v.begin(), v.end());

	for (int& i : v) {
		S[0] = i;
		dfs(1);
	}
}