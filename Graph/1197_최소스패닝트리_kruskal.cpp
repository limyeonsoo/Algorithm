/*
	kruskal algorithm 사용
	1. 초기화시 vertex로만 그래프를 구성한다.
	2. Edge set을 non-decreasing으로 sorting한다.
	3. weight가 제일 작은 edge부터 검토한다.
	4. Cycle이 생기지 않는 경우에만 edge를 추가한다.
	5.  모든 vertex가 연결되면 종료된다.
	6.  모든 edge에 대한 판단이 이루어졌다면 완성될 수 없다.
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int V, E, A, B, C;
struct info {
	int start, dest, weight;
};
vector <info> edges;
int parents[10001];

bool cmp(const info &a, const info &b) {
	return a.weight < b.weight;
}
int Find(int x) {
	if (x == parents[x]) return x;
	return x = Find(parents[x]);
}
int Union(int x, int y) {
	x = Find(x); y = Find(y);
	if (x == y) return 0;
	if (x != y) parents[y] = x;
	return 1;
}
int kruskal() {
	int result = 0;
	sort(edges.begin(), edges.end(), cmp);
	for (int i = 1; i <= V; i++) parents[i] = i;
	for (auto &edge : edges)
		if (Union(edge.start, edge.dest))
			result += edge.weight;
	return result;
}
void input() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> V >> E;
	for (int i = 0; i < E; i++) { 
		cin >> A >> B >> C;      
		edges.push_back({ A, B, C });
	}
}
int main() {
	input();
	cout << kruskal();
}
/*
	스패닝 트리가 되기 위해서는 start, dest 둘 중 하나는 parent가 다르다.
*/