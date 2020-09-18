/*
	�ִ� ��� & ����ġ�� 10������ �ڿ��� 
	=> Dijkstra

	���� ���� �ٸ� �� ���� ���̿� ���� ���� ������ ���� �� �� ����.
	���� �׷���








	a ������ ��忡 ���ؼ� �ٲ� ���̶�� ������ a���� ū ���� ������ ������ �ּڰ��� �� �� ����. 
	Visit �ʿ�X
	?????????????????????
	http://www.secmem.org/blog/2019/01/09/wrong-dijkstra/  
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define INF 2147483647
struct edge {
	int dest;
	int weight;
};
struct cmp {
	bool operator()(const std::pair<int, int>& a, const std::pair<int, int>& b) {
		return a.second > b.second;
	}
};
int V, E, start, u, v, w;
std::vector <std::vector<edge> > nodes;
std::vector <int> path;
std::priority_queue < std::pair<int, int>, std::vector<std::pair<int, int>>, cmp> pq;
void input() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin >> V >> E >> start;
	nodes.resize(V + 1);
	
	for (int i = 0; i < E; i++) {
		std::cin >> u >> v >> w;
		nodes[u].push_back({ v,w });
	}
}
void output() {
	for (int i = 1; i < path.size(); i++) {
		if (path[i] == INF) std::cout << "INF\n";
		else std::cout << path[i] << '\n';
	}
}

void dijkstra() {
	
	pq.push({ start, path[start] });
	while (!pq.empty()) {
		int shortNode = pq.top().first;
		int shortWeight = pq.top().second;
		pq.pop();

		for (auto& node : nodes[shortNode]) {
			if (node.weight + path[shortNode] < path[node.dest]) {
				path[node.dest] = node.weight + path[shortNode];
				pq.push({ node.dest, path[node.dest] });
			}
		}
	}
	
}

void pathManager() {
	path.assign(V + 1, INF);
	path[start] = 0;
}

int main() {
	input();
	pathManager();
	dijkstra();
	output();
}