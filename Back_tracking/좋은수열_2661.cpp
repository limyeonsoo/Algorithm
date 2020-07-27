#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int N;
string ott = "123";

void dfs(string S) {
	//for (int i = 0; i < S.size()-1; i++) { //start
	//	for (int j = 1; j <= (S.size() / 2 - i); j++) { //length
	//		if (S.substr(i, j) == S.substr(j + i, j)) {
	//			S.pop_back();
	//			return;
	//		}
	//	}
	//}
	for (int i = 1; i <= S.size() / 2; i++) {  //길이
		for (int j = 0; j <= S.size() - i * 2; j++) {  //시작점
			if (S.substr(j, i) == S.substr(j + i, i)) {
				S.pop_back(); return;
			}
		}
	}
	if (S.size() == N) {
		cout << S;
		exit(0);
	}
	for (auto& s : ott) {
		if (S.size() > 0 && S[S.size() - 1] == s) continue;
		dfs(S + s);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;	
	dfs("");
}