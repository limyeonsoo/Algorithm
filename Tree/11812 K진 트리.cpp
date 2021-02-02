#include <iostream>
#define ll long long
using namespace std;
ll N, a, b;
int K, Q;
void input() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> K >> Q;
	for (int i = 0; i < Q; i++) {
		cin >> a >> b;
		if (K == 1) cout << abs(a - b) << '\n';
		else {
			int len = 0;
			while (a != b) {
				while (a > b) {
					len++;
					a = (a + K - 2) / K;
				}
				while (a < b) {
					len++;
					b = (b + K - 2) / K;
				}
			}
			cout << len << '\n';
		}
	}
}
int main() {
	input();
}