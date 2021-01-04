//#include <iostream>
//#include <algorithm>
//#include <vector>
//#include <unordered_set>
//#include <string>
//
//using namespace std;
//vector <string> dialNumbers;
//unordered_set <string> set;
//
//string compare() {
//	vector <string>::iterator iter;
//
//	for (iter = dialNumbers.begin() + 1; iter != dialNumbers.end(); ++iter) { //비교하려는 대상.  (숫자로 정렬) 마지막은 제외(substr이 될 수 없음).
//		for (int token = 1; token < iter->size(); token++) {   // substr 크기
//			string sub = iter->substr(0, token);
//			if (set.find(sub) != set.end()) {
//				return "NO";
//			}
//		}
//		set.insert(*iter);
//	}
//	return "YES";
//}
//
//void input() {
//	int testCase, dialNumberCase;
//	cin >> testCase;
//	while (testCase--) {
//		cin >> dialNumberCase;
//		dialNumbers.clear();
//		set.clear();
//		for (int i = 0; i < dialNumberCase; i++) {
//			string temp;
//			cin >> temp;
//			dialNumbers.push_back(temp);
//		}
//		//  <string, int> 중 int 로 정렬 =>  짧은 것 부터 확인하기 위해
//		sort(dialNumbers.begin(), dialNumbers.end());
//		set.insert(dialNumbers[0]);
//		cout << compare() << '\n';
//	}
//}
//
//int main() {
//	input();
//}

//#include <iostream>
//#include <algorithm>
//#include <vector>
//#include <unordered_set>
//#include <string>
//
//using namespace std;
//
//vector <string> dialNumbers;
//
//string solution(vector<string> phone_book) {
//	sort(phone_book.begin(), phone_book.end());
//	for (int i = 0; i < phone_book.size() - 1; i++) {
//		cout << phone_book[i] << ' ' << phone_book[i + 1] << '\n';
//		if (phone_book[i] == phone_book[i + 1].substr(0, phone_book[i].size()))   return "NO";
//	}
//	return "YES";
//}
//
//void input() {
//	int testCase, dialNumberCase;
//	cin >> testCase;
//	while (testCase--) {
//		cin >> dialNumberCase;
//		dialNumbers.clear();
//		for (int i = 0; i < dialNumberCase; i++) {
//			string temp;
//			cin >> temp;
//			dialNumbers.push_back(temp);
//		}
//		//  <string, int> 중 int 로 정렬 =>  짧은 것 부터 확인하기 위해
//		sort(dialNumbers.begin(), dialNumbers.end());
//		for (int i = 0; i < dialNumbers.size(); i++) {
//			cout << dialNumbers[i] << ' ';
//		}cout << '\n';
//		cout << solution(dialNumbers) << '\n';
//	}
//}
//
//int main() {
//	input();
//}


#include <iostream>
#include <string>
#include <vector>

using namespace std;
const int NUMBER = 10;
vector <string> dialNumbers;
int testCase, dialCase;

struct Trie {
	Trie* next[NUMBER];
	bool isEnd;
	bool hasNext;

	Trie() {
		fill(next, next + NUMBER, nullptr);
		isEnd = hasNext = false;
	}

	~Trie() {
		for (int i = 0; i < NUMBER; i++) if (next[i]) delete next[i];
	}

	bool insertNfind(string str) {
		if (str.length() == 0) {
			isEnd = true;
			if (hasNext) return false;
			else return true;
		}
		hasNext = true;
		int current = str[0] - '0';
		if (!next[current]) next[current] = new Trie;
		bool get = next[current]->insertNfind(str.substr(1, str.length()));

		// isEnd  |  insertNfind
		//  true     true        => 접두어 끝을 지나갔다. -> NO
		// false     false       => 후자가 false 면 무조건 NO
		//  true     false       => 후자가 false 면 무조건 NO
		// false     true        => YES

		return !isEnd & get;
	}
};

void input() {
	cin >> testCase;
	while (testCase--) {
		cin >> dialCase;
		dialNumbers.resize(dialCase);
		Trie* root = new Trie;
		bool answer = true;
		for (int i = 0; i < dialCase; i++) {
			cin >> dialNumbers[i];
			if (!(root->insertNfind(dialNumbers[i]))) answer = false;
		}
		cout << (answer ? "YES" : "NO") << "\n";
		delete root;
	}
}

int main() {
	input();
}