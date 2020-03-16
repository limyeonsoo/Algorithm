#pragma warning (disable:4996)
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
vector <int> v[20001];
int color[20001];
int V, E, K; // 정점의 개수, 간선의 개수, 테스트 케이스의 개수
int a, b;  // 정점1, 정점2;

bool result = true;
void dfs(int x) {
	
	for (int i = 0; i < v[x].size(); i++) {
		if (color[v[x][i]] == 0 ) {
			color[v[x][i]] = 3 - color[x];          //현재 color값과 다음의 color값을 다르게 주는 것이 중요.
			dfs(v[x][i]);
		}
		else if(color[v[x][i]]==color[x])       //방문을 했었는데, 현재 값과 다음 값의 color가 같다면 이분그래프 X
			result = false;
	}
}

int main() {
	scanf("%d", &K);
	while (K--) {   //테스트 케이스
  		result = true;
		scanf("%d%d", &V, &E);
		for (int i = 1; i <= E; i++) {
			scanf("%d%d", &a, &b);
			v[a].push_back(b); v[b].push_back(a);
		}
		for (int i = 1; i <= V; i++) {           // 모든 정점에 대해서
			if (color[i] == 0 && result) {       // color==0 이면 방문하지 않은 것.  result==true 라는 것은 이분그래프일 가능성이 아직 있음. 
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