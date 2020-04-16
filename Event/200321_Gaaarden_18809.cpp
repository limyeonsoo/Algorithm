/*
초록 , 빨강  배양액을 뿌릴 위치를 구해야함.
동시에 만나는 곳 꽃.
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

typedef struct{
	int x;
	int y;
}coord;

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

int X, Y, G, R, med;
int garden[51][51];      //garden 입력  호수, 땅, 배양액가능 땅
vector <pair<coord, bool>> culture;

pair<int, int> check_flower[51][51];    //first 는 G, or R  second는 초
vector <pair <coord, int>> cand_R;
vector <pair <coord, int>> cand_G;

queue <coord> q;
int result = 0;

void gardening() {
	for (int y = 0; y < Y; y++) {           //초기화.
		for (int x = 0; x < X; x++) {
			check_flower[y][x].first = 0;
			check_flower[y][x].second = 0;
		}
	}
	med = G;
	int cnt = 0;  //flower 3 을 count;
	for (int j = 0; j < R; j++) {   //순열(2인 곳)부터 bfs로 뻗는다
		check_flower[cand_R[j].first.y][cand_R[j].first.x].first = 1;  //1은 G 2는 R  3은 flower
		q.push({ cand_R[j].first.x, cand_R[j].first.y });
		med--;
	}
	for (int j = 0; j < G; j++) {   //순열(2인 곳)부터 bfs로 뻗는다
		check_flower[cand_G[j].first.y][cand_G[j].first.x].first = 2;  //1은 G 2는 R  3은 flower
		q.push({ cand_G[j].first.x, cand_G[j].first.y });
		med--;
	}  //큐를 통해 배양액 분배 완료.
	while (!q.empty()) {
		coord now = q.front(); q.pop();
		if (check_flower[now.y][now.x].first == 3) continue;  // 이미 flower이면 확인 필요 X
		for (int k = 0; k < 4; k++) { //방향.
			coord next = { now.x + dx[k], now.y + dy[k] };
			if (!(0 <= next.x && next.x < X && 0 <= next.y && next.y < Y)) continue;// 격자 내부 조건 만족.
			if (garden[next.y][next.x] == 0) continue;
			if (check_flower[next.y][next.x].first == 3) continue;  // 이미 flower이면 확인 필요 X
			if (check_flower[next.y][next.x].first == 0) { //아직 퍼지지 않은 땅.
				check_flower[next.y][next.x].first = check_flower[now.y][now.x].first;            //G나 R이 퍼진다.
				check_flower[next.y][next.x].second = check_flower[now.y][now.x].second + 1;// 초는 바뀐다.
				q.push(next);
			}
			else if (check_flower[now.y][now.x].first == 1 && check_flower[next.y][next.x].first == 2) { //R인 곳에 G이
				if (check_flower[now.y][now.x].second + 1 != check_flower[next.y][next.x].second) continue;
				check_flower[next.y][next.x].first = 3;
				cnt++;
			}
			else if (check_flower[now.y][now.x].first == 2 && check_flower[next.y][next.x].first == 1) { //R인 곳에 G이
				if (check_flower[now.y][now.x].second + 1 != check_flower[next.y][next.x].second) continue;
				check_flower[next.y][next.x].first = 3;
				cnt++;
			}
		}
	}
	if (result < cnt) result = cnt;
}
void permutation_R(int depth) {
	if (depth == R) { //cand의 순열을 이용한다.
		gardening();
		return;
	}
	for (int i = depth == 0 ? 0 : cand_R[depth - 1].second + 1; i < culture.size(); i++) {
		if (culture[i].second == true) continue;
		culture[i].second = true;
		cand_R[depth] = { { culture[i].first.x, culture[i].first.y },i };
		permutation_R(depth + 1);
		culture[i].second = false;
	}
}

void permutation_G(int depth) {
	if (depth == G) { //cand의 순열을 이용한다.
		permutation_R(0);
		return;
	}
	for (int i = depth == 0 ? 0 : cand_G[depth - 1].second + 1; i < culture.size(); i++) {
		if (culture[i].second == true) continue;
		culture[i].second = true;
		cand_G[depth] = {{ culture[i].first.x, culture[i].first.y }, i};
		permutation_G(depth+1);
		culture[i].second = false;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> Y >> X >> G >> R;
	
	for (int i = 0; i < Y; i++)
		for (int j = 0; j < X; j++) {
			cin >> garden[i][j];
			if(garden[i][j] == 2) culture.push_back({ { j,i },false }); //좌표와 bool
		}
			//scanf("%d", &garden[i][j]);    //0 : 호수  1 : 배양액 X  2: 배양액 O
		   // 정원 입력 받았음.

	 // TODO : G R 뿌릴 곳을 찾아야함. 2~10개
	 // 중복되지 않는 순열. 조합 X
	cand_R.resize(R);
	cand_G.resize(G);
	permutation_G(0);
	cout << result << '\n';
	//printf("\n%d", result);
}
