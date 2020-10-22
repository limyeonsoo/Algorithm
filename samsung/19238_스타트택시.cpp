/*
	지도 위
		1 : 벽
		0 : 길
		2 : 사람
		3 : 목적지
*
6 3 1
0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 0 0 0
1 1
1 1 1 2
1 2 1 3
1 3 1 6
*/
#include <iostream>
#include <map>
#include <queue>
#include <cstring>
#define ll long long
using namespace std;
map <pair<int, int>, pair<int,int> > paths;
int N, M, taxi_x, taxi_y, man_x, man_y, dest_x, dest_y, answer;
ll E;
int base[21][21];
int nav[21][21];
int visit[21][21];
int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};
queue <pair<int, int> > q;
void input() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M >> E;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> base[i][j];
		}
	}
	cin >> taxi_y >> taxi_x;
	for (int i = 0; i < M; i++) {
		cin >> man_y >> man_x >> dest_y >> dest_x;
		base[man_y][man_x] = 2;
		paths[{man_x, man_y}] = { dest_x, dest_y };
	}
}
bool Check(int energy) {
	return (energy < 0 ? true : false);
}
bool inner(int x, int y) {
	return (0 < x && x <= N && 0 < y && y <= N);
}
int FindingCustomer() {
	memset(visit, -1, sizeof(visit));
	q = queue <pair<int, int> >();
	visit[taxi_y][taxi_x] = 0;
	q.push({ taxi_x, taxi_y });
	int maxDistance = 2147483647;
	if (base[taxi_y][taxi_x] == 2) {
		pair<int, int> dest = paths[{taxi_x, taxi_y}];
		nav[dest.second][dest.first] = 3;
		base[taxi_y][taxi_x] = 0;
		return 0;
	}
	while (!q.empty()) {
		pair<int, int> now = q.front(); q.pop();
		if (visit[now.second][now.first] > maxDistance) break;
		for (int i = 0; i < 4; i++) {
			pair<int, int> next = { now.first + dx[i], now.second + dy[i] };
			if (!inner(next.first, next.second)) continue;
			if (visit[next.second][next.first] > maxDistance) break;
			if (base[next.second][next.first] == 1)continue;
			if (visit[next.second][next.first] != -1) continue;
			visit[next.second][next.first] = visit[now.second][now.first] + 1;
			q.push(next);
			if (base[next.second][next.first] == 2 && maxDistance == 2147483647) {
				maxDistance = visit[next.second][next.first];
			}
		}
	}
	/*if (base[next.second][next.first] == 2) {
		taxi_x = next.first, taxi_y = next.second;
		E -= visit[taxi_y][taxi_x];
		if (Check(E)) return -1;
		pair<int, int> dest = paths[{taxi_x, taxi_y}];
		base[dest.second][dest.first] = 3;
		base[next.second][next.first] = 0;
		return 0;
	}*/
	
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (base[i][j] == 2 && visit[i][j] == maxDistance) {
				taxi_x = j, taxi_y = i;
				E -= visit[taxi_y][taxi_x];
				if (Check(E)) return -1;
				pair<int, int> dest = paths[{taxi_x, taxi_y}];
				nav[dest.second][dest.first] = 3;
				base[i][j] = 0;
				return 0;
			}
		}
	}
	return -1;
}
int FindingDestination() {
	memset(visit, -1, sizeof(visit));
	q = queue <pair<int, int> >();
	visit[taxi_y][taxi_x] = 0;
	q.push({ taxi_x, taxi_y });
	while (!q.empty()) {
		pair<int, int> now = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			pair<int, int> next = { now.first + dx[i], now.second + dy[i] };
			if (!inner(next.first, next.second)) continue;
			if (base[next.second][next.first] == 1)continue;
			if (visit[next.second][next.first] != -1) continue;
			visit[next.second][next.first] = visit[now.second][now.first] + 1;
			q.push(next);
			if (nav[next.second][next.first] == 3) {
				taxi_x = next.first, taxi_y = next.second;
				E -= visit[taxi_y][taxi_x];
				if (Check(E)) return -1;
				nav[taxi_y][taxi_x] = 0;
				E += visit[taxi_y][taxi_x] * 2;
				return 0;
			}
		}
	}
	return -1;
}
int main() {
	input();
	while (M--) {
		if (FindingCustomer() == -1) {
			answer = -1;
			break;
		}
		if (FindingDestination() == -1) {
			answer = -1;
			break;
		}
	}
	cout << (answer == -1 ? answer : E);
}
