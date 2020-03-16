#pragma warning(disable:4996)
#include <iostream>

using namespace std;

int S[10];
bool check[10];
int depth;
int N, M;

void dfs(int depth) {
	if (depth == M) {   // M ��ŭ ������ �� ä����. 
		for (int i = 0; i < M; i++) {
			printf("%d ", S[i]);
		}
		printf("\n");
		return;
	}
	for(int i=1; i<=N; i++){  // depth���� ������ �����ϴ� ���ڸ� �ϳ��� �ٲ��ش�. 
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
		S[0] = i;        // ���� ù ������ ��
		dfs(1);      //depth 1���� ä���. 
		check[i] = false;
	}
}