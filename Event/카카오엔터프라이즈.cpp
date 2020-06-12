//#include <iostream>
//#include <map>
//#include <string>
//#include <vector>
//#include <algorithm>
//using namespace std;
//typedef struct score {
//	int win;
//	int diff;
//}score;
//map <string, score> m;
//map <string, score>::iterator iter;
//vector <pair<int, string> > v;
//int team, a, b;
//string team_a, team_b;
//bool desc(pair<int, string> a, pair<int,string> b) { 
//	return a.first > b.first;
//}
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	cin >> team;
//	for (int i = 0; i < team * (team - 1); i++) {
//		cin >> team_a >> a >> team_b >> b;
//
//		score curr_a = { a > b ? 1 : 0, a - b };
//		score curr_b = { a < b ? 1 : 0, b - a };
//
//		if (m.count(team_a) == 0) { //team이 없음.
//			m.insert(make_pair(team_a, curr_a));
//		}
//		else {
//			m[team_a].diff += curr_a.diff;
//			m[team_a].win += curr_a.win;
//		}
//		if (m.count(team_b) == 0) { //team이 없음.
//			m.insert(make_pair(team_b, curr_b));
//		}
//		else {
//			m[team_b].diff += curr_b.diff;
//			m[team_b].win += curr_b.win;
//		}
//	}
//	for (iter = m.begin(); iter != m.end(); iter++)
//		v.push_back(make_pair(iter->second.win, iter->first));
//
//	sort(v.begin(), v.end(), desc);
//
//	for (int i = 0; i < v.size(); i++)
//		cout << v[i].second << " "<<v[i].first <<" "<< m[v[i].second].diff << '\n';
//
//	return 0;
//}


//#include <iostream>
//#include <algorithm>
//#include <math.h>
//using namespace std;
//int N, K;
//double M, result = 100000000;
//
//double tree[10001];
//
//double rounding(double mid, int digit) {
//	return (floor((mid)*pow(float(10), digit) + 0.4f) / pow(float(10), digit));
//}
//
//int check(double mid) {
//	int tmp = 0;
//	for (int i = 0; i < N; i++) {
//		tmp += (int)(tree[i] / mid);
//	}
//	if (tmp == K) {
//		cout << tmp << ' ' << mid << '\n';
//		return 0;
//	}
//	else if (tmp > K) return 1;
//	else return -1;
//}
//
//void bs(double start, double end) {
//	while (end - start >= 0) {
//		double mid = (end + start) / 2;
//		mid = rounding(mid, 3);
//		//cout << mid << "\n\n";
//		if (check(mid) == 0) {
//			start = mid + 0.01;
//			if (result > mid) result = mid;
//		}
//		else if (check(mid) > 0) {
//			start = mid + 0.01;
//		}
//		else { // 갯수가 적음 더 작게 쪼갠다
//			end = mid - 0.01;
//		}
//	}
//}
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cin >> N >> K;
//	for (int i = 0; i < N; i++) cin >> tree[i];
//	M = *max_element(tree, tree + N);
//	sort(tree, tree + N);
//	bs(0, M);
//	cout.precision(3);
//	cout << result;
//}

//#include <iostream>
//#include <queue>
//#include <algorithm>
//#include <vector>
//#include <string>
//
//using namespace std;
//int N, M;  //병사수, 훈련비용
//string batch;
//vector <unsigned int> army;  //비트마스크
//int main() {
//	cin >> N >> M;
//	army.resize(N);
//	
//	for (int i = 0; i < M; i++) {
//		cin >> batch;
//		const char* temp = batch.c_str();
//		for (int j = 0; j < N; j++) {
//			if (batch[j] == 'o') { // o면 
//				army[i] = 1<<1;
//			}
//			army[i] << 1;
//		}
//		cout << army[i] << '\n';
//	}
//}