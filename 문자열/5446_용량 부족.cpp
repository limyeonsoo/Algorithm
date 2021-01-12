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
	Trie* next[63];
	int charState;
	bool doNotDel;

	Trie() {
		fill(next, next + 63, nullptr);
		charState = -1;
		doNotDel = false;
	}

	~Trie() {
		for (int i = 0; i < 63; i++) if (next[i]) delete next[i];
	}

	void insert(const char* key, bool condition) {
		if (condition) doNotDel = true;
		if (*key == '\0') {
			return;
		}
		charState = checkChar(*key);
		int curr = 0;
		if (charState == 0) curr = *key - 'A';
		else if (charState == 1) curr = *key - 'a'+26;
		else if (charState == 2) curr = 52;
		else if (charState == 3) curr = *key - '0'+53;
		if (!next[curr]) next[curr] = new Trie;
		next[curr]->insert(key + 1, condition);
	}

	string find(const char* key, string query, string current) {
		if (*key == '\0') {
			if (query == current) return current;
		}
		charState = checkChar(*key);
		int curr = 0;
		if (charState == 0) curr = *key - 'A';
		else if (charState == 1) curr = *key - 'a'+26;
		else if (charState == 2) curr = 52;
		else if (charState == 3) curr = *key - '0'+53;
		if (doNotDel) {
			return next[curr]->find(key + 1, query, current + *key);
		}
		else {
			return current+ "*";
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
		unordered_set <string> answer;
		unordered_set <string>::iterator iter;
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
		
		for (iter = deleteSet.begin(); iter != deleteSet.end(); ++iter) {
			string res = root->find(iter->c_str(), *iter, "");
			cout << res << '\n';
			answer.insert(res);
		}
		cout << answer.size() << '\n';
		delete root;
	}
}


int main() {
	input();
}