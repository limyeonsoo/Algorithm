#pragma warning(disable:4996)
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int K, N, p; 
vector <int> v(1001);
int check[1001];
void dfs(int x) {       //정점은 한 정점에 하나씩만 연결되어있으므로, for문 필요 X
	if (check[x] != 0) return;
	check[x] = 1;
	x = v[x];
	dfs(x);
}

int main() {
	scanf("%d", &K);
	while (K--) {
		int count = 0;
		scanf("%d", &N);
		for (int i = 1; i <= N; i++) {
			scanf("%d", &p);
			v[i]=p;                      // 1차원 배열   한 정점에 연결된 정점이 단 하나,
		}
		for (int i = 1; i <= N; i++) {
			if (check[i] == 0) {         //방문하지 않았으면 dfs후 count++
				dfs(i);
				count++;                 //연결요소를 구하는 count.
			}
		}
		memset(check, 0, sizeof(check));
		printf("%d\n", count);
	}

}