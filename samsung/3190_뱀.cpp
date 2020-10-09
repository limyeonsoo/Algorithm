/*
	now와 next로 관리. 뱀이 있는 곳은  visit
	사과가 있는 곳은 base;
	
	방향에 따라 dx dy 지정.

	state = 0, 1, 2, 3
	0 : right
	1 : down
	2 : left
	3 : up
	state = (state + 1) % 4;
		
		 0 -> 1
		 1 -> 2
		 2 -> 3
		 3 -> 0
		
	state = (state + 3) % 4;
		
			0 -> 3
			1 -> 0
			2 -> 1
			3 -> 2


	**************   now.x now.y 를 0으로 바꾸는게 아니라 꼬리를 바꿔야한다.
	**** 사과 먹으면 없어진다.
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
struct Coord {
	int x;
	int y;
};
int boardSize, appleSize, waySize, state, time;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
vector <vector <int> > base;
vector <vector <int> > visit;
queue <pair<int, char> > timer;
queue <Coord> q;
queue <Coord> tailQueue;
bool inner(Coord now) {
	return (0 < now.x && now.x <= boardSize && 0 < now.y && now.y <= boardSize);
}
void rotate(char way) {
	state = (state + (way == 'D' ? 1 : 3)) % 4;
}
void input() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> boardSize;
	base.resize(boardSize+1); for (int i = 1; i <= boardSize; i++) base[i].resize(boardSize+1);
	visit.resize(boardSize+1); for (int i = 1; i <= boardSize; i++) visit[i].resize(boardSize+1);
	cin >> appleSize;
	for (int i = 0; i < appleSize; i++) {
		int x, y;
		cin >> y >> x;
		base[y][x] = 1;
	}
	cin >> waySize;
	for (int i = 0; i < waySize; i++) {
		int time; char way;
		cin >> time >> way;
		timer.push({ time,way });
	}
	visit[1][1] = 1;
	q.push({ 1, 1 });
	tailQueue.push({ 1, 1 });
}
int main() {
	input();

	while (!q.empty()) {  // TODO : time++  시점.
		Coord now = q.front(); q.pop();
		time++;
		Coord next = { now.x + dx[state], now.y + dy[state] };
		if (!inner(next)) break;
		if (visit[next.y][next.x]) break;
		
		if (!base[next.y][next.x]) {
			Coord tail = tailQueue.front(); tailQueue.pop();
			visit[tail.y][tail.x] = 0;
		}
		base[next.y][next.x] = 0;
		visit[next.y][next.x] = 1;
		tailQueue.push(next);
		q.push(next);
		if (!timer.empty() && timer.front().first == time) {
			rotate(timer.front().second);
			timer.pop();
		}
	}
	cout << time;
}