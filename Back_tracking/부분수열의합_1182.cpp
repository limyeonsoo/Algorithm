#include <iostream>
#include <vector>
#include <set>
using namespace std;
vector <int> v;
vector <bool> check;
set <unsigned int> answer;
int N, S;
void dfs(int now, int depth, int sum) {
	if (sum == S) {
		unsigned int ans = 0;
		for (int i = 0; i < N; i++) if (check[i]) ans |= (1 << i);
		answer.insert(ans);	
	}
	for (int i = now; i < N; i++) {
		if (check[i]) continue;
		check[i] = true;
		dfs(i, depth + 1, sum + v[i]);
		check[i] = false;
	}
}
int main() {
	cin >> N >> S;
	v.resize(N); check.resize(N);
	for (int i = 0; i < N; i++) cin >> v[i];
	for (int i = 0; i < v.size(); i++) {
		check[i] = true;
		dfs(i, 0, v[i]);
		check[i] = false;
	}
	cout << answer.size();
}