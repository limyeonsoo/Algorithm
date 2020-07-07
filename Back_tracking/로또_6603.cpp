#include <iostream>
#include <vector>

using namespace std;
int N;
vector <int> v;
vector <bool> check;

void dfs(int now, int depth) {
	if (depth == 5) {
		for (int i = 0; i < check.size(); i++) if (check[i] == true) cout << v[i] << ' ';
		cout << '\n';
		return;
	}
	for (int i = now; i < N; i++) {
		if (check[i]) continue;
		check[i] = true;
		dfs(i, depth + 1);
		check[i] = false;
	}
}
int main() {
	while (1) {
		cin >> N;
		if (N == 0)break;
		v.clear(); v.resize(N); check.clear(); check.resize(N);
		for (int i = 0; i < N; i++)	cin >> v[i];
		for (int i = 0; i < N; i++) {
			check[i] = true;
			dfs(i, 0);
			check[i] = false;
		}
		cout << '\n';
	}
}