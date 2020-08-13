/*
	위상정렬을 이용
	* 단방향이여야함.
	* 오른쪽으로 뻗어가는 트리가 되야함.
	
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N, M, A, B;
vector <vector <int> > students;
vector <int> lines;
queue <int> q;
void input() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M;
	students.resize(N + 1);
	lines.resize(N + 1);
	for (int i = 1; i <= M; i++) {
		cin >> A >> B;
		students[A].push_back(B);
		lines[B]++;                 // 앞에 서는 노드 체크
	}
}
void topologicalSort() {
	for (int i = 1; i <= N; i++)    // base
		if (lines[i] == 0)		    // 들어오는 간선이 없는 노드
			q.push(i);         
	while (!q.empty()) {
		int now = q.front(); q.pop();
		cout << now << ' ';
		for (auto& next : students[now]) {
			lines[next]--;
			if (lines[next] == 0)
				q.push(next);
		}

	}
}
int main() {
	input();
	topologicalSort();
}



/*
	다른 root도 모두 기다려야함.
	ex) 
	          -> 6
	   ->  2  -> 7 -> 8
	1  
	   ->  3  -> 9 -> 7
	
	   ->  4  
	   일 때, 3->9->7 에 3번 돌때까지 7의 향방을 알 수 없음.
	   앞 연결이 없을 때까지 lines --;

*/