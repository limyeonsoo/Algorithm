#pragma warning (disable:4996)
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> v[1001];
int cnt[1001];
int N, M, connection;     //������ ���� N,  ������ ���� M
void dfs(int x) {
	cnt[x] = 1;
	for (int i = 0; i < v[x].size(); i++) {   //v[x]���� x�� ����� ��常ŭ�� size.
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
	for (int i = 1; i <= N; i++) {   //����� ���� N  ��� ��ҿ� ���� �湮 üũ �ؾ���. 
		if (cnt[i] == 0) {     // �� �� ���� �����Ҹ�ŭ�� ��.
			dfs(i); 
			connection++;
		}
		else continue;
	}
	printf("%d", connection);
}