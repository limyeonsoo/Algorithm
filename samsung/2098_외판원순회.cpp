//#pragma warning(disable:4996)
//#include <iostream>
//#include <cstring>
//
//using namespace std;
//
//int N;
//int node[17][17];
//int path[17];
//bool check[17];
//int minimum = 1e9;
//
//void dfs(int start, int city, int pay, int depth) {
//	if (depth == N) {
//		if (node[city][start] == 0)return;
//		pay += node[city][start];
//		if (minimum > pay) {
//			minimum = pay;
//			for (int i = 0; i < N; i++) {
//				printf("%d ", path[i]);
//			}
//			printf("\n");
//		}
//		return;
//	}
//	
//	for (int i = 0; i < N; i++) {
//		if (check[i] == true) continue;
//		if (node[city][i] == 0) continue;
//		if (pay + node[city][i] > minimum) continue;
//		check[city] = true;
//		path[depth] = i;
//		dfs(start, i, pay + node[city][i], depth+1);
//		check[city] = false;
//		
//	}
//}
//
//int main() {
//	scanf("%d", &N);
//	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) scanf("%d", &node[i][j]); // 도시 입력
//	check[0] = true;
//	path[0] = 0;
//	dfs(0, 0, 0, 1);
//	printf("%d", minimum);
//}

//#include <iostream>
//#include <string>
//#include <algorithm>
//#include <vector>
//using namespace std;
//string s;
//vector <char> v;
//int main() {
//	cin >> s;
//	for (int i = 0; i < s.size(); i++) {
//		v.push_back(s[i]);
//	}
//	sort(v.begin(), v.end());
//	for (int i = 0; i < v.size(); i++) {
//		cout << v[i];
//	}
//}

#pragma warning(disable:4996)
#include <iostream>
#include <vector>
#define ll long long
using namespace std;
ll temp;

char N;
vector <ll> v;
int main() {
	/*cin >> N;
	temp = N;
	while (temp > 0) {
		v.insert(v.begin(),(temp % 10));
		temp /= 10;
	}*/
	ll cnt = 0;
	int i = 0;
	while (~scanf("%c", &N)) {
		if (i > 0) {
			i--;
			continue;
		}
		while (1) {
			cnt++;
			ll tmp = 0;
			if (cnt < 10) {
				if (cnt == N-'0') {
					break;
				}
			}
			else if (cnt < 100) {
				//if (cnt % 10 == v[i] || cnt / 10 == v[i]) break;
				if (cnt % 10 == N - '0') tmp++;
				if (cnt / 10 == N - '0') tmp++;
				if (tmp > 0) {
					i += tmp - 1;
					break;
				}
			}
			else if (cnt < 1000) {
				/*if (cnt % 10 == v[i] || cnt / 10 == v[i]) {
					break;
				}
				else if (cnt / 10 % 10 == v[i] || cnt / 100 == v[i]) {
					break;
				}*/
				if (cnt % 10 == N - '0')tmp++;
				if (cnt / 10 == N - '0')tmp++;
				if (cnt / 10 % 10 == N - '0')tmp++;
				if (cnt / 10 / 10 == N - '0')tmp++;
				if (tmp > 0) {
					i += tmp - 1;
					break;
				}
			}
			else {
				/*if (cnt % 10 == v[i] || cnt / 10 == v[i]) {
					break;
				}
				else if (cnt / 10 % 10 == v[i] || cnt / 10 / 10 == v[i]) {
					break;
				}
				else if (cnt / 100 % 10 == v[i] || cnt / 1000) {
					break;
				}*/
				if (cnt % 10 == N - '0')tmp++;
				if (cnt / 10 == N - '0')tmp++;
				if (cnt / 10 % 10 == N - '0')tmp++;
				if (cnt / 10 / 10 == N - '0')tmp++;
				if (cnt / 100 % 10 == N - '0')tmp++;
				if (cnt / 1000 == N - '0')tmp++;
				if (tmp > 0) {
					i += tmp - 1;
					break;
				}
			}
		}
		//cout << cnt << '\n';
	}
	cout << cnt;
}