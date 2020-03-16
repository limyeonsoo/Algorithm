#pragma warning (disable:4996)
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
vector <int> v[20001];
int color[20001];
int V, E, K; // ������ ����, ������ ����, �׽�Ʈ ���̽��� ����
int a, b;  // ����1, ����2;

bool result = true;
void dfs(int x) {
	
	for (int i = 0; i < v[x].size(); i++) {
		if (color[v[x][i]] == 0 ) {
			color[v[x][i]] = 3 - color[x];          //���� color���� ������ color���� �ٸ��� �ִ� ���� �߿�.
			dfs(v[x][i]);
		}
		else if(color[v[x][i]]==color[x])       //�湮�� �߾��µ�, ���� ���� ���� ���� color�� ���ٸ� �̺б׷��� X
			result = false;
	}
}

int main() {
	scanf("%d", &K);
	while (K--) {   //�׽�Ʈ ���̽�
  		result = true;
		scanf("%d%d", &V, &E);
		for (int i = 1; i <= E; i++) {
			scanf("%d%d", &a, &b);
			v[a].push_back(b); v[b].push_back(a);
		}
		for (int i = 1; i <= V; i++) {           // ��� ������ ���ؼ�
			if (color[i] == 0 && result) {       // color==0 �̸� �湮���� ���� ��.  result==true ��� ���� �̺б׷����� ���ɼ��� ���� ����. 
				color[i] = 1;
				dfs(i);
				
			}
		}
		memset(color, 0, sizeof(int)*20001);
		for (int i = 0; i < 20001; i++) {
			v[i].clear();
		}
		
		printf("%s\n", result==true ? "YES" : "NO");
	}
}