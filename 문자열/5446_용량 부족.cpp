#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_set>

using namespace std;

int testCase, targetCase, remainCase, answer;
string target, remain;

// 0 대문자 : 65~90
// 1 소문자 : 97~112
// 2   .    : 46
// 3  숫자  : 48~57

int checkChar(char key) {
	if (key == 46) return 2;
	if (48 <= key && key < 58) return 3;
	int base = key - 'a';
	if (0 <= base && base < 26) return 1;
	else return 0;
}

struct Trie {
	Trie* next[53];
	int charState;
	bool hasNext;
	bool doNotDel;
	bool isEnd;

	Trie() {
		fill(next, next + 53, nullptr);
		charState = -1;
		hasNext = doNotDel = isEnd = false;
	}

	~Trie() {
		for (int i = 0; i < 53; i++) if (next[i]) delete next[i];
	}

	void insert(const char* key, bool condition) {
		if (condition) doNotDel = true;
		if (*key == '\0') {
			isEnd = true;
			return;
		}
		charState = checkChar(*key);
		int curr = 0;
		
		if (charState == 0) curr = *key - 'A';
		else if (charState == 1) curr = *key - 'a' + 26;
		else if (charState == 2) curr = 52;
		else if (charState == 3) curr = *key - '0';
		
		if (!next[curr]) next[curr] = new Trie;
		hasNext = true;
		next[curr]->insert(key + 1, condition);
	}

	void find() {
		//if (*key == '\0') {
		//	return cmd;
		//}
		//charState = checkChar(*key);
		//int curr = 0;
		//if (charState == 0) curr = *key - 'A';
		//else if (charState == 1) curr = *key - 'a' + 26;
		//else if (charState == 2) curr = 52;
		//else if (charState == 3) curr = *key - '0';

		////cout << key << " " << *key << "  ->  " << cmd+ *key << " " << doNotDel << " " << isEnd << " "<<childCount<<'\n';

		//if (doNotDel) {
		//	if (next[curr]) return next[curr]->find(key + 1, cmd + *key);  //지우면 안된다면 무조건 전진.			
		//	else return cmd + *key;
		//}
		//else { //지워도 된다.  단, *을 붙이냐? 안붙이냐?   자식 수에 관련?
		//	// doNotDel 은 false다.
		//	return cmd + "*";
		//	
		//}
		if (!doNotDel) {
			answer++;
			return;
		}
		else if (isEnd)answer++;
		for (int i = 0; i < 53; i++) {
			if (next[i]) next[i]->find();
		}

	}
};


void input() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> testCase;
	while (testCase--) {
		Trie* root = new Trie;
		unordered_set <string> deleteSet;
		//unordered_set <string> answer;
		unordered_set <string>::iterator iter;
		answer = 0;
		cin >> targetCase;
		for (int i = 0; i < targetCase; i++) {
			cin >> target;
			deleteSet.insert(target);
			root->insert(target.c_str(), false);
		}

		cin >> remainCase;
		for (int i = 0; i < remainCase; i++) {
			cin >> remain;
			root->insert(remain.c_str(), true);
		}
		
		root->find();
		//for (iter = deleteSet.begin(); iter != deleteSet.end(); ++iter) {
		//	string res = root->find(iter->c_str(), "");
		//	//cout << res << '\n';
		//	//answer.insert(res);
		//}
		cout << answer << '\n';
		//cout << answer.size() << '\n';
		delete root;
	}
}


int main() {
	input();
}