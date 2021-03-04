//#include <iostream>
//#include <string>
//#include <vector>
//#include <unordered_map>
//#include <queue>
//using namespace std;
//unordered_map <string, int> map_si;
//unordered_map <int, string> map_is;
//vector <string> skills;
//vector <int> indegree;
//vector <vector<int> > chaining;
//void input() {
//	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//	string str, skill;
//	getline(cin, str);
//	
//	for (auto& chr : str) {
//		if (chr == ' ' || chr == '\n') {
//			map_si.insert({ skill, skills.size() });
//			map_is.insert({ skills.size(), skill });
//			skills.push_back(skill);
//			skill = "";
//		}
//		else {
//			skill += chr;
//		}
//	}
//	//마지막 문자.
//	map_si.insert({ skill, skills.size() });
//	map_is.insert({ skills.size(), skill });
//	skills.push_back(skill);
//
//	chaining.resize(skills.size());
//	indegree.resize(skills.size());
//	int chainCnt;
//	string x;
//	string y;
//	cin >> chainCnt;
//
//	for (int i = 0; i < chainCnt; i++) {
//		cin >> x >> y;
//		//단 방향
//		int xIdx = map_si[x];
//		int yIdx = map_si[y];
//		chaining[xIdx].push_back(yIdx);
//		indegree[yIdx]++;
//	}
//}
//
//void dfs(int curr, int depth, vector<string> prev) {
//	
//	if (chaining[curr].size() == 0) {
//		for (auto& p : prev) {
//			cout << p << ' ';
//		}cout << '\n';
//		return;
//	}
//
//	for (auto& next : chaining[curr]) {
//		prev[depth] = map_is[next];
//		dfs(next, depth+1, prev);
//	}
//}
//
//void connection() {
//	queue <int> q;
//	for (int i = 0; i < skills.size();i++) {
//		int skillIdx = map_si[skills[i]];
//		if (indegree[skillIdx] == 0) {
//			vector <string> prev(skills.size());
//			prev[0] = map_is[skillIdx];
//			dfs(skillIdx, 1, prev);
//		}
//	}
//	
//}
//int main() {
//	input();
//	connection();
//}
//
////#include <iostream>
////#include <vector>
////#include <algorithm>
////
////using namespace std;
////int p, n, h;
////vector <vector<int> > PC;
////void input() {
////	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
////	cin >> p >> n >> h; PC.resize(p + 1);
////	int pcNum, time;
////	for (int i = 0; i < n; i++) {
////		cin >> pcNum >> time;
////		PC[pcNum].push_back(time);
////	}
////}
////void predict() {
////	for (int i = 1; i <= p; i++) {
////		sort(PC[i].begin(), PC[i].end());
////		int limitTime = h;
////		int pcNum = 0, totalSum = 0;
////		while (limitTime > 0) {
////			cout << PC[i][pcNum] << ' ' << limitTime << '\n';
////			if (PC[i][pcNum] < limitTime) {
////				limitTime -= PC[i][pcNum];
////				totalSum += (PC[i][pcNum] * 1000);
////			}
////			pcNum++;
////			if (pcNum >= PC[i].size()) break;
////		}
////		cout << i << ' ' << totalSum << '\n';
////	}
////}
////int main() {
////	input();
////	predict();
////}
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N, M, E, soma, answer, eaten;
vector <int> beans;
void input() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> M >> E;
	bool flag = false;
	for (int i = 0; i < N; i++) {
		int bean; cin >> bean;
		beans.push_back(bean);
		if (bean >= E && flag == false) {
			flag = true;
			soma = i-1;
			if (bean == E) eaten += 1;
		}
	}
}
void solve() {
	int left = soma, right = soma+1;
	int leftDistance = 0, rightDistance = 0;
	 // index 벗어나는거 주의
	while (eaten < M) {
		cout << left << ' ' << right << '\n';
		cout << soma <<" : "<< leftDistance << "~" << rightDistance << '\n';
		// 일방 통행
		if (right >= beans.size()) {
			leftDistance = soma - beans[left];
			answer += leftDistance;
			soma--;
			eaten++;
			continue;
		}
		else if (left < 0) {
			rightDistance = beans[right] - soma;
			answer += rightDistance;
			soma++;
			eaten++;
			continue;
		}
		//양방 통행
		leftDistance = soma - beans[left];
		rightDistance = beans[right] - soma;

		if (leftDistance < rightDistance) {
			eaten++; left--;
			answer += rightDistance;
			soma--;
			leftDistance--;
		}
		else {
			eaten++; right++;
			answer += leftDistance;
			soma++;
			rightDistance++;
		}
	}
	cout << answer << '\n';
}
	
int main() {
	input();
	solve();
}


//#include <iostream>
//#include <string>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//int N, cnt, answer;
//vector <int> bases;
//vector<bool> visit;
//void input() {
//	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//	cin >> N; bases.resize(N + 1); visit.resize(N + 1);
//	for (int i = 1; i <= N; i++) {
//		cin >> bases[i];
//	}
//}
//
//void jump(int curr, int cnt) {
//	if (visit[curr]) {
//		answer = max(answer, cnt);
//		return;
//	}
//	visit[curr] = true;
//	int next = curr + bases[curr];
//
//	jump(next, cnt+1);
//}
//
//
//int main() {
//	input();
//	fill(visit.begin(), visit.end(), false);
//	
//	jump(1, 1);
//	fill(visit.begin(), visit.end(), false);
//	jump(2, 1);
//	fill(visit.begin(), visit.end(), false);
//	jump(3, 1);
//	cout << answer;
//}

//#include <iostream>
//#include <string>
//#include <vector>
//#include <algorithm>
//#include <unordered_map>
//#define ll long long
//using namespace std;
//int N, Score, timeCnt, currTime;
//unordered_map <int, int> time_maxScore;
//void input() {
//	//ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//	cin >> N;
//	for (int i = 0; i < N * N; i++) {
//		cin >> Score >> timeCnt;
//		for (int j = 0; j < timeCnt; j++) {
//			cin >> currTime;
//			time_maxScore[currTime] = max(time_maxScore[currTime], Score);
//			
//		}
//	}
//}
//
//void calc() {
//	ll answer = 0;
//	for (auto iter = time_maxScore.begin(); iter != time_maxScore.end(); ++iter) {
//		answer += (ll)iter->second;
//	}
//	cout << answer;
//}
//
//int main() {
//	// 1억이 될까?
//	input();
//	calc();
//}
//
