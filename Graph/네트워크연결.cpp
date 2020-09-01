/*
	��Ʈ��ũ�� ���� �Ǵµ� �ʿ��� �ּҺ��
	=> �ּ� ���д� Ʈ��

	kruskal �̿�

	edge set�� non-decresing���� sorting

*/

#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <algorithm>
using namespace std;
struct edgeSet {
	int weight;
	int start;
	int end;
};
int N, M, a, b, c, result;
vector <int> tree;
vector <edgeSet > com;

int Find(int x) {
	if (x == tree[x]) return x;
	return x = Find(tree[x]);
}
void Union(int x, int y) {
	if (Find(x) != Find(y)) tree[Find(y)] = Find(x);
}


void input() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M;

	tree.resize(N + 1); for (int i = 1; i <= N; i++) tree[i] = i;
	
	for (int i = 0; i < M; i++) {
		cin >> a >> b >> c;
		com.push_back({ c, a, b });
	}
}
bool cmp(const edgeSet& a, const edgeSet& b) {
	return a.weight < b.weight;
}
void solve() {
	sort(com.begin(), com.end(), cmp);

	for (int i = 0; i < com.size(); i++) {
		if (Find(com[i].start) != Find(com[i].end)) {
			result += com[i].weight;
			Union(com[i].start, com[i].end);
		}
	}
	cout << result;
}
int main() {
	input();
	solve();
}

/*
	Union Find �� �߸� «

*/