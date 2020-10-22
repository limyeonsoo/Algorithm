/*
	봄:
		양분 먹기   (어린 나무부터 양분 먹기)
			못먹으면 죽는다.
			먹었으면 나이 증가

		여름 준비
			죽은 나무 좌표, 나이 필요

	가을: 

		범위 안에 age 1인 나무 번식 
			(-) 번식을 하면서 tree vector가 늘어나서 시간이 더 늘어남.
	
*/
#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long

using namespace std;

struct Base {
	int energy;
	vector <int> tree;
};

int N, M, K, x, y, z;
int dx[8] = { 1, 1, 0, -1, -1, -1, 0, 1 };
int dy[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };
int energy[11][11];
Base base[11][11];
vector <int>::iterator iter;
void input() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) cin >> energy[i][j], base[i][j].energy = 5;
	for (int i = 0; i < M; i++) {
		cin >> x >> y >> z;
		base[x - 1][y - 1].tree.push_back(z);
	}
}
bool inner(int x, int y) {
	return (0 <= x && x < N && 0 <= y && y < N);
}
void springAndSummer() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (base[i][j].tree.size() == 0) continue;
			sort(base[i][j].tree.begin(), base[i][j].tree.end());
			int deadTree = 0;
			vector <int> temp;
			for (iter = base[i][j].tree.begin(); iter != base[i][j].tree.end();++iter) {
				if (base[i][j].energy < *iter) { // 양분이 모자람.
					//deadTree.push_back({ j, i, *iter });
					deadTree += ((*iter) / 2);
					//iter = base[i][j].tree.erase(iter);
				}
				else { // 양분 + 나이
					base[i][j].energy -= *iter;
					temp.push_back((*iter)+1);
				}
			}
			/*for (int k = 0; k < base[i][j].tree.size(); k++) {
				int age = base[i][j].tree[k];
				if (base[i][j].energy < age) {
					deadTree += age/2;
				}
				else {
					base[i][j].energy -= age;
					temp.push_back(age + 1);
				}
			}*/
			base[i][j].tree.clear();
			for (int k = 0; k < temp.size(); k++) {
				base[i][j].tree.push_back(temp[k]);
			}
			base[i][j].energy += deadTree;
		}
	}
}
//void summer() {
//	for (auto& dead : deadTree) base[dead.y][dead.x].energy += (dead.age / 2);
//}
void authmnAndWinter() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			base[i][j].energy += energy[i][j];
			
			if (base[i][j].tree.size() == 0) continue;
			for (iter = base[i][j].tree.begin(); iter != base[i][j].tree.end(); ++iter) {
				if (*iter % 5 != 0) continue;
				for (int d = 0; d < 8; d++) {
					if (!inner(j + dx[d], i + dy[d])) continue;
					base[i + dy[d]][j + dx[d]].tree.push_back(1);
				}
			}
			/*for (int k = 0; k < base[i][j].tree.size(); k++) {
				if (base[i][j].tree[k] % 5 != 0)continue;
				for (int d = 0; d < 8; d++) {
					if (!inner(j + dx[d], i + dy[d])) continue;
					base[i + dy[d]][j + dx[d]].tree.push_back(1);
				}
			}*/
		}
	}
}
//void winter() {
//	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) base[i][j].energy += energy[i][j];
//}
ll calcTree() {
	ll answer = 0;
	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) answer += (ll)base[i][j].tree.size();
	return answer;
}
int main() {
	input();
	
	for(int i=0; i<K; i++){
		springAndSummer();
		authmnAndWinter();
	}
	cout << calcTree();
}