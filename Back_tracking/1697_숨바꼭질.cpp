#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define MAX 100000

using namespace std;
int N, K, step;
bool check[100001];
queue <pair<int, int> > q;  //1st : loc // 2nd : step
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> K;
	q.push({ N,step });
	while (~q.empty()) {
		pair<int, int> now = q.front(); q.pop();
		if (now.first == K) {
			cout << now.second;
			break;
		}
		if (0 <= now.first - 1 && now.first - 1 <= MAX) {
			if (!check[now.first - 1]) {
				q.push({ now.first - 1, now.second + 1 });
				check[now.first - 1] = true;
			}
		}
		if (0 <= now.first + 1 && now.first + 1<= MAX) {
			if (!check[now.first + 1]) {
				q.push({ now.first + 1, now.second + 1 });
				check[now.first + 1] = true;
			}
		}
		if (0 <= now.first * 2 && now.first * 2 <= MAX) {
			if (!check[now.first * 2]) {
				q.push({ now.first * 2, now.second + 1 });
				check[now.first * 2] = true;
			}
		}
	}
}