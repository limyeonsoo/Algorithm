#pragma warning(disable:4996)
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

queue <int> q;
vector <vector<int>> v(100001);

int check[100001];
int parent[100001];
int main() {
	int N, x, y;
	scanf("%d", &N);
	
	for (int i = 0; i < N - 1; i++) {
		scanf("%d %d", &x, &y);
		v[x].push_back(y);
		v[y].push_back(x);
	}

	q.push(1); check[1] = 1;
	while (!q.empty()) {
		int now = q.front(); q.pop();
		for (int i = 0; i < v[now].size(); i++) {
			int next = v[now][i];
			if (check[next] != 1) {
				q.push(next);
				check[next] = 1;
				parent[next] = now;
			}
		}
	}
		
	for (int i = 2; i <= N; i++)
		printf("%d\n", parent[i]);
}