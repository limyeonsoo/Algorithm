#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef struct tree{
	int x;
	int y;
	int z;
};
int N, M, K; // N*N개, M개의 나무 정보 x,y,z x,y위치  z는 나이  K년 지난 후
int x, y, z;
vector <vector<vector<int>>> garden;
vector <vector<int>> gradient;
vector <tree> Tree; //여름용

void spring() {  //자신의 나이 (garden의 값 만큼)양분 먹고 1 증가. 여러 개 나무라면 어린 나무만. 양분 없으면 죽는다.
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (garden[i][j].size() != 0) {  //나무가 있다.
				sort(garden[i][j].begin(), garden[i][j].end());
				for (int t = 0; t < garden[i][j].size(); t++) {
					if (gradient[i][j] >= garden[i][j][t]) { //양분을 먹을 수 있다.
						gradient[i][j] -= garden[i][j][t];
						garden[i][j][t] += 1;
					}
					else { //t이후는 다 죽는다.
						for (int g = t; g < garden[i][j].size(); g++) {
							Tree.push_back({ j,i,garden[i][j][g] });
						}
						garden[i][j].erase(garden[i][j].begin() + t, garden[i][j].end());
					}
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M >> K;
	garden.resize(N); for (int i = 0; i < N; i++) garden[i].resize(N);
	gradient.resize(N); for (int i = 0; i < N; i++) gradient[i].resize(N);
	for (int i = 0; i < N; i++) { // 땅 정보 입력 받기.
		for (int j = 0; j < N; j++) {
			cin >> gradient[i][j];       //양분
		}
	}
	for (int i = 0; i < M; i++) {  //나무 정보 입력 받기.
		cin >> x >> y >> z;
		garden[y-1][x-1].push_back(z);   //인덱스가 0부터 시작.
	}
	
	
}
