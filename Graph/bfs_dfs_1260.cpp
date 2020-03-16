#pragma warning (disable:4996)
#include <iostream>
#include <vector>
#include<stack>
#include<queue>
#include <algorithm>     //baekjoon sort
#include <cstring>       //baekjoon  memset
using namespace std;
int N, M, V; //N : vertex,  M : edge, V : SP;
int a, b;
vector <int> A[1001];
int check[1001];
stack<int> s;
queue <int> q;
void dfs(int x) {

	check[x] = 1; s.push(x);
	printf("%d ", x);
	for (int i = 0; i < A[x].size(); i++) {
		int y = A[x][i];
		if (check[y] == 0)
			dfs(y);
	}

}
void bfs(int x) {
	memset(check, 0, sizeof(check));
	check[x] = 1;
	q.push(x);
	while(!q.empty()) {
		int y = q.front();
		printf("%d ", y);
		q.pop();
		for (int i = 0; i < A[y].size(); i++) {
			int next = A[y][i];
			if (check[next] == 0) {
				q.push(next); check[next] = 1;
			}
		}
	}
}
int main() {
	
	scanf("%d %d %d", &N, &M, &V);
	
	for (int i = 1; i <= M; i++) {
		scanf("%d %d", &a, &b);
		A[a].push_back(b); A[b].push_back(a);
	}
	for (int i = 1; i <= N; i++) {
		sort(A[i].begin(), A[i].end());
	}
	dfs(V);
	printf("\n");
	bfs(V);

}
