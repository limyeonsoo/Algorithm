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
	���д� Ʈ���� �Ǳ� ���ؼ��� start, dest �� �� �ϳ��� parent�� �ٸ���.
*/