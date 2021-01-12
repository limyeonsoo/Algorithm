#include <iostream>
#include <bitset>
#include <string>

using namespace std;
bitset<2000> friends[2001];
int N, Q, A, B;
string buddy;


void input() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> buddy;
		for (int j = i; j <= N; j++) {
			friends[i][j] = buddy[j - 1] - '0';
			friends[j][i] = buddy[j - 1] - '0';
		}
	}
	cin >> Q;
	for (int i = 0; i < Q; i++) {
		cin >> A >> B;
		bitset<2000> answer;
		answer = friends[A] & friends[B];
		cout << answer.count()<<'\n';
	}
}
int main() {
	input();
}