#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#define INF 2147483647
struct info {
	int node;
	int weight;
};
struct cmp {
	bool operator()(const info &a, const info& b) {
		return a.weight > b.weight;
	}
};

int N, M, start, end, weight, startPoint, endPoint;
std::vector <std::vector<info>> nodes;
std::vector <int> path;
std::priority_queue <info, std::vector<info>, cmp> pq;

void input() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin >> N >> M;
	nodes.resize(N + 1);
	for (int i = 0; i < M; i++) {
		std::cin >> start >> end >> weight;
		nodes[start].push_back({ end, weight });
	}
	std::cin >> startPoint >> endPoint;
}
void dijkstra() {
	path.resize(N + 1, INF);
	path[startPoint] = 0;
	pq.push({ startPoint, path[startPoint] });
	while (!pq.empty()) {
		int nowNode = pq.top().node;
		int nowCost = pq.top().weight;
		pq.pop();
		for (auto& node : nodes[nowNode]) {
			if (node.weight + path[nowNode] < path[node.node]) {
				path[node.node] = node.weight + path[nowNode];
				pq.push({ node.node, path[node.node] });
			}
		}
	}
}
int main() {
	input();
	dijkstra();
	std::cout << path[endPoint];
}