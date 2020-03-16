#pragma warning(disable:4996)
#include <iostream>

using namespace std;

int S[10];
bool check[10];
int depth;
int N, M;

void dfs(int depth) {
	if (depth == M) {   // M 만큼 순열을 다 채웠다. 
		for (int i = 0; i < M; i++) {
			printf("%d ", S[i]);
		}
		printf("\n");
		return;
	}
	for(int i=1; i<=N; i++){  // depth마다 순열을 구성하는 숫자를 하나씩 바꿔준다. 
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
		S[0] = i;        // 제일 첫 순열의 수
		dfs(1);      //depth 1부터 채운다. 
		check[i] = false;
	}
}