//#include <iostream>
//#include <map>
//#include <string>
//using namespace std;
//
//map <string, int> m;
//int T, N;
//int parents[200002];
//string temp1, temp2;
//
//int Find(int x) {
//	if (parents[x] < 0)return x;
//	return parents[x] = Find(parents[x]); 
//}
//
//void Union(int x, int y) {
//	int root_x, root_y;
//	root_x = Find(x); root_y = Find(y);  // root³ëµåµµ ¹Ù²ãÁü.
//	if (root_x != root_y) {
//		parents[root_x] += parents[root_y];
//		parents[y] = x;
//	}
//}
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cin >> T;
//	while (T--) {
//		cin >> N; m.clear();
//		for (int i = 0; i <= N * 2; i++) parents[i] = -1;
//		int cnt = 1;
//		for (int i = 1; i <= N; i++) {
//			cin >> temp1 >> temp2;
//			if (m.find(temp1) == m.end()) m[temp1] = cnt++; // mapping 
//			if (m.find(temp2) == m.end()) m[temp2] = cnt++;  // mapping
//			Union(m[temp1], m[temp2]);
//			cout << parents[1] * (-1) << '\n';
//		}
//	}
//}

