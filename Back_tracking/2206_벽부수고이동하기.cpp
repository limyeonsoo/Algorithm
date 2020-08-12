/*
	벽을 하나만 부수는 방법 :

	1. 다 돌고 1이 1개인 경로만 추출?
	2. 1을 한 개씩 지워보면서 경로를 탐색? o -> x 전부 벽일 경우 백만X백만의 복잡도 필요.

	보통 BFS로 탐색할 경우 최단경로가 됨.
	경로 저장이 기억이 안남.

*/

#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;
struct xyz {
	int x, y, z;
};
vector <vector<int> > base;
int check[1001][1001][2];  // 좌표 당 step의 수 & wall의 수 
queue <xyz> q;


int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int N, M, result = 2147483647;
string temp;
int main() {
	cin >> N >> M;
	base.resize(N + 1); for (int i = 1; i <= N; i++) base[i].resize(M + 1);
	
	for (int i = 1; i <= N; i++) {
		cin >> temp;
		for (int j = 0; j < temp.size(); j++) {   // index 는 1,1부터
			base[i][j+1] = temp[j]-'0';    
		}
	}

		/*
			벽을 길로 바꾼다. 
			 경로를 탐색한다.
			돌려놓는다.
		*/
	q.push({1,1,0 });
	check[1][1][0] = 1;   // step & wall
	while (!q.empty()) {
		xyz now = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			xyz next = { now.x + dx[i], now.y + dy[i], now.z };
			if (next.x < 1 || N < next.x) continue;			// x 조건
			if (next.y < 1 || M < next.y) continue;	    // y 조건
			//if (check[next.first][next.second].first == 0 ) continue;     // 중복 방지
			
			if (base[next.x][next.y] == 1) {	
				/*  벽 이면 
					벽을 뚫었었는가
					처음 뚫는것인가 구별필요.
				*/
				if (next.z == 1) continue;
				check[next.x][next.y][1] = check[now.x][now.y][0] + 1;
				q.push({ next.x, next.y, 1 });
			}
			else if(base[next.x][next.y] == 0){
				if (check[next.x][next.y][next.z] != 0) continue;
				check[next.x][next.y][next.z] = check[now.x][now.y][next.z] + 1;
				q.push({ next.x, next.y, next.z });
			}
		}
	}
	
	if (check[N][M][0] == 0 && check[N][M][1] == 0) cout << "-1";
	else {
		if (check[N][M][0] == 0) cout << check[N][M][1];
		else if (check[N][M][1] == 0) cout << check[N][M][0];
		else cout << (check[N][M][0] < check[N][M][1] ? check[N][M][0] : check[N][M][1]);
	}
}


/*
	https://kswims.tistory.com/52

*/