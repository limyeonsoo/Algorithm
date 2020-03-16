#pragma warning(disable:4996)
#include <iostream>
#include <vector>
using namespace std;

int S[10];
int N, M;
bool check[10];

void dfs(int depth) {

	if (depth == M) {
		for (int i = 0; i<M; i++) {
			cout << S[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = 1; i <= N; i++) {
		if (check[i])
			continue;
		check[i] = true;
		S[depth] = i;
		dfs(depth + 1);
		check[i] = false;
		
	}
}

int main() {
	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++) {
		check[i] = true;
		S[0] = i;
		dfs(1);
		check[i] = false;
	}
	return 0;

}