//#include <iostream>
//#include <algorithm>
//#include <vector>
//#include <map>
//#include <string>
//
//using namespace std;
//
//vector <pair<string,int> > dialNumbers;
//vector <string > dialString;
//bool cmp(const pair<string, int>& a, const pair<string, int>& b) {
//	if (a.second == b.second) {
//		return a.first < b.first;
//	}
//	return a.second < b.second;
//}
//void print() {
//	for (int i = 0; i < dialNumbers.size(); i++) {
//		cout << dialNumbers[i].first << " : "<<dialNumbers[i].second << "   ";
//	}cout << '\n';
//}
//string compare() {
//	vector <pair<string, int> >::iterator iter;
//	vector <string>::iterator iterstr;
//	for (iter = dialNumbers.begin(); iter != dialNumbers.end(); ++iter) { //비교하려는 대상.  (숫자로 정렬)
//		int start = lower_bound(dialString.begin(), dialString.end(), iter->first) - dialString.begin();
//		int end = upper_bound(dialString.begin(), dialString.end(), iter->first) - dialString.begin();
//
//		for (iterstr = dialString.begin() + start; iterstr != dialString.begin() + end; ++iterstr) {
//			if (*iterstr == iter->first) {
//				continue;
//			}
//			cout << *iterstr << ' '<<iter->first<<'\n';
//			
//			
//			cout << iterstr->substr(0, iter->first.size()) << ' '<<iter->first<<'\n';
//
//			if (iterstr->substr(0, iter->first.size()) == iter->first) {
//				cout << iterstr->substr(0, iter->first.size()) << ' ';
//				cout << iter->first << '\n';
//				return "NO";
//			}
//		}
//	}
//	return "YES";
//}
//void input() {
//	int testCase, dialNumberCase;
//	cin >> testCase;
//	while (testCase--) {
//		cin >> dialNumberCase;
//		for (int i = 0; i < dialNumberCase; i++) {
//			string temp;
//			cin >> temp;
//			dialNumbers.push_back({ temp, temp.size() });
//			dialString.push_back(temp);
//		}
//		sort(dialNumbers.begin(), dialNumbers.end(), cmp);
//		sort(dialString.begin(), dialString.end());
//		cout << compare() << '\n';
//	}
//}
//int main() {
//	input();
//}


#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <string>

using namespace std;
vector <string> dialNumbers;
unordered_set <string> set;

string compare() {
	vector <string>::iterator iter;

	for (iter = dialNumbers.begin()+1; iter != dialNumbers.end(); ++iter) { //비교하려는 대상.  (숫자로 정렬) 마지막은 제외(substr이 될 수 없음).
		for (int token = 1; token < iter->size(); token++) {   // substr 크기
			string sub = iter->substr(0, token);
			if (set.find(sub) != set.end()) {
				return "NO";
			}
		}
		set.insert(*iter);
	}
	return "YES";
}

void input() {
	int testCase, dialNumberCase;
	cin >> testCase;
	while (testCase--) {
		cin >> dialNumberCase;
		dialNumbers.clear();
		set.clear();
		for (int i = 0; i < dialNumberCase; i++) {
			string temp;
			cin >> temp;
			dialNumbers.push_back(temp);
		}
		//  <string, int> 중 int 로 정렬 =>  짧은 것 부터 확인하기 위해
		sort(dialNumbers.begin(), dialNumbers.end());
		set.insert(dialNumbers[0]);
		cout << compare() << '\n';
	}
}

int main() {
	input();
}