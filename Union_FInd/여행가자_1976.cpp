#include <iostream>

using namespace std;
int N, M, A, B, tmp;
int parents[201];

int Find(int x) {
	if (x == parents[x]) return x;
	return parents[x] = Find(parents[x]);
}

void Union(int x, int y) {
	x = Find(x); y = Find(y);
	if (x != y) parents[y] = x;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	for (int i = 0; i < 201; i++) parents[i] = i;
	cin >> N >> M;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> B;
			if (j <= i) continue;
			if (B == 1)Union(i + 1, j + 1);  //index°¡ 1ºÎÅÍ
		}
	}
	for (int i = 0; i < M; i++) {
		cin >> A;
		if (B != Find(A) && i>0) {
			tmp += 1;
		}
		B = Find(A);
	}
	cout << (tmp==0?"YES":"NO");
}