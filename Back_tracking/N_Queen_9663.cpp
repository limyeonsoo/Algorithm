/*#include <iostream>
using namespace std;
bool row[31], d1[31], d2[31];
int N, cnt;
void dfs(int c) {
	if (c == N+1) {
		cnt++;
		return;
	}
	for (int i = 1; i <= N; i++) {
		if (row[i] || d1[i - c + N - 1] || d2[i + c]) continue;
		d1[i - c + N - 1] = d2[i + c] = row[i] = true;
		dfs(c + 1);
		d1[i - c + N - 1] = d2[i + c] = row[i] = false;
	}
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	dfs(1);
	cout << cnt;
}                      */

#include <iostream>
using namespace std;
int row[31], d1[31], d2[31];
int N, cnt;
void dfs(int c) {
	if (c == N + 1) {
		cnt++;
		return;
	}
	for (int i = 1; i <= N; i++) {
		if (row[i] || d1[i - c + N - 1] || d2[i + c]) continue;
		d1[i - c + N - 1] = d2[i + c] = row[i] = 1;
		dfs(c + 1);
		d1[i - c + N - 1] = d2[i + c] = row[i] = 0;
	}
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	dfs(1);
	cout << cnt;
}