#pragma warning (disable:4996)
#include <iostream>
#include < vector>
#include <cstring>
#include <queue>
using namespace std;
typedef struct {
	int point;
	int dis;
}xy;
vector <vector<xy>> v;



int N;
int ans;
int max_node;
int max_distance;
bool check[100001];
queue <xy> q;

int main() {
	scanf("%d", &N);
	v.resize(N+1);
	int idx, node, distance;
	for (int i = 1; i <= N; i++) {
		scanf("%d", &idx);   //index 입력
		while (1) {
			scanf("%d", &node);
			if (node == -1) break;
			scanf("%d", &distance);
			v[idx].push_back({ node, distance });
		}
	}  //입력 완료

	//임의의 점 1 부터 bfs

	q.push({ 1,0 });
	check[1] = true;
	while (!q.empty()) {
		xy now = q.front(); q.pop();
		if (now.dis > max_distance) {
			max_distance = now.dis;
			max_node = now.point;
		}
		for (int i = 0; i < v[now.point].size(); i++) {
			xy next = v[now.point][i];
			if (check[next.point] == false) {
				next.dis = now.dis + next.dis;
				q.push(next);
				check[next.point] = true;
			}
		}
	}
	while (!q.empty())
		q.pop();
	memset(check, 0, sizeof(check));
	q.push({ max_node, 0 });
	check[max_node] = true;
	max_node = 0; max_distance = 0;
	while (!q.empty()) {
		xy now = q.front(); q.pop();
		if (now.dis > max_distance) {
			max_distance = now.dis;
			max_node = now.point;
		}
		for (int i = 0; i < v[now.point].size(); i++) {
			xy next = v[now.point][i];
			if (check[next.point] == false) {
				next.dis = now.dis + next.dis;
				q.push(next);
				check[next.point] = true;
			}
		}
	}


	printf("%d",max_distance);

}