/*
	�༺�� ���� N �� 1~100,000
	�� Vertex N  Edge N-1 �� ���д� Ʈ�� ����.
	N^2      X
	N log N  o
	��ǥ�� int �ڷ��� ��,  -10^9 - 10^9 < 2147483647

	#�켱���� ť #Union-Find  #MST  #Kruskal
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

struct coord {
	int idx, x, y, z;
};
struct info {
	int weight, start, end;
};
struct cmp {
	bool operator()(const info& a, const info& b) {
		return a.weight > b.weight;
	}
};
priority_queue <info, vector<info>, cmp> pq;
vector <coord> planets;
int N, result;
int parents[100001];

bool cmpX(const coord& a, const coord& b) {return a.x < b.x;}
bool cmpY(const coord& a, const coord& b) {return a.y < b.y;}
bool cmpZ(const coord& a, const coord& b) {return a.z < b.z;}

int Find(int x) {
	if (parents[x] == x) return x;
	return parents[x] = Find(parents[x]);
}
bool Union(int x, int y) {
	x = Find(x); y = Find(y);
	if (x == y) return false;
	parents[y] = x;
	return true;
}

void input() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N; planets.resize(N + 1);
	for (int i = 1; i <= N; i++) {
		cin >> planets[i].x >> planets[i].y >> planets[i].z;
		planets[i].idx = i;
	}
}
int kruskal() {
	for (int i = 1; i <= N; i++) parents[i] = i;				// union find parents initializing
	sort(planets.begin() + 1, planets.end(), cmpX);				//* index�� 1���� �̹Ƿ� begin()+1
	for (int i = 1; i < N; i++) {   // index 1~ ������ ��
		pq.push({ abs(planets[i].x - planets[i + 1].x), planets[i].idx, planets[i + 1].idx });
		//cout << abs(planets[i].x - planets[i + 1].x) << ',' << planets[i].idx << "->" << planets[i + 1].idx<<'\n';
	}
	sort(planets.begin() + 1, planets.end(), cmpY);
	for (int i = 1; i < N; i++) {
		pq.push({ abs(planets[i].y - planets[i + 1].y), planets[i].idx, planets[i + 1].idx });
		//cout << abs(planets[i].y - planets[i + 1].y) << ',' << planets[i].idx << "->" << planets[i + 1].idx << '\n';
	}
	sort(planets.begin() + 1, planets.end(), cmpZ);
	for (int i = 1; i < N; i++) {
		pq.push({ abs(planets[i].z - planets[i + 1].z), planets[i].idx, planets[i + 1].idx });
		//cout << abs(planets[i].z - planets[i + 1].z) << ',' << planets[i].idx << "->" << planets[i + 1].idx << '\n';
	}
	while (!pq.empty()) {
		info now = pq.top(); pq.pop();
		if (Union(now.start, now.end)) //spanning tree
			result += now.weight;
	}
	return result;
}
int main() {
	input();
	cout << kruskal();
}
/*
	Union-Find �ʱ�ȭ �� ����.
	Priority-queue�� ���� ���� : x,y,z�� ��� ��ǥ�� �ּ����� ��.
*/