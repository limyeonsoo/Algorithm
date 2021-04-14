/*

	yyyy
	gggg   ¿œ ∞ÊøÏ πÿ ∂Û¿Œ∏∏ ∫¡º≠¥¬ æ»µ .

	=> ≈Î«’


*/

#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <queue>
#define R 0
#define G 1
#define B 2
#define P 3
#define Y 4
using namespace std;

priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> columnUnion;
struct Temp {
	string puyo;
	int x;
	int y;
};
vector <Temp> temp;
int puyoColor[5]; //RGBPY
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
bool visit[12][6];
int bombed, depth, result = -1;
vector <vector<string>> puyopuyo;
string sentence;

void input() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	puyopuyo.resize(12);
	for (int i = 0; i < 12; i++) puyopuyo[i].resize(6);
	for (int i = 0; i < 12; i++) {
		cin >> sentence;
		for (int j = 0; j < 6; j++) {
			puyopuyo[i][j] = sentence[j];
		}
	}
}
void colorColumnCheck(string puyo, int x, int y) {
	columnUnion.push({ x,y });
}

void dfs(int x, int y) {
	string puyo = puyopuyo[y][x];
	depth += 1;
	temp.push_back({ puyo, x, y });
	for (int i = 0; i < 4; i++) {
		pair<int, int> next = { x + dx[i], y + dy[i] };
		if (next.first < 0 || next.first>5) continue;
		if (next.second < 0 || next.second>11) continue;
		if (puyopuyo[next.second][next.first] != puyo) continue;
		if (visit[next.second][next.first]) continue;
		visit[next.second][next.first] = true;
		dfs(next.first, next.second);
	}
}

void bomb(int x, int y) {
	for (int i = y; i > 0; i--) {
		puyopuyo[i][x] = puyopuyo[i-1][x];
	}
	puyopuyo[0][x] = ".";
}

int main() {
	input();
	do {
		bombed = 0, result++;
		for (int i = 11; i >= 0; i--) {
			for (int j = 0; j < 6; j++) {
				if (visit[i][j])continue;
				if (puyopuyo[i][j] == ".") continue;
				visit[i][j] = true;
				dfs(j, i);
				if (depth >= 4) {
					for (int k = 0; k < temp.size(); k++) {
						colorColumnCheck(temp[k].puyo, temp[k].x, temp[k].y);
					}
				}
				temp.clear();
				depth = 0;
			}
		}
		while (!columnUnion.empty()) {
			bombed++;
			bomb(columnUnion.top().first, columnUnion.top().second);
			columnUnion.pop();
		}
		memset(visit, false, sizeof(visit));
		for (int i = 0; i < 5; i++) puyoColor[i] = 0;
		
	} while (bombed);
	

	cout << result;
}