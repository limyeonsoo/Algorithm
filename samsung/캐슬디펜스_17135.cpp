#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int dx[4] = {-1, 0, 1 };
int dy[4] = {0, -1, 0 };
int N,M,D,cnt;

int bottom[16][16];
queue <pair<int, int> > q;
vector <int> idx;
vector <int> n;
vector <int> archer;
int main() {
	scanf("%d%d%d", &N, &M, &D);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &bottom[i][j]);
		}
	}
	n.resize(M); idx.resize(M);
	for (int i = 0; i < M; i++) {
		n[i] = i;
		i < M-3 ? idx[i] = 0 : idx[i] = 1;
	}

	do {
		for (int i = 0; i < M; i++) if (idx[i] == 1) {
			q.push({ N, n[i] });
			archer.push_back(n[i]);
		}  // 궁수의 위치 구함.
		//Each archer, Search all the time inside his available distance.
		while (!q.empty()) {

		}
		


	} while (next_permutation(idx.begin(), idx.end()));

	//printf("%d", cnt);
}