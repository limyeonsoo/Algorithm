#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

typedef struct {
	int pop;
	vector <int> near;
}area;

unsigned int bitmasking = 0; // 구역이 10개니 bitmask
int N, s, temp, total_pop, mini = 100000000;
vector <area> a;

queue <int> q;

pair<bool, int> checkCycle(int depth, unsigned int check_node) { 
	for (int i = 1; i <= N; i++) { //시작점
		int sum = 0, cnt = 0;
		unsigned int check = 0;
		if (check_node & (1 << i)) {  // 등록된 지역
			q.push(i);
			while (!q.empty()) {
				int now = q.front(); q.pop();
				for (int& next : a[now].near) {
					if (check & (1 << next)) continue;
					if (check_node & (1 << next)) { // 등록된 지역일 때만
						q.push(next);
						check |= (1 << next);
						sum += a[next].pop;
						cnt++;
					}
				}
			}
			// 등록된 지역을 다 돌았을 때,
			if (cnt == depth) { // 다 돌았으면 만족,
				return make_pair(true, sum);
			}
			else {
				return make_pair(false, 0);
			}
		}
	}
	return make_pair(false, 0);
}


void dfs(int now, int depth, int blue_sum, unsigned int check_blue) {  //파란팀을 check_blue == -1 로 정한다.
	// 이때, blue 지역은 check_blue; depth만큼의 수
	// 그러면 red 지역은 check_red = check_blue 의 반대
	int diff = abs(blue_sum - (total_pop - blue_sum));
	if (mini > diff) { // 최소 차이가 작으면 사이클을 확인한다.
		
		pair<bool, int> red, blue;
		unsigned int check_red = 0;
		for (int i = 1; i <= N; i++)
			check_red = ((check_blue & (1 << i) ? check_red : check_red | (1 << i)));
		red = checkCycle(N - depth, check_red);
		//blue 는 check 필요 X => 연결 되는 곳만 왔기 때문.
		
		if (red.first) { //red가 cycle을 만족하면
		//blue의 sum을 구한다.  red sum은 red.second
		// blue sum은 total_sum - red.second;
			mini = abs(red.second - (total_pop - red.second));
		}
	}
	

	for (int i = 1; i <= N; i++) {
		if (check_blue & (1 << i)) continue;  //이미 방문 했으면 X
		bool connection = false;
		for (int pre = 1; pre <= N; pre++) {
			if (!(check_blue & (1 << pre))) continue;
			// ** 중요 : now에서는 못가지만, team 전체에서 봤을 때는 갈 수 있다. ** //
			if (a[pre].near.end() != find(a[pre].near.begin(), a[pre].near.end(), i)) {
				connection = true;
				break;  
			}
		}
		if (connection) {
			check_blue |= (1 << i);
			dfs(i, depth + 1, blue_sum+a[i].pop, check_blue);
			check_blue &= ~(1 << i);
		}
	}
}

void input() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	a.resize(N + 1);  // index를 1부터

	for (int i = 1; i <= N; i++) {	
		cin >> a[i].pop;        // 각 지역 인구수
		total_pop += a[i].pop;  // 총 인구수 합
	}

	for (int i = 1; i <= N; i++) {
		cin >> s;
		for (int j = 0; j < s; j++) {
			cin >> temp;
			a[i].near.push_back(temp); // 인접 노드 입력  //양방향
		}
	}
}

int main() {
	input();  // 지역 인구, 지역별 이웃 지역을 담은 배열 a생성

	if (N == 2) {  // 지역이 2개면 바로 해결 가능.
		cout << abs(a[1].pop - a[2].pop);
		return 0;
	}

	for (int i = 1; i <= N; i++) { // 시작점은 각 지역별
		bitmasking |= (1 << i);    // i 진입 체크 후
		dfs(i, 1, a[i].pop, bitmasking);
		bitmasking = 0;            // 리셋
	}

	cout << (mini == 100000000 ? -1 : mini);
}


/*
틀린 케이스 : 
8
17 42 46 81 71 8 37 12
4 2 4 5 7
5 1 3 4 5 8
2 2 4
5 1 2 3 7 8
5 1 2 6 7 8
2 5 8
4 1 4 5 8
5 2 4 5 6 7
ans : 2  but : 4

reason : 1 3 4 8 vs 1 4 5 6 // 156 vs 158
 일직선으로 밖에 뻗지 못했음.

*/

/* 
틀린 케이스 : 
2
3 4 
0
0
ans : 1  but : -1

reason : 차이를 구하는 것인데, 
  near이 0이라 연결을 하지 못해 dfs를 들어가지 못해 -1을 반환.

*/

/*
시간 초과 : 
  사이클을 확인 후 -> 최소값을 구했다.
  최소값을 만족하면 => 사이클을 확인한다.
*/