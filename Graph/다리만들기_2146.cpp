#pragma warning(disable:4996)
#include <iostream>
#include <queue>

using namespace std;

//queue <pair<pair<int, int>,int>> q;
//int N;
//int land[101][101];
//int bfs_cnt[101][101];
//int dfs_cnt[101][101];
//int dx[4] = { 0, 0, -1, 1 };
//int dy[4] = { -1, 1, 0, 0 };
//int group_cnt[101];
//
//void dfs(int x, int y, int step) {
//	if (dfs_cnt[y][x] != 0) return;
//	dfs_cnt[y][x] = step;
//	for (int i = 0; i < 4; i++)
//		if (0 <= x + dx[i] && x + dx[i] < N && 0 <= y + dy[i] && y + dy[i] < N)
//			if(land[y+dy[i]][x+dx[i]] == 1)
//				dfs(x + dx[i], y + dy[i], step);
//	return;
//}
//
//int main() {
//	scanf("%d", &N);
//	for (int i = 0; i < N; i++)
//		for (int j = 0; j < N; j++)
//			scanf("%d", &land[i][j]);
//
//	int step = 1;
//	for (int i = 0; i < N; i++)
//		for (int j = 0; j < N; j++)
//			if (dfs_cnt[i][j] == 0 && land[i][j] == 1)
//				dfs(j, i, step++);                             //dfs 로 Group을 구한다.	
//
//	for (int i = 0; i < N; i++) {                                  // queue에 넣을때 그룹정보도 함께 준다.
//		for (int j = 0; j < N; j++) {
//			if (land[i][j] == 1) {
//				q.push({ make_pair(j, i), dfs_cnt[i][j]});
//				bfs_cnt[i][j] = land[i][j];
//			}
//		}
//	}
//
//	while (!q.empty()) {                                        //bfs로 거리를 구한다.
//		pair<int, int> curr = q.front().first; int group = q.front().second; q.pop();
//
//		for (int i = 0; i < 4; i++) {
//			pair<int, int> next = { curr.first + dx[i], curr.second + dy[i] };
//			if (0 <= next.first && next.first < N && 0 <= next.second && next.second < N) {
//
//				if (bfs_cnt[next.second][next.first] >= bfs_cnt[curr.second][curr.first] && dfs_cnt[next.second][next.first] != group) {  // 종료 조건.  bfs를 돌다가   다른 Group이 check해놓은 같은 수를 만나면 최소값.          //값이 차이가 날때
//					printf("%d", group_cnt[group] + group_cnt[dfs_cnt[next.second][next.first]]);
//					printf("%d %d", group_cnt[group],group_cnt[dfs_cnt[next.second][next.first]]);
//					exit(0);
//				}
//
//				if (bfs_cnt[next.second][next.first] == 0) {
//					q.push({ next, group });
//					bfs_cnt[next.second][next.first] = bfs_cnt[curr.second][curr.first] + 1;
//					group_cnt[group] = bfs_cnt[next.second][next.first] - 1;
//					dfs_cnt[next.second][next.first] = group;
//
//					
//					if (bfs_cnt[next.second][next.first] == step) {   //마지막 그룹을 돌고 난 후
//						for (int j = 0; j < 4; j++) {
//							pair<int, int>another = { next.first + dx[i], next.second + dy[i] };
//							if (bfs_cnt[another.second][another.first] == bfs_cnt[next.second][next.first]) {
//								printf("%d", group_cnt[group] + group_cnt[dfs_cnt[next.second][next.first]]-1);
//								exit(0);
//							}
//						}
//					}
//				}
//			}
//		}
//		
//	}
//	
//}
//
//
///*
//printf("\n%d %d", group_cnt[group] ,group_cnt[dfs_cnt[next.second][next.first]]);
//					printf("\n%d %d", curr.first, curr.second);
//					printf("\n%d %d", next.first, next.second);
//					printf("\n");
//					for (int i = 0; i < N; i++) {
//						for (int j = 0; j < N; j++) {
//							printf("%d ", dfs_cnt[i][j]);
//						}
//						printf("\n");
//					}printf("\n");
//					for (int i = 0; i < N; i++) {
//						for (int j = 0; j < N; j++) {
//							printf("%d ", bfs_cnt[i][j]);
//						}
//						printf("\n");
//					}
//*/
//
////while (!q.empty()) {                                        //bfs로 거리를 구한다.
////	pair<int, int> curr = q.front().first; int group = q.front().second; q.pop();
////	for (int i = 0; i < 4; i++) {
////		pair<int, int> next = { curr.first + dx[i], curr.second + dy[i] };
////		if (0 <= next.first && next.first < N && 0 <= next.second && next.second < N) {
////			if (bfs_cnt[next.second][next.first] >= bfs_cnt[curr.second][curr.first] + 1 && dfs_cnt[next.second][next.first] != group) {  // 종료 조건.  bfs를 돌다가   다른 Group이 check해놓은 같은 수를 만나면 최소값.
////				printf("%d", bfs_cnt[next.second][next.first]);
////				exit(0);
////			}
////			if (bfs_cnt[next.second][next.first] == 0) {
////				q.push({ next, group });
////				bfs_cnt[next.second][next.first] = bfs_cnt[curr.second][curr.first] + 1;
////				dfs_cnt[next.second][next.first] = group;
////			}
////		}
////	}
////}

/*===============================================================================================*/


int land[101][101];
int group[101][101];
int check[101][101];

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

vector <queue<int>> q;

typedef struct {
	int x;
	int y;
}coord;

void dfs(coord prs, int color) {
	if (land[prs.y][prs.x] == 0 || group[prs.y][prs.x] != 0)
		return;
	group[prs.y][prs.x] = color;
	for (int i = 0; i < 4; i++) {
		coord next; next.x = prs.x + dx[i]; next.y = prs.y + dy[i];
		dfs(next, color);
	}
	return; 
}

int main(){

	int N;
	int min=197;
	int color = 0;
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			scanf("%d", &land[i][j]);

	for (int i = 0; i < N; i++) 
		for (int j = 0; j < N; j++) 
			if (land[i][j] == 1 && group[i][j] == 0) {
				coord prs = { j,i }; 
				dfs(prs, ++color);
			}
	if (color == 1) {
		printf("0"); 
		exit(0);
	}
	while (color) {   // 그룹 별로 BFS실행
		queue <pair<int,int>> q;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				if (group[i][j] == color && land[i][j] == 1) {
					q.push(make_pair(j, i));
					check[i][j] = 1;
				}
		
		while (!q.empty()) {
			coord curr; curr.x = q.front().first; curr.y = q.front().second; q.pop();
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					coord next; next.x = curr.x + dx[i]; next.y = curr.y + dy[i];
					if (0 <= next.x && next.x < N && 0 <= next.y && next.y < N) {
						if (group[next.y][next.x] != color && group[next.y][next.x] != 0)
						{
							if(min > check[curr.y][curr.x] - 1) min = check[curr.y][curr.x] - 1;
							while (!q.empty()) {
								q.pop();
							}
							i = 4; j = 4;
						}
						if (land[next.y][next.x] == 0 && check[next.y][next.x] == 0)
						{
							q.push({ next.x, next.y });
							check[next.y][next.x] = check[curr.y][curr.x] + 1;
						}
					}						
				}
			}
		}
		
		memset(check, 0, sizeof(check));
		color--;
	}
	printf("%d", min);
}
		
