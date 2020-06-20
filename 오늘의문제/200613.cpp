//#include <iostream>
//#include <algorithm>
//#include <vector>
//#include <queue>
//#include <stack>
//using namespace std;
//
//int N, M, S, sp, temp, result;
//unsigned int true_people;
//unsigned int false_people;
//vector <vector<int> > party;
//bool check[51];
//
//
//
//
//int true_false(int i) {
//	int t = 0, f = 0;
//	for (auto &k : party[i]) {
//		if (true_people & (1 << k)) { // 진실을 아는 자가 있다.
//			t++;
//		}
//		else if (false_people & (1 << k)) {
//			f++;
//		}
//		else if (true_people & (1 << k) && false_people & (1 << k)) {
//			return -1;
//		}
//	}
//	if (t == 0) {
//		for (auto k : party[i]) {
//			false_people = false_people | (1 << k);
//		}
//		return 0; //거짓말 가능
//	}
//	else if (f == 0) {
//		for (auto k : party[i]) {
//			true_people = true_people | (1 << k);
//		}
//		return 1; //진실
//	}
//	else return -1;
//}
//
//void finalizing(int checking, int i) {
//	if (checking == 0) {  // 거짓말을 했었다.
//		for (auto k : party[i]) {
//			false_people &= ~(1 << k);
//		}
//	}
//	else if (checking == 1) {  //진실
//		for (auto k : party[i]) {
//			true_people &=  ~(1 << k);
//		}
//	}
//}
//
//void dfs(int now, int depth, int cnt) {
//	if (depth == M) {
//		if (result < cnt) result = cnt;
//		return;
//	}
//	
//	for (int i = 1; i < M; i++) {
//		if (check[i])continue;
//		int checking = 0;
//		
//		check[i] = true;
//		checking = true_false(i);
//		if (checking == 1) {
//			dfs(i, 1, cnt);
//		}
//		else if (checking == 0) {
//			dfs(i, 1, cnt+1);
//		}
//		finalizing(checking, i);
//		check[i] = false;
//	}
//}
//
//
//
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cin >> N >> M >> S;
//	for (int i = 0; i < S; i++) {
//		cin >> sp;
//		true_people = true_people | (1 << sp);
//	}
//
//	/*for (int i = 50; i > 0; i--) {
//		printf("%d", (secret & (1 << i - 1)) ? 1 : 0);
//	}*/
//	party.resize(M+1);
//	for (int i = 0; i < M; i++) { //party
//		cin >> temp;
//		for (int j = 0; j < temp; j++) {
//			cin >> sp;
//			party[temp].push_back(sp);
//		}
//	}
//
//	for (int i = 1; i < M; i++) {
//		int checking;
//		check[i] = true;
//		checking = true_false(i);
//		if (checking == 1) {
//			dfs(i, 1, 0);
//		}
//		else if (checking == 0) {
//			dfs(i, 1, 1);
//		}
//		check[i] = false;
//	}
//	cout << result;
//}


/* 지뢰 2232 */
//#include <iostream>
//#include <vector>
//using namespace std;
//int N, temp, base;
//vector <int> v;
//vector <int> result;
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cin >> N;
//
//	v.push_back(0);
//	for (int i = 0; i < N; i++) {
//		cin >> temp;
//		v.push_back(temp);
//	}
//	v.push_back(0);     //v의 size 는  N+2
//
//	for (int i = 1; i < v.size() - 1; i++) {
//		if (v[i] > v[i - 1] && v[i] > v[i + 1]) result.push_back(i);
//		else if (v[i] > v[i - 1] && v[i] == v[i + 1]) result.push_back(i);
//		else if (v[i] == v[i - 1] && v[i] > v[i + 1]) result.push_back(i);
//		else if (v[i] == v[i - 1] && v[i] == v[i + 1]) result.push_back(i);
//	}
//	for (int i = 0; i < result.size(); i++) cout << result[i] << '\n';
//}

///* 1515 수 이어 쓰기*/
//#pragma warning(disable:4996)
//#include <stdio.h>
//#include <vector>
//#define ll long long
//ll temp, cnt;
//int i;
//char N;
//int main() {
//	while (~scanf("%c", &N)) {
//		if (N == '\n') break;
//		if (i > 0) {
//			i--;
//			continue;
//		}
//		while (1) {
//			cnt++;
//			ll tmp = 0;
//			if (cnt < 10) if (cnt == N - '0') break;
//			else if (cnt < 100) {
//				if (cnt % 10 == N - '0') tmp++;
//				if (cnt / 10 == N - '0') tmp++;
//				if (tmp > 0) {
//					i += tmp - 1;
//					break;
//				}
//			}
//			else if (cnt < 1000) {
//				if (cnt % 10 == N - '0')tmp++;
//				if (cnt / 10 == N - '0')tmp++;
//				if (cnt / 10 % 10 == N - '0')tmp++;
//				if (cnt / 10 / 10 == N - '0')tmp++;
//				if (tmp > 0) {
//					i += tmp - 1;
//					break;
//				}
//			}
//			else {
//				if (cnt % 10 == N - '0')tmp++;
//				if (cnt / 10 == N - '0')tmp++;
//				if (cnt / 10 % 10 == N - '0')tmp++;
//				if (cnt / 10 / 10 == N - '0')tmp++;
//				if (cnt / 100 % 10 == N - '0')tmp++;
//				if (cnt / 1000 == N - '0')tmp++;
//				if (tmp > 0) {
//					i += tmp - 1;
//					break;
//				}
//			}
//		}
//	}
//	printf("%d", cnt);
//}

#include <iostream>
#include <cstdio>

using namespace std;
int N, A, B;
int AA[5];
int BB[5];

void input(int A, int CC[]) {
	if (A / 1000 > 0) CC[1] = A / 1000;
	if (A / 100 > 0) CC[2] = A / 100 % 10;
	if (A / 10 > 0) CC[3] = A / 10 % 10;
	CC[4] = A % 10;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cin >> N;
	while(N--){
		memset(AA, 0, sizeof(AA));
		memset(BB, 0, sizeof(BB));
		cin >> A >> B;
		input(A, AA); input(B, BB);

		cout << AA[1] << AA[2] << AA[3] << AA[4];
	}
}