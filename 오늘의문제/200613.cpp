#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

int N, M, S, sp, temp, result;
unsigned int true_people;
unsigned int false_people;
vector <vector<int> > party;
bool check[51];




int true_false(int i) {
	int t = 0, f = 0;
	for (auto &k : party[i]) {
		if (true_people & (1 << k)) { // 진실을 아는 자가 있다.
			t++;
		}
		else if (false_people & (1 << k)) {
			f++;
		}
		else if (true_people & (1 << k) && false_people & (1 << k)) {
			return -1;
		}
	}
	if (t == 0) {
		for (auto k : party[i]) {
			false_people = false_people | (1 << k);
		}
		return 0; //거짓말 가능
	}
	else if (f == 0) {
		for (auto k : party[i]) {
			true_people = true_people | (1 << k);
		}
		return 1; //진실
	}
	else return -1;
}

void finalizing(int checking, int i) {
	if (checking == 0) {  // 거짓말을 했었다.
		for (auto k : party[i]) {
			false_people &= ~(1 << k);
		}
	}
	else if (checking == 1) {  //진실
		for (auto k : party[i]) {
			true_people &=  ~(1 << k);
		}
	}
}

void dfs(int now, int depth, int cnt) {
	if (depth == M) {
		if (result < cnt) result = cnt;
		return;
	}
	
	for (int i = 1; i < M; i++) {
		if (check[i])continue;
		int checking = 0;
		
		check[i] = true;
		checking = true_false(i);
		if (checking == 1) {
			dfs(i, 1, cnt);
		}
		else if (checking == 0) {
			dfs(i, 1, cnt+1);
		}
		finalizing(checking, i);
		check[i] = false;
	}
}




int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M >> S;
	for (int i = 0; i < S; i++) {
		cin >> sp;
		true_people = true_people | (1 << sp);
	}

	/*for (int i = 50; i > 0; i--) {
		printf("%d", (secret & (1 << i - 1)) ? 1 : 0);
	}*/
	party.resize(M+1);
	for (int i = 0; i < M; i++) { //party
		cin >> temp;
		for (int j = 0; j < temp; j++) {
			cin >> sp;
			party[temp].push_back(sp);
		}
	}

	for (int i = 1; i < M; i++) {
		int checking;
		check[i] = true;
		checking = true_false(i);
		if (checking == 1) {
			dfs(i, 1, 0);
		}
		else if (checking == 0) {
			dfs(i, 1, 1);
		}
		check[i] = false;
	}
	cout << result;
}