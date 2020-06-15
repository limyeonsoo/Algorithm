#include <iostream>

using namespace std;
int N, M, Q, A, B;
int sets[1000001];


int Find(int x) {
	if (sets[x] == x) return x;
	return sets[x] = Find(sets[x]);
}

void Union(int x, int y) {
	x = Find(x); y = Find(y);
	if(x!=y) sets[y] = x;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i <= N; i++) {
		sets[i] = i;
	}
	for (int i = 0; i < M; i++) {
		cin >> Q >> A >> B;
		if (Q == 0) {
			Union(A, B);


		}
		else if (Q == 1) {
			if (A == B) {
				cout << "YES" << '\n';
			}
			else {
				cout << (Find(A) == Find(B) ? "YES" : "NO") << '\n';
			}
		}
	}
}