/*
      /    이런 경우   -1로 처리해주면 안됨.
	 /
	/


	0 3
	3 4 5
	3
	3
*/
#include <iostream>
#include <vector>
#define INF 2147483647

using namespace std;
vector <vector<int>> base;
vector <vector<int>> base2;
vector <vector<int>> visit;
int N, L, result;
void input() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> L;
	base.resize(N); base2.resize(N); visit.resize(N);
	for (int i = 0; i < N; i++) base[i].resize(N), base2[i].resize(N), visit[i].resize(N);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> base[i][j];
}

void check() {
	for (int i = 0; i < N; i++) {
		bool success = true;
		for (int j = 1; j < N; j++) {
			if (!success) break;
			int now = base[i][j - 1];
			int next = base[i][j];
			if (now == next) continue;
			else {
				// 오른쪽이 크면
				bool flatten = true;
				if (now == next - 1) {
					for (int pre = j - 1; pre > j - 1 - L; pre--) {
						if (pre < 0) {
							flatten = false;
							break;
						}
						if (base[i][pre] != base[i][j-1] || visit[i][pre] == -INF) {
							flatten = false;
							break;
						}
					}
					//경사를 쌓자
					if (flatten) {
						for (int pre = j-1; pre > j-1-L; pre--)
							visit[i][pre] = INF;

					}
				}// 왼쪽이 크면
				else if (now - 1 == next) {
					for (int post = j; post < j + L; post++) {
						if (post >= N) {
							flatten = false;
							break;
						}
						if (base[i][post] != base[i][j] || visit[i][post] == INF) {
							flatten = false;
							break;
						}
					}
					//경사를 쌓자
					if (flatten) {
						for (int post = j; post < j + L; post++)
							visit[i][post] = -INF;
					}
				}
				else flatten = false;
				success = (flatten == false ? false : true);
			}
		}
		/*if (success) {
			cout << i << '\n';
		}*/
		result += (success == true ? 1 : 0);
	}
}
void rocation() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			base2[i][j] = base[N-1-j][i];
		}
	}
}
void copyBase() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			visit[i][j] = 0;
			base[i][j] = base2[i][j];
		}
	}
}
int main() {
	input();
	
	rocation();
	
	check();
	copyBase();
	
	check();
	cout << result;
}