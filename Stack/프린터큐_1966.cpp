//#include <iostream>
//#include <vector>
//#include <queue>
//#include <algorithm>
//
//using namespace std;
//deque <pair<int, int>> q;
//vector <int> weight;
//int T, N, idx, M, temp;
//pair<int, int> p_temp;
//int main() {
//	cin >> T;
//	while (T--) {
//		int cnt = 1; pair<int, int> p_temp;
//		q.clear();
//		cin >> N >> idx;
//		for (int i = 0; i < N; i++) {
//			cin >> temp;
//			q.push_back({ temp, i});
//		}
//
//		while (!q.empty()) {
//			if (q.front().first != (max_element(q.begin(), q.end())->first)) {
//				p_temp = q.front();
//				q.pop_front();
//				q.push_back(p_temp);
//			}
//			else {  //Å« ¼ö¸é
//				if (q.front().second == idx) {
//					cout << cnt<<'\n';
//				}
//				q.pop_front();
//				cnt++;
//			}
//		}
//	}
//}