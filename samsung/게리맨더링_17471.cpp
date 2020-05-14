#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

typedef struct {
	int pop;
	vector <int> near;
}area;

int N, s, temp, red, blue, mini = 1000000000;
vector <area> a;
int check[12];
bool state;
queue <int> q;

void dfs(int now, int depth) {  //파란팀을 check == -1 로 정한다.
	if (depth >= 0) {
		for (int i = 1; i <= N; i++) { //모든 노드에 대해서
			if (check[i] != 0) continue;   // dfs에서 했던 건 체크 X
			check[i] = 1;
			q.push(i);
			while (!q.empty()) {
				int red = q.front(); q.pop();
				for (int& next : a[red].near) {
					if (check[next] != 0) continue;
					check[next] = 1;
					q.push(next);
				}
			}
			//for (int i = 1; i <= N; i++) printf("%d ", check[i]); printf("\n");
			state = true;
			for (int i = 1; i <= N; i++)
				if (check[i] == 0) { //방문 안한 곳이 있다.
					state = false;
					break;
				}
			if (state == true) {  //모두 방문 했고, 빨강 / 파랑 나뉘었다.
				blue = 0; red = 0;
				for (int i = 1; i <= N; i++) check[i] == -1 ? blue += a[i].pop : red += a[i].pop;
				if (abs(blue - red) != -1 && mini > abs(blue - red)) mini = abs(blue - red);
				for (int i = 1; i <= N; i++) if (check[i] == 1)check[i] = 0;
				return;
			}
			break;
		}
	}
	for (int& next : a[now].near) {
		if(next == 0)
		if (check[next] != 0) continue;
		check[next] = -1;
		dfs(next, depth + 1);
		check[next] = 0;
	}
}


int main() {
	scanf("%d", &N);
	a.resize(N+1);
	for (int i = 1; i <= N; i++) scanf("%d", &a[i].pop); //인구수 입력
	for (int i = 1; i <= N; i++) {
		scanf("%d", &s);
		for (int j = 0; j < s; j++) {
			scanf("%d", &temp);
			a[i].near.push_back(temp); //인접 노드 입력
		}
	}
	for (int i = 1; i <= N; i++) {
		check[i] = -1;
		dfs(i, 0);
		memset(check, 0, sizeof(check));
	}
	printf("%d", mini == 1000000000 ? -1 : mini);
}