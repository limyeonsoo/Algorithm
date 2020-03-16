#pragma warning (disable:4996)
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> v[1001];
int cnt[1001];
int N, M, connection;     //정점의 개수 N,  간선의 개수 M
void dfs(int x) {
	cnt[x] = 1;
	for (int i = 0; i < v[x].size(); i++) {   //v[x]에는 x와 연결된 노드만큼이 size.
		if (cnt[v[x][i]] == 0)
			dfs(v[x][i]);
	}
}

int main() {
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= M; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		v[a].push_back(b); v[b].push_back(a);
	}
	sort(v->begin(), v->end());
	for (int i = 1; i <= N; i++) {   //요소의 개수 N  모든 요소에 대해 방문 체크 해야함. 
		if (cnt[i] == 0) {     // 한 번 돌면 연결요소만큼만 돔.
			dfs(i); 
			connection++;
		}
		else continue;
	}
	printf("%d", connection);
}