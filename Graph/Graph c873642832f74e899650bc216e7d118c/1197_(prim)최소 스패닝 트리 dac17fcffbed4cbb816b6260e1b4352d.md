# 1197_(prim)최소 스패닝 트리

#MST #MinimumSpanningTree #Kruskal #Prim #Graph

[Minimum Spanning Tree](Minimum%20Spanning%20Tree%2040232e1de14d4c209b68805c2c0ca68b.md)

# Prime Algorithm

## Pre

/*
    prim algorithm 사용
    각 vertex에 있는 edge를 다 넣는다.
    edge별로 weight가 가장 낮은 것으로 구성하여 vertex추가.
*/

## Code

```cpp
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
```

## Fail

- 

```cpp
시간 초과 :
for(int i=1; i<=V; i++) sort(vertex[i].begin(), vertex[i].end(), cmp);
  // pair.second 기준 오름차순 정렬.
	 sorting을 했어도, Edge 수가 많으면
	 Edge 탐색이 오래 걸릴 수 있음.
https://www.acmicpc.net/source/21717606

런타임에러 :
priority queue  pop 하기 전 방문 여부를 확인 할 때, 런타임 에러

while (check[pq.top().first]) 
	pq.pop();
now = pq.top().first;
result += pq.top().second;
pq.pop();
check[now] = true;
edge_cnt++;
```

## Post

### 해결방법

- Priority_queue를 이용.
- queue가 비었을 때 접근 하지 않는다.

```cpp
while (!pq.empty()) {
         pair<int, int> next = pq.top();
         pq.pop();
         if (!check[next.first]) {
            now = next.first;
            result += next.second;
            check[now] = true;
            edge_cnt++;
            break;
         }
      }
```

## Reference

[https://www.acmicpc.net/board/view/53983](https://www.acmicpc.net/board/view/53983)  // 처음부터 비슷

- [ ]  [https://debuglog.tistory.com/89](https://debuglog.tistory.com/89)  // Priorityqueue를 사용하지 않음