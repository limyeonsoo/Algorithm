///*
//	가장자리는 모두 #이다. => 크기줄일 수 있다.
//
//	pruning 조건 :  파랑이 먼저 나간다.
//					10번이 넘는다.
//
//	8x8  방향 4 * depth 10   10 * 9 * 8 * 7
//
//	0 : 왼 
//	1 : 아래
//	2 : 오
//	3 : 위
//*/
//#include <iostream>
//#include <vector>
//#include <string>
//
//using namespace std;
//vector <vector<char> > base;
//vector <vector<char> > rotation;
//pair <int, int> hole;
//pair <int, int> Red;
//pair <int, int> Blue;
//int dx[4] = { 1, 0, -1, 0 };
//int dy[4] = { 0, 1, 0, -1 };
//int N, M, answer = 2147483647;
//string inputString;
//void input() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cin >> N >> M;
//	base.resize(N - 1); for (int i = 0; i < N - 1; i++) base[i].resize(M - 1);
//	for (int i = 0; i < N; i++) {
//		cin >> inputString;
//		if (i == 0 || i == N - 1)continue;
//		for (int j = 1; j < inputString.size() - 1; j++) {
//			base[i][j] = inputString[j];
//			if (base[i][j] == 'O')base[i][j] = '.', hole = { j,i };
//			if (base[i][j] == 'R') base[i][j] = '.', Red = { j,i };
//			if (base[i][j] == 'B') base[i][j] = '.', Blue = { j,i };
//		}
//	}
//}
//
//bool inner(int x, int y) {
//	return (0 < x && x < M - 1 && 0 < y && y < N - 1);
//}
//
//void solve(pair<int, int> red, pair<int, int> blue, int depth, int direction) {
//	if (answer < depth) return;
//	if(depth > 10) return;
//	bool red_flag = false;
//	bool blue_flag = false;
//	pair<int, int> end_red = red;
//	pair<int, int> end_blue = blue;
//	while (1) {
//		pair<int, int> next = { end_red.first + dx[direction], end_red.second + dy[direction] };
//		if (!inner(next.first, next.second)) break;
//		if (base[next.second][next.first] == '#') break;
//		if (next.second == hole.second && next.first == hole.first) red_flag = true;
//		
//		end_red = next;
//
//	}
//	while (1) {
//		pair<int, int> next = { end_blue.first + dx[direction], end_blue.second + dy[direction] };
//		if (!inner(next.first, next.second)) break;
//		if (base[next.second][next.first] == '#') break;
//		if (next.second == hole.second && next.first == hole.first) blue_flag = true;
//		end_blue = next;
//	}
//	if (end_red.first == end_blue.first && end_red.second == end_blue.second) {
//		if (direction == 0 ) { //가로
//			if (red.first < blue.first) end_red.first = end_red.first - dx[direction];
//			else end_blue.first = end_blue.first - dx[direction];
//		}
//		else if (direction == 2) {
//			if (red.first < blue.first) end_blue.first = end_blue.first - dx[direction];
//			else end_red.first = end_red.first - dx[direction];
//		}
//		else if (direction == 1) {
//			if (red.second < blue.second) end_red.second = end_red.second - dy[direction];
//			else end_blue.second = end_blue.second - dy[direction];
//		}
//		else if (direction == 3) {
//			if (red.second < blue.second) end_blue.second = end_blue.second - dy[direction];
//			else end_red.second = end_red.second - dy[direction];
//		}
//	}
//	
//	if (blue_flag) return;
//	if (red_flag && depth<=10) {
//		answer = (answer > depth ? depth : answer);
//		return;
//	}
//	
//	for (int i = 0; i < 4; i++) {
//		if (i == direction) continue;
//		if ((abs(i - direction)) == 2) continue;
//		solve(end_red, end_blue, depth + 1, i);
//	}
//}
//
//
//int main() {
//	input();
//	
//	for (int i = 0; i < 4; i++) {
//		solve(Red, Blue, 1, i);
//	}
//	
//	cout << (answer <= 10 ? 1 : 0);
//}

/*
6 7
#######
#R....#
#.###.#
#....##
#..#BO#
#######


10 10
##########
#R#...##.#
#........#
########.#
#...#....#
#.#...####
#.########
#.#O...###
#...######
##########

10 10
##########
#R#...##.#
#B.......#
########.#
#...#....#
#.#...####
#.########
#.#....###
#O...#####
##########
*/

/*
	가장자리는 모두 #이다. => 크기줄일 수 있다.

	pruning 조건 :  파랑이 먼저 나간다.
					10번이 넘는다.

	8x8  방향 4 * depth 10   10 * 9 * 8 * 7

	0 : 왼
	1 : 아래
	2 : 오
	3 : 위
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;
vector <vector<char> > base;
pair <int, int> hole, Red, Blue;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int N, M, answer = 2147483647;
string inputString;

void input() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M;
	base.resize(N - 1); for (int i = 0; i < N - 1; i++) base[i].resize(M - 1);
	for (int i = 0; i < N; i++) {
		cin >> inputString;
		if (i == 0 || i == N - 1)continue;
		for (int j = 1; j < inputString.size() - 1; j++) {
			base[i][j] = inputString[j];
			if (base[i][j] == 'O')base[i][j] = '.', hole = { j,i };
			if (base[i][j] == 'R') base[i][j] = '.', Red = { j,i };
			if (base[i][j] == 'B') base[i][j] = '.', Blue = { j,i };
		}
	}
}

bool inner(int x, int y) {
	return (0 < x && x < M - 1 && 0 < y && y < N - 1);
}

pair<int, int> moving(pair<int, int> color, int direction, bool &flag) {
	while (1) {
		pair<int, int> next = { color.first + dx[direction], color.second + dy[direction] };
		if (!inner(next.first, next.second)) break;
		if (base[next.second][next.first] == '#') break;
		if (next.second == hole.second && next.first == hole.first) flag = true;
		color = next;
	}
	return color;
}

void solve(pair<int, int> red, pair<int, int> blue, int depth, int direction) {
	if (answer < depth) return;
	if (depth > 10) return;
	bool red_flag = false;
	bool blue_flag = false;
	pair<int, int> end_red = red;
	pair<int, int> end_blue = blue;
	
	end_red = moving(end_red, direction, red_flag);
	end_blue = moving(end_blue, direction, blue_flag);
	
	if (end_red.first == end_blue.first && end_red.second == end_blue.second) {
		if (direction == 0) {
			if (red.first < blue.first) end_red.first = end_red.first - dx[direction];
			else end_blue.first = end_blue.first - dx[direction];
		}
		else if (direction == 2) {
			if (red.first < blue.first) end_blue.first = end_blue.first - dx[direction];
			else end_red.first = end_red.first - dx[direction];
		}
		else if (direction == 1) {
			if (red.second < blue.second) end_red.second = end_red.second - dy[direction];
			else end_blue.second = end_blue.second - dy[direction];
		}
		else if (direction == 3) {
			if (red.second < blue.second) end_blue.second = end_blue.second - dy[direction];
			else end_red.second = end_red.second - dy[direction];
		}
	}

	if (blue_flag) return;
	if (red_flag && depth <= 10) {
		answer = (answer > depth ? depth : answer);
		return;
	}

	for (int i = 0; i < 4; i++) {
		if (i == direction) continue;
		if ((abs(i - direction)) == 2) continue;
		solve(end_red, end_blue, depth + 1, i);
	}
}

int main() {
	input();
	for (int i = 0; i < 4; i++) solve(Red, Blue, 1, i);
	cout << (answer <= 10 ? answer : -1);
}

/*
6 7
#######
#R....#
#.###.#
#....##
#..#BO#
#######


10 10
##########
#R#...##.#
#........#
########.#
#...#....#
#.#...####
#.########
#.#O...###
#...######
##########

10 10
##########
#R#...##.#
#B.......#
########.#
#...#....#
#.#...####
#.########
#.#....###
#O...#####
##########
*/