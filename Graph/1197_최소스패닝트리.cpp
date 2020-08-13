/*
	prim algorithm 사용
	각 vertex에 있는 edge를 다 넣는다.
	edge별로 weight가 가장 낮은 것으로 구성하여 vertex추가.
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct cmp {
	bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
		if (a.second > b.second) return true;
		return false;
	}
};	
priority_queue <pair<int, int>, vector<pair<int, int> >, cmp> pq;  // pair를 담는 priority queue
vector <vector<pair<int, int> > > vertex;                          // <next vertex, weight>
int V, E, A, B, C;
bool check[10001];
int prim() {
	int now = 1, result = 0, cnt = 0;
	check[now] = true;
	while (cnt < V - 1) {          // 간선은 노드의 수 -1
		for (auto& next : vertex[now])
			if (!check[next.first])
				pq.push(next);
		while (!pq.empty()) {
			pair<int, int> next = pq.top();
			pq.pop();
			if (!check[next.first]) {
				now = next.first;
				result += next.second;
				check[now] = true;
				cnt++;
				break;
			}
		}
	}
	return result;
}
void input() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> V >> E;
	vertex.resize(V + 1);  // index를 1부터
	for (int i = 0; i < E; i++) { //간선의 개수 만큼
		cin >> A >> B >> C;       // A -> B  (C만큼)
		vertex[A].push_back({ B,C }); // vertex A에서 B로 가는 C edge
		vertex[B].push_back({ A,C }); // vertex B에서 A로 가는 C edge
	}
}
int main() {
	input();
	cout << prim();
}

/*
	시간 초과 :
	 sorting을 했어도, Edge 수가 많으면
	 Edge 탐색이 오래 걸릴 수 있음.
*/

