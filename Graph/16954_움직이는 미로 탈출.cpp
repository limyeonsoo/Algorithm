///*
//
//	없어지는 경우가 있으면 바로 끝냈지만, 
//	다른 방법으로 갈 수가 있다.
//*/
//#include <iostream>
//#include <queue>
//#define size 8
//using namespace std;
//int dx[9] = {0, 1, 1, 0, -1, -1, -1, 0, 1};
//int dy[9] = {0, 0, 1, 1, 1, 0, -1, -1, -1};
//char base[size][size];
//queue <pair<int, int> > q;
//void input() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	for (int i = 0; i < size; i++) {
//		int cnt = 0;
//		for (int j = 0; j < size; j++) {
//			cin >> base[i][j];
//			if (base[i][j] == '#')cnt++;
//		}
//		if (cnt == 8) {
//			cout << "0";
//			exit(0);
//		}
//	}
//	q.push({ 0, 7 });
//}
//bool shapCheck() {
//	for (int i = 0; i < size; i++)
//		for (int j = 0; j < size; j++) 
//			if (base[i][j] == '#') 
//				return true;
//	return false;
//}
//bool inner(pair<int, int> coord) {
//	return (0 <= coord.first && coord.first < size && 0 <= coord.second && coord.second < size);
//}
//bool moveWall(pair<int,int> now) {
//	int x = now.first, y = now.second;
//	char temp[size][size];
//	copy(&base[0][0], &base[0][0] + 64, &temp[0][0]);
//	for (int i = 1; i < size; i++) {
//		for (int j = 0; j < size; j++) {
//			if (i == y && j == x && temp[i - 1][j] == '#') return true;
//			base[i][j] = temp[i - 1][j];
//		}
//	}
//	for (int j = 0; j < size; j++) base[0][j] = '.';
//	return false;
//}
//
//int main() {
//	input();
//
//	while (shapCheck()) {
//		pair<int, int> now = q.front(); q.pop();
//		if (moveWall(now)) {
//			cout << "0";
//			exit(0);
//		};
//		for (int d = 0; d < 9; d++) {
//			pair<int, int> next = { now.first + dx[d], now.second + dy[d] };
//			if (!inner(next)) continue;
//			if (base[next.second][next.first] == '#') continue;
//			if (!moveWall(next)) continue;
//			q.push(next);
//		}
//
//		
//	}
//	cout << "1";
//
//}

/*

	없어지는 경우가 있으면 바로 끝냈지만,
	다른 방법으로 갈 수가 있다.
*/
#include <iostream>
#include <queue>
#define size 8
using namespace std;
int dx[9] = { 0, 1, 1, 0, -1, -1, -1, 0, 1 };
int dy[9] = { 0, 0, 1, 1, 1, 0, -1, -1, -1 };
vector <vector<char> > basic;
vector <vector<char> > sharp;
void input() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	basic.resize(size);
	sharp.resize(size);
	for (int i = 0; i < size; i++) {
		basic[i].resize(size);
		sharp[i].resize(size);
		int cnt = 0;
		for (int j = 0; j < size; j++) {
			cin >> basic[i][j];
			if (basic[i][j] == '#')cnt++;
			sharp[i][j] = '#';
		}
		if (cnt == 8) {
			cout << "0";
			exit(0);
		}
	}
}
bool sameSharp(vector <vector<char> > base) {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < size; j++) {
			if (base[i][j] != sharp[i][j]) return false;
		}
	}
	return true;
}
bool shapCheck(vector <vector<char> > base) {
	int check = 0;
	
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			if (base[i][j] == '#')
				check++;
	
	if (check == 0) {
		cout << "1";
		exit(0);
	}
	return (0<check && check<64);
}
bool inner(pair<int, int> coord) {
	return (0 <= coord.first && coord.first < size && 0 <= coord.second && coord.second < size);
}
vector <vector<char> > moveWall (pair<int,int> now, vector <vector<char> > base){
	int x = now.first, y = now.second;
	vector <vector<char> > temp;
	temp.resize(size); for (int i = 0; i < size; i++) temp[i].resize(size);
	copy(base.begin(), base.end(), temp.begin());
	for (int i = 1; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (i == y && j == x && base[i - 1][j] == '#') return sharp;
			temp[i][j] = base[i - 1][j];
		}
	}
	for (int j = 0; j < size; j++) temp[0][j] = '.';
	return temp;
}
void dfs(int x, int y, vector <vector<char> > base) {
	
	if (sameSharp(base)) return;
	if (!shapCheck(base)) return;
	
	for (int i = 0; i < 9; i++) {
		pair<int, int> next = { x + dx[i], y + dy[i] };
		if (!inner(next)) continue;
		if (base[next.second][next.first] == '#') continue;
		dfs(next.first, next.second, moveWall(next, base));
	}

}

int main() {
	input();
	
	vector <vector<char> > temp;
	temp.resize(size); for (int i = 0; i < size; i++) temp[i].resize(size);
	copy(basic.begin(), basic.end(), temp.begin());
	
	for (int i = 0; i < 9; i++) {
		pair<int, int> next = { 0 + dx[i], 7 + dy[i] };
		if (!inner(next)) continue;
		if (basic[next.second][next.first] == '#') continue;
		temp = moveWall(next, basic);
		dfs(next.first, next.second, temp);
	}
	cout << "0";
}
