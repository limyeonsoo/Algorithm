//#include <iostream>
//#include <vector>
//#define uint unsigned int
//using namespace std;
//int N, answer = 2147483647;
//vector <vector<int> > node;
//void input() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cin >> N;
//	node.resize(N); for (int i = 0; i < N; i++) node[i].resize(N);
//	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) cin >> node[i][j];
//}
//
//void round(int pre, int now, int pay, uint visit) {
//	pay += node[pre][now];
//	if (visit == (1 << N)-1) {
//		if (node[now][0] == 0) return;
//		answer = (answer > pay + node[now][0] ? pay + node[now][0] : answer);
//		return;
//	}
//	for (int next = 0; next < N; next++) {
//		if (visit & (1 << next)) continue;
//		if (node[now][next] == 0) continue;
//		round(now, next, pay, visit | (1 << next));
//	}
//}
//
//int main() {
//	input();
//	round(0, 0, 0, (1<<0));
//	cout << answer;
//}

//#include <iostream>
//#include <vector>
//#include <cstring>
//#include <algorithm>
//#define INF 2137483647
//#define uint unsigned int
//using namespace std;
//int N, answer = INF;
//int node[16][16];
//int cost[16][1 << 16];
//
//void input() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cin >> N;
//	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) cin >> node[i][j];
//	memset(cost, -1, sizeof(cost));
//}
//int route(int now, uint visit) {
//	if (visit == (1<<N)-1) {
//		return (node[now][0] == 0 ? INF : node[now][0]);
//	}
//	if (cost[now][visit] != -1) return cost[now][visit];
//	cost[now][visit] = INF;
//	for (int i = 1; i < N; i++) {
//		if (visit & (1 << i)) continue;
//		if (node[now][i] == 0) continue;
//		cost[now][visit] = min(cost[now][visit], node[now][i] + route(i, visit | (1 << i)));
//	}
//	return cost[now][visit];
//}
//int main() {
//	input();
//	cout << route(0, (1 << 0));
//}



#include <iostream>
#include <iomanip>
#include <cstring>
#include <cmath>
#include <algorithm>
#define INF 987654321
#define uint unsigned int
using namespace std;
int N;
double cost[16][1 << 16];
double node[16][16];
pair<int, int> coord[16];
void input() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> coord[i].first >> coord[i].second;
	
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			node[i][j] = sqrt(pow(abs(coord[i].first - coord[j].first), 2) + pow(abs(coord[i].second - coord[j].second), 2));
		
	for (int i = 0; i < N; i++)
		for (int j = 0; j < (1 << N); j++)
			cost[i][j] = -1.0;
}

double route(int now, uint visit) {
	if (visit == (1 << N) - 1) {
		return (node[now][0] == 0 ? INF : node[now][0]);
	}
	if (cost[now][visit] != -1.0) return cost[now][visit];
	cost[now][visit] = INF;
	for (int i = 0; i < N; i++) {
		if (visit & (1 << i)) continue;
		if (node[now][i] == 0) continue;
		cost[now][visit] = min(cost[now][visit], node[now][i] + route(i, visit | (1 << i)));
	}
	return cost[now][visit];
}

int main() {
	input();
	cout << fixed << setprecision(8) << route(0, (1 << 0));
}