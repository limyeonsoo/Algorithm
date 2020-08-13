/*
	kruskal algorithm ���
	1. �ʱ�ȭ�� vertex�θ� �׷����� �����Ѵ�.
	2. Edge set�� non-decreasing���� sorting�Ѵ�.
	3. weight�� ���� ���� edge���� �����Ѵ�.
	4. Cycle�� ������ �ʴ� ��쿡�� edge�� �߰��Ѵ�.

	5.  ��� vertex�� ����Ǹ� ����ȴ�.

	6.  ��� edge�� ���� �Ǵ��� �̷�����ٸ� �ϼ��� �� ����.
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
priority_queue <pair<int, int>, vector<pair<int, int> >, cmp> pq;  // pair�� ��� priority queue
vector <vector<pair<int, int> > > vertex;                          // <next vertex, weight>
int V, E, A, B, C;
bool check[10001];
int prim() {
	int now = 1, result = 0, cnt = 0;
	check[now] = true;
	while (cnt < V - 1) {          // ������ ����� �� -1
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
	vertex.resize(V + 1);  // index�� 1����
	for (int i = 0; i < E; i++) { //������ ���� ��ŭ
		cin >> A >> B >> C;       // A -> B  (C��ŭ)
		vertex[A].push_back({ B,C }); // vertex A���� B�� ���� C edge
		vertex[B].push_back({ A,C }); // vertex B���� A�� ���� C edge
	}
}
int main() {
	input();
	cout << prim();
}

/*
	�ð� �ʰ� :
	 sorting�� �߾, Edge ���� ������
	 Edge Ž���� ���� �ɸ� �� ����.
*/

