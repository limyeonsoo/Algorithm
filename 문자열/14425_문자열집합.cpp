/////////////////////////////////////Hash/////////////////////////

//#include <iostream>
//#include <unordered_set>
//#include <string>
//
//using namespace std;
//
//int main() {
//	int N, M, answer = 0;
//	string temp;
//	unordered_set <string> set;
//	cin >> N >> M;
//	for (int i = 0; i < N; i++) {
//		cin >> temp;
//		set.insert(temp);
//	}
//
//	for (int i = 0; i < M; i++) {
//		cin >> temp;
//		if (set.find(temp) != set.end()) answer++;
//	}
//	cout << answer;
//}


///////////////////////////// Trie /////////////////////////////////////////

#include <iostream>
#include <string>

using namespace std;

struct Trie {
	Trie* next[26];
	bool isEnd;

	Trie() {
		fill(next, next + 26, nullptr);
		isEnd = false;
	}
	~Trie() {
		for (int i = 0; i < 26; i++) if (next[i]) delete next[i];
	}

	void insert(const char* key) {
		if (*key == '\0') {
			isEnd = true;
			return;
		}
		int curr = *key - 'a';
		if (!next[curr]) next[curr] = new Trie;
		next[curr]->insert(key + 1);
	}

	bool find(const char* key) {
		if (*key == '\0') {
			if (isEnd) return true;
			return false;
		}
		int curr = *key - 'a';
		if (!next[curr]) return false;
		return next[curr]->find(key + 1);
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M, answer = 0;
	string temp;
	Trie* root = new Trie;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		root->insert(temp.c_str());
	}

	for (int i = 0; i < M; i++) {
		cin >> temp;
		if (root->find(temp.c_str())) answer++;
	}
	cout << answer;
}